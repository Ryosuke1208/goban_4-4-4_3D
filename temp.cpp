//************************************************
// 期待値計算のプログラム
//************************************************
#include "define.h"

void evaluation(int puzzle[][4][4], int value[][4][4], int playerNumber) {
	int i, j, k;
	int x, y, z;
	int tempScore = 0;
	int enemyNumber = 0;
	if (playerNumber == P2) enemyNumber = P1;
	if (playerNumber == P1) enemyNumber = P2;
	int cnt;
	struct TEMP {
		int XYZ1[3][3];

	};
	struct TEMP temp;

	for (i = 3; i >= 0; i--) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				if (puzzle[i][j][k] == OK) {
					tempScore = value[i][j][k];
					// 立体での縦
					cnt = 0;
					for (x = 0; x < 4; x++) {
						if (puzzle[x][j][k] == enemyNumber) {
							cnt++;
						}
						if (puzzle[x][j][k] == playerNumber) {
							break;
						}
						if (cnt >= 2) {
							for (x = 0; x < 4; x++) {
								temp.XYZ1[0][x] = x;
								temp.XYZ1[0][x] = x;
								temp.XYZ1[0][x] = x;
							}
						}
					}
					// 平面での縦
					for (y = 0; y < 4; y++) {
						if (puzzle[i][y][k] == enemyNumber) {
							tempScore--;
							break;
						}
					}
					// 平面での横
					for (z = 0; z < 4; z++) {
						if (puzzle[i][j][z] == enemyNumber) {
							tempScore--;
							break;
						}
					}
					// 左下から右上への平面での斜め
					if (j == k) {
						for (z = 0; z < 4; z++) {
							if (puzzle[i][z][z] == enemyNumber) {
								tempScore--;
								break;
							}
						}
						// 一番下の左下から一番上右上への対角線
						if (i + j == 3) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][y] == enemyNumber) {
									tempScore--;
									break;
								}
							}
						}
						// 一番下の右上から一番上左下への対角線
						if (i == j) {
							for (x = 3; x >= 0; x--) {
								if (puzzle[x][x][x] == enemyNumber) {
									tempScore--;
									break;
								}
							}
						}
					}
					// 左上から右下への平面での斜め
					if (j + k == 3) {
						for (y = 3, z = 0; y >= 0; y--, z++) {
							if (puzzle[i][y][z] == enemyNumber) {
								tempScore--;
								break;
							}
						}
						// 一番下の左上から一番上の右下への対角線
						if (i == j) {
							for (x = 3, z = 0; x >= 0; x--, z++) {
								if (puzzle[x][x][z] == enemyNumber) {
									tempScore--;
									break;
								}
							}
						}
						// 一番下の右下から一番上の左上への対角線
						if (i == k) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][x] == enemyNumber) {
									tempScore--;
									break;
								}
							}
						}
					}
					// 縦平面（Ｙ軸）での斜め
					if (i + k == 3) {
						for (x = 0, z = 3; x < 4; x++, z--) {
							if (puzzle[x][j][z] == enemyNumber) {
								tempScore--;
								break;
							}
						}
					}
					// 縦平面での斜め反対
					if (i == k) {
						for (x = 0; x < 4; x++) {
							if (puzzle[x][j][x] == enemyNumber) {
								tempScore--;
								break;
							}
						}
					}
					// 奥平面（Ｚ軸）での斜め
					if (i + j == 3) {
						for (x = 0, y = 3; x < 4; x++, y--) {
							if (puzzle[x][y][k] == enemyNumber) {
								tempScore--;
								break;
							}
						}
					}
					// 奥平面での斜め反対
					if (i == j) {
						for (x = 0; x < 4; x++) {
							if (puzzle[x][x][k] == enemyNumber) {
								tempScore--;
								break;
							}
						}
					}
					value[i][j][k] = tempScore;
				}
			}
		}
	}
}
