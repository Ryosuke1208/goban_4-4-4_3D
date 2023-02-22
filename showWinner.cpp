//************************************************
//show winner
//************************************************
#include "define.h"

void showWinPvP(int playerNum) {
    unsigned int Cr;
    ClearDrawScreen();
    SetFontSize(100);
    if (playerNum == P1) {
        Cr = LIGHT_RED;
        DrawString(103, 300, "PLAYER1Å@WIN", Cr);
    }
    else {
        Cr = LIGHT_BLUE;
        DrawString(103, 300, "PLAYER2 WIN", Cr);
    }
    SetFontSize(25);
    DrawString(325, 500, "press enter", Cr);
    ScreenFlip();
    while (1) {
        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }
}

void showWinPvC(int playerNum) {
    unsigned int Cr;
    ClearDrawScreen();
    SetFontSize(100);
    if (playerNum == P1) {
        Cr = LIGHT_RED;
        DrawString(103, 300, "PLAYER1Å@WIN", Cr);
    }
    else {
        Cr = LIGHT_BLUE;
        DrawString(103, 300, "  CPU  WIN  ", Cr);
    }
    SetFontSize(25);
    DrawString(325, 500, "press enter", Cr);
    ScreenFlip();
    while (1) {
        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }
}