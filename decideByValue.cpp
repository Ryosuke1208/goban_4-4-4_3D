//************************************************
// 深さの探索で見つからなかったときに評価値で
// 決定する
//************************************************
#include "define.h"

boolean decideByValue(int puzzle[][FIGURE_NUM][FIGURE_NUM], int* x, int* y, int* z) {
    int i, j, k;
    int cnt;
    //各マスの評価値 単純にそこに置いた時のビンゴになり得る数を基にしている
    int value[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}}
    };
    //クロスアタック対策
    if (puzzle[3][1][1] == OK) {
        cnt = 0;
        if (puzzle[3][0][1] == P1) cnt++;
        if (puzzle[3][1][0] == P1) cnt++;
        if (puzzle[3][1][3] == P1) cnt++;
        if (puzzle[3][3][1] == P1) cnt++;
        if (cnt >= 2) {
            *x = 3;
            *y = 1;
            *z = 1;
            return true;
        }
    }
    if (puzzle[3][2][2] == OK) {
        cnt = 0;
        if (puzzle[3][0][2] == P1) cnt++;
        if (puzzle[3][2][0] == P1) cnt++;
        if (puzzle[3][2][3] == P1) cnt++;
        if (puzzle[3][3][2] == P1) cnt++;
        if (cnt >= 2) {
            *x = 3;
            *y = 2;
            *z = 2;
            return true;
        }
    }
    // 評価値の高い手が見つかった時はそこを返す
    for (i = 3; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == OK) {
                    if (value[i][j][k] == 7) {
                        *x = i;
                        *y = j;
                        *z = k;
                        return true;
                    }
                }
            }
        }
    }
    // 評価値の高い手が見つからなかった時はとりあえず空いてるとこを返す
    for (i = 3; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == OK) {
                    *x = i;
                    *y = j;
                    *z = k;
                    return true;
                }
            }
        }
    }
    return false; //置ける場所がなかった時
}