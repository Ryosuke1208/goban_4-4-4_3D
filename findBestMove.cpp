//************************************************
// CPUが最適解を見つける方法の大枠
//************************************************
#include "define.h"

boolean search(int, int[][FIGURE_NUM][FIGURE_NUM], int, int, int, int);

void findBestMove(int order, int puzzle[][FIGURE_NUM][FIGURE_NUM], int* x, int* y, int* z, int playerNumber) { //空いてるマスの座標を返している
    int i, j, k;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == OK) {
                    if (search(order, puzzle, i, j, k, playerNumber)) break; // 返す手が決まった時
                }
            }
            if (k != 4) break;
        }
        if (j != 4) break;
    }

    *x = i;
    *y = j;
    *z = k;
}
