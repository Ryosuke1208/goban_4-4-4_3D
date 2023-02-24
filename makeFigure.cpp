//************************************************
// 4Å~4Å~4ÇÃê}å`ÇÃçÏê¨
//************************************************
#include "define.h"

void fill(int, int, int, int);

void makeFigure(int puzzle[][FIGURE_NUM][FIGURE_NUM]) {
    static int i, j, k;
    // ê}å`ÇÃï\é¶
    for (i = 0; i < FIGURE_NUM; i++) {// 4Ç¬ÇÃê}å`
        for (j = 0; j < LINE_NUM; j++) {// â°ÇÃÉâÉCÉì
            DrawLineAA((float)(LINE_START_X + j * (LINE_COL_W - LINE_ROW_H)), (float)(LINE_START_Y + j * -LINE_ROW_H + i * FIGURE_INTERVAL),
                (float)(LINE_START_X + (LINE_COL_W * (LINE_NUM - 1)) + j * (LINE_COL_W - LINE_ROW_H)), (float)(LINE_START_Y + j * -LINE_ROW_H + i * FIGURE_INTERVAL), BLACK);
        }
        for (j = 0; j < LINE_NUM; j++) {// ècÇÃÉâÉCÉì
            DrawLineAA((float)(LINE_START_X + j * LINE_COL_W), (float)(LINE_START_Y + i * FIGURE_INTERVAL),
                (float)(LINE_START_X + (LINE_COL_W - LINE_ROW_H) * (LINE_NUM - 1) + j * LINE_COL_W), (float)(LINE_START_Y + (LINE_NUM - 1) * -LINE_ROW_H + i * FIGURE_INTERVAL), BLACK);
        }
    }
    // êFìhÇË
    for (i = 0; i < FIGURE_NUM; i++) {
        for (j = 0; j < FIGURE_NUM; j++) {
            for (k = 0; k < FIGURE_NUM; k++) {
                if (puzzle[i][j][k] != NG) {
                    fill(i, j, k, puzzle[i][j][k]);
                }
            }
        }
    }
}