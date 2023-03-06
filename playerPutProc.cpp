//************************************************
// �v���C���[�����u���ۂ̏���
//************************************************
#include "define.h"

void makeFigure(int[][FIGURE_NUM][FIGURE_NUM], int, int);
boolean playerCanPut(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
void fill(int, int, int, int);

int playerPutProc(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum, int d, int m, int temp[][3]) {
    int ClickX, ClickY, Button, LogType;
    int x = -1, y = -1, z = -1;
    while (1) {
        ClearDrawScreen();
        // �}�`�̍쐬�ƕ`��
        makeFigure(puzzle, d, m);
        if (playerCanPut(puzzle, &x, &y, &z)) fill(x, y, z, playerNum);// ���������u����ӏ����ǂ����m�F����
        // �}�E�X�̃{�^���������ꂽ�藣���ꂽ�肵�����ǂ����̏����擾����
        if (!GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE)) {
            if ((Button & MOUSE_INPUT_LEFT))
            {
                // ���N���b�N��������Ă��āA���ꂽ�u�Ԃɏ����m�肷��
                if (LogType == MOUSE_INPUT_LOG_UP) {
                    if (playerCanPut(puzzle, &x, &y, &z)) {
                        puzzle[x][y][z] = playerNum;
                        if (x > 0) puzzle[x - 1][y][z] = OK;
                        temp[0][0] = x;
                        temp[0][1] = y;
                        temp[0][2] = z;
                        return 1;
                    }
                    else {
                        LogType = 0;
                        continue;
                    }
                }
            }
        }
        if (m == 1) {
            if (CheckHitKey(KEY_INPUT_BACK)) {
                return 0;
            }
        }
        ScreenFlip();
    }
}