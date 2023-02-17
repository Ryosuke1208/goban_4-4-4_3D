#define DEBUG_ON

#include "define.h"

void fill(int, int, int, int);
void makeFigure(int [][FIGURE_NUM][FIGURE_NUM]);
int getMouseXYZ(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);

// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) 
{
	if (DxLib_Init() == -1)	return -1; //エラー起きたら終了	

	SetBackgroundColor(241, 237, 238);
	SetGraphMode(800, 800, 32);
	ChangeWindowMode(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
    SetMouseDispFlag(TRUE);

    int x, y, z;
    int canPutFlag; //プレイヤーがおける箇所かどうかのフラグ
    int i, j, k;
    //起点は一番上の図形の左下、X軸(右方向)がx、Y軸(奥の方向)がx,縦軸がz
    int puzzle[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{-1,-1,0,-1},{-1,-1,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1}},
        {{-1,-1,-1,-1},{-1,-1,-1,0},{-1,-1,0,-1},{0,-1,-1,-1}},
        {{-1,0,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1},{0,-1,-1,-1}},
        //{{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}}
        {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}
    };
    //************************************************
    //ゲーム画面
    //************************************************
    while (1) {
        ClearDrawScreen();   
        canPutFlag = 0;
        makeFigure(puzzle);
        //************************************************
        //プレイヤー側の処理
        //************************************************
        canPutFlag = getMouseXYZ(puzzle, &x, &y, &z); //マウスでXYZ座標の読み取り
        if (canPutFlag) {
            fill(x, y, z, 1);
            if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 1) {
                puzzle[z][y][x] = 1;
            }
        }
        //************************************************

        ScreenFlip();

        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}