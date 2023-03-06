//************************************************
// 終了した状態を表示する
//************************************************
#include "define.h"

void showBingoLine(int[][FIGURE_NUM][FIGURE_NUM], int, int, int, struct BINGO);

int showFinishedStatus(int puzzle[][FIGURE_NUM][FIGURE_NUM], int d, int m, int pNum, struct BINGO b) {
    int flag;
    while (1) {
        ClearDrawScreen();
        showBingoLine(puzzle, d, m, pNum, b);
        SetFontSize(80);
        DrawString(450, 680, "FINISHED", BLACK);
        SetFontSize(40);
        DrawString(450, 750, "press enter", BLACK);
        if (m == 1) {// VS CPUの時は手を戻せるようにしている
            if (CheckHitKey(KEY_INPUT_BACK)) {
                flag = 1;
                break;
            }
            else if (CheckHitKey(KEY_INPUT_RETURN)) {
                return 0;
            }
        }
        else {// VSプレイヤーはそのままおわり
            if (CheckHitKey(KEY_INPUT_RETURN)) {
                return 0;
            }
        }
        ScreenFlip();
    }
    return flag;
}