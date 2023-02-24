//************************************************
// CPU‚ªŽè‚ð’u‚­Û‚Ìˆ—
//************************************************
#include "define.h"

void makeFigure(int[][FIGURE_NUM][FIGURE_NUM]);
void findBestMove(int, int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*, int);
int search(int, int[][FIGURE_NUM][FIGURE_NUM], int, int, int, int);
boolean normalValue(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);

void cpuNormalProc(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum) {
    int x = 0, y = 0, z = 0;
    int order = 1;
    while (1) {
        ClearDrawScreen();
        // }Œ`‚Ìì¬‚Æ•`‰æ
        makeFigure(puzzle);
        while (1) {
            findBestMove(order, puzzle, &x, &y, &z, playerNum);
            if (x != 4) break;
            order++;
            if (order == 5) {
                normalValue(puzzle, &x, &y, &z);
                break;
            }
        }
        puzzle[x][y][z] = playerNum;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        ScreenFlip();
        break;
    }
}