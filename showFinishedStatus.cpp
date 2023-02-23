//************************************************
// 終了した状態を3秒間表示する
//************************************************
#include "define.h"

void makeFigure(int[][FIGURE_NUM][FIGURE_NUM]);

void showFinishedStatus(int puzzle[][FIGURE_NUM][FIGURE_NUM]) {
    ClearDrawScreen();
    makeFigure(puzzle);
    SetFontSize(80);
    DrawString(10, 10, "FINISHED", BLACK);
    ScreenFlip();
    WaitTimer(3000);
}