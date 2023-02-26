//************************************************
// CPU‚ªŽè‚ð’u‚­Û‚Ìˆ—
//************************************************
#include "define.h"

void makeFigure(int[][FIGURE_NUM][FIGURE_NUM]);
void findBestMove(int, int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
int search(int, int[][FIGURE_NUM][FIGURE_NUM], int, int, int);
boolean normalValue(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);

void cpuNormalProc(int puzzle[][FIGURE_NUM][FIGURE_NUM]) {
    int x = 0, y = 0, z = 0;
    int depth = 1;
    while (1) {
        ClearDrawScreen();
        // }Œ`‚Ìì¬‚Æ•`‰æ
        makeFigure(puzzle);
        while (1) {
            findBestMove(depth, puzzle, &x, &y, &z);
            if (x != 4) break;
            depth++;
            if (depth == 4) {
                normalValue(puzzle, &x, &y, &z);
                break;
            }
        }
        puzzle[x][y][z] = P2;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        ScreenFlip();
        break;
    }
}