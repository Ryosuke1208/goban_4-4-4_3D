//************************************************
// その時点でリーチになっている本数を数える
// 殴り書き ひどい
//************************************************
#include "define.h"

int isReach(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum) {
	int x, y, z;
	int cnt1, cnt2;
	int reach = 0;
	for (x = FIGURE_NUM - 1; x >= 0; x--) {
		for (y = 0; y < FIGURE_NUM; y++) {// 一面ごとを平面に見たときの横線のチェック 16通り
			cnt1 = 0;
			cnt2 = 0;
			if (puzzle[x][y][0] == playerNum) cnt1++;
			if (puzzle[x][y][1] == playerNum) cnt1++;
			if (puzzle[x][y][2] == playerNum) cnt1++;
			if (puzzle[x][y][3] == playerNum) cnt1++;
			if (puzzle[x][y][0] == OK) cnt2++;
			if (puzzle[x][y][1] == OK) cnt2++;
			if (puzzle[x][y][2] == OK) cnt2++;
			if (puzzle[x][y][3] == OK) cnt2++;
			if (cnt1 == 3 && cnt2 == 1) reach++;
		}
	}
	for (x = FIGURE_NUM - 1; x >= 0; x--) {
		for (z = 0; z < FIGURE_NUM; z++) {// 一面ごとを平面に見たときの縦線のチェック 16通り
			cnt1 = 0;
			cnt2 = 0;
			if (puzzle[x][0][z] == playerNum) cnt1++;
			if (puzzle[x][1][z] == playerNum) cnt1++;
			if (puzzle[x][2][z] == playerNum) cnt1++;
			if (puzzle[x][3][z] == playerNum) cnt1++;
			if (puzzle[x][0][z] == OK) cnt2++;
			if (puzzle[x][1][z] == OK) cnt2++;
			if (puzzle[x][2][z] == OK) cnt2++;
			if (puzzle[x][3][z] == OK) cnt2++;
			if (cnt1 == 3 && cnt2 == 1) reach++;
		}
	}
	for (x = FIGURE_NUM - 1; x >= 0; x--) {// 一面ごとを平面に見たときの左下から右上へのななめ線のチェック 4通り
		cnt1 = 0;
		cnt2 = 0;
		if (puzzle[x][0][0] == playerNum) cnt1++;
		if (puzzle[x][1][1] == playerNum) cnt1++;
		if (puzzle[x][2][2] == playerNum) cnt1++;
		if (puzzle[x][3][3] == playerNum) cnt1++;
		if (puzzle[x][0][0] == OK) cnt2++;
		if (puzzle[x][1][1] == OK) cnt2++;
		if (puzzle[x][2][2] == OK) cnt2++;
		if (puzzle[x][3][3] == OK) cnt2++;
		if (cnt1 == 3 && cnt2 == 1) reach++;
	}
	for (x = FIGURE_NUM - 1; x >= 0; x--) {// 一面ごとを平面に見たときの左上から右下へななめ線のチェック 4通り
		cnt1 = 0;
		cnt2 = 0;
		if (puzzle[x][3][0] == playerNum) cnt1++;
		if (puzzle[x][2][1] == playerNum) cnt1++;
		if (puzzle[x][1][2] == playerNum) cnt1++;
		if (puzzle[x][0][3] == playerNum) cnt1++;
		if (puzzle[x][3][0] == OK) cnt2++;
		if (puzzle[x][2][1] == OK) cnt2++;
		if (puzzle[x][1][2] == OK) cnt2++;
		if (puzzle[x][0][3] == OK) cnt2++;
		if (cnt1 == 3 && cnt2 == 1) reach++;
	}
	for (y = 0; y < FIGURE_NUM; y++) {// 四面を立体に見たときの横軸の左上から右下へななめ線のチェック 4通り
		cnt1 = 0;
		cnt2 = 0;
		if (puzzle[0][y][0] == playerNum) cnt1++;
		if (puzzle[1][y][1] == playerNum) cnt1++;
		if (puzzle[2][y][2] == playerNum) cnt1++;
		if (puzzle[3][y][3] == playerNum) cnt1++;
		if (puzzle[0][y][0] == OK) cnt2++;
		if (puzzle[1][y][1] == OK) cnt2++;
		if (puzzle[2][y][2] == OK) cnt2++;
		if (puzzle[3][y][3] == OK) cnt2++;
		if (cnt1 == 3 && cnt2 == 1) reach++;
	}
	for (y = 0; y < FIGURE_NUM; y++) {// 四面を立体に見たときの横軸の右上から左下へななめ線のチェック 4通り
		cnt1 = 0;
		cnt2 = 0;
		if (puzzle[0][y][3] == playerNum) cnt1++;
		if (puzzle[1][y][2] == playerNum) cnt1++;
		if (puzzle[2][y][1] == playerNum) cnt1++;
		if (puzzle[3][y][0] == playerNum) cnt1++;
		if (puzzle[0][y][3] == OK) cnt2++;
		if (puzzle[1][y][2] == OK) cnt2++;
		if (puzzle[2][y][1] == OK) cnt2++;
		if (puzzle[3][y][0] == OK) cnt2++;
		if (cnt1 == 3 && cnt2 == 1) reach++;
	}
	for (z = 0; z < FIGURE_NUM; z++) {// 四面を立体に見たときの縦軸の手前から奥へななめ線のチェック 4通り
		cnt1 = 0;
		cnt2 = 0;
		if (puzzle[0][0][z] == playerNum) cnt1++;
		if (puzzle[1][1][z] == playerNum) cnt1++;
		if (puzzle[2][2][z] == playerNum) cnt1++;
		if (puzzle[3][3][z] == playerNum) cnt1++;
		if (puzzle[0][0][z] == OK) cnt2++;
		if (puzzle[1][1][z] == OK) cnt2++;
		if (puzzle[2][2][z] == OK) cnt2++;
		if (puzzle[3][3][z] == OK) cnt2++;
		if (cnt1 == 3 && cnt2 == 1) reach++;
	}
	for (z = 0; z < FIGURE_NUM; z++) {// 四面を立体に見たときの縦軸の奥から手前へななめ線のチェック 4通り
		cnt1 = 0;
		cnt2 = 0;
		if (puzzle[0][3][z] == playerNum) cnt1++;
		if (puzzle[1][2][z] == playerNum) cnt1++;
		if (puzzle[2][1][z] == playerNum) cnt1++;
		if (puzzle[3][0][z] == playerNum) cnt1++;
		if (puzzle[0][3][z] == OK) cnt2++;
		if (puzzle[1][2][z] == OK) cnt2++;
		if (puzzle[2][1][z] == OK) cnt2++;
		if (puzzle[3][0][z] == OK) cnt2++;
		if (cnt1 == 3 && cnt2 == 1) reach++;
	}
	for (y = 0; y < FIGURE_NUM; y++) {
		for (z = 0; z < FIGURE_NUM; z++) {// 四面を立体に見たときの高さの縦のチェック 16通り
			cnt1 = 0;
			cnt2 = 0;
			if (puzzle[0][y][z] == playerNum) cnt1++;
			if (puzzle[1][y][z] == playerNum) cnt1++;
			if (puzzle[2][y][z] == playerNum) cnt1++;
			if (puzzle[3][y][z] == playerNum) cnt1++;
			if (puzzle[0][y][z] == OK) cnt2++;
			if (puzzle[1][y][z] == OK) cnt2++;
			if (puzzle[2][y][z] == OK) cnt2++;
			if (puzzle[3][y][z] == OK) cnt2++;
			if (cnt1 == 3 && cnt2 == 1) reach++;
		}
	}
	// 立体的な視点での斜めのチェック
	cnt1 = 0;
	cnt2 = 0;
	if (puzzle[0][0][0] == playerNum) cnt1++;
	if (puzzle[1][1][1] == playerNum) cnt1++;
	if (puzzle[2][2][2] == playerNum) cnt1++;
	if (puzzle[3][3][3] == playerNum) cnt1++;
	if (puzzle[0][0][0] == OK) cnt2++;
	if (puzzle[1][1][1] == OK) cnt2++;
	if (puzzle[2][2][2] == OK) cnt2++;
	if (puzzle[3][3][3] == OK) cnt2++;
	if (cnt1 == 3 && cnt2 == 1) reach++;

	cnt1 = 0;
	cnt2 = 0;
	if (puzzle[0][3][3] == playerNum) cnt1++;
	if (puzzle[1][2][2] == playerNum) cnt1++;
	if (puzzle[2][1][1] == playerNum) cnt1++;
	if (puzzle[3][0][0] == playerNum) cnt1++;
	if (puzzle[0][3][3] == OK) cnt2++;
	if (puzzle[1][2][2] == OK) cnt2++;
	if (puzzle[2][1][1] == OK) cnt2++;
	if (puzzle[3][0][0] == OK) cnt2++;
	if (cnt1 == 3 && cnt2 == 1) reach++;

	cnt1 = 0;
	cnt2 = 0;
	if (puzzle[0][3][0] == playerNum) cnt1++;
	if (puzzle[1][2][1] == playerNum) cnt1++;
	if (puzzle[2][1][2] == playerNum) cnt1++;
	if (puzzle[3][0][3] == playerNum) cnt1++;
	if (puzzle[0][3][0] == OK) cnt2++;
	if (puzzle[1][2][1] == OK) cnt2++;
	if (puzzle[2][1][2] == OK) cnt2++;
	if (puzzle[3][0][3] == OK) cnt2++;
	if (cnt1 == 3 && cnt2 == 1) reach++;

	cnt1 = 0;
	cnt2 = 0;
	if (puzzle[0][0][3] == playerNum) cnt1++;
	if (puzzle[1][1][2] == playerNum) cnt1++;
	if (puzzle[2][2][1] == playerNum) cnt1++;
	if (puzzle[3][3][0] == playerNum) cnt1++;
	if (puzzle[0][0][3] == OK) cnt2++;
	if (puzzle[1][1][2] == OK) cnt2++;
	if (puzzle[2][2][1] == OK) cnt2++;
	if (puzzle[3][3][0] == OK) cnt2++;
	if (cnt1 == 3 && cnt2 == 1) reach++;

	return reach;
}