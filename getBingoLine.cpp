//************************************************
// ビンゴになっているラインを返す
// 後付けでめんどいのでコード適当
//************************************************
#include "define.h"

struct BINGO getBingoLine(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum) {
	int x, y, z;
	struct BINGO bingo = { {-1,-1,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1} };
	for (x = FIGURE_NUM - 1; x >= 0; x--) {
		for (y = 0; y < FIGURE_NUM; y++) {
			if (puzzle[x][y][0] == playerNum && puzzle[x][y][1] == playerNum &&
				puzzle[x][y][2] == playerNum && puzzle[x][y][3] == playerNum) {
				bingo.bingoX[0] = x;
				bingo.bingoX[1] = x;
				bingo.bingoX[2] = x;
				bingo.bingoX[3] = x;
				bingo.bingoY[0] = y;
				bingo.bingoY[1] = y;
				bingo.bingoY[2] = y;
				bingo.bingoY[3] = y;
				bingo.bingoZ[0] = 0;
				bingo.bingoZ[1] = 1;
				bingo.bingoZ[2] = 2;
				bingo.bingoZ[3] = 3;
				return bingo;
			}
		}
		for (z = 0; z < FIGURE_NUM; z++) {
			if (puzzle[x][0][z] == playerNum && puzzle[x][1][z] == playerNum &&
				puzzle[x][2][z] == playerNum && puzzle[x][3][z] == playerNum) {
				bingo.bingoX[0] = x;
				bingo.bingoX[1] = x;
				bingo.bingoX[2] = x;
				bingo.bingoX[3] = x;
				bingo.bingoY[0] = 0;
				bingo.bingoY[1] = 1;
				bingo.bingoY[2] = 2;
				bingo.bingoY[3] = 3;
				bingo.bingoZ[0] = z;
				bingo.bingoZ[1] = z;
				bingo.bingoZ[2] = z;
				bingo.bingoZ[3] = z;
				return bingo;
			}
		}
		if (puzzle[x][0][0] == playerNum && puzzle[x][1][1] == playerNum &&
			puzzle[x][2][2] == playerNum && puzzle[x][3][3] == playerNum) {
			bingo.bingoX[0] = x;
			bingo.bingoX[1] = x;
			bingo.bingoX[2] = x;
			bingo.bingoX[3] = x;
			bingo.bingoY[0] = 0;
			bingo.bingoY[1] = 1;
			bingo.bingoY[2] = 2;
			bingo.bingoY[3] = 3;
			bingo.bingoZ[0] = 0;
			bingo.bingoZ[1] = 1;
			bingo.bingoZ[2] = 2;
			bingo.bingoZ[3] = 3;
			return bingo;
		}
		if (puzzle[x][3][0] == playerNum && puzzle[x][2][1] == playerNum &&
			puzzle[x][1][2] == playerNum && puzzle[x][0][3] == playerNum) {
			bingo.bingoX[0] = x;
			bingo.bingoX[1] = x;
			bingo.bingoX[2] = x;
			bingo.bingoX[3] = x;
			bingo.bingoY[0] = 3;
			bingo.bingoY[1] = 2;
			bingo.bingoY[2] = 1;
			bingo.bingoY[3] = 0;
			bingo.bingoZ[0] = 0;
			bingo.bingoZ[1] = 1;
			bingo.bingoZ[2] = 2;
			bingo.bingoZ[3] = 3;
			return bingo;
		}
	}
	for (y = 0; y < FIGURE_NUM; y++) {
		if (puzzle[0][y][0] == playerNum && puzzle[1][y][1] == playerNum &&
			puzzle[2][y][2] == playerNum && puzzle[3][y][3] == playerNum) {
			bingo.bingoX[0] = 0;
			bingo.bingoX[1] = 1;
			bingo.bingoX[2] = 2;
			bingo.bingoX[3] = 3;
			bingo.bingoY[0] = y;
			bingo.bingoY[1] = y;
			bingo.bingoY[2] = y;
			bingo.bingoY[3] = y;
			bingo.bingoZ[0] = 0;
			bingo.bingoZ[1] = 1;
			bingo.bingoZ[2] = 2;
			bingo.bingoZ[3] = 3;
			return bingo;
		}
		if (puzzle[0][y][3] == playerNum && puzzle[1][y][2] == playerNum &&
			puzzle[2][y][1] == playerNum && puzzle[3][y][0] == playerNum) {
			bingo.bingoX[0] = 0;
			bingo.bingoX[1] = 1;
			bingo.bingoX[2] = 2;
			bingo.bingoX[3] = 3;
			bingo.bingoY[0] = y;
			bingo.bingoY[1] = y;
			bingo.bingoY[2] = y;
			bingo.bingoY[3] = y;
			bingo.bingoZ[0] = 3;
			bingo.bingoZ[1] = 2;
			bingo.bingoZ[2] = 1;
			bingo.bingoZ[3] = 0;
			return bingo;
		}
	}
	for (z = 0; z < FIGURE_NUM; z++) {
		if (puzzle[0][0][z] == playerNum && puzzle[1][1][z] == playerNum &&
			puzzle[2][2][z] == playerNum && puzzle[3][3][z] == playerNum) {
			bingo.bingoX[0] = 0;
			bingo.bingoX[1] = 1;
			bingo.bingoX[2] = 2;
			bingo.bingoX[3] = 3;
			bingo.bingoY[0] = 0;
			bingo.bingoY[1] = 1;
			bingo.bingoY[2] = 2;
			bingo.bingoY[3] = 3;
			bingo.bingoZ[0] = z;
			bingo.bingoZ[1] = z;
			bingo.bingoZ[2] = z;
			bingo.bingoZ[3] = z;
			return bingo;
		}
		if (puzzle[0][3][z] == playerNum && puzzle[1][2][z] == playerNum &&
			puzzle[2][1][z] == playerNum && puzzle[3][0][z] == playerNum) {
			bingo.bingoX[0] = 0;
			bingo.bingoX[1] = 1;
			bingo.bingoX[2] = 2;
			bingo.bingoX[3] = 3;
			bingo.bingoY[0] = 3;
			bingo.bingoY[1] = 2;
			bingo.bingoY[2] = 1;
			bingo.bingoY[3] = 0;
			bingo.bingoZ[0] = z;
			bingo.bingoZ[1] = z;
			bingo.bingoZ[2] = z;
			bingo.bingoZ[3] = z;
			return bingo;
		}
	}
	for (y = 0; y < FIGURE_NUM; y++) {
		for (z = 0; z < FIGURE_NUM; z++) {
			if (puzzle[0][y][z] == playerNum && puzzle[1][y][z] == playerNum &&
				puzzle[2][y][z] == playerNum && puzzle[3][y][z] == playerNum) {
				bingo.bingoX[0] = 0;
				bingo.bingoX[1] = 1;
				bingo.bingoX[2] = 2;
				bingo.bingoX[3] = 3;
				bingo.bingoY[0] = y;
				bingo.bingoY[1] = y;
				bingo.bingoY[2] = y;
				bingo.bingoY[3] = y;
				bingo.bingoZ[0] = z;
				bingo.bingoZ[1] = z;
				bingo.bingoZ[2] = z;
				bingo.bingoZ[3] = z;
				return bingo;
			}
		}
	}
	// 立体的な視点での斜めのチェック
	if (puzzle[0][0][0] == playerNum && puzzle[1][1][1] == playerNum &&
		puzzle[2][2][2] == playerNum && puzzle[3][3][3] == playerNum) {
		bingo.bingoX[0] = 0;
		bingo.bingoX[1] = 1;
		bingo.bingoX[2] = 2;
		bingo.bingoX[3] = 3;
		bingo.bingoY[0] = 0;
		bingo.bingoY[1] = 1;
		bingo.bingoY[2] = 2;
		bingo.bingoY[3] = 3;
		bingo.bingoZ[0] = 0;
		bingo.bingoZ[1] = 1;
		bingo.bingoZ[2] = 2;
		bingo.bingoZ[3] = 3;
		return bingo;
	}
	if (puzzle[0][3][3] == playerNum && puzzle[1][2][2] == playerNum &&
		puzzle[2][1][1] == playerNum && puzzle[3][0][0] == playerNum) {
		bingo.bingoX[0] = 0;
		bingo.bingoX[1] = 1;
		bingo.bingoX[2] = 2;
		bingo.bingoX[3] = 3;
		bingo.bingoY[0] = 3;
		bingo.bingoY[1] = 2;
		bingo.bingoY[2] = 1;
		bingo.bingoY[3] = 0;
		bingo.bingoZ[0] = 3;
		bingo.bingoZ[1] = 2;
		bingo.bingoZ[2] = 1;
		bingo.bingoZ[3] = 0;
		return bingo;
	}
	if (puzzle[0][3][0] == playerNum && puzzle[1][2][1] == playerNum &&
		puzzle[2][1][2] == playerNum && puzzle[3][0][3] == playerNum) {
		bingo.bingoX[0] = 0;
		bingo.bingoX[1] = 1;
		bingo.bingoX[2] = 2;
		bingo.bingoX[3] = 3;
		bingo.bingoY[0] = 3;
		bingo.bingoY[1] = 2;
		bingo.bingoY[2] = 1;
		bingo.bingoY[3] = 0;
		bingo.bingoZ[0] = 0;
		bingo.bingoZ[1] = 1;
		bingo.bingoZ[2] = 2;
		bingo.bingoZ[3] = 3;
		return bingo;

	}
	if (puzzle[0][0][3] == playerNum && puzzle[1][1][2] == playerNum &&
		puzzle[2][2][1] == playerNum && puzzle[3][3][0] == playerNum) {
		bingo.bingoX[0] = 0;
		bingo.bingoX[1] = 1;
		bingo.bingoX[2] = 2;
		bingo.bingoX[3] = 3;
		bingo.bingoY[0] = 0;
		bingo.bingoY[1] = 1;
		bingo.bingoY[2] = 2;
		bingo.bingoY[3] = 3;
		bingo.bingoZ[0] = 3;
		bingo.bingoZ[1] = 2;
		bingo.bingoZ[2] = 1;
		bingo.bingoZ[3] = 0;
		return bingo;
	}
	return bingo;
}