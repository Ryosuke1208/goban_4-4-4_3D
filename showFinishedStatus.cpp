//************************************************
// èIóπÇµÇΩèÛë‘Ç3ïbä‘ï\é¶Ç∑ÇÈ
//************************************************
#include "define.h"

void makeFigure(int [][FIGURE_NUM][FIGURE_NUM]);

void showFinishedStatus(int puzzle[][FIGURE_NUM][FIGURE_NUM]) {
    ClearDrawScreen();
    makeFigure(puzzle);
    SetFontSize(80);
    DrawString(10, 10, "FINISHED", BLACK);
    SetFontSize(25);
    DrawString(10, 100, "press enter", BLACK);
    ScreenFlip();
    while (1) {
        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }
}