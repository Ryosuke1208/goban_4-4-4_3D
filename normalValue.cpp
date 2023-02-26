//************************************************
// �[���̒T���Ō�����Ȃ������Ƃ��ɕ]���l��
// ���肷��
//************************************************
#include "define.h"

int isReach(int [][FIGURE_NUM][FIGURE_NUM], int);

boolean normalValue(int puzzle[][FIGURE_NUM][FIGURE_NUM], int* x, int* y, int* z) {
    int i, j, k;
    int cnt, cnt2;
    int max = -999;
    //�e�}�X�̕]���l �P���ɂ����ɒu�������̃r���S�ɂȂ蓾�鐔����ɂ��Ă���
    int value[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}},
        {{4,15,15,4},{15,10,10,15},{15,10,10,15},{4,15,15,4}},
        {{4,4,4,4},{4,4,4,4},{4,4,4,4},{4,4,4,4}},
        {{7,4,4,7},{4,2,2,4},{4,2,2,4},{7,4,4,7}}
    };
    // 2�i�ڊp�̕]���_�̕ύX
    // ���Ɏ��g�̎肪����Ƃ��͏�ɒu��
    if (puzzle[3][0][0] == P2) value[2][0][0] += 10;
    if (puzzle[3][0][3] == P2) value[2][0][3] += 10;
    if (puzzle[3][3][0] == P2) value[2][3][0] += 10;
    if (puzzle[3][3][3] == P2) value[2][3][3] += 10;
    // 3�i�ڊp�̕]���_�̕ύX
    // ���肪�������Ƃ��͑j�~����
    if (puzzle[3][0][0] == P1) value[1][0][0] += 30;
    if (puzzle[3][0][3] == P1) value[1][0][3] += 30;
    if (puzzle[3][3][0] == P1) value[1][3][0] += 30;
    if (puzzle[3][3][3] == P1) value[1][3][3] += 30;
    // �������u���������ύX
    //if (puzzle[3][0][0] == P2 && puzzle[3][0][3] == P2 && puzzle[3][3][0] == P2) value[1][0][0] += 30;
    //if (puzzle[3][0][3] == P2 && puzzle[3][0][0] == P2 && puzzle[3][3][3] == P2) value[1][0][3] += 30;
    //if (puzzle[3][3][0] == P2 && puzzle[3][0][0] == P2 && puzzle[3][3][3] == P2) value[1][3][0] += 30;
    //if (puzzle[3][3][3] == P2 && puzzle[3][0][3] == P2 && puzzle[3][3][0] == P2) value[1][3][3] += 30;

    // �N���X�A�^�b�N�΍�
    // �΂ߎ~��
    if (puzzle[3][0][3] == P1 && puzzle[3][3][3] == P1) {
        for (j = 1; j < 3; j++) {
            if (puzzle[2][j][3] == OK) {
                puzzle[2][j][3] = P2;
                puzzle[1][j][3] = OK;
                //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
                if (isReach(puzzle, P1) == 0) {
                    puzzle[2][j][3] = OK;
                    puzzle[1][j][3] = NG;
                    *x = 2;
                    *y = j;
                    *z = 3;
                    return true;
                }
                puzzle[2][j][3] = OK;
                puzzle[1][j][3] = NG;
            }
        }
    }
    if (puzzle[3][0][0] == P1 && puzzle[3][0][3] == P1) {
        for (k = 1; k < 3; k++) {
            if (puzzle[2][0][k] == OK) {
                puzzle[2][0][k] = P2;
                puzzle[1][0][k] = OK;
                //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
                if (isReach(puzzle, P1) == 0) {
                    puzzle[2][0][k] = OK;
                    puzzle[1][0][k] = NG;
                    *x = 2;
                    *y = 0;
                    *z = k;
                    return true;
                }
                puzzle[2][0][k] = OK;
                puzzle[1][0][k] = NG;
            }
        }
    }
    if (puzzle[3][3][0] == P1 && puzzle[3][3][3] == P1) {
        for (k = 1; k < 3; k++) {
            if (puzzle[2][3][k] == OK) {
                puzzle[2][3][k] = P2;
                puzzle[1][3][k] = OK;
                //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
                if (isReach(puzzle, P1) == 0) {
                    puzzle[2][3][k] = OK;
                    puzzle[1][3][k] = NG;
                    *x = 2;
                    *y = 3;
                    *z = k;
                    return true;
                }
                puzzle[2][3][k] = OK;
                puzzle[1][3][k] = NG;
            }
        }
    }
    if (puzzle[3][0][0] == P1 && puzzle[3][3][0] == P1) {
        for (j = 1; j < 3; j++) {
            if (puzzle[2][j][0] == OK) {
                puzzle[2][j][0] = P2;
                puzzle[1][j][0] = OK;
                //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
                if (isReach(puzzle, P1) == 0) {
                    puzzle[2][j][0] = OK;
                    puzzle[1][j][0] = NG;
                    *x = 2;
                    *y = j;
                    *z = 0;
                    return true;
                }
                puzzle[2][j][0] = OK;
                puzzle[1][j][0] = NG;
            }
        }
    }
    // �����~��
    for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
            cnt = 0;
            cnt2 = 0;
            if (puzzle[0][j][k] == P1) cnt++;
            if (puzzle[1][j][k] == P1) cnt++;
            if (puzzle[2][j][k] == P1) cnt++;
            if (puzzle[3][j][k] == P1) cnt++;
            if (puzzle[0][j][k] == P2) cnt2++;
            if (puzzle[1][j][k] == P2) cnt2++;
            if (puzzle[2][j][k] == P2) cnt2++;
            if (puzzle[3][j][k] == P2) cnt2++;
            if (cnt == 2 && cnt2 == 0) {
                for (i = 3; i >= 0; i--) {
                    if (puzzle[i][j][k] == OK) {
                        puzzle[i][j][k] = P2;
                        if (i > 0) puzzle[i - 1][j][k] = OK;
                        //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
                        if (isReach(puzzle, P1) == 0) {
                            puzzle[i][j][k] = OK;
                            if (i > 0) puzzle[i - 1][j][k] = NG;
                            *x = i;
                            *y = j;
                            *z = k;
                            return true;
                        }
                        puzzle[i][j][k] = OK;
                        if (i > 0) puzzle[i - 1][j][k] = NG;
                    }
                }
            }
        }
    }

    for (i = 3; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            cnt = 0;
            cnt2 = 0;
            if (puzzle[i][j][0] == P1) cnt++;
            if (puzzle[i][j][1] == P1) cnt++;
            if (puzzle[i][j][2] == P1) cnt++;
            if (puzzle[i][j][3] == P1) cnt++;
            if (puzzle[i][j][0] == P2) cnt2++;
            if (puzzle[i][j][1] == P2) cnt2++;
            if (puzzle[i][j][2] == P2) cnt2++;
            if (puzzle[i][j][3] == P2) cnt2++;
            if (cnt == 2 && cnt2 == 0) {
                for (k = 0; k < 4; k++) {
                    if (puzzle[i][j][k] == OK) {
                        puzzle[i][j][k] = P2;
                        if (i > 0) puzzle[i - 1][j][k] = OK;
                        //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
                        if (isReach(puzzle, P1) == 0) {
                            puzzle[i][j][k] = OK;
                            if (i > 0) puzzle[i - 1][j][k] = NG;
                            *x = i;
                            *y = j;
                            *z = k;
                            return true;
                        }
                        puzzle[i][j][k] = OK;
                        if (i > 0) puzzle[i - 1][j][k] = NG;
                    }

                }
            }
        }
    }
    for (i = 3; i >= 0; i--) {
        for (k = 0; k < 4; k++) {
            cnt = 0;
            cnt2 = 0;
            if (puzzle[i][0][k] == P1) cnt++;
            if (puzzle[i][1][k] == P1) cnt++;
            if (puzzle[i][2][k] == P1) cnt++;
            if (puzzle[i][3][k] == P1) cnt++;
            if (puzzle[i][0][k] == P2) cnt2++;
            if (puzzle[i][1][k] == P2) cnt2++;
            if (puzzle[i][2][k] == P2) cnt2++;
            if (puzzle[i][3][k] == P2) cnt2++;
            if (cnt == 2 && cnt2 == 0) {
                for (j = 0; j < 4; j++) {
                    if (puzzle[i][j][k] == OK) {
                        puzzle[i][j][k] = P2;
                        if (i > 0) puzzle[i - 1][j][k] = OK;
                        //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
                        if (isReach(puzzle, P1) == 0) {
                            puzzle[i][j][k] = OK;
                            if (i > 0) puzzle[i - 1][j][k] = NG;
                            *x = i;
                            *y = j;
                            *z = k;
                            return true;
                        }
                        puzzle[i][j][k] = OK;
                        if (i > 0) puzzle[i - 1][j][k] = NG;
                    }
                }
            }
        }
    }

    // �]���l�̍����肪�����������͂�����Ԃ�
    for (i = 3; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == OK) {
                    puzzle[i][j][k] = P2;
                    if (i > 0)puzzle[i - 1][j][k] = OK;
                    if (isReach(puzzle, P1) == 0) {
                        if (value[i][j][k] > max) {
                            max = value[i][j][k];
                            *x = i;
                            *y = j;
                            *z = k;
                        }
                    }
                    puzzle[i][j][k] = OK;
                    if (i > 0)puzzle[i - 1][j][k] = NG;
                }
            }
        }
    }
    return true;
}