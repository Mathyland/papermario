#include "dead.h"
#include "common.h"

// Copy of flo_07 (CAC1F0.c)

#define NAMESPACE EC71B0

#include "world/common/atomic/TexturePan.inc.c"

#include "world/common/SpawnSunEffect.inc.c"

ApiStatus func_80240344_EC74F4(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = fx_misc_particles(3, -272.0f, 80.0f, 20.0f, 200.0f, 120.0f, 4.0f, 8, 0);

    ((MiscParticlesFXData*)effect->data)->unk_38 = 240;
    ((MiscParticlesFXData*)effect->data)->unk_3C = 240;
    ((MiscParticlesFXData*)effect->data)->unk_40 = 240;
    ((MiscParticlesFXData*)effect->data)->unk_48 = 230;
    ((MiscParticlesFXData*)effect->data)->unk_4C = 230;
    ((MiscParticlesFXData*)effect->data)->unk_50 = 240;
    return ApiStatus_DONE2;
}
