//************************************************
// CPU���œK������������@�̏ڍ�
//************************************************
#include "define.h"

int isDone(int[][FIGURE_NUM][FIGURE_NUM], int);
void findBestMove(int, int [][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
int isReach(int[][FIGURE_NUM][FIGURE_NUM], int);

boolean search(int depth, int puzzle[][FIGURE_NUM][FIGURE_NUM], int x, int y, int z) {
    int cnt1 = 0, cnt2 = 0;
    int x2, y2, z2;
    
    // CPU�����r���S�o����Ƃ��͂����Ō���
    if (depth == 1) {
        puzzle[x][y][z] = P2;
        cnt1 = isDone(puzzle, P2);
        puzzle[x][y][z] = OK;
    }
    // �v���C���[�����r���S�ɂȂ�Ƃ��͑j�~�����Ō���
    else if (depth == 2) {
        puzzle[x][y][z] = P1;
        cnt1 = isDone(puzzle, P1);
        puzzle[x][y][z] = OK;
    }
    // ���[�`�ɂȂ����U�߂Ă���
    else if (depth == 3) {
        puzzle[x][y][z] = P2;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        // �v���C���[�������[�`�ɂȂ鐔�𐔂���
        cnt1 = isReach(puzzle, P1);
        // CPU�������[�`�ɂȂ鐔�𐔂���
        cnt2 = isReach(puzzle, P2);
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
        // �v���C���[�����[�`�ɂȂ炸�ɁA
        // CPU�������[�`�~2�ȏ�ɂȂ鎞�͂����Ō���
        if (cnt1 == 0 && cnt2 >= 2) return true;
        else return false;
    }// ���肪���[�`�ɂȂ�̂�h��
    else if (depth == 4) {
        puzzle[x][y][z] = P1;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        // �v���C���[�������[�`�ɂȂ鐔�𐔂���
        cnt1 = isReach(puzzle, P1);
        puzzle[x][y][z] = P2;
        cnt2 = isReach(puzzle, P1);
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
        if (cnt1 >= 2 && cnt2 == 0) return true;
        else return false;
    }
    else if (depth == 5) {
        puzzle[x][y][z] = P2;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        // �v���C���[�������[�`�ɂȂ鐔�𐔂���
        findBestMove(3, puzzle, &x2, &y2, &z2);
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
        if (x2 != 4) return true;
        else return false;
    }
    if (cnt1) return true;
    else return false;
}

