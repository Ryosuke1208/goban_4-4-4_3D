//************************************************
// ドローかどうかのチェック
//************************************************
#include "define.h"

boolean isDraw(int puzzle[][FIGURE_NUM][FIGURE_NUM]){
    int i, j, k;
    // おける箇所がない時はtrueを返す
    for (i = 0; i < FIGURE_NUM; i++) {
        for (j = 0; j < FIGURE_NUM; j++) {
            for (k = 0; k < FIGURE_NUM; k++) {
                if (puzzle[i][j][k] == OK) {
                    return false;
                }
            }
        }
    }
    return true;
}