#include <actor.h>
#include <data_symbols.h>
#include <function_symbols.h>
#include <inttypes.h>
#include <ultra64.h>

void func_8001DBA0(uint16_t* arg0, uint16_t index) {
    gActors[index].unk_0xD2 = arg0[5];
    Actor_Spawn(index);
    gActors[index].pos.x = arg0[1] - D_800BE558;
    gActors[index].pos.y = arg0[2] - D_800BE55C;
    gActors[index].unk_0x110 = arg0[3];
    gActors[index].unk_0xD8 = arg0[4];
}

#pragma GLOBAL_ASM("asm/nonmatchings/1E7A0/func_8001DC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1E7A0/func_8001DE30.s")

#ifdef NON_MATCHING
// https://decomp.me/scratch/QZfDW
void Actor_Spawn(uint16_t index) {
    float phi_a0 = 0;

    /* needs work:
     * Reproduce argument spilling
     * Float instructions should be below this ifelse block
     * flag and unk_0xE8 rvalues may be loaded incorrectly
     */
    if (gActors[index].unk_0xD2 < 0x100) {
        // actorInit = (((unk_0xD2 * 7) & 0xFFFF) * 2) + &gActorInit;
        gActors[index].unk_0xA2 = -gActorInit[gActors[index].unk_0xD2].unk_0x0;
        gActors[index].unk_0xA8 = -gActorInit[gActors[index].unk_0xD2].unk_0x2;
        gActors[index].unk_0xAA = -gActorInit[gActors[index].unk_0xD2].unk_0x4;
        gActors[index].unk_0xB0 = -gActorInit[gActors[index].unk_0xD2].unk_0x6;

        gActors[index].unk_0xA4 = gActorInit[gActors[index].unk_0xD2].unk_0x0;
        gActors[index].unk_0xA6 = gActorInit[gActors[index].unk_0xD2].unk_0x2;
        gActors[index].unk_0xAC = gActorInit[gActors[index].unk_0xD2].unk_0x4;
        gActors[index].unk_0xAE = gActorInit[gActors[index].unk_0xD2].unk_0x6;

        gActors[index].health = gActorInit[gActors[index].unk_0xD2].health;
        gActors[index].unk_0xE4 = gActorInit[gActors[index].unk_0xD2].unk_0xA;
        gActors[index].flag = gActorInitFlags[gActors[index].unk_0xD2]; // ((gActors[index].unk_0xD2 * 4) + 0x800D0000)->unk - 0x6228;
        gActors[index].unk_0xE8 = D_800C9FCC[gActors[index].unk_0xD2];
    }
    else {
        // OK
        gActors[index].unk_0xA2 = -0x10;
        gActors[index].unk_0xA4 = 0x10;
        gActors[index].unk_0xA6 = 0x10;
        gActors[index].unk_0xA8 = -0x10;
        gActors[index].unk_0xAA = -0x10;
        gActors[index].unk_0xAC = 0x10;
        gActors[index].unk_0xAE = 0x10;
        gActors[index].unk_0xB0 = -0x10;
        gActors[index].health = 10;
        gActors[index].unk_0xE4 = 10;
        gActors[index].flag = ACTOR_FLAG_ACTIVE | ACTOR_FLAG_DRAW;
        gActors[index].unk_0xE8 = (uint32_t)&D_800E1380;
    }

    gActors[index].unk_0xB4 = 1;
    gActors[index].unk_0xB8 = 1;

    // OK (except regalloc)
    gActors[index].unk_0x14C = 0;
    gActors[index].unk_0x148 = 0;
    gActors[index].unk_0x144 = 0;
    gActors[index].unk_0x140_f = 0;
    gActors[index].unk_0x13C = 0;
    gActors[index].unk_0x138 = 0;
    gActors[index].unk_0x134 = 0;
    gActors[index].unk_0x130 = 0;
    gActors[index].unk_0x12C_f = 0;
    gActors[index].unk_0x128 = 0;
    gActors[index].unk_0x124 = 0;
    gActors[index].unk_0x120 = 0;
    gActors[index].unk_0x11C = 0;
    gActors[index].unk_0x118 = 0;
    gActors[index].unk_0x114 = 0;
    gActors[index].unk_0x110 = 0;

    // weird float stuff?
    gActors[index].rgba.a = 0xFF;
    gActors[index].unk_0xE6 = 1;
    gActors[index].unk_0xDE = 1;
    gActors[index].unk_0xC4 = 0;
    gActors[index].unk_0xC0 = 0;
    gActors[index].unk_0xBC = 0;
    gActors[index].unk_0xD6 = (int8_t)0;
    gActors[index].unk_0xD4 = (int8_t)0;
    gActors[index].unk_0xD0_h = (int8_t)0;
    gActors[index].unk_0xCE = (int8_t)0;
    gActors[index].unk_0xCC = (int8_t)0;
    gActors[index].unk_0xCA = (int8_t)0;
    gActors[index].unk_0xC8 = (int8_t)0;

    // OK
    gActors[index].unk_0x190 = 0;
    gActors[index].unk_0x18C = 0;
    gActors[index].unk_0x188 = 0;
    gActors[index].unk_0x184_w = 0;
    gActors[index].unk_0x180_w = 0;
    gActors[index].unk_0x17C = 0;
    gActors[index].unk_0x178 = 0;
    gActors[index].unk_0x174 = 0;
    gActors[index].unk_0x170_w = 0;
    gActors[index].unk_0x16C = 0;
    gActors[index].unk_0x168 = 0;
    gActors[index].unk_0x164 = 0;
    gActors[index].unk_0x160 = 0;
    gActors[index].unk_0x15C = 0;
    gActors[index].unk_0x158 = 0;
    gActors[index].unk_0x154 = 0;
    gActors[index].unk_0x150 = 0;
    gActors[index].unk_0x10C = 0;
    gActors[index].unk_0x108 = 0;
    gActors[index].unk_0x104 = 0;
    gActors[index].unk_0x100 = 0;
    gActors[index].unk_0xFC = 0;
    gActors[index].unk_0xF8 = 0;
    gActors[index].unk_0xF4 = 0;
    gActors[index].unk_0xF0 = 0;
    gActors[index].unk_0xEC = 0;
    gActors[index].unk_0xE2 = 0;
    gActors[index].unk_0xDF = 0;
    gActors[index].unk_0xDD = 0;
    gActors[index].unk_0xDC = 0;
    gActors[index].unk_0xDB = 0;
    gActors[index].unk_0xDA = 0;

    // something produces a float to u32 here

    gActors[index].unk_0x98 = phi_a0;
    gActors[index].unk_0x94 = phi_a0;
    gActors[index].pos.z_w = phi_a0;
    gActors[index].pos.y_1 = phi_a0;
    gActors[index].pos.x_1 = phi_a0;
    gActors[index].unk_0x84 = phi_a0;
    gActors[index].unk_0xA0 = phi_a0;
    gActors[index].rgba.b = phi_a0;
    gActors[index].rgba.g = phi_a0;
    gActors[index].rgba.r = phi_a0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/1E7A0/Actor_Spawn.s")
#endif
