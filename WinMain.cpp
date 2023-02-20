#include "define.h"

void fill(int, int, int, int);
void makeFigure(int [][FIGURE_NUM][FIGURE_NUM]);
boolean playerCanPut(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
boolean isDone(int puzzle[][FIGURE_NUM][FIGURE_NUM], int);
int checkBingo(int[][FIGURE_NUM][FIGURE_NUM], int, int, int, int);

// Program start with WinMain
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) 
{
	if (DxLib_Init() == -1)	return -1; //when error occurs, finish

	SetBackgroundColor(241, 237, 238);
	SetGraphMode(800, 800, 32);
	ChangeWindowMode(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
    SetMouseDispFlag(TRUE);

    int x, y, z;
    int playerNum = 0;
    int puzzle[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK}}
    };
    //************************************************
    //game proc
    //************************************************
    while (1) {
        ClearDrawScreen();   
        //make figure
        makeFigure(puzzle);

        /**********************player vs player***********************/
        //player proc
        if (playerCanPut(puzzle, &x, &y, &z)) { //scan Mouse-XYZ-point and player can put, return true
            fill(x, y, z, (playerNum % 2) + 1); //1 → P1, 2 → P2
            if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 1) {
                puzzle[x][y][z] = (playerNum % 2) + 1; //left-click on, change status to player

                if (x > 0)puzzle[x - 1][y][z] = 0;
                //if (checkBingo(puzzle, x, y, z, (playerNum % 2) + 1)) break;
                if (x > 0) puzzle[x - 1][y][z] = OK;
                if (isDone(puzzle, (playerNum % 2) + 1)) break;

                playerNum++;
            }
        }
        /************************************************************/
        ScreenFlip();

        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }

    printfDx("プレイヤー%dの勝利です。", playerNum);

	DxLib_End(); // finish DxLib

	return 0;
}