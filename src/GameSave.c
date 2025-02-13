#include "GameSave.h"
#include <data_symbols.h>
#include <function_symbols.h>
#include <ultra64.h>

uint16_t gGameSave_Names[2][11];
uint8_t gGameSave_Age[2];
uint8_t gGameSave_Sex[2];
uint16_t gGameSave_RedGems[2];
uint16_t gGameSave_YellowGems[2];
uint64_t D_80171AD8[2]; // contains total play time
uint32_t gFestivalRecords[7];

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80004E70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80004E90.s")

int32_t IsOver999(uint32_t x) { //{Vegeta Joke}
    if (999 < x) return 1;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80004F24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/GameSave_Initialize.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/GameSave_SetDefaults.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/GameSave_CheckAndWipe.s")

void GameSave_LoadRecords(void) {
    uint16_t index;

    osEepromProbe(&D_8012ADA0);
    if (gSaveSlotIndex) {
        osEepromLongRead(&D_8012ADA0, 0x24, &gFestivalRecords, 0x32);
        osEepromLongRead(&D_8012ADA0, 0x2C, &gTimeRecords, 0x80);
    }
    else {
        osEepromLongRead(&D_8012ADA0, 0xC, &gFestivalRecords, 0x32);
        osEepromLongRead(&D_8012ADA0, 0x14, &gTimeRecords, 0x80);
    }
    if (D_80171B19 >= 2) {
        D_80171B19 = 0;
    }

    func_80004F24();

    for (index = 0; index < 64; index++) {
        if (gTimeRecords[index] > 36000) {
            gTimeRecords[index] = 36000;
        }
    }
}

void func_80005770(void) {
    osEepromProbe(&D_8012ADA0);
    osEepromLongWrite(&D_8012ADA0, 2, gGameSave_Names, 0x48);

    if (gSaveSlotIndex) {
        osEepromLongWrite(&D_8012ADA0, 0x24, &gFestivalRecords, 0x32);
        osEepromLongWrite(&D_8012ADA0, 0x2C, &gTimeRecords, 0x80);
    }
    else {
        osEepromLongWrite(&D_8012ADA0, 0xC, &gFestivalRecords, 0x32);
        osEepromLongWrite(&D_8012ADA0, 0x14, &gTimeRecords, 0x80);
    }
}

void GameSave_Erase(void) {
    GameSave_Initialize(gSaveSlotIndex);
    GameSave_SetDefaults();
    func_80005770();
}

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80005860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_800058E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_800059A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80005B68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80005C3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_8000607C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80006360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80006B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80006B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80006CC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80006DF4.s")

#ifdef NON_MATCHING
void func_80006E60(void) {
    gCurrentStage = (uint8_t)gWorldProgress;
    D_800BE5D0 = D_800C8378[gWorldProgress];
    D_800D28E4 = D_800C83F8[gWorldProgress];
    func_80043918();
    D_800CBF40 = 1;
    gGameState = GAMESTATE_TRANSITION;
    gGameSubState = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80006E60.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80006EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_800072A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_800073CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80007578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_800075A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/NameEntry_PrintKeyboard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/NameEntry_Setup.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/NameEntry_IsMaxed.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80007ABC.s")

#ifdef NON_MATCHING
// compiler refuses to recognize symbols
void NameEntry_EnterChar(uint16_t* lang1, uint16_t* lang2, uint16_t* Eng) {
    if (gNameEntryCurrentChar < 10) {
        if (gNameEntryLanguage == 0) gNameEntrySpace[gNameEntryCurrentChar] = lang1[gNameEntrySelectedColumn];
        else if (gNameEntryLanguage == 1)
            gNameEntrySpace[gNameEntryCurrentChar] = lang2[gNameEntrySelectedColumn];
        else if (gNameEntryLanguage == 2)
            gNameEntrySpace[gNameEntryCurrentChar] = Eng[gNameEntrySelectedColumn];
        SFX_Play_1(0x23);
        SFX_Play_1(0x10d);
        func_80007ABC();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/NameEntry_EnterChar.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80007C8C.s")
