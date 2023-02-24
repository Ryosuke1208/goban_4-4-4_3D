//************************************************
// �v���C���[�����u���ۂ̏���
//************************************************
#include "define.h"

void makeFigure(int[][FIGURE_NUM][FIGURE_NUM]);
boolean playerCanPut(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
void fill(int, int, int, int);

void playerPutProc(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum) {
    int ClickX, ClickY, Button, LogType;
    int x = -1, y = -1, z = -1;
    while (1) {
        ClearDrawScreen();
        // �}�`�̍쐬�ƕ`��
        makeFigure(puzzle);
        if (playerCanPut(puzzle, &x, &y, &z)) { // ���������u����ӏ����ǂ����m�F����
            fill(x, y, z, playerNum);
        }

        // �}�E�X�̃{�^���������ꂽ�藣���ꂽ�肵�����ǂ����̏����擾����
        if (!GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE)) {

            if ((Button & MOUSE_INPUT_LEFT))
            {
                // ���N���b�N��������Ă��āA���ꂽ�u�Ԃɏ����m�肷��
                if (LogType == MOUSE_INPUT_LOG_UP) {
                    if (x >= 0 && x <= 3 && y >= 0 && y <= 3 && z >= 0 && z <= 3) {
                        puzzle[x][y][z] = playerNum;
                        if (x > 0) puzzle[x - 1][y][z] = OK;
                        break;
                    }
                    else {
                        continue;
                    }
                }
            }
        }

        ScreenFlip();
    }
}