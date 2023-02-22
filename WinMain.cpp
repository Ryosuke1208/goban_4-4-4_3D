#include "define.h"

void PvP();
void PvC();

// Program start with WinMain
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    if (DxLib_Init() == -1)	return -1; //when error occurs, finish

    SetBackgroundColor(241, 237, 238);
    SetGraphMode(800, 800, 32);
    ChangeWindowMode(TRUE);
    SetDrawScreen(DX_SCREEN_BACK);
    SetMouseDispFlag(TRUE);

    
    //************************************************
    //game proc
    //************************************************
    PvC();

	DxLib_End(); // finish DxLib

	return 0;
}

