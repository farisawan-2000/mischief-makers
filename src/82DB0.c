#include <actor.h>
#include <data_symbols.h>
#include <function_symbols.h>
#include <inttypes.h>
#include <ultra64.h>


#ifdef NON_MATCHING
void func_800821B0(void) {
    s32 sp28[2];
    s32 temp_t1;
    u16 temp_v0;
    s32 phi_a0;

    if ((((gActors->flag & 1) != 0) || (D_800BE714 != 0)) && (temp_v0 = gActors->unk_0x84, ((temp_v0 & 0xF800) == 0x5800))) {
        D_800BE714 = 0;
        temp_t1 = ((s32)(temp_v0 & 0x7FF) % 0x322) & 0xFFFF;
        phi_a0 = 0x1004A0918;

        if (temp_t1 != 0) {
            phi_a0 = 0x5095C98 + (temp_t1 * 4) + 0xFAFFFFFC + 0x40AC80;
        }

        func_800011F0(phi_a0, sp28, 8U);
        func_80001290(sp28[0] + 0xFB000000 + 0x40AC80, 0x801C4400U, sp28[1] - sp28[0]);
        D_80178460 = 1;
        return;
    }
    D_80178460 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/82DB0/func_800821B0.s")
#endif

#ifdef NON_MATCHING
// regalloc, missing instructions, temp for D_800BE6A4 & 0x7FFF is early
void func_800822B8(void) {
    uint16_t phi_v0;

    if (D_80178460 != 0) {
        func_80001264();

        if (((D_800BE6A4 & 0x7FFF) + gCurrentFramebufferIndex) != 0) {
            if (((D_800BE6A4 & 0x7FFF) + gCurrentFramebufferIndex) != 1) {
                phi_v0 = D_800BE6A4 & 0x7FFF;
            }
            else {
                func_80098B50(0x801C4400, 0x8027BEE8, 0x1000);
                phi_v0 = D_800BE6A4 & 0x7FFF;
            }
        }
        else {
            func_80098B50(0x801C4400, 0x8027AEE8, 0x1000);
            if (!D_800BE6A4) {
            }

            phi_v0 = D_800BE6A4 & 0x7FFF;
        }

        D_800BE6A4 = phi_v0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/82DB0/func_800822B8.s")
#endif
