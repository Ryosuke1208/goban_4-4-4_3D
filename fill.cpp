//************************************************
// �}�`�̐F�h�菈��
//************************************************
#include "define.h"

void fill(int x, int y, int z, int status) {
	static int triangleX = 0, triangleY = 0;
	static unsigned int color = 0;
	switch (status) {
	case OK:
		color = LIGHT_GRAY; // ���C�g�O���[ �u�����Ƃ��o����ӏ��̐F
		break;
	case P1:
		color = LIGHT_RED; // ���C�g���b�h PLAYER1�̐F
		break;
	case P2:
		color = LIGHT_BLUE; // ���C�g�u���[ PLAYER2 or COMPUTER�̐F
		break;
	case BINGO_P1:
		color = RED; // P1���r���S�̎��̕\���F
		break;
	case BINGO_P2:
		color = BLUE; // P2���r���S�̎��̕\���F
		break;
	default:
		break;
	}

	//************************************************
	// �F�h�������ӏ��̐}�`�̍�����XY���W���擾���A
	// �O�p�`��2�g���ĐF�h���\������
	//************************************************
	triangleX = LINE_START_X + (LINE_COL_W * z) + ((LINE_COL_W - LINE_ROW_H) * y);
	triangleY = LINE_START_Y + (-LINE_ROW_H * y) + FIGURE_INTERVAL * x;
	// �����̎O�p�`�̍����A��A�E���̍��W
	DrawTriangleAA((float)(triangleX + TRIANGLE_GAP_X), (float)(triangleY - TRIANGLE_GAP_Y),
		(float)(triangleX + (LINE_COL_W - LINE_ROW_H)), (float)(triangleY - LINE_ROW_H + TRIANGLE_GAP_Y),
		(float)(triangleX + LINE_COL_W), (float)(triangleY - TRIANGLE_GAP_Y), color, TRUE);
	// �E���̎O�p�`�̉E��A����A���̍��W
	DrawTriangleAA((float)(triangleX + LINE_COL_W + (LINE_COL_W - LINE_ROW_H) - TRIANGLE_GAP_X), (float)(triangleY - LINE_ROW_H + TRIANGLE_GAP_Y),
		(float)(triangleX + (LINE_COL_W - LINE_ROW_H)), (float)(triangleY - LINE_ROW_H + TRIANGLE_GAP_Y),
		(float)(triangleX + LINE_COL_W), (float)(triangleY - TRIANGLE_GAP_Y), color, TRUE);
}