//************************************************
// CPUが最適解を見つける方法の詳細
//************************************************
#include "define.h"

int isDone(int[][FIGURE_NUM][FIGURE_NUM], int);
void findBestMove(int, int [][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
int isReach(int[][FIGURE_NUM][FIGURE_NUM], int);

boolean search(int depth, int puzzle[][FIGURE_NUM][FIGURE_NUM], int x, int y, int z) {
    int cnt1 = 0, cnt2 = 0;
    
    // CPU側がビンゴ出来るときはそこで決定
    if (depth == 1) {
        puzzle[x][y][z] = P2;
        cnt1 = isDone(puzzle, P2);
        puzzle[x][y][z] = OK;
    }
    // プレイヤー側がビンゴになるときは阻止する手で決定
    else if (depth == 2) {
        puzzle[x][y][z] = P1;
        cnt1 = isDone(puzzle, P1);
        puzzle[x][y][z] = OK;
    }
    // リーチになる手を攻めていく
    else if (depth == 3) {
        puzzle[x][y][z] = P2;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        //プレイヤー側がリーチになる数を数える
        cnt1 = isReach(puzzle, P1);
        //CPU側がリーチになる数を数える
        cnt2 = isReach(puzzle, P2);
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
        //プレイヤーがリーチにならずに、
        //CPU側がリーチ×2以上になる時はそこで決定
        if (cnt1 == 0 && cnt2 >= 2) return true;
        else return false;
    }  
    if (cnt1) return true;
    else return false;
}

