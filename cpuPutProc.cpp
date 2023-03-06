//************************************************
// CPU‚ªŽè‚ð’u‚­ˆ—
//************************************************
#include "define.h"

void makeFigure(int[][FIGURE_NUM][FIGURE_NUM], int, int);
void findBestMove(int, int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
int search(int, int[][FIGURE_NUM][FIGURE_NUM], int, int, int);
boolean easyValue(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
boolean normalValue(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
boolean difficultValue(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);

void cpuPutProc(int puzzle[][FIGURE_NUM][FIGURE_NUM], int temp[][3], int d) {
    int x = 0, y = 0, z = 0;
    int depth = 1;
    while (1) {
        ClearDrawScreen();
        // }Œ`‚Ìì¬‚Æ•`‰æ
        makeFigure(puzzle, d, 1);
        while (1) {
            findBestMove(depth, puzzle, &x, &y, &z);
            if (x != 4) break;
            depth++;
            if (depth == 5) {
                if (d == 0) {
                    easyValue(puzzle, &x, &y, &z);
                }
                else if (d == 1) {
                    normalValue(puzzle, &x, &y, &z);
                }
                else if (d == 2) {
                    difficultValue(puzzle, &x, &y, &z);
                }
                break;
            }
        }
        puzzle[x][y][z] = P2;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        temp[1][0] = x;
        temp[1][1] = y;
        temp[1][2] = z;
        ScreenFlip();
        break;
    }
}