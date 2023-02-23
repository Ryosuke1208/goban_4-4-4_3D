//************************************************
// CPU���œK������������@�̏ڍ�
//************************************************
#include "define.h"

int isDone(int[][FIGURE_NUM][FIGURE_NUM], int);
void findBestMove(int, int [][FIGURE_NUM][FIGURE_NUM], int*, int*, int*, int);
int isReach(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum);

boolean search(int order, int puzzle[][FIGURE_NUM][FIGURE_NUM], int x, int y, int z, int playerNumber) {
    int cnt = 0;
    int x2 = 0, y2 = 0, z2 = 0;

    //CPU�̔Ԃ̎���order=1,���̃v���C���[�̎���order=2�Ƃ��āA
    //���݂��̎��̈��Ńr���S�ɂȂ邩�Ȃ�Ȃ������m�F
    if (order == 1) {
        puzzle[x][y][z] = playerNumber;
        cnt = isDone(puzzle, playerNumber);
        puzzle[x][y][z] = OK;
    }
    else if (order == 2) {//���肪�r���S�ɂȂ�Ȃ����m�F
        puzzle[x][y][z] = (playerNumber % 2) + 1;
        cnt = isDone(puzzle, (playerNumber % 2) + 1);
        puzzle[x][y][z] = OK;
    }
    else if (order == 3) {
        puzzle[x][y][z] = playerNumber;
        if(x > 0) puzzle[x - 1][y][z] = OK;
        //findBestMove(1, puzzle, &x2, &y2, &z2, playerNumber);
        //puzzle[x2][y2][z2] = playerNumber;
        cnt = isReach(puzzle, playerNumber);
        //puzzle[x2][y2][z2] = OK;
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
        if (cnt >= 2) {
            return true;
        }
        else return false;
    }
    else if (order == 4) {
        puzzle[x][y][z] = (playerNumber % 2) + 1;
        if (x > 0) puzzle[x - 1][y][z] = OK;
        cnt = isReach(puzzle, (playerNumber % 2) + 1);
        puzzle[x][y][z] = OK;
        if (x > 0) puzzle[x - 1][y][z] = NG;
        if (cnt >= 2) {
            return true;
        }
        else return false;
    }
    
    if (cnt) return true; // ���肪�r���S�ɂȂ�Ȃ�j�~�����A�������r���S�ɂȂ�Ȃ炻�̎���o��
    else return false;

    //���݂��Ɏ��̎�Ńr���S�ɂȂ�Ȃ��Ƃ��ɂ��̐���l���Ă���
}

/*
boolean search(int order, int puzzle[][FIGURE_NUM][FIGURE_NUM], int x, int y, int z, int playerNumber) {
    int cnt = 0;

    //CPU�̔Ԃ̎���order=1,���̃v���C���[�̎���order=2�Ƃ��āA
    //���݂��̎��̈��Ńr���S�ɂȂ邩�Ȃ�Ȃ������m�F
    if (order == 1) {
        puzzle[x][y][z] = playerNumber;
        cnt = isDone(puzzle, playerNumber);
        puzzle[x][y][z] = OK;
    }
    else if (order == 2) {//���肪�r���S�ɂȂ�Ȃ����m�F
        puzzle[x][y][z] = (playerNumber % 2) + 1;
        cnt = isDone(puzzle, (playerNumber % 2) + 1);
        puzzle[x][y][z] = OK;

    }
    if (cnt) return true; // ���肪�r���S�ɂȂ�Ȃ�j�~�����A�������r���S�ɂȂ�Ȃ炻�̎���o��
    else return false;

    //���݂��Ɏ��̎�Ńr���S�ɂȂ�Ȃ��Ƃ��ɂ��̐���l���Ă���
}
*/