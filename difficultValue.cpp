//************************************************
// CPU�̋����u�����v�̕]���֐�
// ��{�I�ɂ͏��ĂȂ��ʂ̋���
// �ꉞ����������Ώ��Ă�
//************************************************
#include "define.h"

int isReach(int[][FIGURE_NUM][FIGURE_NUM], int);
void evaluation(int[][4][4], int[][4][4], int);

boolean difficultValue(int puzzle[][FIGURE_NUM][FIGURE_NUM], int* x, int* y, int* z) {
    int i, j, k;
    int cnt, cnt2;
    int max = -999;
    int flag = 0;
    //�e�}�X�̕]���l �P���ɂ����ɒu�������̃r���S�ɂȂ蓾�鐔����ɂ��Ă���
    int value[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {   
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}}
    };
    // 2�i�ڊp�̕]���_�̕ύX
    // �Ƃ肠����2�i�ڒ[�܂ł͗D��I�Ɏ擾����
    // ����̕K����ɂȂ肦��̂ő��肪�u�������̂ق����������Ă���
    if (puzzle[3][0][0] == P2) value[2][0][0] += 10;
    if (puzzle[3][0][3] == P2) value[2][0][3] += 10;
    if (puzzle[3][3][0] == P2) value[2][3][0] += 10;
    if (puzzle[3][3][3] == P2) value[2][3][3] += 10;
    if (puzzle[3][0][0] == P1) value[2][0][0] += 15;
    if (puzzle[3][0][3] == P1) value[2][0][3] += 15;
    if (puzzle[3][3][0] == P1) value[2][3][0] += 15;
    if (puzzle[3][3][3] == P1) value[2][3][3] += 15;
    // ��ԉ��̊p�����܂��Ă���Ƃ��́A���̗�̃_�u�����[�`��h��
    /*if (puzzle[3][0][0] != OK && puzzle[3][3][0] != OK
        && puzzle[3][0][3] != OK && puzzle[3][3][3] != OK) {
        value[3][1][1] += 5;
        value[3][1][2] += 5;
        value[3][2][1] += 5;
        value[3][2][2] += 5;
        if (puzzle[3][0][0] == P1 && puzzle[3][3][3] == P1) {
            if(value[3][2][2] != P2) value[3][1][1] += 10;
            if(value[3][1][1] != P2) value[3][2][2] += 10;
        }
        if (puzzle[3][3][0] == P1 && puzzle[3][0][3] == P1) {
            if (value[3][2][1] != P2) value[3][1][2] += 10;
            if (value[3][1][2] != P2) value[3][2][1] += 10;
        }
    }*/
    // ���肪�j�̂Q�i�ڂɒu������R�i�ڂ͑��Ƃ�
    if (puzzle[2][1][1] == P1) value[1][1][1] += 50;
    if (puzzle[2][1][2] == P1) value[1][1][2] += 50;
    if (puzzle[2][2][1] == P1) value[1][2][1] += 50;
    if (puzzle[2][2][2] == P1) value[1][2][2] += 50;

    // �p�c2�~2����Q�b�g�����Ƃ��͏����m��
    if (puzzle[3][0][0] == P2 && puzzle[2][0][0] == P2
        && puzzle[3][3][0] == P2 && puzzle[2][3][0] == P2
        && puzzle[3][1][0] == OK && puzzle[3][2][0] == OK) {
        value[3][1][0] += 100;
        value[3][2][0] += 100;
        if (puzzle[3][1][0] == P2) value[2][1][0] += 100;
        if (puzzle[3][2][0] == P2) value[2][2][0] += 100;
        if (puzzle[3][1][0] == P2 && puzzle[2][1][0] == P2) {
            value[1][0][0] += 100;
            value[1][1][0] += 100;
            value[1][3][0] += 100;
        }
        if (puzzle[3][2][0] == P2 && puzzle[2][2][0] == P2) {
            value[1][0][0] += 100;
            value[1][2][0] += 100;
            value[1][3][0] += 100;
        }
    }
    if (puzzle[3][0][3] == P2 && puzzle[2][0][3] == P2
        && puzzle[3][3][3] == P2 && puzzle[2][3][3] == P2
        && puzzle[3][1][3] == OK && puzzle[3][2][3] == OK) {
        value[3][1][3] += 100;
        value[3][2][3] += 100;
        if (puzzle[3][1][3] == P2) value[2][1][3] += 100;
        if (puzzle[3][2][3] == P2) value[2][2][3] += 100;
        if (puzzle[3][1][3] == P2 && puzzle[2][1][3] == P2) {
            value[1][0][3] += 100;
            value[1][1][3] += 100;
            value[1][3][3] += 100;
        }
        if (puzzle[3][2][3] == P2 && puzzle[2][2][3] == P2) {
            value[1][0][3] += 100;
            value[1][2][3] += 100;
            value[1][3][3] += 100;
        }
    }
    if (puzzle[3][0][0] == P2 && puzzle[2][0][0] == P2
        && puzzle[3][0][3] == P2 && puzzle[2][0][3] == P2
        && puzzle[3][0][1] == OK && puzzle[3][0][2] == OK) {
        value[3][0][1] += 100;
        value[3][0][2] += 100;
        if (puzzle[3][0][1] == P2) value[2][0][1] += 100;
        if (puzzle[3][0][2] == P2) value[2][0][2] += 100;
        if (puzzle[3][0][1] == P2 && puzzle[2][0][1] == P2) {
            value[1][0][0] += 100;
            value[1][0][1] += 100;
            value[1][0][3] += 100;
        }
        if (puzzle[3][0][2] == P2 && puzzle[2][0][2] == P2) {
            value[1][0][0] += 100;
            value[1][0][2] += 100;
            value[1][0][3] += 100;
        }
    }
    if (puzzle[3][3][0] == P2 && puzzle[2][3][0] == P2
        && puzzle[3][3][3] == P2 && puzzle[2][3][3] == P2
        && puzzle[3][3][1] == OK && puzzle[3][3][2] == OK) {
        value[3][3][1] += 100;
        value[3][3][2] += 100;
        if (puzzle[3][3][1] == P2) value[2][3][1] += 100;
        if (puzzle[3][3][2] == P2) value[2][3][2] += 100;
        if (puzzle[3][3][1] == P2 && puzzle[2][3][1] == P2) {
            value[1][3][0] += 100;
            value[1][3][1] += 100;
            value[1][3][3] += 100;
        }
        if (puzzle[3][3][2] == P2 && puzzle[2][3][2] == P2) {
            value[1][3][0] += 100;
            value[1][3][2] += 100;
            value[1][3][3] += 100;
        }
    }
    
    evaluation(puzzle, value, P2);

    /*******************************************************************************/
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
                            flag = 1;
                        }
                    }
                    puzzle[i][j][k] = OK;
                    if (i > 0)puzzle[i - 1][j][k] = NG;
                }
            }
        }
    }
    // �����h�~�̂��߂̏���
    // flag��0�̂܂܁A�܂��̏����Ō��܂��Ă��Ȃ���
    if (flag == 0) {
        for (i = 3; i >= 0; i--) {
            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    if (puzzle[i][j][k] == OK) {
                        *x = i;
                        *y = j;
                        *z = k;
                    }
                }
            }
        }
    }
    return true;
}
// �N���X�A�^�b�N�΍�
    // �΂ߎ~��
    //if (puzzle[3][0][3] == P1 && puzzle[3][3][3] == P1) {
    //    for (j = 1; j < 3; j++) {
    //        if (puzzle[2][j][3] == OK) {
    //            puzzle[2][j][3] = P2;
    //            puzzle[1][j][3] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[2][j][3] = OK;
    //                puzzle[1][j][3] = NG;
    //                *x = 2;
    //                *y = j;
    //                *z = 3;
    //                return true;
    //            }
    //            puzzle[2][j][3] = OK;
    //            puzzle[1][j][3] = NG;
    //        }
    //    }
    //}
    //if (puzzle[3][0][0] == P1 && puzzle[3][0][3] == P1) {
    //    for (k = 1; k < 3; k++) {
    //        if (puzzle[2][0][k] == OK) {
    //            puzzle[2][0][k] = P2;
    //            puzzle[1][0][k] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[2][0][k] = OK;
    //                puzzle[1][0][k] = NG;
    //                *x = 2;
    //                *y = 0;
    //                *z = k;
    //                return true;
    //            }
    //            puzzle[2][0][k] = OK;
    //            puzzle[1][0][k] = NG;
    //        }
    //    }
    //}
    //if (puzzle[3][3][0] == P1 && puzzle[3][3][3] == P1) {
    //    for (k = 1; k < 3; k++) {
    //        if (puzzle[2][3][k] == OK) {
    //            puzzle[2][3][k] = P2;
    //            puzzle[1][3][k] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[2][3][k] = OK;
    //                puzzle[1][3][k] = NG;
    //                *x = 2;
    //                *y = 3;
    //                *z = k;
    //                return true;
    //            }
    //            puzzle[2][3][k] = OK;
    //            puzzle[1][3][k] = NG;
    //        }
    //    }
    //}
    //if (puzzle[3][0][0] == P1 && puzzle[3][3][0] == P1) {
    //    for (j = 1; j < 3; j++) {
    //        if (puzzle[2][j][0] == OK) {
    //            puzzle[2][j][0] = P2;
    //            puzzle[1][j][0] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[2][j][0] = OK;
    //                puzzle[1][j][0] = NG;
    //                *x = 2;
    //                *y = j;
    //                *z = 0;
    //                return true;
    //            }
    //            puzzle[2][j][0] = OK;
    //            puzzle[1][j][0] = NG;
    //        }
    //    }
    //}

    /*******************************************************************************/
    // ���̓I�Ɍ������̑�2�ʁA��3�ʂ�ʂ���̎΂ߎ~��
    //cnt = 0;
    //cnt2 = 0;
    //if (puzzle[3][0][0] == P1) cnt++;
    //if (puzzle[2][1][1] == P1) cnt++;
    //if (puzzle[1][2][2] == P1) cnt++;
    //if (puzzle[0][3][3] == P1) cnt++;
    //if (puzzle[3][0][0] == P2) cnt2++;
    //if (puzzle[2][1][1] == P2) cnt2++;
    //if (puzzle[1][2][2] == P2) cnt2++;
    //if (puzzle[0][3][3] == P2) cnt2++;
    //if (cnt >= 1 && cnt2 == 0) {
    //    if (puzzle[0][3][3] == OK) {
    //        puzzle[0][3][3] = P2;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[0][3][3] = OK;
    //            *x = 0;
    //            *y = 3;
    //            *z = 3;
    //            return true;
    //        }
    //        puzzle[0][3][3] = OK;
    //    }
    //    if (puzzle[1][2][2] == OK) {
    //        puzzle[1][2][2] = P2;
    //        puzzle[0][2][2] = OK;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[1][2][2] = OK;
    //            puzzle[0][2][2] = NG;
    //            *x = 1;
    //            *y = 2;
    //            *z = 2;
    //            return true;
    //        }
    //        puzzle[1][2][2] = OK;
    //        puzzle[0][2][2] = NG;
    //    }
    //    if (puzzle[2][1][1] == OK) {
    //        puzzle[2][1][1] = P2;
    //        puzzle[1][1][1] = OK;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[2][1][1] = OK;
    //            puzzle[1][1][1] = NG;
    //            *x = 2;
    //            *y = 1;
    //            *z = 1;
    //            return true;
    //        }
    //        puzzle[2][1][1] = OK;
    //        puzzle[1][1][1] = NG;
    //    }
    //    if (puzzle[3][0][0] == OK) {
    //        puzzle[3][0][0] = P2;
    //        puzzle[2][0][0] = OK;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[3][0][0] = OK;
    //            puzzle[2][0][0] = NG;
    //            *x = 3;
    //            *y = 0;
    //            *z = 0;
    //            return true;
    //        }
    //        puzzle[3][0][0] = OK;
    //        puzzle[2][0][0] = NG;
    //    }

    //}
    //cnt = 0;
    //cnt2 = 0;
    //if (puzzle[3][3][3] == P1) cnt++;
    //if (puzzle[2][2][2] == P1) cnt++;
    //if (puzzle[1][1][1] == P1) cnt++;
    //if (puzzle[0][0][0] == P1) cnt++;
    //if (puzzle[3][3][3] == P2) cnt2++;
    //if (puzzle[2][2][2] == P2) cnt2++;
    //if (puzzle[1][1][1] == P2) cnt2++;
    //if (puzzle[0][0][0] == P2) cnt2++;
    //if (cnt >= 1 && cnt2 == 0) {
    //    if (puzzle[0][0][0] == OK) {
    //        puzzle[0][0][0] = P2;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[0][0][0] = OK;
    //            *x = 0;
    //            *y = 0;
    //            *z = 0;
    //            return true;
    //        }
    //        puzzle[0][0][0] = OK;
    //    }
    //    if (puzzle[1][1][1] == OK) {
    //        puzzle[1][1][1] = P2;
    //        puzzle[0][1][1] = OK;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[1][1][1] = OK;
    //            puzzle[0][1][1] = NG;
    //            *x = 1;
    //            *y = 1;
    //            *z = 1;
    //            return true;
    //        }
    //        puzzle[1][1][1] = OK;
    //        puzzle[0][1][1] = NG;
    //    }
    //    if (puzzle[2][2][2] == OK) {
    //        puzzle[2][2][2] = P2;
    //        puzzle[1][2][2] = OK;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[2][2][2] = OK;
    //            puzzle[1][2][2] = NG;
    //            *x = 2;
    //            *y = 2;
    //            *z = 2;
    //            return true;
    //        }
    //        puzzle[2][2][2] = OK;
    //        puzzle[1][2][2] = NG;
    //    }
    //    if (puzzle[3][3][3] == OK) {
    //        puzzle[3][3][3] = P2;
    //        puzzle[2][3][3] = OK;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[3][3][3] = OK;
    //            puzzle[2][3][3] = NG;
    //            *x = 3;
    //            *y = 3;
    //            *z = 3;
    //            return true;
    //        }
    //        puzzle[3][3][3] = OK;
    //        puzzle[2][3][3] = NG;
    //    }

    //}
    //cnt = 0;
    //cnt2 = 0;
    //if (puzzle[3][0][3] == P1) cnt++;
    //if (puzzle[2][1][2] == P1) cnt++;
    //if (puzzle[1][2][1] == P1) cnt++;
    //if (puzzle[0][3][0] == P1) cnt++;
    //if (puzzle[3][0][3] == P2) cnt2++;
    //if (puzzle[2][1][2] == P2) cnt2++;
    //if (puzzle[1][2][1] == P2) cnt2++;
    //if (puzzle[0][3][0] == P2) cnt2++;
    //if (cnt == 2 && cnt2 == 0) {
    //    if (puzzle[0][3][0] == OK) {
    //        puzzle[0][3][0] = P2;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[0][3][0] = OK;
    //            *x = 0;
    //            *y = 3;
    //            *z = 0;
    //            return true;
    //        }
    //        puzzle[0][3][0] = OK;
    //    }
    //    if (puzzle[1][2][1] == OK) {
    //        puzzle[1][2][1] = P2;
    //        puzzle[0][2][1] = OK;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[1][2][1] = OK;
    //            puzzle[0][2][1] = NG;
    //            *x = 1;
    //            *y = 2;
    //            *z = 1;
    //            return true;
    //        }
    //        puzzle[1][2][1] = OK;
    //        puzzle[0][2][1] = NG;
    //    }
    //    if (puzzle[2][1][2] == OK) {
    //        puzzle[2][1][2] = P2;
    //        puzzle[1][1][2] = OK;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[2][1][2] = OK;
    //            puzzle[1][1][2] = NG;
    //            *x = 2;
    //            *y = 1;
    //            *z = 2;
    //            return true;
    //        }
    //        puzzle[2][1][2] = OK;
    //        puzzle[1][1][2] = NG;
    //    }
    //    if (puzzle[3][0][3] == OK) {
    //        puzzle[3][0][3] = P2;
    //        puzzle[2][0][3] = OK;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[3][0][3] = OK;
    //            puzzle[2][0][3] = NG;
    //            *x = 3;
    //            *y = 0;
    //            *z = 3;
    //            return true;
    //        }
    //        puzzle[3][0][3] = OK;
    //        puzzle[2][0][3] = NG;
    //    }

    //}
    //cnt = 0;
    //cnt2 = 0;
    //if (puzzle[3][3][0] == P1) cnt++;
    //if (puzzle[2][2][1] == P1) cnt++;
    //if (puzzle[1][1][2] == P1) cnt++;
    //if (puzzle[0][0][3] == P1) cnt++;
    //if (puzzle[3][3][0] == P2) cnt2++;
    //if (puzzle[2][2][1] == P2) cnt2++;
    //if (puzzle[1][1][2] == P2) cnt2++;
    //if (puzzle[0][0][3] == P2) cnt2++;
    //if (cnt == 2 && cnt2 == 0) {
    //    if (puzzle[0][0][3] == OK) {
    //        puzzle[0][0][3] = P2;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[0][0][3] = OK;
    //            *x = 0;
    //            *y = 0;
    //            *z = 3;
    //            return true;
    //        }
    //        puzzle[0][0][3] = OK;
    //    }
    //    if (puzzle[1][1][2] == OK) {
    //        puzzle[1][1][2] = P2;
    //        puzzle[0][1][2] = OK;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[1][1][2] = OK;
    //            puzzle[0][1][2] = NG;
    //            *x = 1;
    //            *y = 1;
    //            *z = 2;
    //            return true;
    //        }
    //        puzzle[1][1][2] = OK;
    //        puzzle[0][1][2] = NG;
    //    }
    //    if (puzzle[2][2][1] == OK) {
    //        puzzle[2][2][1] = P2;
    //        puzzle[1][2][1] = OK;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[2][2][1] = OK;
    //            puzzle[1][2][1] = NG;
    //            *x = 2;
    //            *y = 2;
    //            *z = 1;
    //            return true;
    //        }
    //        puzzle[2][2][1] = OK;
    //        puzzle[1][2][1] = NG;
    //    }
    //    if (puzzle[3][3][0] == OK) {
    //        puzzle[3][3][0] = P2;
    //        puzzle[2][3][0] = OK;
    //        if (isReach(puzzle, P1) == 0) {
    //            puzzle[3][3][0] = OK;
    //            puzzle[2][3][0] = NG;
    //            *x = 3;
    //            *y = 3;
    //            *z = 0;
    //            return true;
    //        }
    //        puzzle[3][3][0] = OK;
    //        puzzle[2][3][0] = NG;
    //    }

    //}
    //
    //// ���ʂŌ������̎΂߂̃_�u���A�^�b�N��h��
    //for (i = 3; i >= 0; i--) {
    //    cnt = 0;
    //    cnt2 = 0;
    //    if (puzzle[i][0][0] == P1) cnt++;
    //    if (puzzle[i][1][1] == P1) cnt++;
    //    if (puzzle[i][2][2] == P1) cnt++;
    //    if (puzzle[i][3][3] == P1) cnt++;
    //    if (puzzle[i][0][0] == P2) cnt2++;
    //    if (puzzle[i][1][1] == P2) cnt2++;
    //    if (puzzle[i][2][2] == P2) cnt2++;
    //    if (puzzle[i][3][3] == P2) cnt2++;
    //    if (cnt == 2 && cnt2 == 0) {
    //        for (j = 0; j < 4; j++) {
    //            if (puzzle[i][j][j] == OK) {
    //                puzzle[i][j][j] = P2;
    //                if (i > 0) puzzle[i - 1][j][j] = OK;
    //                //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //                if (isReach(puzzle, P1) == 0) {
    //                    puzzle[i][j][j] = OK;
    //                    if (i > 0) puzzle[i - 1][j][j] = NG;
    //                    *x = i;
    //                    *y = j;
    //                    *z = j;
    //                    return true;
    //                }
    //                puzzle[i][j][j] = OK;
    //                if (i > 0) puzzle[i - 1][j][j] = NG;
    //            }
    //        }
    //    }
    //}
    //for (i = 3; i >= 0; i--) {
    //    cnt = 0;
    //    cnt2 = 0;
    //    if (puzzle[i][3][0] == P1) cnt++;
    //    if (puzzle[i][2][1] == P1) cnt++;
    //    if (puzzle[i][1][2] == P1) cnt++;
    //    if (puzzle[i][0][3] == P1) cnt++;
    //    if (puzzle[i][3][0] == P2) cnt2++;
    //    if (puzzle[i][2][1] == P2) cnt2++;
    //    if (puzzle[i][1][2] == P2) cnt2++;
    //    if (puzzle[i][0][3] == P2) cnt2++;
    //    if (cnt == 2 && cnt2 == 0) {
    //        if (puzzle[i][3][0] == OK) {
    //            puzzle[i][3][0] = P2;
    //            if (i > 0) puzzle[i - 1][3][0] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[i][3][0] = OK;
    //                if (i > 0) puzzle[i - 1][3][0] = NG;
    //                *x = i;
    //                *y = 3;
    //                *z = 0;
    //                return true;
    //            }
    //            puzzle[i][3][0] = OK;
    //            if (i > 0) puzzle[i - 1][3][0] = NG;
    //        }
    //        if (puzzle[i][2][1] == OK) {
    //            puzzle[i][2][1] = P2;
    //            if (i > 0) puzzle[i - 1][2][1] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[i][2][1] = OK;
    //                if (i > 0) puzzle[i - 1][2][1] = NG;
    //                *x = i;
    //                *y = 2;
    //                *z = 1;
    //                return true;
    //            }
    //            puzzle[i][2][1] = OK;
    //            if (i > 0) puzzle[i - 1][2][1] = NG;
    //        }
    //        if (puzzle[i][1][2] == OK) {
    //            puzzle[i][1][2] = P2;
    //            if (i > 0) puzzle[i - 1][1][2] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[i][1][2] = OK;
    //                if (i > 0) puzzle[i - 1][1][2] = NG;
    //                *x = i;
    //                *y = 1;
    //                *z = 2;
    //                return true;
    //            }
    //            puzzle[i][1][2] = OK;
    //            if (i > 0) puzzle[i - 1][1][2] = NG;
    //        }
    //        if (puzzle[i][0][3] == OK) {
    //            puzzle[i][0][3] = P2;
    //            if (i > 0) puzzle[i - 1][0][3] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[i][0][3] = OK;
    //                if (i > 0) puzzle[i - 1][0][3] = NG;
    //                *x = i;
    //                *y = 0;
    //                *z = 3;
    //                return true;
    //            }
    //            puzzle[i][0][3] = OK;
    //            if (i > 0) puzzle[i - 1][0][3] = NG;
    //        }
    //    }
    //}
    //
    //// �����~��
    //for (j = 0; j < 4; j++) {
    //    for (k = 0; k < 4; k++) {
    //        cnt = 0;
    //        cnt2 = 0;
    //        if (puzzle[0][j][k] == P1) cnt++;
    //        if (puzzle[1][j][k] == P1) cnt++;
    //        if (puzzle[2][j][k] == P1) cnt++;
    //        if (puzzle[3][j][k] == P1) cnt++;
    //        if (puzzle[0][j][k] == P2) cnt2++;
    //        if (puzzle[1][j][k] == P2) cnt2++;
    //        if (puzzle[2][j][k] == P2) cnt2++;
    //        if (puzzle[3][j][k] == P2) cnt2++;
    //        if (cnt == 2 && cnt2 == 0) {
    //            for (i = 3; i >= 0; i--) {
    //                if (puzzle[i][j][k] == OK && !(i == 1 && j == 0 && k == 0) && !(i == 1 && j == 0 && k == 3) && !(i == 1 && j == 3 && k == 0) && !(i == 1 && j == 3 && k == 3)) {
    //                    puzzle[i][j][k] = P2;
    //                    if (i > 0) puzzle[i - 1][j][k] = OK;
    //                    //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //                    if (isReach(puzzle, P1) == 0) {
    //                        puzzle[i][j][k] = OK;
    //                        if (i > 0) puzzle[i - 1][j][k] = NG;
    //                        *x = i;
    //                        *y = j;
    //                        *z = k;
    //                        return true;
    //                    }
    //                    puzzle[i][j][k] = OK;
    //                    if (i > 0) puzzle[i - 1][j][k] = NG;
    //                }
    //            }
    //        }
    //    }
    //}
    ///*******************************************************************************/
    //// ���ʏc���̃_�u�����[�`�΍�
    //for (i = 3; i >= 0; i--) {
    //    for (j = 0; j < 4; j++) {
    //        cnt = 0;
    //        cnt2 = 0;
    //        if (puzzle[i][j][0] == P1) cnt++;
    //        if (puzzle[i][j][1] == P1) cnt++;
    //        if (puzzle[i][j][2] == P1) cnt++;
    //        if (puzzle[i][j][3] == P1) cnt++;
    //        if (puzzle[i][j][0] == P2) cnt2++;
    //        if (puzzle[i][j][1] == P2) cnt2++;
    //        if (puzzle[i][j][2] == P2) cnt2++;
    //        if (puzzle[i][j][3] == P2) cnt2++;
    //        if (cnt == 2 && cnt2 == 0) {
    //            for (k = 0; k < 4; k++) {
    //                if (puzzle[i][j][k] == OK && !(i == 1 && j == 0 && k == 0) && !(i == 1 && j == 0 && k == 3) && !(i == 1 && j == 3 && k == 0) && !(i == 1 && j == 3 && k == 3)) {
    //                    puzzle[i][j][k] = P2;
    //                    if (i > 0) puzzle[i - 1][j][k] = OK;
    //                    //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //                    if (isReach(puzzle, P1) == 0) {
    //                        puzzle[i][j][k] = OK;
    //                        if (i > 0) puzzle[i - 1][j][k] = NG;
    //                        *x = i;
    //                        *y = j;
    //                        *z = k;
    //                        return true;
    //                    }
    //                    puzzle[i][j][k] = OK;
    //                    if (i > 0) puzzle[i - 1][j][k] = NG;
    //                }

    //            }
    //        }
    //    }
    //}
    //for (i = 3; i >= 0; i--) {
    //    for (k = 0; k < 4; k++) {
    //        cnt = 0;
    //        cnt2 = 0;
    //        if (puzzle[i][0][k] == P1) cnt++;
    //        if (puzzle[i][1][k] == P1) cnt++;
    //        if (puzzle[i][2][k] == P1) cnt++;
    //        if (puzzle[i][3][k] == P1) cnt++;
    //        if (puzzle[i][0][k] == P2) cnt2++;
    //        if (puzzle[i][1][k] == P2) cnt2++;
    //        if (puzzle[i][2][k] == P2) cnt2++;
    //        if (puzzle[i][3][k] == P2) cnt2++;
    //        if (cnt == 2 && cnt2 == 0) {
    //            for (j = 0; j < 4; j++) {
    //                if (puzzle[i][j][k] == OK && !(i == 1 && j == 0 && k == 0) && !(i == 1 && j == 0 && k == 3) && !(i == 1 && j == 3 && k == 0) && !(i == 1 && j == 3 && k == 3)) {
    //                    puzzle[i][j][k] = P2;
    //                    if (i > 0) puzzle[i - 1][j][k] = OK;
    //                    //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //                    if (isReach(puzzle, P1) == 0) {
    //                        puzzle[i][j][k] = OK;
    //                        if (i > 0) puzzle[i - 1][j][k] = NG;
    //                        *x = i;
    //                        *y = j;
    //                        *z = k;
    //                        return true;
    //                    }
    //                    puzzle[i][j][k] = OK;
    //                    if (i > 0) puzzle[i - 1][j][k] = NG;
    //                }
    //            }
    //        }
    //    }
    //}
    ///*******************************************************************************/
    //// ��ԉ��̒[�ɑ���̎肪���鎞�ɂ������痧�̎΂߂̎��
    //// �Ԃ�
    //for (j = 0; j < 4; j++) {
    //    if (puzzle[3][j][0] == P1) {
    //        if (puzzle[2][j][1] == OK) {
    //            puzzle[2][j][1] = P2;
    //            puzzle[1][j][1] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[2][j][1] = OK;
    //                puzzle[1][j][1] = NG;
    //                *x = 2;
    //                *y = j;
    //                *z = 1;
    //                return true;
    //            }
    //            puzzle[2][j][1] = OK;
    //            puzzle[1][j][1] = NG;
    //        }
    //        if (puzzle[1][j][2] == OK) {
    //            puzzle[1][j][2] = P2;
    //            puzzle[0][j][2] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[1][j][2] = OK;
    //                puzzle[0][j][2] = NG;
    //                *x = 1;
    //                *y = j;
    //                *z = 2;
    //                return true;
    //            }
    //            puzzle[1][j][2] = OK;
    //            puzzle[0][j][2] = NG;
    //        }
    //    }
    //}
    //for (j = 0; j < 4; j++) {
    //    if (puzzle[3][j][3] == P1) {
    //        if (puzzle[2][j][2] == OK) {
    //            puzzle[2][j][2] = P2;
    //            puzzle[1][j][2] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[2][j][2] = OK;
    //                puzzle[1][j][2] = NG;
    //                *x = 2;
    //                *y = j;
    //                *z = 2;
    //                return true;
    //            }
    //            puzzle[2][j][2] = OK;
    //            puzzle[1][j][2] = NG;
    //        }
    //        if (puzzle[1][j][1] == OK) {
    //            puzzle[1][j][1] = P2;
    //            puzzle[0][j][1] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[1][j][1] = OK;
    //                puzzle[0][j][1] = NG;
    //                *x = 1;
    //                *y = j;
    //                *z = 1;
    //                return true;
    //            }
    //            puzzle[1][j][1] = OK;
    //            puzzle[0][j][1] = NG;
    //        }
    //    }
    //}
    //for (k = 0; k < 4; k++) {
    //    if (puzzle[3][0][k] == P1) {
    //        if (puzzle[2][1][k] == OK) {
    //            puzzle[2][1][k] = P2;
    //            puzzle[1][1][k] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[2][1][k] = OK;
    //                puzzle[1][1][k] = NG;
    //                *x = 2;
    //                *y = 1;
    //                *z = k;
    //                return true;
    //            }
    //            puzzle[2][1][k] = OK;
    //            puzzle[1][1][k] = NG;
    //        }
    //        if (puzzle[1][2][k] == OK) {
    //            puzzle[1][2][k] = P2;
    //            puzzle[0][2][k] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[1][2][k] = OK;
    //                puzzle[0][2][k] = NG;
    //                *x = 1;
    //                *y = 2;
    //                *z = k;
    //                return true;
    //            }
    //            puzzle[1][2][k] = OK;
    //            puzzle[0][2][k] = NG;
    //        }
    //    }
    //}
    //for (k = 0; k < 4; k++) {
    //    if (puzzle[3][3][k] == P1) {
    //        if (puzzle[2][2][k] == OK) {
    //            puzzle[2][2][k] = P2;
    //            puzzle[1][2][k] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[2][2][k] = OK;
    //                puzzle[1][2][k] = NG;
    //                *x = 2;
    //                *y = 2;
    //                *z = k;
    //                return true;
    //            }
    //            puzzle[2][2][k] = OK;
    //            puzzle[1][2][k] = NG;
    //        }
    //        if (puzzle[1][1][k] == OK) {
    //            puzzle[1][1][k] = P2;
    //            puzzle[0][1][k] = OK;
    //            //�v���C���[�������[�`�ɂȂ�Ȃ����ǂ���
    //            if (isReach(puzzle, P1) == 0) {
    //                puzzle[1][1][k] = OK;
    //                puzzle[0][1][k] = NG;
    //                *x = 1;
    //                *y = 1;
    //                *z = k;
    //                return true;
    //            }
    //            puzzle[1][1][k] = OK;
    //            puzzle[0][1][k] = NG;
    //        }
    //    }
    //}
    //        