//************************************************
// �I��������Ԃ�\������
//************************************************
#include "define.h"

void showBingoLine(int[][FIGURE_NUM][FIGURE_NUM], int, int, int, struct BINGO);

int showFinishedStatus(int puzzle[][FIGURE_NUM][FIGURE_NUM], int d, int m, int pNum, struct BINGO b) {
    int flag;
    while (1) {
        ClearDrawScreen();
        showBingoLine(puzzle, d, m, pNum, b);
        SetFontSize(80);
        DrawString(450, 680, "FINISHED", BLACK);
        SetFontSize(40);
        DrawString(450, 750, "press enter", BLACK);
        if (m == 1) {// VS CPU�̎��͎��߂���悤�ɂ��Ă���
            if (CheckHitKey(KEY_INPUT_BACK)) {
                flag = 1;
                break;
            }
            else if (CheckHitKey(KEY_INPUT_RETURN)) {
                return 0;
            }
        }
        else {// VS�v���C���[�͂��̂܂܂����
            if (CheckHitKey(KEY_INPUT_RETURN)) {
                return 0;
            }
        }
        ScreenFlip();
    }
    return flag;
}