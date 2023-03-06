#include "define.h"

void showTitle(int*, int*, int*);
void PvP();
void PvC(int, int);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    if (DxLib_Init() == -1)	return -1;
    // DxLibÇÃèâä˙ê›íË
    SetBackgroundColor(241, 237, 238);
    SetGraphMode(800, 800, 32);
    ChangeWindowMode(TRUE);
    SetDrawScreen(DX_SCREEN_BACK);
    SetMouseDispFlag(TRUE);
    int m, d, f;
    //************************************************
    // ÉQÅ[ÉÄÇÃèàóù
    //************************************************
    while (1) {
        showTitle(&m, &d, &f);
        if (m == 0) PvP();
        else if (m == 1) PvC(d, f);
        else break;
    }


	DxLib_End(); 

	return 0;
}

