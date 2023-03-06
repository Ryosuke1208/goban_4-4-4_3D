#pragma once

#include "DxLib.h"
// �}�`�֌W
#define LINE_NUM 5 // ���̐�
#define LINE_START_X 150 // ��ԏ�̐}�`��X���W(�}�`�̍����̍��W)
#define LINE_START_Y 170 // ��ԏ�̐}�`��Y���W(�}�`�̍����̍��W)
#define LINE_COL_W 80 // �c�̐��̕�
#define LINE_ROW_H 30 // ���̐��̕�
#define FIGURE_NUM 4 // �}�`�̐�(4��)
#define FIGURE_INTERVAL 150 // �}�`���Ƃ�Y���̋���
#define TRIANGLE_GAP_X 5 // �F��h��ۂ̎O�p�`�Ɛ��Ƃ̌��Ԃ�X���W 
#define TRIANGLE_GAP_Y 1.5f //  �F��h��ۂ̎O�p�`�Ɛ��Ƃ̌��Ԃ�Y���W 
// �F�֌W
#define BLACK GetColor(0,0,0)
#define LIGHT_GRAY GetColor(224, 224, 224)
#define LIGHT_RED GetColor(255, 153, 153)
#define LIGHT_BLUE GetColor(153, 204, 255)
#define RED GetColor(255, 51, 51)
#define BLUE GetColor(51, 51, 255)
// �Ֆʊ֌W
#define NG -1
#define OK 0
#define P1 1
#define P2 2
#define BINGO_P1 3
#define BINGO_P2 4
// �r���S�ɂȂ������Ԃ��\����
struct BINGO {
	int bingoX[4];
	int bingoY[4];
	int bingoZ[4];
};
