//************************************************
// CPUが手を置く際の処理
//************************************************
#include "define.h"

void makeFigure(int [][FIGURE_NUM][FIGURE_NUM]);
void findBestMove(int, int [][FIGURE_NUM][FIGURE_NUM], int*, int*, int*, int);
int search(int, int [][FIGURE_NUM][FIGURE_NUM], int, int, int, int);
boolean easyValue(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);

void cpuEasyProc(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum) {
    int x = 0, y = 0, z = 0;
    int order = 1;
    while (1) {
        ClearDrawScreen();
        // 図形の作成と描画
        makeFigure(puzzle);
        while (1) {
            findBestMove(order, puzzle, &x, &y, &z, playerNum);
            if (x != 4) break;
            order++;
            if (order == 5) {
                easyValue(puzzle, &x, &y, &z);
                break;
            }
        }
        puzzle[x][y][z] = playerNum;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        ScreenFlip();
        break;
    }
}