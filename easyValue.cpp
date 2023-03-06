//************************************************
// CPUの強さ「弱い」の評価関数
// ダブルアタックをすれば簡単に勝てる
//************************************************
#include "define.h"

int isReach(int[][FIGURE_NUM][FIGURE_NUM], int);

boolean easyValue(int puzzle[][FIGURE_NUM][FIGURE_NUM], int* x, int* y, int* z) {
    int i, j, k;
    int max = -999;
    int flag = 0;
    //各マスの評価値 単純にそこに置いた時のビンゴになり得る数を基にしている
    int value[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}},
        {{2,15,15,2},{15,10,10,15},{15,10,10,15},{2,15,15,2}},
        {{4,15,15,4},{15,4,4,15},{15,4,4,15},{4,15,15,4}},
        {{10,4,4,10},{4,2,2,4},{4,2,2,4},{10,4,4,10}}
    };

    for (i = 3; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == OK) {
                    puzzle[i][j][k] = P2;
                    if (i > 0)puzzle[i - 1][j][k] = OK;
                    if (isReach(puzzle, P1) == 0) {
                        if (value[i][j][k] > max) {
                            max = value[i][j][k];
                            *x = i;
                            *y = j;
                            *z = k;
                            flag = 1;
                        }
                    }
                    puzzle[i][j][k] = OK;
                    if (i > 0)puzzle[i - 1][j][k] = NG;
                }
            }
        }
    }
    // 抜け防止のための処理
    // flagが0のまま、つまり上の処理で決まっていない時
    if (flag == 0) {
        for (i = 3; i >= 0; i--) {
            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    if (puzzle[i][j][k] == OK) {
                        *x = i;
                        *y = j;
                        *z = k;
                    }
                }
            }
        }
    }
    return true;
}