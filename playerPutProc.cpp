//************************************************
// プレイヤーが手を置く際の処理
//************************************************
#include "define.h"

void makeFigure(int[][FIGURE_NUM][FIGURE_NUM]);
boolean playerCanPut(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
void fill(int, int, int, int);

void playerPutProc(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum) {
    int ClickX, ClickY, Button, LogType;
    int x = 0, y = 0, z = 0;
    while (1) {
        ClearDrawScreen();
        // 図形の作成と描画
        makeFigure(puzzle);
        if (playerCanPut(puzzle, &x, &y, &z)) { // そもそも置ける箇所かどうか確認する
            fill(x, y, z, playerNum);
        }
        // マウスのボタンが押されたり離されたりしたかどうかの情報を取得する
        if (!GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE)) {

            if ((Button & MOUSE_INPUT_LEFT) != 0)
            {
                // 左クリックが押されていて、離れた瞬間に情報を確定する
                if (LogType == MOUSE_INPUT_LOG_UP) {
                    puzzle[x][y][z] = playerNum;
                    if (x > 0) puzzle[x - 1][y][z] = OK;
                    break;
                }
            }
        }
        ScreenFlip();
    }
}