//************************************************
// 4×4×4の図形の作成＋ビンゴラインの作成
//************************************************
#include "define.h"

void fill(int, int, int, int);

void showBingoLine(int puzzle[][FIGURE_NUM][FIGURE_NUM], int d, int m, int pNum, struct BINGO b) {
    static int i, j, k;
    SetFontSize(80);
    // 図形の表示
    for (i = 0; i < FIGURE_NUM; i++) {// 4つの図形
        for (j = 0; j < LINE_NUM; j++) {// 横のライン
            DrawLineAA((float)(LINE_START_X + j * (LINE_COL_W - LINE_ROW_H)), (float)(LINE_START_Y + j * -LINE_ROW_H + i * FIGURE_INTERVAL),
                (float)(LINE_START_X + (LINE_COL_W * (LINE_NUM - 1)) + j * (LINE_COL_W - LINE_ROW_H)), (float)(LINE_START_Y + j * -LINE_ROW_H + i * FIGURE_INTERVAL), BLACK);
        }
        for (j = 0; j < LINE_NUM; j++) {// 縦のライン
            DrawLineAA((float)(LINE_START_X + j * LINE_COL_W), (float)(LINE_START_Y + i * FIGURE_INTERVAL),
                (float)(LINE_START_X + (LINE_COL_W - LINE_ROW_H) * (LINE_NUM - 1) + j * LINE_COL_W), (float)(LINE_START_Y + (LINE_NUM - 1) * -LINE_ROW_H + i * FIGURE_INTERVAL), BLACK);
        }
    }
    // 色塗り
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
    //VS CPUの時だけ表示
    if (m == 1) {
        DrawString(50, 700, "VS CPU", BLACK);
    }
    else {
        DrawString(50, 700, "VS ﾌﾟﾚｲﾔｰ", BLACK);
    }
}