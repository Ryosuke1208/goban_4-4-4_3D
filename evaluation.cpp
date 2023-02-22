//************************************************
//evaluate
//************************************************
#include "define.h"

int isDone(int board[][FIGURE_NUM][FIGURE_NUM], int);

int evaluate(int board[][FIGURE_NUM][FIGURE_NUM], int player) {
	int count = 0;
	count = isDone(board, player);
	if (count) {
		return count * 10000000;
	}
	else {
		return 100;
	}
}