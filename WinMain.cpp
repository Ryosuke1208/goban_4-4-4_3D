#include "DxLib.h"
#include "define.h"
// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) 
{
	if (DxLib_Init() == -1)	return -1; //エラー起きたら終了	

	SetBackgroundColor(241, 237, 238);
	SetGraphMode(800, 800, 32);
	ChangeWindowMode(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
    SetMouseDispFlag(TRUE);

    int x, y;
    unsigned int Cr;
    int mouseX, mouseY;
    int triangleX, triangleY;
    //************************************************
    //ゲーム画面
    //************************************************
    while (1) {
        ClearDrawScreen();
        Cr = GetColor(61, 84, 103);
        //************************************************
        //図形の作成
        //************************************************
        for (x = 0; x < FIGURE_NUM; x++) {// 縦4つ作成
            for (y = 0; y < LINE_NUM; y++) {// 横の線 一面の作成
                DrawLineAA(LINE_START_X + y * (LINE_COL_W - LINE_ROW_H), LINE_START_Y + y * -LINE_ROW_H + x * FIGURE_INTERVAL, LINE_START_X + (LINE_COL_W * (LINE_NUM - 1)) + y * (LINE_COL_W - LINE_ROW_H), LINE_START_Y + y * -LINE_ROW_H + x * FIGURE_INTERVAL, Cr);
            }
            for (y = 0; y < LINE_NUM; y++) {// 縦の線 一面の作成
                DrawLineAA(LINE_START_X + y * LINE_COL_W, LINE_START_Y + x * FIGURE_INTERVAL, LINE_START_X + (LINE_COL_W - LINE_ROW_H) * (LINE_NUM - 1) + y * LINE_COL_W, LINE_START_Y + (LINE_NUM - 1) * -LINE_ROW_H + x * FIGURE_INTERVAL, Cr);
            }
        }
        Cr = GetColor(209, 204, 220);
        //************************************************
        //図形上のXYZ座標の取得
        //************************************************
        GetMousePoint(&mouseX, &mouseY);

        DrawFormatString(0, 0, Cr, "座標Ｘ %d　　座標Ｙ %d", mouseX, mouseY);

        int X, Y, Z = 0;
        for (int i = 0; i < FIGURE_NUM; i++) {
            if (mouseY < LINE_START_Y + i * FIGURE_INTERVAL && mouseY > LINE_START_Y + i * FIGURE_INTERVAL - (LINE_ROW_H * (LINE_NUM - 1))) Z = i;
        }
        Y = (LINE_START_Y + FIGURE_INTERVAL * Z - mouseY) / LINE_ROW_H;
        X = (mouseX - (LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H))) / LINE_COL_W;
        if (LINE_START_X + LINE_COL_W * X + Y * (LINE_COL_W - LINE_ROW_H) < mouseX && mouseX < LINE_START_X + LINE_COL_W * X + (LINE_COL_W - LINE_ROW_H) + Y * (LINE_COL_W - LINE_ROW_H) 
            && (float)(mouseX - (LINE_START_X + LINE_COL_W * X + Y * (LINE_COL_W - LINE_ROW_H))) * 0.6f < (LINE_START_Y + FIGURE_INTERVAL * Z - (Y * LINE_ROW_H)) - mouseY) X--;

        DrawFormatString(0, 30, Cr, "Ｘ %d　　Ｙ %d　　Ｚ %d", X, Y, Z);

        //************************************************
        //図形上のXYZ座標の左下の座標の取得
        //************************************************
        triangleX = LINE_START_X + (LINE_COL_W * X) + ((LINE_COL_W - LINE_ROW_H) * Y);
        triangleY = LINE_START_Y + (-LINE_ROW_H * Y) + FIGURE_INTERVAL * Z;

        DrawFormatString(0, 60, Cr, "triangleX %d　　triangleY %d", triangleX, triangleY);

        //triangleX += TRIANGLE_GAP;
        //triangleY -= TRIANGLE_GAP;
        //左下、上、右下
        DrawTriangleAA(triangleX + 5, triangleY, triangleX + (LINE_COL_W - LINE_ROW_H), triangleY - LINE_ROW_H + 3,
            triangleX + LINE_COL_W - 3, triangleY, Cr, TRUE);
        //右上、左上、下
        DrawTriangleAA(triangleX + LINE_COL_W + (LINE_COL_W - LINE_ROW_H) - 1, triangleY - LINE_ROW_H + 1, triangleX + (LINE_COL_W - LINE_ROW_H), triangleY - LINE_ROW_H + 3,
            triangleX + LINE_COL_W - 5, triangleY, Cr, TRUE);

        ScreenFlip();
            //if (CheckHitKey(KEY_INPUT_RETURN)) break;
        //}
        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }
    /*for (x = 0; x < 4; x++) {
        for (y = 0; y < 8; y++) {
            DrawLineAA(line[y][0], (float)(line[y][1] + 150 * x), line[y][2], (float)(line[y][3] + 150 * x), Cr);
        }
    }*/
	//WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}