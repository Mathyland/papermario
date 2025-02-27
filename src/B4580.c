#include "model.h"
#include "animation_script.h"

AnimScript gAnimScriptDefault = {
    AS_WAIT, 60,
    AS_END,
};

extern s32 gAnimCount;

typedef struct DisplayListBufferHandle {
    /* 0x0 */ s32 ttl;
    /* 0x4 */ void* addr;
} DisplayListBufferHandle; // size = 0x8

typedef DisplayListBufferHandle AnimatedMeshVertexCopyList[0x60];

extern AnimatedMeshVertexCopyList D_801533C0;
extern AnimatedMeshVertexCopyList D_801536C0;
extern AnimatedMeshList D_801539C0;
extern AnimatedMeshList D_80153A00;
extern s32 gAnimModelFogEnabled;
extern s32 gAnimModelFogR;
extern s32 gAnimModelFogG;
extern s32 gAnimModelFogB;
extern s32 gAnimModelFogA;
extern s32 gAnimModelFogStart;
extern s32 gAnimModelFogEnd;
extern s32 gAnimVtxSegment;
extern Matrix4f gAnimRotMtx;
extern Matrix4f gAnimScaleMtx;
extern Matrix4f gAnimTranslateMtx;
extern Matrix4f gAnimRotScaleMtx;
extern StaticAnimatorNode** gAnimTreeRoot;

extern Gfx D_8014B7F8[];
extern Gfx D_8014B820[];
extern Gfx D_8014B848[];
extern Gfx D_8014B870[];
extern Gfx D_8014B898[];
extern Gfx D_8014B8C0[];
extern Gfx D_8014B8E8[];
extern Gfx D_8014BE78[];
extern Gfx D_8014BEA0[];
extern Gfx D_8014BEC8[];
extern Gfx D_8014BEF0[];
extern Gfx D_8014BF18[];
extern Gfx D_8014BF40[];
extern Gfx D_8014BF68[];

void appendGfx_animator_node(ModelAnimator*, AnimatorNode*, Matrix4f);

// copy Vtx array from node->fcData.vtxList, but overwrite xyz coordinates with ones from buffer
// if animator has own vertexArray, buffer is offset within it
Vtx* animator_copy_vertices_to_buffer(ModelAnimator* animator, AnimatorNode* node, Vec3s* buffer, s32 vtxCount,
                                      s32 overhead, s32 startIdx) {
    DisplayListBufferHandle* handle;
    Vtx* bufferMem;
    Vtx* nodeVtxList;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_801533C0); i++) {
        handle = &D_801533C0[i];
        if (handle->ttl < 0) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(D_801533C0));

    bufferMem = general_heap_malloc((vtxCount + overhead) * sizeof(*bufferMem));
    handle->addr = bufferMem;

    ASSERT(bufferMem != NULL);

    handle->ttl = 3;
    nodeVtxList = &node->fcData.vtxList[startIdx];

    if (animator->vertexArray != NULL) {
        i = ((s32)buffer & 0xFFFFFF); // needed to match
        buffer = (Vec3s*)(i + (s32)animator->vertexArray);
    }

    for (i = 0; i < vtxCount; i++) {
        *bufferMem = *nodeVtxList;
        bufferMem->v.ob[0] = buffer->x;
        bufferMem->v.ob[1] = buffer->y;
        bufferMem->v.ob[2] = buffer->z;
        bufferMem++;
        buffer++;
        nodeVtxList++;
    }
    return handle->addr;
}

void animator_make_mirrorZ(Matrix4f mtx) {
    guMtxIdentF(mtx);
    mtx[0][0] = 1.0f;
    mtx[1][1] = 1.0f;
    mtx[2][2] = -1.0f;
    mtx[3][3] = 1.0f;
}

void animator_make_mirrorY(Matrix4f mtx) {
    guMtxIdentF(mtx);
    mtx[0][0] = 1.0f;
    mtx[1][1] = -1.0f;
    mtx[2][2] = 1.0f;
    mtx[3][3] = 1.0f;
}

void animator_make_mirrorX(Matrix4f mtx) {
    guMtxIdentF(mtx);
    mtx[0][0] = -1.0f;
    mtx[1][1] = 1.0f;
    mtx[2][2] = 1.0f;
    mtx[3][3] = 1.0f;
}

void animator_make_identity(Matrix4f mtx) {
    guMtxIdentF(mtx);
    mtx[0][0] = 1.0f;
    mtx[1][1] = 1.0f;
    mtx[2][2] = 1.0f;
    mtx[3][3] = 1.0f;
}

AnimatorNode* get_animator_child_with_id(AnimatorNode* node, s32 id) {
    s32 i;

    if (node->uniqueIndex == id) {
        return node;
    }

    for (i = 0; i < ARRAY_COUNT(node->children); i++) {
        if (node->children[i] != NULL) {
            AnimatorNode* child = get_animator_child_with_id(node->children[i], id);

            if (child != NULL) {
                return child;
            }

        }
    }

    return NULL;
}

AnimatorNode* get_animator_child_for_model(AnimatorNode* node, s32 modelId) {
    s32 i;

    if (node->fcData.modelID == modelId) {
        return node;
    }

    for (i = 0; i < ARRAY_COUNT(node->children); i++) {
        if (node->children[i] != NULL) {
            AnimatorNode* child = get_animator_child_for_model(node->children[i], modelId);

            if (child != NULL) {
                return child;
            }

        }
    }

    return NULL;
}

void free_animator_nodes(AnimatorNode* root) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(root->children); i++) {
        if (root->children[i] != NULL) {
            free_animator_nodes(root->children[i]);
        }
    }
    heap_free(root);
}

void clear_animator_list(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentAnimMeshListPtr = &D_801539C0;
        for (i = 0; i < ARRAY_COUNT(D_801533C0); i++) {
            D_801533C0[i].ttl = -1;
        }

        for (i = 0; i < ARRAY_COUNT(D_801536C0); i++) {
            D_801536C0[i].ttl = -1;
        }
    } else {
        gCurrentAnimMeshListPtr = &D_80153A00;
    }

    for (i = 0; i < ARRAY_COUNT(*gCurrentAnimMeshListPtr); i++) {
        (*gCurrentAnimMeshListPtr)[i] = NULL;
    }

    gAnimModelFogR = 10;
    gAnimModelFogG = 10;
    gAnimModelFogB = 10;
    gAnimModelFogA = 10;
    gAnimModelFogStart = 800;
    gAnimCount = 0;
    gAnimModelFogEnabled = 0;
    gAnimModelFogEnd = 1000;
}

void reset_animator_list(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentAnimMeshListPtr = &D_801539C0;
    } else {
        gCurrentAnimMeshListPtr = &D_80153A00;
    }

    gAnimModelFogR = 10;
    gAnimModelFogG = 10;
    gAnimModelFogB = 10;
    gAnimModelFogA = 10;
    gAnimModelFogStart = 800;
    gAnimCount = 0;
    gAnimModelFogEnabled = 0;
    gAnimModelFogEnd = 1000;
}

void delete_model_animator_node(AnimatorNode* node) {
    s32 i;

    node->flags = 0;

    for (i = 0; i < ARRAY_COUNT(node->children); i++) {
        if (node->children[i] != NULL) {
            delete_model_animator_node(node->children[i]);
            node->children[i] = NULL;
        }
    }

    heap_free(node);
}

void delete_model_animator_nodes(ModelAnimator* animator) {
    animator->nextUniqueID = 0;

    if (animator->rootNode != NULL) {
        delete_model_animator_node(animator->rootNode);
        animator->rootNode = NULL;
    }
}

void delete_model_animator(ModelAnimator* animator) {
    s32 i;

    animator->nextUniqueID = 0;

    if (animator->rootNode != NULL) {
        delete_model_animator_node(animator->rootNode);
        animator->rootNode = NULL;

        for (i = 0; i < ARRAY_COUNT(*gCurrentAnimMeshListPtr); i++) {
            if ((*gCurrentAnimMeshListPtr)[i] == animator) {
                (*gCurrentAnimMeshListPtr)[i] = NULL;
                break;
            }
        }

        heap_free(animator);
        gAnimCount--;
    }
}

s32 create_model_animator(s16* animPos) {
    ModelAnimator* animator;
    s32 i, j;

    for (i = 0; i < ARRAY_COUNT(*gCurrentAnimMeshListPtr); i++) {
        if ((*gCurrentAnimMeshListPtr)[i] == NULL) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(*gCurrentAnimMeshListPtr));

    (*gCurrentAnimMeshListPtr)[i] = animator = heap_malloc(sizeof(*animator));
    gAnimCount += 1;

    ASSERT(animator != NULL);

    animator->flags = MODEL_ANIMATOR_FLAGS_UPDATE_PENDING | MODEL_ANIMATOR_FLAGS_ENABLED | MODEL_ANIMATOR_FLAGS_CAM_2 | MODEL_ANIMATOR_FLAGS_CAM_1 | MODEL_ANIMATOR_FLAGS_CAM_0;
    animator->renderMode = RENDER_MODE_ALPHATEST;
    animator->nextUpdateTime = 1.0f;
    animator->timeScale = 1.0f;
    animator->animReadPos = animPos;

    if (animPos == NULL) {
        animator->animReadPos = gAnimScriptDefault;
    }

    animator->savedReadPos = animPos;
    animator->animationBuffer = NULL;
    animator->vertexArray = NULL;
    animator->fpRenderCallback = NULL;
    animator->rootNode = NULL;
    animator->nextUniqueID = 0;

    for (j = 0; j < ARRAY_COUNT(animator->staticNodeIDs); j++) {
        animator->staticNodeIDs[j] = j + 1;
    }

    if (gGameStatusPtr->isBattle) {
        i |= 0x800;
    }
    return i;
}

s32 create_mesh_animator(s32 animPos, s16* animBuffer) {
    ModelAnimator* animator;
    s32 i, j;

    for (i = 0; i < ARRAY_COUNT(*gCurrentAnimMeshListPtr); i++) {
        if ((*gCurrentAnimMeshListPtr)[i] == NULL) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(*gCurrentAnimMeshListPtr));

    (*gCurrentAnimMeshListPtr)[i] = animator = heap_malloc(sizeof(*animator));
    gAnimCount += 1;

    ASSERT(animator != NULL);

    animator->flags = MODEL_ANIMATOR_FLAGS_UPDATE_PENDING | MODEL_ANIMATOR_FLAGS_ENABLED | MODEL_ANIMATOR_FLAGS_CAM_2 | MODEL_ANIMATOR_FLAGS_CAM_1 | MODEL_ANIMATOR_FLAGS_CAM_0;
    animator->renderMode = RENDER_MODE_ALPHATEST;
    animator->vertexArray = NULL;
    animator->fpRenderCallback = NULL;
    animator->rootNode = NULL;
    animator->nextUniqueID = 0;
    animator->animationBuffer = animBuffer;
    animator->nextUpdateTime = 1.0f;
    animator->timeScale = 1.0f;
    animPos = (animPos & 0xFFFFFF) + (s32)animator->animationBuffer;
    animator->animReadPos = (s16*)animPos;
    animator->savedReadPos = (s16*)animPos;

    for (j = 0; j < ARRAY_COUNT(animator->staticNodeIDs); j++) {
        animator->staticNodeIDs[j] = j + 1;
    }

    if (gGameStatusPtr->isBattle) {
        i |= 0x800;
    }
    return i;
}

AnimatorNode* add_anim_node(ModelAnimator* animator, s32 parentNodeID, AnimatorNodeBlueprint* nodeBP) {
    AnimatorNode* ret;
    AnimatorNode* child;
    s32 nextUniqueID;
    s32 nullRootNode;
    s32 i;

    ret = heap_malloc(sizeof(*ret));
    ASSERT(ret != NULL);

    ret->flags = MODEL_ANIMATOR_FLAGS_ENABLED;
    ret->displayList = nodeBP->displayList;
    ret->basePos.x = nodeBP->basePos.x;
    ret->basePos.y = nodeBP->basePos.y;
    ret->basePos.z = nodeBP->basePos.z;
    ret->pos.x = 0.0f;
    ret->pos.y = 0.0f;
    ret->pos.z = 0.0f;
    ret->rotation.x = nodeBP->rotation.x;
    ret->rotation.y = nodeBP->rotation.y;
    ret->rotation.z = nodeBP->rotation.z;
    ret->scale.x = 1.0f;
    ret->scale.y = 1.0f;
    ret->scale.z = 1.0f;
    ret->vertexStartOffset = -1;

    for (i = 0; i < ARRAY_COUNT(ret->children); i++) {
        ret->children[i] = NULL;
    }

    nextUniqueID = animator->nextUniqueID;
    nextUniqueID = nextUniqueID + 1;

    if (parentNodeID == 0) {
        s32 nullRootNode = animator->rootNode == NULL; // todo ???

        ret->uniqueIndex = nextUniqueID;

        if (nullRootNode) {
            animator->rootNode = ret;
        } else {
            child = get_animator_child_with_id(animator->rootNode, 1);
            ASSERT(child != NULL);

            for (i = 0; i < ARRAY_COUNT(child->children); i++) {
                if (child->children[i] == NULL) {
                    child->children[i] = ret;
                    break;
                }
            }

            ASSERT(i < ARRAY_COUNT(child->children));
        }
    } else {
        ret->uniqueIndex = nextUniqueID;
        child = get_animator_child_with_id(animator->rootNode, parentNodeID);
        ASSERT(child != NULL);

        for (i = 0; i < ARRAY_COUNT(child->children); i++) {
            if (child->children[i] == NULL) {
                child->children[i] = ret;
                break;
            }
        }

        ASSERT(i < ARRAY_COUNT(child->children));
    }

    animator->nextUniqueID = nextUniqueID;
    return ret;
}

void update_model_animator(s32 animatorID) {
    if (!gGameStatusPtr->isBattle || animatorID & 0x800) {
        ModelAnimator* animator;

        animatorID &= ~0x800;
        animator = (*gCurrentAnimMeshListPtr)[animatorID];

        if (animator != NULL && animator->flags != 0) {
            s32 temp = 0;

            if (!(animator->flags & MODEL_ANIMATOR_FLAGS_FREEZE_ANIMATION)) {
                animator->flags &= ~MODEL_ANIMATOR_FLAGS_UPDATE_PENDING;
                animator->nextUpdateTime -= animator->timeScale;
                if (animator->nextUpdateTime <= 0.0f) {
                    if (!(animator->flags & MODEL_ANIMATOR_FLAGS_MESH)) {
                        do {
                            temp = step_model_animator(animator);
                        } while (temp > 0);
                    } else {
                        animator->nextUpdateTime = 1.0f;
                        reload_mesh_animator_tree(animator);
                        do {
                            temp = step_mesh_animator(animator);
                        } while (temp > 0);
                    }
                }

                if (temp != -1) {
                    s32 i;

                    animator_update_model_transforms(animator, NULL);

                    for (i = 0; i < ARRAY_COUNT(D_801533C0); i++) {
                        if (D_801533C0[i].ttl >= 0) {
                            D_801533C0[i].ttl--;
                            if (D_801533C0[i].ttl == 0) {
                                D_801533C0[i].ttl = -1;
                                general_heap_free(D_801533C0[i].addr);
                            }
                        }
                    }

                    for (i = 0; i < ARRAY_COUNT(D_801536C0); i++) {
                        if (D_801536C0[i].ttl >= 0) {
                            D_801536C0[i].ttl--;
                            if (D_801536C0[i].ttl == 0) {
                                D_801536C0[i].ttl = -1;
                                general_heap_free(D_801536C0[i].addr);
                            }
                        }
                    }
                }
            }
        }
    }
}

void update_model_animator_with_transform(s32 animatorID, Mtx* mtx) {
    if (!gGameStatusPtr->isBattle || animatorID & 0x800) {
        ModelAnimator* animator;

        animatorID &= ~0x800;
        animator = (*gCurrentAnimMeshListPtr)[animatorID];

        if (animator != NULL && animator->flags != 0) {
            s32 temp = 0;

            if (!(animator->flags & MODEL_ANIMATOR_FLAGS_FREEZE_ANIMATION)) {
                animator->flags &= ~MODEL_ANIMATOR_FLAGS_UPDATE_PENDING;
                animator->nextUpdateTime -= animator->timeScale;
                if (animator->nextUpdateTime <= 0.0f) {
                    if (!(animator->flags & MODEL_ANIMATOR_FLAGS_MESH)) {
                        do {
                            temp = step_model_animator(animator);
                        } while (temp > 0);
                    } else {
                        animator->nextUpdateTime = 1.0f;
                        reload_mesh_animator_tree(animator);
                        do {
                            temp = step_mesh_animator(animator);
                        } while (temp > 0);
                    }
                }

                if (temp != -1) {
                    s32 i;

                    animator_update_model_transforms(animator, mtx);

                    for (i = 0; i < ARRAY_COUNT(D_801533C0); i++) {
                        if (D_801533C0[i].ttl >= 0) {
                            D_801533C0[i].ttl--;
                            if (D_801533C0[i].ttl == 0) {
                                D_801533C0[i].ttl = -1;
                                general_heap_free(D_801533C0[i].addr);
                            }
                        }
                    }

                    for (i = 0; i < ARRAY_COUNT(D_801536C0); i++) {
                        if (D_801536C0[i].ttl >= 0) {
                            D_801536C0[i].ttl--;
                            if (D_801536C0[i].ttl == 0) {
                                D_801536C0[i].ttl = -1;
                                general_heap_free(D_801536C0[i].addr);
                            }
                        }
                    }
                }
            }
        }
    }
}

s32 step_model_animator(ModelAnimator* animator) {
    s16* args = animator->animReadPos;
    AnimatorNode* node;
    f32 x, y, z;
    s32 flags;
    s32 nodeId;

    switch (*args++) {
        case AS_END:
            return -1;
        case AS_SET_RENDER_MODE:
            animator->renderMode = *args++;
            animator->animReadPos = args;
            return 1;
        case AS_WAIT:
            animator->nextUpdateTime = *args++;
            animator->animReadPos = args;
            break;
        case AS_END_LOOP:
            animator->animReadPos = animator->savedReadPos;
            return 1;
        case AS_LOOP:
            animator->animReadPos = animator->savedReadPos = args;
            return 1;
        case AS_SET_FLAGS:
            flags = *args++;
            animator->animReadPos = args;
            animator->flags |= flags & 0xFFFF;
            return 1;
        case AS_SET_NODE_FLAGS:
            node = get_animator_child_with_id(animator->rootNode, animator->staticNodeIDs[*args++ - 1]);
            flags = *args++;
            node->flags |= flags;
            animator->animReadPos = args;
            return 1;
        case AS_CLEAR_NODE_FLAGS:
            node = get_animator_child_with_id(animator->rootNode, animator->staticNodeIDs[*args++ - 1]);
            flags = *args++;
            node->flags &= ~flags;
            animator->animReadPos = args;
            return 1;
        case AS_OP_19:
            animator->flags |= MODEL_ANIMATOR_FLAGS_NO_FLIP;
            animator->animReadPos = args;
            return 1;
        case AS_SET_ROTATION:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = (f32)*args++ * 180.0 / 32767.0;
            y = (f32)*args++ * 180.0 / 32767.0;
            z = (f32)*args++ * 180.0 / 32767.0;
            animator->animReadPos = args;

            node = get_animator_child_with_id(animator->rootNode, nodeId);
            ASSERT(node != NULL);
            node->rotation.x = x;
            node->rotation.y = y;
            node->rotation.z = z;
            return 1;
        case AS_ADD_ROTATION:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = (f32)*args++ * 180.0 / 32767.0;
            y = (f32)*args++ * 180.0 / 32767.0;
            z = (f32)*args++ * 180.0 / 32767.0;
            animator->animReadPos = args;

            node = get_animator_child_with_id(animator->rootNode, nodeId);
            ASSERT(node != NULL);
            node->rotation.x += x;
            node->rotation.y += y;
            node->rotation.z += z;
            return 1;
        case AS_SET_POS:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = *args++;
            y = *args++;
            z = *args++;
            animator->animReadPos = args;
            node = get_animator_child_with_id(animator->rootNode, nodeId);
            ASSERT(node != NULL);
            node->pos.x = x;
            node->pos.y = y;
            node->pos.z = z;
            return 1;
        case AS_SET_SCALE:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = (f32)*args++ * 180.0 / 32767.0;
            y = (f32)*args++ * 180.0 / 32767.0;
            z = (f32)*args++ * 180.0 / 32767.0;
            animator->animReadPos = args;

            node = get_animator_child_with_id(animator->rootNode, nodeId);
            ASSERT(node != NULL);
            node->scale.x = x;
            node->scale.y = y;
            node->scale.z = z;
            return 1;
    }
    return 0;
}

void animator_update_model_transforms(ModelAnimator* animator, Mtx* rootTransform) {
    Matrix4f flipMtx;

    if (animator->rootNode != NULL) {
        switch (animator->flags & (MODEL_ANIMATOR_FLAGS_FLIP_Z | MODEL_ANIMATOR_FLAGS_FLIP_Y | MODEL_ANIMATOR_FLAGS_FLIP_X)) {
            case MODEL_ANIMATOR_FLAGS_FLIP_Z:
                animator_make_mirrorZ(flipMtx);
                break;
            case MODEL_ANIMATOR_FLAGS_FLIP_Y:
                animator_make_mirrorY(flipMtx);
                break;
            case MODEL_ANIMATOR_FLAGS_FLIP_X:
                animator_make_mirrorX(flipMtx);
                break;
            default:
                animator_make_identity(flipMtx);
                break;
        }
        animator_node_update_model_transform(animator, flipMtx, animator->rootNode, rootTransform);
    }
}

void animator_node_update_model_transform(ModelAnimator* animator, f32 (*flipMtx)[4], AnimatorNode* node,
                                          Mtx* rootTransform) {
    Matrix4f sp10;
    s32 i;

    guRotateRPYF(gAnimRotMtx, clamp_angle(node->rotation.x), clamp_angle(node->rotation.y), clamp_angle(node->rotation.z));
    guScaleF(gAnimScaleMtx, node->scale.x, node->scale.y, node->scale.z);
    guTranslateF(gAnimTranslateMtx, node->basePos.x + node->pos.x, node->basePos.y + node->pos.y, node->basePos.z + node->pos.z);
    guMtxCatF(gAnimScaleMtx, gAnimRotMtx, gAnimRotScaleMtx);
    guMtxCatF(gAnimRotScaleMtx, gAnimTranslateMtx, sp10);

    if (!(animator->flags & MODEL_ANIMATOR_FLAGS_NO_FLIP)) {
        guMtxCatF(sp10, flipMtx, sp10);
    }

    copy_matrix(sp10, node->mtx);

    if (node->flags & MODEL_ANIMATOR_FLAGS_HAS_MODEL) {
        Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(node->fcData.modelID));

        copy_matrix(sp10, model->transformMatrix);
        guMtxL2F(sp10, rootTransform);
        guMtxCatF(model->transformMatrix, sp10, model->transformMatrix);
        model->flags |= MODEL_FLAGS_USES_TRANSFORM_MATRIX;
    }

    for (i = 0; i < ARRAY_COUNT(node->children); i++) {
        if (node->children[i] != NULL) {
            animator_node_update_model_transform(animator, sp10, node->children[i], rootTransform);
        }
    }
}

void render_animated_model(s32 animatorID, Mtx* rootTransform) {
    RenderTask rt;
    RenderTask* rtPtr = &rt;

    if (!gGameStatusPtr->isBattle || animatorID & 0x800) {
        ModelAnimator* animator;

        animatorID &= ~0x800;
        animator = (*gCurrentAnimMeshListPtr)[animatorID];
        if (animator != NULL && animator->flags != 0 && !(animator->flags & MODEL_ANIMATOR_FLAGS_UPDATE_PENDING) &&
            animator->flags & (1 << gCurrentCamID) && !(animator->flags & MODEL_ANIMATOR_FLAGS_HIDDEN))
        {
            animator->mtx = *rootTransform;
            animator->vertexArray = NULL;
            rtPtr->appendGfxArg = animator;
            rtPtr->appendGfx = (void (*)(void*))appendGfx_animator;
            rtPtr->distance = 0;
            rtPtr->renderMode = animator->renderMode;
            queue_render_task(rtPtr);
        }
    }
}

void render_animated_model_with_vertices(s32 animatorID, Mtx* rootTransform, s32 vtxSegment, Vec3s* vertexArray) {
    RenderTask rt;
    RenderTask* rtPtr = &rt;

    if (!gGameStatusPtr->isBattle || animatorID & 0x800) {
        ModelAnimator* animator;

        animatorID &= ~0x800;
        animator = (*gCurrentAnimMeshListPtr)[animatorID];
        if (animator != NULL && animator->flags != 0 && !(animator->flags & MODEL_ANIMATOR_FLAGS_UPDATE_PENDING) &&
            animator->flags & (1 << gCurrentCamID) && !(animator->flags & MODEL_ANIMATOR_FLAGS_HIDDEN))
        {
            animator->mtx = *rootTransform;
            gAnimVtxSegment = vtxSegment;
            animator->vertexArray = vertexArray;
            rtPtr->appendGfxArg = animator;
            rtPtr->appendGfx = (void (*)(void*))appendGfx_animator;
            rtPtr->distance = 0;
            rtPtr->renderMode = animator->renderMode;
            queue_render_task(rtPtr);
        }
    }
}

void appendGfx_animator(ModelAnimator* animator) {
    Matrix4f sp10;

    if (animator->vertexArray != NULL) {
        gSPSegment(gMasterGfxPos++, gAnimVtxSegment, VIRTUAL_TO_PHYSICAL(animator->vertexArray));
    }

    gDisplayContext->matrixStack[gMatrixListPos] = animator->mtx;
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    //TODO find better match
    switch (gAnimModelFogEnabled != 0) {
        case FALSE:
            switch (animator->renderMode) {
                case RENDER_MODE_SURFACE_OPA:
                    gSPDisplayList(gMasterGfxPos++, D_8014B7F8);
                    break;
                case RENDER_MODE_DECAL_OPA:
                    gSPDisplayList(gMasterGfxPos++, D_8014B820);
                    break;
                case RENDER_MODE_INTERSECTING_OPA:
                    gSPDisplayList(gMasterGfxPos++, D_8014B848);
                    break;
                case RENDER_MODE_ALPHATEST:
                    gSPDisplayList(gMasterGfxPos++, D_8014B870);
                    break;
                case RENDER_MODE_SURFACE_XLU_LAYER1:
                    gSPDisplayList(gMasterGfxPos++, D_8014B898);
                    break;
                case RENDER_MODE_DECAL_XLU:
                    gSPDisplayList(gMasterGfxPos++, D_8014B8C0);
                    break;
                case RENDER_MODE_INTERSECTING_XLU:
                    gSPDisplayList(gMasterGfxPos++, D_8014B8E8);
                    break;
            }
            break;
        case TRUE:
            switch (animator->renderMode) {
                case RENDER_MODE_SURFACE_OPA:
                    gSPDisplayList(gMasterGfxPos++, D_8014BE78);
                    break;
                case RENDER_MODE_DECAL_OPA:
                    gSPDisplayList(gMasterGfxPos++, D_8014BEA0);
                    break;
                case RENDER_MODE_INTERSECTING_OPA:
                    gSPDisplayList(gMasterGfxPos++, D_8014BEC8);
                    break;
                case RENDER_MODE_ALPHATEST:
                    gSPDisplayList(gMasterGfxPos++, D_8014BEF0);
                    break;
                case RENDER_MODE_SURFACE_XLU_LAYER1:
                    gSPDisplayList(gMasterGfxPos++, D_8014BF18);
                    break;
                case RENDER_MODE_DECAL_XLU:
                    gSPDisplayList(gMasterGfxPos++, D_8014BF40);
                    break;
                case RENDER_MODE_INTERSECTING_XLU:
                    gSPDisplayList(gMasterGfxPos++, D_8014BF68);
                    break;
            }

            gDPSetFogColor(gMasterGfxPos++, gAnimModelFogR, gAnimModelFogG, gAnimModelFogB, gAnimModelFogA);
            gSPFogPosition(gMasterGfxPos++, gAnimModelFogStart, gAnimModelFogEnd);
            break;
    }

    guMtxL2F(sp10, &animator->mtx);
    appendGfx_animator_node(animator, animator->rootNode, sp10);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

#ifdef NON_EQUIVALENT
void appendGfx_animator_node(ModelAnimator* animator, AnimatorNode* node, Matrix4f mtx) {
    s32 i, dlSize, bufferIdx;
    DisplayListBufferHandle* bufferHandle;
    Gfx* gfxPos;
    s32 j;
    u32 w0,w1;
    s32 totalVtxCount;
    s32 cmd;

    if (node->flags & MODEL_ANIMATOR_FLAGS_HIDDEN) {
        for (i = 0; i < ARRAY_COUNT(node->children); i++) {
            if (node->children[i] != NULL) {
                guMtxCatF(node->mtx, mtx, node->mtx);
                appendGfx_animator_node(animator, node->children[i], node->mtx);
            }
        }
        return;
    }

    guMtxCatF(node->mtx, mtx, node->mtx);
    guMtxF2L(node->mtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPPipeSync(gMasterGfxPos++);

    gSPTexture(gMasterGfxPos++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
    gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
    gSPClearGeometryMode(gMasterGfxPos++, G_LIGHTING);
    if (animator->flags & MODEL_ANIMATOR_FLAGS_CULL_BACK) {
        gSPSetGeometryMode(gMasterGfxPos++, G_CULL_BACK);
    }
    if (!gAnimModelFogEnabled) {
        gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    } else {
        gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, 0, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    }
    gDPPipeSync(gMasterGfxPos++);

    if (animator->fpRenderCallback != NULL) {
        animator->fpRenderCallback(animator->renderCallbackArg);
    }
    gDPPipeSync(gMasterGfxPos++);

    if (node->displayList != NULL) {
        if (node->vertexStartOffset < 0) {
            gSPDisplayList(gMasterGfxPos++, node->displayList);
        } else {
            dlSize = 0;
            if (node->displayList[dlSize].words.w0 >> 0x18 != G_ENDDL) {
                while (TRUE) {
                    w0 = node->displayList[dlSize++].words.w0;
                    cmd = w0 >> 0x18;
                    if (cmd == G_ENDDL) {
                        break;
                    }
                }
            }

            for (bufferIdx = 0; bufferIdx < ARRAY_COUNT(D_801536C0); bufferIdx++) {
                bufferHandle = &D_801536C0[bufferIdx];
                if (bufferHandle->ttl < 0) {
                    break;
                }
            }
            ASSERT(bufferIdx < ARRAY_COUNT(D_801536C0));

            gfxPos = general_heap_malloc(dlSize * sizeof(Gfx));
            bufferHandle->addr = gfxPos;
            ASSERT(gfxPos != NULL);
            bufferHandle->ttl = 3;


            totalVtxCount = 0;
            j = 0;
            do {
                w0 = ((s32*)node->displayList)[j++];
                w1 = ((s32*)node->displayList)[j++];
                cmd = w0 >> 0x18;
                if (cmd == G_ENDDL) {
                    break;
                }
                if (cmd == G_VTX) {
                    s32 startIdx = _SHIFTR(w0,1,7);
                    s32 vtxCount = _SHIFTR(w0,12,8);
                    startIdx -= vtxCount;
                    if (node->fcData.vtxList == NULL) {
                        Vtx* newBuffer = &((Vtx*)w1)[node->vertexStartOffset + totalVtxCount];
                        gSPVertex(gfxPos++, newBuffer, vtxCount, startIdx);
                    } else {
                        // if node->fcData.vtxList != NULL, all vertex buffers in gSPVertex commands are pointers to Vec3s, not to Vtx
                        Vtx* newBuffer = animator_copy_vertices_to_buffer(animator, node, w1 + (node->vertexStartOffset + totalVtxCount) * 0x6, vtxCount, startIdx, totalVtxCount);
                        gSPVertex(gfxPos++, newBuffer, vtxCount, startIdx);
                    }
                    totalVtxCount += vtxCount;
                } else {
                    Gfx* temp = gfxPos++;
                    temp->words.w0 = w0;
                    temp->words.w1 = w1;
                }
            } while (TRUE);
            gSPEndDisplayList(gfxPos++);
            gSPDisplayList(gMasterGfxPos++, bufferHandle->addr);
        }
    }
    gDPPipeSync(gMasterGfxPos++);

    for (i = 0; i < ARRAY_COUNT(node->children); i++) {
        if (node->children[i] != NULL) {
            appendGfx_animator_node(animator, node->children[i], node->mtx);
        }
    }
}
#else
INCLUDE_ASM(s32, "B4580", appendGfx_animator_node);
#endif

AnimatorNode* get_animator_node_for_tree_index(ModelAnimator* animator, s32 arg1) {
    return get_animator_child_with_id(animator->rootNode, animator->staticNodeIDs[arg1 - 1]);
}

AnimatorNode* get_animator_node_with_id(ModelAnimator* animator, s32 id) {
    return get_animator_child_for_model(animator->rootNode, id);
}

void set_animator_tree_to_node_map(ModelAnimator* animator, s32* nodeIDs, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        animator->staticNodeIDs[i] = *nodeIDs;
        nodeIDs++;
    }
}

ModelAnimator* get_animator_by_index(s32 animModelID) {
    return (*gCurrentAnimMeshListPtr)[animModelID & ~0x800];
}

ModelAnimator* set_animator_render_callback(s32 animModelID, s32 callbackArg, void (*callbackFunc)(void*)) {
    ModelAnimator* ret = (*gCurrentAnimMeshListPtr)[animModelID & ~0x800];

    ret->fpRenderCallback = callbackFunc;
    ret->renderCallbackArg = callbackArg;
    return ret;
}

void enable_anim_model_fog(void) {
    gAnimModelFogEnabled = TRUE;
}

void disable_anim_model_fog(void) {
    gAnimModelFogEnabled = FALSE;
}

void set_anim_model_fog_dist(s32 start, s32 end) {
    gAnimModelFogStart = start;
    gAnimModelFogEnd = end;
}

void set_anim_model_fog_color(s32 r, s32 g, s32 b, s32 a) {
    gAnimModelFogR = r;
    gAnimModelFogG = g;
    gAnimModelFogB = b;
    gAnimModelFogA = a;
}

s32 is_anim_model_fog_enabled(void) {
    return gAnimModelFogEnabled;
}

void get_anim_model_fog_distance(s32* start, s32* end) {
    *start = gAnimModelFogStart;
    *end = gAnimModelFogEnd;
}

void get_anim_model_fog_color(s32* r, s32* g, s32* b, s32* a) {
    *r = gAnimModelFogR;
    *g = gAnimModelFogG;
    *b = gAnimModelFogB;
    *a = gAnimModelFogA;
}

void set_animator_flags(s32 index, s32 bits) {
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[index & ~0x800];

    animator->flags |= bits;
}

void clear_animator_flags(s32 index, s32 bits) {
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[index & ~0x800];

    animator->flags &= ~bits;
}

void play_model_animation(s32 index, s32 animPos) {
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[index & ~0x800];

    if (animator->animationBuffer != NULL) {
        animPos = (animPos & 0xFFFFFF) + (s32)animator->animationBuffer; // TODO: array access?
    }
    animator->animReadPos = (s16*)animPos;
    animator->savedReadPos = (s16*)animPos;
    animator->treeIndexPos = 0;
    animator->nextUpdateTime = 1.0f;
}

void play_model_animation_starting_from(s32 index, s32 animPos, s32 framesToSkip) {
    s32 indexMasked = index & ~0x800;
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[indexMasked];
    s32 i;

    if (animator->animationBuffer != NULL) {
        animPos = (animPos & 0xFFFFFF) + (s32)animator->animationBuffer; // TODO: array access?
    }

    animator->animReadPos = (s16*)animPos;
    animator->savedReadPos = (s16*)animPos;
    animator->treeIndexPos = 0;
    animator->nextUpdateTime = 1.0f;

    for (i = 0; i < framesToSkip; i++) {
        update_model_animator(indexMasked);
    }
}

void load_model_animator_node(StaticAnimatorNode* node, ModelAnimator* animator, s32 parentNodeID, s32* treeIndexToNodeIDs) {
    AnimatorNodeBlueprint bp;
    AnimatorNodeBlueprint* bpPtr = &bp;
    AnimatorNode* newNode;
    s32 i;

    if (node != NULL) {
        bpPtr->displayList = node->displayList;
        bpPtr->basePos.x = 0.0f;
        bpPtr->basePos.y = 0.0f;
        bpPtr->basePos.z = 0.0f;
        bpPtr->rotation.x = ((f32) node->rot.x * 180.0) / 32767.0;
        bpPtr->rotation.y = ((f32) node->rot.y * 180.0) / 32767.0;
        bpPtr->rotation.z = ((f32) node->rot.z * 180.0) / 32767.0;

        newNode = add_anim_node(animator, parentNodeID, bpPtr);

        if (node->modelID != 0) {
            newNode->fcData.modelID = node->modelID - 1;
            newNode->flags |= MODEL_ANIMATOR_FLAGS_HAS_MODEL;
        }

        i = 0;
        while (gAnimTreeRoot[i] != node) {
            i++;
        }

        treeIndexToNodeIDs[i] = newNode->uniqueIndex;

        if (node->child != NULL) {
            load_model_animator_node(node->child, animator, newNode->uniqueIndex, treeIndexToNodeIDs);
        }

        if (node->sibling != NULL) {
            load_model_animator_node(node->sibling, animator, parentNodeID, treeIndexToNodeIDs);
        }
    }
}

void load_model_animator_tree(s32 index, StaticAnimatorNode** tree) {
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[index & ~0x800];
    s32 nodeIDs[ARRAY_COUNT(animator->staticNodeIDs)];

    if (animator != NULL && animator->flags != 0) {
        gAnimTreeRoot = tree;
        load_model_animator_node(*tree, animator, 0, nodeIDs);
        set_animator_tree_to_node_map(animator, nodeIDs, ARRAY_COUNT(animator->staticNodeIDs));
    }
}

void load_mesh_animator_node(StaticAnimatorNode* node, ModelAnimator* animator, s32 parentNodeID, s32* treeIndexToNodeIDs) {
    if (node != NULL) {
        if (node->child != NULL && parentNodeID == 0) {
            load_mesh_animator_node(node->child, animator, 0, treeIndexToNodeIDs);
        } else {
            do {
                animator->staticNodes[parentNodeID] = node;
                node = node->sibling;
                parentNodeID++;
            } while (node != NULL);
        }
    }
}

void load_mesh_animator_tree(s32 index, StaticAnimatorNode** tree) {
    s32 indexMasked = index & ~0x800;
    ModelAnimator* animator = (*gCurrentAnimMeshListPtr)[indexMasked];
    s32 nodeIDs[ARRAY_COUNT(animator->staticNodeIDs)];
    s32 i;

    if (animator != NULL && animator->flags != 0) {
        if ((*tree)->vertexStartOffset == 0) {
            load_model_animator_tree(indexMasked, tree);
            return;
        }

        gAnimTreeRoot = tree;
        animator->staticRoot = tree;
        animator->treeIndexPos = 0;
        animator->savedTreePos = 0;

        for (i = 0; i < ARRAY_COUNT(animator->staticNodes); i++) {
            animator->staticNodes[i] = NULL;
        }

        load_mesh_animator_node(*gAnimTreeRoot, animator, 0, nodeIDs);
        animator->flags |= MODEL_ANIMATOR_FLAGS_MESH;
    }
}

void reload_mesh_animator_node(StaticAnimatorNode* node, ModelAnimator* animator, s32 parentNodeID, s32* treeIndexToNodeIDs) {
    AnimatorNodeBlueprint bp;
    AnimatorNodeBlueprint* bpPtr = &bp;
    AnimatorNode* newNode;
    s32 i;

    if (node != NULL) {
        bpPtr->displayList = node->displayList;
        bpPtr->basePos.x = 0.0f;
        bpPtr->basePos.y = 0.0f;
        bpPtr->basePos.z = 0.0f;
        bpPtr->rotation.x = ((f32) node->rot.x * 180.0) / 32767.0;
        bpPtr->rotation.y = ((f32) node->rot.y * 180.0) / 32767.0;
        bpPtr->rotation.z = ((f32) node->rot.z * 180.0) / 32767.0;

        newNode = add_anim_node(animator, parentNodeID, bpPtr);
        newNode->vertexStartOffset = node->vertexStartOffset;
        newNode->fcData.vtxList = node->vtxList;

        i = 0;
        while (gAnimTreeRoot[i] != node) {
            i++;
        }

        treeIndexToNodeIDs[i] = newNode->uniqueIndex;

        if (node->child != NULL) {
            reload_mesh_animator_node(node->child, animator, newNode->uniqueIndex, treeIndexToNodeIDs);
        }
    }
}

void reload_mesh_animator_tree(ModelAnimator* animator) {
    s32 nodeIDs[ARRAY_COUNT(animator->staticNodeIDs)];
    s32 i;

    delete_model_animator_nodes(animator);
    gAnimTreeRoot = animator->staticRoot;

    for (i = 0; i < ARRAY_COUNT(animator->staticNodes); i++) {
        nodeIDs[i] = 0;
    }

    reload_mesh_animator_node(animator->staticNodes[animator->treeIndexPos], animator, 0, nodeIDs);
    nodeIDs[0] = -1;
    set_animator_tree_to_node_map(animator, nodeIDs, ARRAY_COUNT(nodeIDs));
}

s32 step_mesh_animator(ModelAnimator* animator) {
    s16* args = animator->animReadPos;
    s16* oldPos = animator->animReadPos;
    AnimatorNode* node;
    f32 x, y, z;
    s32 flags;
    s32 nodeId;

    switch (*args++) {
        case AS_END:
            return -1;
        case AS_SET_RENDER_MODE:
            animator->renderMode = *args++;
            animator->animReadPos = args;
            return 1;
        case AS_WAIT:
            args++;
            animator->animReadPos = args;
            return 1;
        case AS_END_LOOP:
            animator->animReadPos = animator->savedReadPos;
            animator->treeIndexPos = animator->savedTreePos;
            reload_mesh_animator_tree(animator);
            return 1;
        case AS_OP_4:
            animator->animReadPos = animator->savedReadPos;
            animator->treeIndexPos = animator->savedTreePos;
            break;
        case AS_LOOP:
            animator->animReadPos = animator->savedReadPos = args;
            animator->savedTreePos = animator->treeIndexPos;
            return 1;
        case AS_SET_FLAGS:
            flags = *args++;
            animator->animReadPos = args;
            animator->flags |= flags & 0xFFFF;
            return 1;
        case AS_SET_NODE_FLAGS:
            node = get_animator_child_with_id(animator->rootNode, animator->staticNodeIDs[*args++ - 1]);
            flags = *args++;
            node->flags |= flags;
            animator->animReadPos = args;
            return 1;
        case AS_CLEAR_NODE_FLAGS:
            node = get_animator_child_with_id(animator->rootNode, animator->staticNodeIDs[*args++ - 1]);
            flags = *args++;
            node->flags &= ~flags;
            animator->animReadPos = args;
            return 1;
        case AS_OP_19:
            animator->flags |= MODEL_ANIMATOR_FLAGS_NO_FLIP;
            animator->animReadPos = args;
            return 1;
        case AS_SET_ROTATION:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = (f32)*args++ * 180.0 / 32767.0;
            y = (f32)*args++ * 180.0 / 32767.0;
            z = (f32)*args++ * 180.0 / 32767.0;
            animator->animReadPos = args;
            if (nodeId != 0xFF) {
                node = get_animator_child_with_id(animator->rootNode, nodeId);
                if (node != NULL) {
                    node->rotation.x = x;
                    node->rotation.y = y;
                    node->rotation.z = z;
                    return 1;
                } else {
                    animator->animReadPos = oldPos;
                    animator->treeIndexPos++;
                    break;
                }
            }
            return 1;
        case AS_ADD_ROTATION:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = (f32)*args++ * 180.0 / 32767.0;
            y = (f32)*args++ * 180.0 / 32767.0;
            z = (f32)*args++ * 180.0 / 32767.0;
            animator->animReadPos = args;
            if (nodeId != 0xFF) {
                node = get_animator_child_with_id(animator->rootNode, nodeId);
                if (node != NULL) {
                    node->rotation.x += x;
                    node->rotation.y += y;
                    node->rotation.z += z;
                    return 1;
                } else {
                    animator->animReadPos = oldPos;
                    animator->treeIndexPos++;
                    break;
                }
            }
            return 1;
        case AS_SET_POS:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = *args++;
            y = *args++;
            z = *args++;
            animator->animReadPos = args;
            if (nodeId != 0xFF) {
                node = get_animator_child_with_id(animator->rootNode, nodeId);
                if (node != NULL) {
                    node->pos.x = x;
                    node->pos.y = y;
                    node->pos.z = z;
                    return 1;
                } else {
                    animator->animReadPos = oldPos;
                    animator->treeIndexPos++;
                    break;
                }
            }
            return 1;
        case AS_SET_SCALE:
            nodeId = animator->staticNodeIDs[*args++ - 1];
            x = (f32)*args++ * 180.0 / 32767.0;
            y = (f32)*args++ * 180.0 / 32767.0;
            z = (f32)*args++ * 180.0 / 32767.0;
            animator->animReadPos = args;
            if (nodeId != 0xFF) {
                node = get_animator_child_with_id(animator->rootNode, nodeId);
                if (node != NULL) {
                    node->scale.x = x;
                    node->scale.y = y;
                    node->scale.z = z;
                    return 1;
                } else {
                    animator->animReadPos = oldPos;
                    animator->treeIndexPos++;
                    break;
                }
            }
            return 1;
    }
    return 0;
}
