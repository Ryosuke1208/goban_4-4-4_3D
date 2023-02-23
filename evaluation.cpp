//************************************************
//evaluate
//************************************************
#include "define.h"

int isDone(int board[][FIGURE_NUM][FIGURE_NUM], int);

int evaluate(int board[][FIGURE_NUM][FIGURE_NUM], int player) {
	int count = 0;
	count = isDone(board, player) - isDone(board, (player % 2) + 1);
	if (count != 0) {
		return count * 1000000;
	}
	else {
		return -10000000;
	}
}