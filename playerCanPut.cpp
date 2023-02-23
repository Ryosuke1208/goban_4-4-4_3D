//************************************************
// �}�E�X��XYZ���W���擾���A
// �����ɒu�����Ԃ����擾
// ��ԏ�̐}�`�̍����̐}�`�̍��W��{0,0,0}�Ƃ��āA
// �c����X���W�A���s���̎���Y���W�A�E�����̎���Z���W
// �Ƃ���(�����܂Ő}�`���XYZ���W�ł���
// �}�E�X��XY���W�̊T�O�Ƃ͈Ⴄ)
//************************************************
#include "define.h"

boolean playerCanPut(int puzzle[][FIGURE_NUM][FIGURE_NUM], int* x, int* y, int *z) {
    int X = 0, Y = 0, Z = 0;
    static int i;
    static int mouseX, mouseY;

    GetMousePoint(&mouseX, &mouseY);
    // ���������}�E�X��Y���W���}�`�͈͓̔��ɂ��邩�ǂ����̔���(�}�W�b�N�i���o�[����)
    if (mouseY < LINE_START_Y - (LINE_ROW_H * 4) || // ��ԏ�̐}�`�̏�
        (mouseY > LINE_START_Y && mouseY < LINE_START_Y + FIGURE_INTERVAL * 1 - (LINE_ROW_H * (LINE_NUM - 1))) || // 1�Ԗڂ�2�Ԗڂ̐}�`�̊�
            (mouseY > LINE_START_Y + FIGURE_INTERVAL * 1 && mouseY < LINE_START_Y + FIGURE_INTERVAL * 2 - (LINE_ROW_H * (LINE_NUM - 1))) || // 2�Ԗڂ�3�Ԗڂ̐}�`�̊�
                (mouseY > LINE_START_Y + FIGURE_INTERVAL * 2 && mouseY < LINE_START_Y + FIGURE_INTERVAL * 3 - (LINE_ROW_H * (LINE_NUM - 1))) || // 3�Ԗڂƈ�ԉ��̐}�`�̊�
                    mouseY > LINE_START_Y + FIGURE_INTERVAL * 3) return false; // ��ԉ��̐}�`�̉�

    for (i = 0; i < FIGURE_NUM; i++) { // �}�`���X���W�̌���
        if (mouseY < LINE_START_Y + i * FIGURE_INTERVAL && mouseY > LINE_START_Y + i * FIGURE_INTERVAL - (LINE_ROW_H * (LINE_NUM - 1))) X = i;
    }
    Y = (LINE_START_Y + FIGURE_INTERVAL * X - mouseY) / LINE_ROW_H; // �}�`���Y���W�̌���
    // ���������}�E�X��X���W���}�`�͈͓̔��ɂ��邩�ǂ����̔���
    if (mouseX < LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H) || mouseX > LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H) + LINE_COL_W * (LINE_NUM - 1) + (LINE_COL_W - LINE_ROW_H)) {
        return false;
    }
    Z = (mouseX - (LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H))) / LINE_COL_W; // �}�`���X���W�̌���
    // �}�`��̂Ђ��`�̈��̐}�`�̎΂߂ɂȂ��Ă��镔����Z���W�̒���
    // �ڐ�̌X�������߂āAZ���W���{�|���Ă���
    if (LINE_START_X + LINE_COL_W * Z + Y * (LINE_COL_W - LINE_ROW_H) <= mouseX && mouseX <= LINE_START_X + LINE_COL_W * Z + (LINE_COL_W - LINE_ROW_H) + Y * (LINE_COL_W - LINE_ROW_H)
        && (float)(mouseX - (LINE_START_X + LINE_COL_W * Z + Y * (LINE_COL_W - LINE_ROW_H))) * ((float)LINE_ROW_H / (float)(LINE_COL_W - LINE_ROW_H))
            <= (float)(LINE_START_Y + FIGURE_INTERVAL * X - (Y * LINE_ROW_H)) - mouseY) Z--;

#ifdef DEBUG_ON
    static int tempX1, tempX2;
    static float tempX3, tempY;
    tempX1 = LINE_START_X + LINE_COL_W * (X + 1) + Y * (LINE_COL_W - LINE_ROW_H);
    tempX2 = LINE_START_X + LINE_COL_W * (X + 1) + (LINE_COL_W - LINE_ROW_H) + Y * (LINE_COL_W - LINE_ROW_H);
    tempX3 = (float)(mouseX - (LINE_START_X + LINE_COL_W * (X + 1) + Y * (LINE_COL_W - LINE_ROW_H))) * ((float)LINE_ROW_H / (float)(LINE_COL_W - LINE_ROW_H));
    tempY = (float)(LINE_START_Y + FIGURE_INTERVAL * Z - (Y * LINE_ROW_H)) - mouseY;
    DrawFormatString(0, 0, BLACK, "���W�w %d�@�@���W�x %d", mouseX, mouseY);
    DrawFormatString(0, 20, BLACK, "X %d�@�@Y %d�@�@Z %d", X, Y, Z);
    DrawFormatString(0, 40, BLACK, "tempX1 %d�@�@tempX2 %d", tempX1, tempX2);
    DrawFormatString(0, 60, BLACK, "tempX3 %f�@�@tempY %f", tempX3, tempY);
#endif

    if (X >= 0 && X <= 3 && Y >= 0 && Y <= 3 && Z >= 0 && Z <= 3 && puzzle[X][Y][Z] == OK) {
        * x = X;
        * y = Y;
        * z = Z;
        return true; //�u�����Ƃ��o����Ƃ���XYZ���W���Z�b�g����true��ԋp����
    }
    else {
        return false;    
    }
}
