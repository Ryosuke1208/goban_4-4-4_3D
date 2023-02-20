//************************************************
//check Bingo or not proc
//************************************************
#include "define.h"

boolean isDone(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum) {
	static int i,j,k;
	static int cnt;

	for (i = 0; i < FIGURE_NUM; i++) {
		for (k = FIGURE_NUM - 1; k >= 0; k--) {
			if (puzzle[k][0][i] == playerNum && puzzle[k][1][i] == playerNum &&
				puzzle[k][2][i] == playerNum && puzzle[k][3][i] == playerNum) return true;
		}
	}
	for (j = 0; j < FIGURE_NUM; j++) {
		for (k = FIGURE_NUM - 1; k >= 0; k--) {
			if (puzzle[k][j][0] == playerNum && puzzle[k][j][1] == playerNum &&
				puzzle[k][j][2] == playerNum && puzzle[k][j][3] == playerNum) return true;
		}
	}
	return false;
}