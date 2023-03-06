//************************************************
// 4~4~4‚Ì}Œ`‚Ìì¬{ƒrƒ“ƒSƒ‰ƒCƒ“‚Ìì¬
//************************************************
#include "define.h"

void fill(int, int, int, int);

void showBingoLine(int puzzle[][FIGURE_NUM][FIGURE_NUM], int d, int m, int pNum, struct BINGO b) {
    static int i, j, k;
    SetFontSize(80);
    // }Œ`‚Ì•\¦
    for (i = 0; i < FIGURE_NUM; i++) {// 4‚Â‚Ì}Œ`
        for (j = 0; j < LINE_NUM; j++) {// ‰¡‚Ìƒ‰ƒCƒ“
            DrawLineAA((float)(LINE_START_X + j * (LINE_COL_W - LINE_ROW_H)), (float)(LINE_START_Y + j * -LINE_ROW_H + i * FIGURE_INTERVAL),
                (float)(LINE_START_X + (LINE_COL_W * (LINE_NUM - 1)) + j * (LINE_COL_W - LINE_ROW_H)), (float)(LINE_START_Y + j * -LINE_ROW_H + i * FIGURE_INTERVAL), BLACK);
        }
        for (j = 0; j < LINE_NUM; j++) {// c‚Ìƒ‰ƒCƒ“
            DrawLineAA((float)(LINE_START_X + j * LINE_COL_W), (float)(LINE_START_Y + i * FIGURE_INTERVAL),
                (float)(LINE_START_X + (LINE_COL_W - LINE_ROW_H) * (LINE_NUM - 1) + j * LINE_COL_W), (float)(LINE_START_Y + (LINE_NUM - 1) * -LINE_ROW_H + i * FIGURE_INTERVAL), BLACK);
        }
    }
    // F“h‚è
    for (i = 0; i < FIGURE_NUM; i++) {
        for (j = 0; j < FIGURE_NUM; j++) {
            for (k = 0; k < FIGURE_NUM; k++) {
                if (puzzle[i][j][k] != NG) {
                    fill(i, j, k, puzzle[i][j][k]);
                }
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (pNum % 2 == 0) {
            fill(b.bingoX[i], b.bingoY[i], b.bingoZ[i], BINGO_P1);
        }
        else {
            fill(b.bingoX[i], b.bingoY[i], b.bingoZ[i], BINGO_P2);
        }
    }
    //VS CPU‚Ì‚¾‚¯•\¦
    if (m == 1) {
        DrawString(50, 700, "VS CPU", BLACK);
    }
    else {
        DrawString(50, 700, "VS ÌßÚ²Ô°", BLACK);
    }
}