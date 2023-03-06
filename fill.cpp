//************************************************
// 図形の色塗り処理
//************************************************
#include "define.h"

void fill(int x, int y, int z, int status) {
	static int triangleX = 0, triangleY = 0;
	static unsigned int color = 0;
	switch (status) {
	case OK:
		color = LIGHT_GRAY; // ライトグレー 置くことが出来る箇所の色
		break;
	case P1:
		color = LIGHT_RED; // ライトレッド PLAYER1の色
		break;
	case P2:
		color = LIGHT_BLUE; // ライトブルー PLAYER2 or COMPUTERの色
		break;
	case BINGO_P1:
		color = RED; // P1がビンゴの時の表示色
		break;
	case BINGO_P2:
		color = BLUE; // P2がビンゴの時の表示色
		break;
	default:
		break;
	}

	//************************************************
	// 色塗りをする箇所の図形の左下のXY座標を取得し、
	// 三角形を2つ使って色塗りを表現する
	//************************************************
	triangleX = LINE_START_X + (LINE_COL_W * z) + ((LINE_COL_W - LINE_ROW_H) * y);
	triangleY = LINE_START_Y + (-LINE_ROW_H * y) + FIGURE_INTERVAL * x;
	// 左側の三角形の左下、上、右下の座標
	DrawTriangleAA((float)(triangleX + TRIANGLE_GAP_X), (float)(triangleY - TRIANGLE_GAP_Y),
		(float)(triangleX + (LINE_COL_W - LINE_ROW_H)), (float)(triangleY - LINE_ROW_H + TRIANGLE_GAP_Y),
		(float)(triangleX + LINE_COL_W), (float)(triangleY - TRIANGLE_GAP_Y), color, TRUE);
	// 右側の三角形の右上、左上、下の座標
	DrawTriangleAA((float)(triangleX + LINE_COL_W + (LINE_COL_W - LINE_ROW_H) - TRIANGLE_GAP_X), (float)(triangleY - LINE_ROW_H + TRIANGLE_GAP_Y),
		(float)(triangleX + (LINE_COL_W - LINE_ROW_H)), (float)(triangleY - LINE_ROW_H + TRIANGLE_GAP_Y),
		(float)(triangleX + LINE_COL_W), (float)(triangleY - TRIANGLE_GAP_Y), color, TRUE);
}