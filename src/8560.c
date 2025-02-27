#include "common.h"
#include "nu/nusys.h"
#include "ld_addrs.h"
#include "mips.h"

extern s8 D_F79DDD0F[];
extern s8 D_7599F6D8[];

void func_8002D160(void) {
    s32 (*readFunc)(OSPiHandle*, u32, u32*);
    s32 (*readFunc2)(OSPiHandle*, u32, u32*);
    s8* vramDest = D_7599F6D8;
    s8* romStart = D_F79DDD0F;
    s32 seed;
    u32 hash;
    u32 thisInsn;
    u32 thisInsn2;
    u32 prevInsn;
    u8* it;

    // vramDest
    readFunc = osEPiReadIo;
    seed = 0x0B112D28;
    hash = 0;
    readFunc(nuPiCartHandle, 0xB0000D10, &thisInsn);
    seed -= thisInsn;
    prevInsn = 0;

    for (it = _316D90_ROM_START; it < _316D90_ROM_END; it += 4) {
        readFunc(nuPiCartHandle, (u32)it, &thisInsn);
        hash += LOWER(thisInsn) + UPPER(thisInsn);

        if (OPCODE(prevInsn) == LUI && (OPCODE(thisInsn) == ADDIU || OPCODE(thisInsn) == LW)) {
            if (GET_RS(thisInsn) == GET_RT(prevInsn) && GET_RS(thisInsn) == GET_RT(thisInsn)) {
                hash -= LOWER(thisInsn);
                hash -= LOWER(prevInsn);
            }
        }

        if (OPCODE(thisInsn) == JAL) {
            hash -= LOWER(thisInsn) + (UPPER(thisInsn) & 0xFC00);
        }

        prevInsn = thisInsn;
    }
    vramDest += seed + 0x2A4EB6 - hash;

    // romStart
    readFunc2 = osEPiReadIo;
    seed = 0x18F414AB;
    hash = 0;
    readFunc2(nuPiCartHandle, 0xB0000E38, &thisInsn2);
    seed -= thisInsn2;
    prevInsn = 0;

    for (it = _316F30_ROM_START; it < _316F30_ROM_END; it += 4) {
        readFunc2(nuPiCartHandle, (u32)it, &thisInsn2);
        hash += LOWER(thisInsn2) + UPPER(thisInsn2);

        if (OPCODE(prevInsn) == LUI && (OPCODE(thisInsn2) == ADDIU || OPCODE(thisInsn2) == LW)) {
            if (GET_RS(thisInsn2) == GET_RT(prevInsn) && GET_RS(thisInsn2) == GET_RT(thisInsn2)) {
                hash -= LOWER(thisInsn2);
                hash -= LOWER(prevInsn);
            }
        }

        if (OPCODE(thisInsn2) == JAL) {
            hash -= LOWER(thisInsn2) + (UPPER(thisInsn2) & 0xFC00);
        }
        prevInsn = thisInsn2;
    }
    romStart += seed + 0xED41C - hash;

    dma_copy(romStart, _316F30_ROM_END, vramDest);
}
