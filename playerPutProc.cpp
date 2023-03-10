//************************************************
// プレイヤーが手を置く際の処理
//************************************************
#include "define.h"

void makeFigure(int[][FIGURE_NUM][FIGURE_NUM], int, int);
boolean playerCanPut(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
void fill(int, int, int, int);

int playerPutProc(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum, int d, int m, int temp[][3]) {
    int ClickX, ClickY, Button, LogType;
    int x = -1, y = -1, z = -1;
    while (1) {
        ClearDrawScreen();
        // 図形の作成と描画
        makeFigure(puzzle, d, m);
        if (playerCanPut(puzzle, &x, &y, &z)) fill(x, y, z, playerNum);// そもそも置ける箇所かどうか確認する
        // マウスのボタンが押されたり離されたりしたかどうかの情報を取得する
        if (!GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE)) {
            if ((Button & MOUSE_INPUT_LEFT))
            {
                // 左クリックが押されていて、離れた瞬間に情報を確定する
                if (LogType == MOUSE_INPUT_LOG_UP) {
                    if (playerCanPut(puzzle, &x, &y, &z)) {
                        puzzle[x][y][z] = playerNum;
                        if (x > 0) puzzle[x - 1][y][z] = OK;
                        temp[0][0] = x;
                        temp[0][1] = y;
                        temp[0][2] = z;
                        return 1;
                    }
                    else {
                        LogType = 0;
                        continue;
                    }
                }
            }
        }
        if (m == 1) {
            if (CheckHitKey(KEY_INPUT_BACK)) {
                return 0;
            }
        }
        ScreenFlip();
    }
}