//************************************************
// タイトル表示
// 画像使いたくないので適当
//************************************************
#include "define.h"

void showTitle(int *m, int *d, int *f) {
	unsigned int Cr = GetColor(255, 255, 153);
	int fontHandle1, fontHandle2, fontHandle3;
	int mode = 0, difficulty = 0, first = 0;
	int mouseX, mouseY;
	fontHandle1 = CreateFontToHandle(NULL, 100, 1, DX_FONTTYPE_ANTIALIASING);
	fontHandle2 = CreateFontToHandle(NULL, 30, 1, DX_FONTTYPE_ANTIALIASING);
	fontHandle3 = CreateFontToHandle(NULL, 50, 1, DX_FONTTYPE_ANTIALIASING);
	while (1) {
		ClearDrawScreen();

		GetMousePoint(&mouseX, &mouseY);
		DrawStringToHandle(55, 50, "3D FOUR SCORE", BLACK, fontHandle1);
		DrawLineAA(0.0f, 200.0f, 800.0f, 200.0f, BLACK);
		DrawStringToHandle(55, 220, "ルール説明", BLACK, fontHandle2);
		DrawStringToHandle(55, 250, "・縦、横、斜めで4つマスが揃えば勝ち", BLACK, fontHandle2);
		DrawStringToHandle(55, 280, "・初めは一番下しか置けない", BLACK, fontHandle2);
		DrawStringToHandle(55, 310, "・マスを埋めると上のマスが置けるようになる", BLACK, fontHandle2);
		DrawLineAA(0.0f, 360.0f, 800.0f, 360.0f, BLACK);

		if (mode == 0) DrawBoxAA(5.0f, 365.0f, 395.0f, 445.0f, Cr, TRUE);
		else if (mode == 1) DrawBoxAA(405.0f, 365.0f, 795.0f, 445.0f, Cr, TRUE);

		DrawStringToHandle(35, 380, "VS プレイヤー", BLACK, fontHandle3);
		DrawStringToHandle(485, 380, "VS ＣＰＵ", BLACK, fontHandle3);
		DrawLineAA(400.0f, 360.0f, 400.0f, 450.0f, BLACK);
		DrawLineAA(0.0f, 450.0f, 800.0f, 450.0f, BLACK);
		DrawStringToHandle(50, 470, "難易度", BLACK, fontHandle3);
		DrawLineAA(260.0f, 450.0f, 260.0f, 540.0f, BLACK);

		if (mode == 1) {
			if (difficulty == 0) DrawBoxAA(265.0f, 455.0f, 435.0f, 535.0f, Cr, TRUE);
			else if (difficulty == 1) DrawBoxAA(445.0f, 455.0f, 615.0f, 535.0f, Cr, TRUE);
			else if (difficulty == 2) DrawBoxAA(625.0f, 455.0f, 795.0f, 535.0f, Cr, TRUE);
		}

		DrawStringToHandle(300, 470, "弱い", BLACK, fontHandle3);
		DrawLineAA(440.0f, 450.0f, 440.0f, 540.0f, BLACK);
		DrawStringToHandle(480, 470, "普通", BLACK, fontHandle3);
		DrawLineAA(620.0f, 450.0f, 620.0f, 540.0f, BLACK);
		DrawStringToHandle(660, 470, "強い", BLACK, fontHandle3);
		DrawLineAA(0.0f, 540.0f, 800.0f, 540.0f, BLACK);

		if (mode == 1) {
			if (first == 0) DrawBoxAA(5.0f, 545.0f, 395.0f, 625.0f, Cr, TRUE);
			else if (first == 1) DrawBoxAA(405.0f, 545.0f, 795.0f, 625.0f, Cr, TRUE);
		}

		DrawStringToHandle(120, 560, "先　行", BLACK, fontHandle3);
		DrawLineAA(400.0f, 540.0f, 400.0f, 630.0f, BLACK);
		DrawStringToHandle(520, 560, "後　行", BLACK, fontHandle3);
		DrawLineAA(0.0f, 630.0f, 800.0f, 630.0f, BLACK);
		
		if (mouseX > 0 && mouseX < 800 && mouseY > 630 && mouseY < 800) {
			DrawBoxAA(5.0f, 635.0f, 795.0f, 795.0f, LIGHT_RED, TRUE);
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
				*m = mode;
				*d = difficulty;
				*f = first;
				break;
			}
		}
		DrawStringToHandle(270, 670, "START", BLACK, fontHandle1);


		if (mouseX > 0 && mouseX < 400 && mouseY > 360 && mouseY < 450 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0 ) mode = 0;
		if (mouseX > 400 && mouseX < 800 && mouseY > 360 && mouseY < 450 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) mode = 1;
	
		if (mouseX > 260 && mouseX < 440 && mouseY > 450 && mouseY < 540 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) difficulty = 0;
		if (mouseX > 440 && mouseX < 620 && mouseY > 450 && mouseY < 540 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) difficulty = 1;
		if (mouseX > 620 && mouseX < 800 && mouseY > 450 && mouseY < 540 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) difficulty = 2;

		if (mouseX > 0 && mouseX < 400 && mouseY > 540 && mouseY < 630 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) first = 0;
		if (mouseX > 400 && mouseX < 800 && mouseY > 540 && mouseY < 630 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) first = 1;


		ScreenFlip();
	}
}