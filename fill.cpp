//************************************************
//fill proc
//************************************************
#include "define.h"

void fill(int x, int y, int z, int status) {
	static int triangleX = 0, triangleY = 0;
	static unsigned int color = 0;
	switch (status) {
	case 0:
		color = LIGHT_GRAY; //light gray
		break;
	case 1:
		color = LIGHT_RED; //light red
		break;
	default:
		break;
	}

	//************************************************
	//get left-down-point each XYZ-point
	//************************************************
	triangleX = LINE_START_X + (LINE_COL_W * x) + ((LINE_COL_W - LINE_ROW_H) * y);
	triangleY = LINE_START_Y + (-LINE_ROW_H * y) + FIGURE_INTERVAL * z;
	//left-down,top,right-down -point
	DrawTriangleAA((float)(triangleX + TRIANGLE_GAP_X), (float)(triangleY - TRIANGLE_GAP_Y),
		(float)(triangleX + (LINE_COL_W - LINE_ROW_H)), (float)(triangleY - LINE_ROW_H + TRIANGLE_GAP_Y),
		(float)(triangleX + LINE_COL_W), (float)(triangleY - TRIANGLE_GAP_Y), color, TRUE);
	//right-up,left-up,down -point
	DrawTriangleAA((float)(triangleX + LINE_COL_W + (LINE_COL_W - LINE_ROW_H) - TRIANGLE_GAP_X), (float)(triangleY - LINE_ROW_H + TRIANGLE_GAP_Y),
		(float)(triangleX + (LINE_COL_W - LINE_ROW_H)), (float)(triangleY - LINE_ROW_H + TRIANGLE_GAP_Y),
		(float)(triangleX + LINE_COL_W), (float)(triangleY - TRIANGLE_GAP_Y), color, TRUE);
}