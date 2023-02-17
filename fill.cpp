//************************************************
//�h��Ԃ�����
//************************************************
#include "define.h"

void fill(int x, int y, int z, int status) {
	static int triangleX = 0, triangleY = 0;
	static unsigned int color = 0;
	switch (status) {
	case 0:
		color = GetColor(224, 224, 224); //�D�F
		break;
	case 1:
		//color = GetColor(224, 224, 224); //�D�F
		color = GetColor(255, 153, 153); //������
		break;
	default:
		break;
	}

	//************************************************
	//XYZ���W�̐}�`�̍����̍��W�̎擾
	//************************************************
	triangleX = LINE_START_X + (LINE_COL_W * x) + ((LINE_COL_W - LINE_ROW_H) * y);
	triangleY = LINE_START_Y + (-LINE_ROW_H * y) + FIGURE_INTERVAL * z;
#ifdef DEBUG_ON
	DrawFormatString(0, 60, color, "triangleX %d�@�@triangleY %d", triangleX, triangleY);
#endif
	//�����A��A�E���̍��W
	DrawTriangleAA(triangleX + TRIANGLE_GAP_X, triangleY - TRIANGLE_GAP_Y, triangleX + (LINE_COL_W - LINE_ROW_H), triangleY - LINE_ROW_H + TRIANGLE_GAP_Y,
		triangleX + LINE_COL_W, triangleY - TRIANGLE_GAP_Y, color, TRUE);
	//�E��A����A���̍��W
	DrawTriangleAA(triangleX + LINE_COL_W + (LINE_COL_W - LINE_ROW_H) - TRIANGLE_GAP_X, triangleY - LINE_ROW_H + TRIANGLE_GAP_Y, triangleX + (LINE_COL_W - LINE_ROW_H), triangleY - LINE_ROW_H + TRIANGLE_GAP_Y,
		triangleX + LINE_COL_W, triangleY - TRIANGLE_GAP_Y, color, TRUE);
}