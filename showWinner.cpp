//************************************************
// 勝者の表示
//************************************************
#include "define.h"

void showWinPvP(int playerNum) {
    WaitTimer(1000);// 前のエンター入力と同時に読み取る可能性があるので少し止める
    unsigned int Cr;
    ClearDrawScreen();
    SetFontSize(100);
    if (playerNum == P1) {
        Cr = LIGHT_RED;
        DrawString(103, 300, "PLAYER1　WIN", Cr);
    }
    else {
        Cr = LIGHT_BLUE;
        DrawString(103, 300, "PLAYER2 WIN", Cr);
    }
    SetFontSize(50);
    DrawString(260, 500, "press enter", Cr);
    ScreenFlip();
    while (1) {
        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }
}

void showWinPvC(int playerNum) {
    WaitTimer(1000);// 前のエンター入力と同時に読み取る可能性があるので少し止める
    unsigned int Cr;
    ClearDrawScreen();
    SetFontSize(100);
    if (playerNum == P1) {
        Cr = LIGHT_RED;
        DrawString(103, 300, "PLAYER1　WIN", Cr);
    }
    else {
        Cr = LIGHT_BLUE;
        DrawString(103, 300, "  CPU  WIN  ", Cr);
    }
    SetFontSize(50);
    DrawString(260, 500, "press enter", Cr);
    ScreenFlip();
    while (1) {
        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }
}

void showDraw() {
    WaitTimer(1000);// 前のエンター入力と同時に読み取る可能性があるので少し止める
    ClearDrawScreen();
    SetFontSize(100);
    DrawString(103, 300, "    DRAW    ", BLACK);
    SetFontSize(50);
    DrawString(260, 500, "press enter", BLACK);
    ScreenFlip();
    while (1) {
        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }
}