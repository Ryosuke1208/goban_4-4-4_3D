//************************************************
// �[���̒T���Ō�����Ȃ������Ƃ��ɕ]���l��
// ���肷��
//************************************************
#include "define.h"

boolean decideByValue(int puzzle[][FIGURE_NUM][FIGURE_NUM], int* x, int* y, int* z) {
    int i, j, k;
    int cnt;
    //�e�}�X�̕]���l �P���ɂ����ɒu�������̃r���S�ɂȂ蓾�鐔����ɂ��Ă���
    int value[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}}
    };
    //�N���X�A�^�b�N�΍�
    if (puzzle[3][1][1] == OK) {
        cnt = 0;
        if (puzzle[3][0][1] == P1) cnt++;
        if (puzzle[3][1][0] == P1) cnt++;
        if (puzzle[3][1][3] == P1) cnt++;
        if (puzzle[3][3][1] == P1) cnt++;
        if (cnt >= 2) {
            *x = 3;
            *y = 1;
            *z = 1;
            return true;
        }
    }
    if (puzzle[3][2][2] == OK) {
        cnt = 0;
        if (puzzle[3][0][2] == P1) cnt++;
        if (puzzle[3][2][0] == P1) cnt++;
        if (puzzle[3][2][3] == P1) cnt++;
        if (puzzle[3][3][2] == P1) cnt++;
        if (cnt >= 2) {
            *x = 3;
            *y = 2;
            *z = 2;
            return true;
        }
    }
    // �]���l�̍����肪�����������͂�����Ԃ�
    for (i = 3; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == OK) {
                    if (value[i][j][k] == 7) {
                        *x = i;
                        *y = j;
                        *z = k;
                        return true;
                    }
                }
            }
        }
    }
    // �]���l�̍����肪������Ȃ��������͂Ƃ肠�����󂢂Ă�Ƃ���Ԃ�
    for (i = 3; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == OK) {
                    *x = i;
                    *y = j;
                    *z = k;
                    return true;
                }
            }
        }
    }
    return false; //�u����ꏊ���Ȃ�������
}