#include "define.h"

void PvP();

// Program start with WinMain
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    if (DxLib_Init() == -1)	return -1; //when error occurs, finish

    SetBackgroundColor(241, 237, 238);
    SetGraphMode(800, 800, 32);
    ChangeWindowMode(TRUE);
    SetDrawScreen(DX_SCREEN_BACK);
    SetMouseDispFlag(TRUE);

    
    //BOARD EVALUATION
    //if cannot find best answer choose by this evaluation
    int value[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}}
    };
    //************************************************
    //game proc
    //************************************************
    PvP();

	DxLib_End(); // finish DxLib

	return 0;
}

