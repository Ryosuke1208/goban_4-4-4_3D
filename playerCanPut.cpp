//************************************************
// マウスのXYZ座標を取得し、
// そこに置ける状態かを取得
// 一番上の図形の左下の図形の座標を{0,0,0}として、
// 縦軸がX座標、奥行きの軸がY座標、右向きの軸がZ座標
// とする(あくまで図形上のXYZ座標であり
// マウスのXY座標の概念とは違う)
//************************************************
#include "define.h"

boolean playerCanPut(int puzzle[][FIGURE_NUM][FIGURE_NUM], int* x, int* y, int *z) {
    int X = 0, Y = 0, Z = 0;
    static int i;
    static int mouseX, mouseY;

    GetMousePoint(&mouseX, &mouseY);
    // そもそもマウスのY座標が図形の範囲内にあるかどうかの判定(マジックナンバーあり)
    if (mouseY < LINE_START_Y - (LINE_ROW_H * 4) || // 一番上の図形の上
        (mouseY > LINE_START_Y && mouseY < LINE_START_Y + FIGURE_INTERVAL * 1 - (LINE_ROW_H * (LINE_NUM - 1))) || // 1番目と2番目の図形の間
            (mouseY > LINE_START_Y + FIGURE_INTERVAL * 1 && mouseY < LINE_START_Y + FIGURE_INTERVAL * 2 - (LINE_ROW_H * (LINE_NUM - 1))) || // 2番目と3番目の図形の間
                (mouseY > LINE_START_Y + FIGURE_INTERVAL * 2 && mouseY < LINE_START_Y + FIGURE_INTERVAL * 3 - (LINE_ROW_H * (LINE_NUM - 1))) || // 3番目と一番下の図形の間
                    mouseY > LINE_START_Y + FIGURE_INTERVAL * 3) return false; // 一番下の図形の下

    for (i = 0; i < FIGURE_NUM; i++) { // 図形上のX座標の決定
        if (mouseY < LINE_START_Y + i * FIGURE_INTERVAL && mouseY > LINE_START_Y + i * FIGURE_INTERVAL - (LINE_ROW_H * (LINE_NUM - 1))) X = i;
    }
    Y = (LINE_START_Y + FIGURE_INTERVAL * X - mouseY) / LINE_ROW_H; // 図形上のY座標の決定
    // そもそもマウスのX座標が図形の範囲内にあるかどうかの判定
    if (mouseX < LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H) || mouseX > LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H) + LINE_COL_W * (LINE_NUM - 1) + (LINE_COL_W - LINE_ROW_H)) {
        return false;
    }
    Z = (mouseX - (LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H))) / LINE_COL_W; // 図形上のX座標の決定
    // 図形上のひし形の一つ一つの図形の斜めになっている部分のZ座標の調整
    // 接戦の傾きを求めて、Z座標を＋－している
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
    DrawFormatString(0, 0, BLACK, "座標Ｘ %d　　座標Ｙ %d", mouseX, mouseY);
    DrawFormatString(0, 20, BLACK, "X %d　　Y %d　　Z %d", X, Y, Z);
    DrawFormatString(0, 40, BLACK, "tempX1 %d　　tempX2 %d", tempX1, tempX2);
    DrawFormatString(0, 60, BLACK, "tempX3 %f　　tempY %f", tempX3, tempY);
#endif

    if (X >= 0 && X <= 3 && Y >= 0 && Y <= 3 && Z >= 0 && Z <= 3 && puzzle[X][Y][Z] == OK) {
        * x = X;
        * y = Y;
        * z = Z;
        return true; //置くことが出来るときはXYZ座標をセットしてtrueを返却する
    }
    else {
        return false;    
    }
}
