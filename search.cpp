//************************************************
// CPU���œK������������@�̏ڍ�
//************************************************
#include "define.h"

int isDone(int[][FIGURE_NUM][FIGURE_NUM], int);
void findBestMove(int, int [][FIGURE_NUM][FIGURE_NUM], int*, int*, int*, int);
int isReach(int [][FIGURE_NUM][FIGURE_NUM], int);

boolean search(int order, int puzzle[][FIGURE_NUM][FIGURE_NUM], int x, int y, int z, int playerNumber) {
    int cnt = 0;
    int x2 = 0, y2 = 0, z2 = 0;
    // �������r���S�ɂȂ�Ȃ����̊m�F
    if (order == 1) {
        puzzle[x][y][z] = playerNumber;
        cnt = isDone(puzzle, playerNumber);
        puzzle[x][y][z] = OK;
    }
    // ���肪�r���S�ɂȂ�Ȃ����̊m�F
    else if (order == 2) {
        puzzle[x][y][z] = (playerNumber % 2) + 1;
        cnt = isDone(puzzle, (playerNumber % 2) + 1);
        puzzle[x][y][z] = OK;
    }
    // ���[�`�ɂȂ����U�߂Ă���
    else if (order == 3) {
        puzzle[x][y][z] = playerNumber;
        if(x > 0) puzzle[x - 1][y][z] = OK;
        cnt = isReach(puzzle, playerNumber);
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
    }  
    if (cnt) return true;
    else return false;
}

