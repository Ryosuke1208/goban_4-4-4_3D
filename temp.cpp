//************************************************
// ä˙ë“ílåvéZÇÃÉvÉçÉOÉâÉÄ
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
					// óßëÃÇ≈ÇÃèc
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
					// ïΩñ Ç≈ÇÃèc
					for (y = 0; y < 4; y++) {
						if (puzzle[i][y][k] == enemyNumber) {
							tempScore--;
							break;
						}
					}
					// ïΩñ Ç≈ÇÃâ°
					for (z = 0; z < 4; z++) {
						if (puzzle[i][j][z] == enemyNumber) {
							tempScore--;
							break;
						}
					}
					// ç∂â∫Ç©ÇÁâEè„Ç÷ÇÃïΩñ Ç≈ÇÃéŒÇﬂ
					if (j == k) {
						for (z = 0; z < 4; z++) {
							if (puzzle[i][z][z] == enemyNumber) {
								tempScore--;
								break;
							}
						}
						// àÍî‘â∫ÇÃç∂â∫Ç©ÇÁàÍî‘è„âEè„Ç÷ÇÃëŒäpê¸
						if (i + j == 3) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][y] == enemyNumber) {
									tempScore--;
									break;
								}
							}
						}
						// àÍî‘â∫ÇÃâEè„Ç©ÇÁàÍî‘è„ç∂â∫Ç÷ÇÃëŒäpê¸
						if (i == j) {
							for (x = 3; x >= 0; x--) {
								if (puzzle[x][x][x] == enemyNumber) {
									tempScore--;
									break;
								}
							}
						}
					}
					// ç∂è„Ç©ÇÁâEâ∫Ç÷ÇÃïΩñ Ç≈ÇÃéŒÇﬂ
					if (j + k == 3) {
						for (y = 3, z = 0; y >= 0; y--, z++) {
							if (puzzle[i][y][z] == enemyNumber) {
								tempScore--;
								break;
							}
						}
						// àÍî‘â∫ÇÃç∂è„Ç©ÇÁàÍî‘è„ÇÃâEâ∫Ç÷ÇÃëŒäpê¸
						if (i == j) {
							for (x = 3, z = 0; x >= 0; x--, z++) {
								if (puzzle[x][x][z] == enemyNumber) {
									tempScore--;
									break;
								}
							}
						}
						// àÍî‘â∫ÇÃâEâ∫Ç©ÇÁàÍî‘è„ÇÃç∂è„Ç÷ÇÃëŒäpê¸
						if (i == k) {
							for (x = 3, y = 0; x >= 0; x--, y++) {
								if (puzzle[x][y][x] == enemyNumber) {
									tempScore--;
									break;
								}
							}
						}
					}
					// ècïΩñ ÅiÇxé≤ÅjÇ≈ÇÃéŒÇﬂ
					if (i + k == 3) {
						for (x = 0, z = 3; x < 4; x++, z--) {
							if (puzzle[x][j][z] == enemyNumber) {
								tempScore--;
								break;
							}
						}
					}
					// ècïΩñ Ç≈ÇÃéŒÇﬂîΩëŒ
					if (i == k) {
						for (x = 0; x < 4; x++) {
							if (puzzle[x][j][x] == enemyNumber) {
								tempScore--;
								break;
							}
						}
					}
					// âúïΩñ ÅiÇyé≤ÅjÇ≈ÇÃéŒÇﬂ
					if (i + j == 3) {
						for (x = 0, y = 3; x < 4; x++, y--) {
							if (puzzle[x][y][k] == enemyNumber) {
								tempScore--;
								break;
							}
						}
					}
					// âúïΩñ Ç≈ÇÃéŒÇﬂîΩëŒ
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
