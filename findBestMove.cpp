//************************************************
// CPU‚ªÅ“K‰ğ‚ğŒ©‚Â‚¯‚é•û–@‚Ì‘å˜g
//************************************************
#include "define.h"

boolean search(int, int[][FIGURE_NUM][FIGURE_NUM], int, int, int);

void findBestMove(int depth, int puzzle[][FIGURE_NUM][FIGURE_NUM], int* x, int* y, int* z) {
    int i, j, k;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == OK) {
                    if (search(depth, puzzle, i, j, k)) break; // •Ô‚·è‚ªŒˆ‚Ü‚Á‚½
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
