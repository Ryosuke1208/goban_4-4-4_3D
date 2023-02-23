//************************************************
// �v���C���[�����u���ۂ̏���
//************************************************
#include "define.h"

void makeFigure(int[][FIGURE_NUM][FIGURE_NUM]);
boolean playerCanPut(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
void fill(int, int, int, int);

void playerPutProc(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum) {
    int ClickX, ClickY, Button, LogType;
    int x = 0, y = 0, z = 0;
    while (1) {
        ClearDrawScreen();
        // �}�`�̍쐬�ƕ`��
        makeFigure(puzzle);
        if (playerCanPut(puzzle, &x, &y, &z)) { // ���������u����ӏ����ǂ����m�F����
            fill(x, y, z, playerNum);
        }
        // �}�E�X�̃{�^���������ꂽ�藣���ꂽ�肵�����ǂ����̏����擾����
        if (!GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE)) {

            if ((Button & MOUSE_INPUT_LEFT) != 0)
            {
                // ���N���b�N��������Ă��āA���ꂽ�u�Ԃɏ����m�肷��
                if (LogType == MOUSE_INPUT_LOG_UP) {
                    puzzle[x][y][z] = playerNum;
                    if (x > 0) puzzle[x - 1][y][z] = OK;
                    break;
                }
            }
        }
        ScreenFlip();
    }
}