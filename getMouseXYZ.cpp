//************************************************
//�}�E�X�̐}�`���XYZ���W�̎擾
//************************************************
#include "define.h"

int getMouseXYZ(int puzzle[][FIGURE_NUM][FIGURE_NUM], int* x, int* y, int *z) {
    int X = 0, Y = 0, Z = 0;
    static int i;
    static int mouseX, mouseY;

    GetMousePoint(&mouseX, &mouseY);
    //Y���W���}�`�O�Ȃ�h��Ԃ������Ȃ�
    if (mouseY < LINE_START_Y - (LINE_ROW_H * 4) || //��ԏ�̐}�`�̏�
        (mouseY > LINE_START_Y && mouseY < LINE_START_Y + FIGURE_INTERVAL * 1 - (LINE_ROW_H * (LINE_NUM - 1))) || // ��ԏ�Ɠ�Ԗڂ̊�
            (mouseY > LINE_START_Y + FIGURE_INTERVAL * 1 && mouseY < LINE_START_Y + FIGURE_INTERVAL * 2 - (LINE_ROW_H * (LINE_NUM - 1))) || // ��ԏ�ƎO�Ԗڂ̊�
                (mouseY > LINE_START_Y + FIGURE_INTERVAL * 2 && mouseY < LINE_START_Y + FIGURE_INTERVAL * 3 - (LINE_ROW_H * (LINE_NUM - 1))) || // �O�ԏ�Ǝl�Ԗڂ̊�
                    mouseY > LINE_START_Y + FIGURE_INTERVAL * 3) return 0; //��ԉ��̐}�`�̉�
    for (i = 0; i < FIGURE_NUM; i++) {
        if (mouseY < LINE_START_Y + i * FIGURE_INTERVAL && mouseY > LINE_START_Y + i * FIGURE_INTERVAL - (LINE_ROW_H * (LINE_NUM - 1))) Z = i;
    }
    Y = (LINE_START_Y + FIGURE_INTERVAL * Z - mouseY) / LINE_ROW_H;
    //X���W���}�`�O�Ȃ�h��Ԃ������Ȃ�
    if (mouseX < LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H) || mouseX > LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H) + LINE_COL_W * (LINE_NUM - 1) + (LINE_COL_W - LINE_ROW_H)) {
        return 0;
    }
    X = (mouseX - (LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H))) / LINE_COL_W;
    if (LINE_START_X + LINE_COL_W * X + Y * (LINE_COL_W - LINE_ROW_H) <= mouseX && mouseX <= LINE_START_X + LINE_COL_W * X + (LINE_COL_W - LINE_ROW_H) + Y * (LINE_COL_W - LINE_ROW_H)
        && (float)(mouseX - (LINE_START_X + LINE_COL_W * X + Y * (LINE_COL_W - LINE_ROW_H))) * ((float)LINE_ROW_H / (float)(LINE_COL_W - LINE_ROW_H))
            <= (float)(LINE_START_Y + FIGURE_INTERVAL * Z - (Y * LINE_ROW_H)) - mouseY) X--;

#ifdef DEBUG_ON
    static int tempX1, tempX2;
    static float tempX3, tempY;
    tempX1 = LINE_START_X + LINE_COL_W * (X + 1) + Y * (LINE_COL_W - LINE_ROW_H);
    tempX2 = LINE_START_X + LINE_COL_W * (X + 1) + (LINE_COL_W - LINE_ROW_H) + Y * (LINE_COL_W - LINE_ROW_H);
    tempX3 = (float)(mouseX - (LINE_START_X + LINE_COL_W * (X + 1) + Y * (LINE_COL_W - LINE_ROW_H))) * ((float)LINE_ROW_H / (float)(LINE_COL_W - LINE_ROW_H));
    tempY = (float)(LINE_START_Y + FIGURE_INTERVAL * Z - (Y * LINE_ROW_H)) - mouseY;
    DrawFormatString(0, 0, GetColor(0, 0, 0), "���W�w %d�@�@���W�x %d", mouseX, mouseY);
    DrawFormatString(0, 30, GetColor(209, 204, 220), "X %d�@�@Y %d�@�@Z %d", X, Y, Z);
    DrawFormatString(0, 120, GetColor(209, 204, 220), "tempX1 %d�@�@tempX2 %d", tempX1, tempX2);
    DrawFormatString(0, 150, GetColor(209, 204, 220), "tempX3 %f�@�@tempY %f", tempX3, tempY);
#endif

    if (X >= 0 && X <= 3 && Y >= 0 && Y <= 3 && Z >= 0 && Z <= 3) {
        * x = X;
        * y = Y;
        * z = Z;
        if (puzzle[Z][Y][X] == 0) return 1; //�u�����Ƃ��ł��鎞�����F��ς��Ă�
        else return 0;
    }
    else {
        return 0;    
    }
}
