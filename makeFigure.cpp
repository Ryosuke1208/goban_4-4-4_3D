//************************************************
//ê}å`ÇÃçÏê¨
//************************************************
#include "define.h"

void fill(int, int, int, int);

void makeFigure(int puzzle[][FIGURE_NUM][FIGURE_NUM]) {
    static int i, j, k;
    static int color = GetColor(0, 0, 0);
    for (i = 0; i < FIGURE_NUM; i++) {// èc4Ç¬çÏê¨
        for (j = 0; j < LINE_NUM; j++) {// â°ÇÃê¸ àÍñ ÇÃçÏê¨
            DrawLineAA(LINE_START_X + j * (LINE_COL_W - LINE_ROW_H), LINE_START_Y + j * -LINE_ROW_H + i * FIGURE_INTERVAL, LINE_START_X + (LINE_COL_W * (LINE_NUM - 1)) + j * (LINE_COL_W - LINE_ROW_H), LINE_START_Y + j * -LINE_ROW_H + i * FIGURE_INTERVAL, color);
        }
        for (j = 0; j < LINE_NUM; j++) {// ècÇÃê¸ àÍñ ÇÃçÏê¨
            DrawLineAA(LINE_START_X + j * LINE_COL_W, LINE_START_Y + i * FIGURE_INTERVAL, LINE_START_X + (LINE_COL_W - LINE_ROW_H) * (LINE_NUM - 1) + j * LINE_COL_W, LINE_START_Y + (LINE_NUM - 1) * -LINE_ROW_H + i * FIGURE_INTERVAL, color);
        }
    }
    for (i = 0; i < FIGURE_NUM; i++) {
        for (j = 0; j < FIGURE_NUM; j++) {
            for (k = 0; k < FIGURE_NUM; k++) {
                if (puzzle[k][j][i] != -1) {
                    fill(i, j, k, puzzle[k][j][i]);
                }
            }
        }
    }
}