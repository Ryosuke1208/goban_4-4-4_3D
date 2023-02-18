//************************************************
//get Mouse figure's-XYZ-point and check can put
//************************************************
#include "define.h"

boolean playerCanPut(int puzzle[][FIGURE_NUM][FIGURE_NUM], int* x, int* y, int *z) {
    int X = 0, Y = 0, Z = 0;
    static int i;
    static int mouseX, mouseY;

    GetMousePoint(&mouseX, &mouseY);
    //if Y-point over figure's-area , not fill
    if (mouseY < LINE_START_Y - (LINE_ROW_H * 4) || //over top area
        (mouseY > LINE_START_Y && mouseY < LINE_START_Y + FIGURE_INTERVAL * 1 - (LINE_ROW_H * (LINE_NUM - 1))) || // between top area and second area
            (mouseY > LINE_START_Y + FIGURE_INTERVAL * 1 && mouseY < LINE_START_Y + FIGURE_INTERVAL * 2 - (LINE_ROW_H * (LINE_NUM - 1))) || // between second area and third area
                (mouseY > LINE_START_Y + FIGURE_INTERVAL * 2 && mouseY < LINE_START_Y + FIGURE_INTERVAL * 3 - (LINE_ROW_H * (LINE_NUM - 1))) || // between third area and four area
                    mouseY > LINE_START_Y + FIGURE_INTERVAL * 3) return false; //under four area

    for (i = 0; i < FIGURE_NUM; i++) { //decide Z-point
        if (mouseY < LINE_START_Y + i * FIGURE_INTERVAL && mouseY > LINE_START_Y + i * FIGURE_INTERVAL - (LINE_ROW_H * (LINE_NUM - 1))) Z = i;
    }
    Y = (LINE_START_Y + FIGURE_INTERVAL * Z - mouseY) / LINE_ROW_H; //decide Y-point
    //if X-point over figure's-area , not fill
    if (mouseX < LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H) || mouseX > LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H) + LINE_COL_W * (LINE_NUM - 1) + (LINE_COL_W - LINE_ROW_H)) {
        return false;
    }
    X = (mouseX - (LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H))) / LINE_COL_W; //decide X-point
    if (LINE_START_X + LINE_COL_W * X + Y * (LINE_COL_W - LINE_ROW_H) <= mouseX && mouseX <= LINE_START_X + LINE_COL_W * X + (LINE_COL_W - LINE_ROW_H) + Y * (LINE_COL_W - LINE_ROW_H) //digonal area check
        && (float)(mouseX - (LINE_START_X + LINE_COL_W * X + Y * (LINE_COL_W - LINE_ROW_H))) * ((float)LINE_ROW_H / (float)(LINE_COL_W - LINE_ROW_H))
            <= (float)(LINE_START_Y + FIGURE_INTERVAL * Z - (Y * LINE_ROW_H)) - mouseY) X--;

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

    if (X >= 0 && X <= 3 && Y >= 0 && Y <= 3 && Z >= 0 && Z <= 3 && puzzle[Z][Y][X] == 0) {
        * x = X;
        * y = Y;
        * z = Z;
        return true; //if can put ,return true
    }
    else {
        return false;    
    }
}
