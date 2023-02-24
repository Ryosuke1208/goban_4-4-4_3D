//************************************************
// プレイヤーが手を置く際の処理
//************************************************
#include "define.h"

void makeFigure(int[][FIGURE_NUM][FIGURE_NUM]);
boolean playerCanPut(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
void fill(int, int, int, int);

void playerPutProc(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum) {
    int ClickX, ClickY, Button, LogType;
    int x = -1, y = -1, z = -1;
    while (1) {
        ClearDrawScreen();
        // 図形の作成と描画
        makeFigure(puzzle);
        if (playerCanPut(puzzle, &x, &y, &z)) { // そもそも置ける箇所かどうか確認する
            fill(x, y, z, playerNum);
        }

        // マウスのボタンが押されたり離されたりしたかどうかの情報を取得する
        if (!GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE)) {

            if ((Button & MOUSE_INPUT_LEFT))
            {
                // 左クリックが押されていて、離れた瞬間に情報を確定する
                if (LogType == MOUSE_INPUT_LOG_UP) {
                    if (x >= 0 && x <= 3 && y >= 0 && y <= 3 && z >= 0 && z <= 3) {
                        puzzle[x][y][z] = playerNum;
                        if (x > 0) puzzle[x - 1][y][z] = OK;
                        break;
                    }
                    else {
                        continue;
                    }
                }
            }
        }

        ScreenFlip();
    }
}