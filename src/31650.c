#include "common.h"
#include "audio.h"
#include "nu/nualsgi.h"

UnkAl0* D_80078E50 = NULL;
UnkAl0* D_80078E54 = NULL;
s8 D_80078E58 = 0;
s16 D_80078E5A = 0x7FFF;
s8 D_80078E5C = 0;
s32 D_80078E60[] = { 0x7FFF7FFC, 0x7FF57FE8, 0x7FD77FC0, 0x7FA57F84, 0x7F5F7F34, 0x7F057ED0, 0x7E977E58, 0x7E157DCD,
                     0x7D7F7D2D, 0x7CD67C7A, 0x7C1A7BB4, 0x7B497ADA, 0x7A6679ED, 0x796F78ED, 0x786677DA, 0x774976B4, 0x761A757B,
                     0x74D87430, 0x738472D3, 0x721E7164, 0x70A66FE3, 0x6F1C6E51, 0x6D816CAD, 0x6BD56AF9, 0x6A186933, 0x684A675D,
                     0x666C6577, 0x647E6381, 0x6280617C, 0x60735F67, 0x5E575D43, 0x5C2C5B11,
                   };


void func_80056250(UnkAl0* globals, ALConfig* config) {
    s32 i;
    ALHeap* heap = config->heap;

    if (D_80078E50 != NULL) {
        return;
    }

    globals->unk_0C = config->unk_00;
    globals->unk_10 = config->unk_04;
    globals->unk_00 = 0;
    globals->unk_04 = 0;
    globals->frequency = config->frequency;
    globals->dmaNew = config->dmaNew;

    D_80078E50 = globals;
    D_80078E54 = globals;
    D_80078E58 = 0;
    D_80078E5A = 0x7FFF;
    D_80078E5C = 1;
    D_80078E54->unk_1C = alHeapAlloc(heap, config->unk_00, sizeof(UnkAl7C));

    for (i = 0; i < config->unk_00; i++) {
        UnkAl7C* al7C = &D_80078E54->unk_1C[i];
        al7C->unk_04 = alHeapAlloc(heap, 1, 0x20);
        al7C->unk_08 = alHeapAlloc(heap, 1, 0x20);
        al7C->dmaProc = ((ALDMAproc (*)(NUDMAState**))(D_80078E54->dmaNew))(&al7C->dmaState);
        al7C->unk_2C = 0;
        al7C->unk_30 = 1;
        al7C->unk_34 = 0;
        al7C->unk_38 = alHeapAlloc(heap, 1, 0x20);
        al7C->unk_40 = 0;
        al7C->unk_44 = 1;
        al7C->unk_3C = 1.0f;
        al7C->unk_48 = alHeapAlloc(heap, 1, 0x50);
        al7C->unk_6C = 1;
        al7C->unk_70 = 0;
        al7C->unk_4E = 1;
        al7C->unk_5C = 1;
        al7C->unk_62 = 1;
        al7C->unk_50 = 1;
        al7C->unk_52 = 1;
        al7C->unk_54 = 0;
        al7C->unk_56 = 0;
        al7C->unk_5A = 1;
        al7C->unk_58 = 0;
        al7C->unk_60 = 1;
        al7C->unk_5E = 0;
        al7C->unk_64 = 0;
        al7C->unk_68 = 0;
        al7C->unk_4C = 64;
        al7C->unk_74 = 0;
        al7C->unk_00 = 0;
        al7C->unk_78 = 0;
        al7C->unk_79 = i;
    }
    D_80078E54->unk_20 = alHeapAlloc(heap, config->unk_04, sizeof(UnkLen18));
    for (i = 0; i < config->unk_04; i++) {
        UnkLen18* temp = &D_80078E54->unk_20[i];
        temp->unk_10 = 0;
        temp->unk_14 = 0;
        temp->unk_00 = 0x7FFF;
        temp->unk_0C = 0;
        temp->unk_04 = alHeapAlloc(heap, 1, 0x14);
        temp->unk_08 = alHeapAlloc(heap, 1, 0x14);
        func_80058E84(temp->unk_04, temp->unk_0C, heap);
        func_80058E84(temp->unk_08, temp->unk_0C, heap);
    }


    D_80078E54->unk_24 = alHeapAlloc(heap, 0x170, 2);
    D_80078E54->unk_28 = alHeapAlloc(heap, 0x170, 2);
    D_800A3FEC = 0;
    D_800A3FEE = 0;
    D_800A3FF0 = 4;

    D_800A3FE0 = alHeapAlloc(heap, 0x2E0, 2);
    D_800A3FE4 = alHeapAlloc(heap, 0x2E0, 2);
    for (i = 0; i < 0x2E0; i++) {
        D_800A3FE4[i] = D_800A3FE0[i] = 0;
    }

    D_80078E54->heap = heap;
}

void func_800565A4(void) {
    if (D_80078E50 != NULL) {
        D_80078E50 = NULL;
    }
}

INCLUDE_ASM(Acmd*, "31650", alAudioFrame, Acmd* cmdList, s32* cmdLen, s16* outBuf, s32 outLen);

void func_80056D34(void) {
    D_80078E58 = 1;
}

void func_80056D44(s16 arg0) {
    D_80078E5A = arg0;
}

s16 func_80056D50(void) {
    return D_80078E5A;
}

#ifdef NON_MATCHING
void func_80056D5C(s8 arg0) {
    D_80078181 = arg0;
    D_80078E5C = 1;
}
#else
INCLUDE_ASM(s32, "31650", func_80056D5C);
#endif

void func_80056D78(u8 arg0, u16 arg1) {
    UnkLen18* temp = &D_80078E54->unk_20[arg0];

    temp->unk_00 = arg1 & 0x7FFF;
}

u16 func_80056DA4(u8 arg0, u16 arg1) {
    UnkLen18* temp = &D_80078E54->unk_20[arg0];

    return temp->unk_00;
}

void func_80056DCC(u8 arg0, u8 arg1) {
    UnkLen18* temp = &D_80078E54->unk_20[arg0];

    temp->unk_0C = arg1;
    func_8005904C(temp->unk_04, arg1);
    func_8005904C(temp->unk_08, arg1);
}

INCLUDE_ASM(s32, "31650", func_80056E34);

void func_80056EC0(u8 arg0, s8 arg1) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    al7C->unk_78 = arg1;
}

INCLUDE_ASM(void, "31650", func_80056EE8, u8 arg0);

void func_80056F78(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    al7C->unk_70 = 1;
}

INCLUDE_ASM(void, "31650", func_80056FA4, u8 arg0, u8 arg1, s32 arg2, f32 arg3, s16 arg4, u8 arg5, u8 arg6,
            s32 arg7);

INCLUDE_ASM(void, "31650", func_80057224, u8 arg0, Instrument* arg1);

void func_80057344(u8 arg0, f32 arg1) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    al7C->unk_3C = arg1;
}

INCLUDE_ASM(void, "31650", func_8005736C, u8 arg0, s16 arg1, s32 arg2, u8 arg3, u8 arg4);

INCLUDE_ASM(void, "31650", func_80057548, u8 arg0, u8 arg1, u8 arg2);

INCLUDE_ASM(void, "31650", func_800576EC, u8 arg0, s32 arg1, s32 arg2);

INCLUDE_ASM(s32, "31650", func_80057874);

INCLUDE_ASM(s32, "31650", func_800579D8);

s32 func_80057B64(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_70;
}

s32 func_80057B8C(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_78;
}

f32 func_80057BB4(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_3C;
}

u8 func_80057BDC(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_4C_s.unk_4D;
}

s16 func_80057C04(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_54;
}

s16 func_80057C2C(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_56;
}

INCLUDE_ASM(s32, "31650", func_80057C54);

INCLUDE_ASM(s32, "31650", func_80057D0C);

void func_80057DC8(s32 arg0) {
    if (arg0 < 2) {
        D_800A3FF0 = 0;
        D_800A3FEE = 0;
    }

    D_800A3FF0 = arg0;
    if (arg0 >= 5) {
        D_800A3FF0 = 4;
    }
}

void func_80057E08(u8 arg0) {
    s32* phi_a1 = (s32*)D_800A3FE0;
    s32* phi_v1 = (s32*)D_800A3FE4;
    s32 i;

    for (i = 0; i < 0x170; i++) {
        *phi_a1++ = 0;
        *phi_v1++ = 0;
    }

    D_800A3FEC = arg0;
    D_800A3FEE = 1;
    D_800A3FE8 = 0;
}

void func_80057E5C(u8 arg0) {
    s32* phi_a1 = (s32*)D_800A3FE0;
    s32* phi_v1 = (s32*)D_800A3FE4;
    s32 i;

    for (i = 0; i < 0x170; i++) {
        *phi_a1++ = 0;
        *phi_v1++ = 0;
    }

    D_800A3FEC = arg0;
    D_800A3FEE = 2;
    D_800A3FE8 = 0;
}

void func_80057EB0(void) {
    D_800A3FEC = 0;
    D_800A3FEE = 0;
    D_800A3FE8 = 0;
}

void func_80057ED0(s16 arg0) {
    s32* phi_a1 = (s32*)D_800A3FE0;
    s32* phi_v1 = (s32*)D_800A3FE4;
    s32 i;

    for (i = 0; i < 0x170; i++) {
        *phi_a1++ = 0;
        *phi_v1++ = 0;
    }

    D_800A3FEC = 0;
    D_800A3FEE = arg0;
    D_800A3FE8 = 0;
}

void alHeapInit(ALHeap* hp, u8* base, s32 len) {
    u32 i;
    s32 alignBytes = 0x10 - ((s32)base & 0xF);

    if (alignBytes != 0x10) {
        hp->base = base + alignBytes;
    } else {
        hp->base = base;
    }
    hp->len = len;
    hp->count = 0;
    hp->cur = hp->base;

    for (i = 0; i < (u32)(hp->len) >> 2; i++) {
        ((u32*)hp->base)[i] = 0;
    }
}

void* alHeapAlloc(ALHeap* heap, s32 arg1, s32 size) {
    void* ret = NULL;
    u8* newCur = &heap->cur[ALIGN16(arg1 * size)];

    if (&heap->base[heap->len] >= newCur) {
        ret = heap->cur;
        heap->cur = newCur;
    }

    return ret;
}

void alCopy(void* src, void* dst, s32 size) {
    s32 i;
    u8* srcIt = src;
    u8* dstIt = dst;

    for (i = 0; i < size; i++) {
        *dstIt++ = *srcIt++;
    }
}

INCLUDE_ASM(s32, "31650", func_80058004);
