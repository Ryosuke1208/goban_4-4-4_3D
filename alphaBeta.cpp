//************************************************
//alpha beta algorythum
//************************************************
#include "define.h"

int alphaBeta(int board[][FIGURE_NUM][FIGURE_NUM], int depth, int alpha, int beta, int player) {
	static int i, j, k;
	static int score;
	if (depth == 0) {
		//return evaluate(board, player);
	}
	for (i = 0; i < FIGURE_NUM; i++) {
		for (j = 0; j < FIGURE_NUM; j++) {
			for (k = 0; k < FIGURE_NUM; k++) {
				if (board[i][j][k] == OK) {
					board[i][j][k] = player;
					if (i > 0) board[i - 1][j][k] = OK;
					score = -alphaBeta(board, depth - 1, -beta, -alpha, (player % 2) + 1);
					if (i > 0) board[i - 1][j][k] = NG;
					board[i][j][k] = OK;
					if (score > alpha) {
						alpha = score;
					}
					if (alpha >= beta) {
						return alpha;
					}
				}
			}
		}
	}
	return alpha;
}