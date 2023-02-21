//************************************************
//check Bingo or not proc
//************************************************
#include "define.h"

int isDone(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum) {
	static int x, y, z;
	static int cnt = 0;

	for (x = FIGURE_NUM - 1; x >= 0; x--) {
		for (y = 0; y < FIGURE_NUM; y++) { //check horizonal line on one board
			if (puzzle[x][y][0] == playerNum && puzzle[x][y][1] == playerNum &&
				puzzle[x][y][2] == playerNum && puzzle[x][y][3] == playerNum) cnt++;
		}
		for (z = 0; z < FIGURE_NUM; z++) { //check vertical line on one board
			if (puzzle[x][0][z] == playerNum && puzzle[x][1][z] == playerNum &&
				puzzle[x][2][z] == playerNum && puzzle[x][3][z] == playerNum) cnt++;
		}
		
		if (puzzle[x][0][0] == playerNum && puzzle[x][1][1] == playerNum && //check cross line
			puzzle[x][2][2] == playerNum && puzzle[x][3][3] == playerNum) cnt++;
		if (puzzle[x][3][0] == playerNum && puzzle[x][2][1] == playerNum && //check cross line
			puzzle[x][1][2] == playerNum && puzzle[x][0][3] == playerNum) cnt++;
	}

	for (y = 0; y < FIGURE_NUM; y++) { //check horizonal cross line on four board
		if (puzzle[0][y][0] == playerNum && puzzle[1][y][1] == playerNum &&
			puzzle[2][y][2] == playerNum && puzzle[3][y][3] == playerNum) cnt++;
		if (puzzle[0][y][3] == playerNum && puzzle[1][y][2] == playerNum &&
			puzzle[2][y][1] == playerNum && puzzle[3][y][0] == playerNum) cnt++;
	}

	for (z = 0; z < FIGURE_NUM; z++) { //check vertical cross line on four board
		if (puzzle[0][0][z] == playerNum && puzzle[1][1][z] == playerNum &&
			puzzle[2][2][z] == playerNum && puzzle[3][3][z] == playerNum) cnt++;
		if (puzzle[0][3][z] == playerNum && puzzle[1][2][z] == playerNum &&
			puzzle[2][1][z] == playerNum && puzzle[3][0][z] == playerNum) cnt++;
	}

	for (y = 0; y < FIGURE_NUM; y++) {
		for (z = 0; z < FIGURE_NUM; z++) {
			if(puzzle[0][y][z] == playerNum && puzzle[1][y][z] == playerNum &&
				puzzle[2][y][z] == playerNum && puzzle[3][y][z] == playerNum) cnt++;
		}
	}

	if(puzzle[0][0][0] == playerNum && puzzle[1][1][1] == playerNum &&
		puzzle[2][2][2] == playerNum && puzzle[3][3][3] == playerNum) cnt++;;
	if (puzzle[0][3][3] == playerNum && puzzle[1][2][2] == playerNum &&
		puzzle[2][1][1] == playerNum && puzzle[3][0][0] == playerNum) cnt++;;
	if (puzzle[0][3][0] == playerNum && puzzle[1][2][1] == playerNum &&
		puzzle[2][1][2] == playerNum && puzzle[3][0][3] == playerNum) cnt++;;
	if (puzzle[0][0][3] == playerNum && puzzle[1][1][2] == playerNum &&
		puzzle[2][2][1] == playerNum && puzzle[3][3][0] == playerNum) cnt++;;

	return cnt;
}