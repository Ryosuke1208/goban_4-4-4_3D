//************************************************
// 深さの探索で見つからなかったときに評価値で
// 決定する
//************************************************
#include "define.h"

int isReach(int [][FIGURE_NUM][FIGURE_NUM], int);

boolean normalValue(int puzzle[][FIGURE_NUM][FIGURE_NUM], int* x, int* y, int* z) {
    int i, j, k;
    int cnt, cnt2;
    int max = -999;
    int flag = 1;
    //各マスの評価値 単純にそこに置いた時のビンゴになり得る数を基にしている
    int value[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}},
        {{4,4,4,4},{4,10,10,4},{4,10,10,4},{4,4,4,4}},
        {{4,4,4,4},{4,4,4,4},{4,4,4,4},{4,4,4,4}},
        {{7,4,4,7},{4,2,2,4},{4,2,2,4},{7,4,4,7}}
    };
    // 2段目角の評価点の変更
    // 下に自身の手があるときは上に置く
    if (puzzle[3][0][0] == P2) value[2][0][0] += 10;
    if (puzzle[3][0][3] == P2) value[2][0][3] += 10;
    if (puzzle[3][3][0] == P2) value[2][3][0] += 10;
    if (puzzle[3][3][3] == P2) value[2][3][3] += 10;
    // 3段目角の評価点の変更
    // 相手がおいたときは阻止する
    if (puzzle[3][0][0] == P1) value[1][0][0] += 30;
    if (puzzle[3][0][3] == P1) value[1][0][3] += 30;
    if (puzzle[3][3][0] == P1) value[1][3][0] += 30;
    if (puzzle[3][3][3] == P1) value[1][3][3] += 30;
    // 自分が置いた時も変更
    if (puzzle[3][0][0] == P2 && puzzle[3][0][3] == P2 && puzzle[3][3][0] == P2) value[1][0][0] += 30;
    if (puzzle[3][0][3] == P2 && puzzle[3][0][0] == P2 && puzzle[3][3][3] == P2) value[1][0][3] += 30;
    if (puzzle[3][3][0] == P2 && puzzle[3][0][0] == P2 && puzzle[3][3][3] == P2) value[1][3][0] += 30;
    if (puzzle[3][3][3] == P2 && puzzle[3][0][3] == P2 && puzzle[3][3][0] == P2) value[1][3][3] += 30;

    // クロスアタック対策
    // 垂直止め
    for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
            cnt = 0;
            cnt2 = 0;
            if (puzzle[0][j][k] == P1) cnt++;
            if (puzzle[1][j][k] == P1) cnt++;
            if (puzzle[2][j][k] == P1) cnt++;
            if (puzzle[3][j][k] == P1) cnt++;
            if (puzzle[0][j][k] == P2) cnt2++;
            if (puzzle[1][j][k] == P2) cnt2++;
            if (puzzle[2][j][k] == P2) cnt2++;
            if (puzzle[3][j][k] == P2) cnt2++;
            if (cnt == 2 && cnt2 == 0) {
                for (i = 3; i >= 0; i--) {
                    if (puzzle[i][j][k] == 0) {
                        puzzle[i][j][k] = P2;
                        if (i > 0) puzzle[i - 1][j][k] = OK;
                        //プレイヤー側がリーチにならないかどうか
                        if (isReach(puzzle, P1) == 0) {
                            puzzle[i][j][k] = OK;
                            if (i > 0) puzzle[i - 1][j][k] = NG;
                            *x = i;
                            *y = j;
                            *z = k;
                            return true;
                        }
                        puzzle[i][j][k] = OK;
                        if (i > 0) puzzle[i - 1][j][k] = NG;
                    }
                }
            }
        }
    }

    for (i = 3; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            cnt = 0;
            cnt2 = 0;
            if (puzzle[i][j][0] == P1) cnt++;
            if (puzzle[i][j][1] == P1) cnt++;
            if (puzzle[i][j][2] == P1) cnt++;
            if (puzzle[i][j][3] == P1) cnt++;
            if (puzzle[i][j][0] == P2) cnt2++;
            if (puzzle[i][j][1] == P2) cnt2++;
            if (puzzle[i][j][2] == P2) cnt2++;
            if (puzzle[i][j][3] == P2) cnt2++;
            if (cnt == 2 && cnt2 == 0) {
                for (k = 0; k < 4; k++) {
                    if (puzzle[i][j][k] == 0) {
                        puzzle[i][j][k] = P2;
                        if (i > 0) puzzle[i - 1][j][k] = OK;
                        //プレイヤー側がリーチにならないかどうか
                        if (isReach(puzzle, P1) == 0) {
                            puzzle[i][j][k] = OK;
                            if (i > 0) puzzle[i - 1][j][k] = NG;
                            *x = i;
                            *y = j;
                            *z = k;
                            return true;
                        }
                        puzzle[i][j][k] = OK;
                        if (i > 0) puzzle[i - 1][j][k] = NG;
                    }

                }
            }
        }
    }
    for (i = 3; i >= 0; i--) {
        for (k = 0; k < 4; k++) {
            cnt = 0;
            cnt2 = 0;
            if (puzzle[i][0][k] == P1) cnt++;
            if (puzzle[i][1][k] == P1) cnt++;
            if (puzzle[i][2][k] == P1) cnt++;
            if (puzzle[i][3][k] == P1) cnt++;
            if (puzzle[i][0][k] == P2) cnt2++;
            if (puzzle[i][1][k] == P2) cnt2++;
            if (puzzle[i][2][k] == P2) cnt2++;
            if (puzzle[i][3][k] == P2) cnt2++;
            if (cnt == 2 && cnt2 == 0) {
                for (j = 0; j < 4; j++) {
                    if (puzzle[i][j][k] == 0) {
                        puzzle[i][j][k] = P2;
                        if (i > 0) puzzle[i - 1][j][k] = OK;
                        //プレイヤー側がリーチにならないかどうか
                        if (isReach(puzzle, P1) == 0) {
                            puzzle[i][j][k] = OK;
                            if (i > 0) puzzle[i - 1][j][k] = NG;
                            *x = i;
                            *y = j;
                            *z = k;
                            return true;
                        }
                        puzzle[i][j][k] = OK;
                        if (i > 0) puzzle[i - 1][j][k] = NG;
                    }
                }
            }
        }
    }
    /*if (puzzle[3][1][1] == OK) {
        cnt = 0;
        if (puzzle[3][0][1] == P1) cnt++;
        if (puzzle[3][1][0] == P1) cnt++;
        if (puzzle[3][1][3] == P1) cnt++;
        if (puzzle[3][3][1] == P1) cnt++;
        if (cnt >= 1) {
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
        if (cnt >= 1) {
            *x = 3;
            *y = 2;
            *z = 2;
            return true;
        }
    }
    if (puzzle[3][2][1] == OK) {
        cnt = 0;
        if (puzzle[3][2][0] == P1) cnt++;
        if (puzzle[3][0][1] == P1) cnt++;
        if (puzzle[3][3][1] == P1) cnt++;
        if (puzzle[3][2][3] == P1) cnt++;
        if (cnt >= 1) {
            *x = 3;
            *y = 2;
            *z = 1;
            return true;
        }
    }
    if (puzzle[3][1][2] == OK) {
        cnt = 0;
        if (puzzle[3][0][1] == P1) cnt++;
        if (puzzle[3][0][1] == P1) cnt++;
        if (puzzle[3][3][1] == P1) cnt++;
        if (puzzle[3][1][3] == P1) cnt++;
        if (cnt >= 1) {
            *x = 3;
            *y = 1;
            *z = 2;
            return true;
        }
    }*/

    // 評価値の高い手が見つかった時はそこを返す
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
                        }
                    }
                    puzzle[i][j][k] = OK;
                    if (i > 0)puzzle[i - 1][j][k] = NG;
                }
            }
        }
    }
    return true;
}