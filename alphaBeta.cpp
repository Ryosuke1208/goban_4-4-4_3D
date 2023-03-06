////************************************************
////alpha beta algorythum
////************************************************
//#include "define.h"
//
//int evaluate(int board[][FIGURE_NUM][FIGURE_NUM], int);
//int isDone(int board[][FIGURE_NUM][FIGURE_NUM], int);
//
//int alphaBeta(int board[][FIGURE_NUM][FIGURE_NUM], int depth, int alpha, int beta, int player) {
//	int i, j, k;
//	int score;
//	if (isDone(board, player) || depth == 0) {
//		return evaluate(board, player);
//	}
//	for (i = 0; i < FIGURE_NUM; i++) {
//		for (j = 0; j < FIGURE_NUM; j++) {
//			for (k = 0; k < FIGURE_NUM; k++) {
//				if (board[i][j][k] == OK) {
//					board[i][j][k] = player;
//					if (i > 0) board[i - 1][j][k] = OK;
//					score = -alphaBeta(board, depth - 1, -beta, -alpha, (player % 2) + 1);
//					if (i > 0) board[i - 1][j][k] = NG;
//					board[i][j][k] = OK;
//					if (score > alpha) {
//						alpha = score;
//					}
//					if (alpha >= beta) {
//						return alpha;
//					}
//				}
//			}
//		}
//	}
//	return alpha;
//}
//
//
//int alphaBeta(int board[][FIGURE_NUM][FIGURE_NUM], int, int, int, int);
//
//void find_best_move(int board[][4][4], int depth, int player, int num[3]) {
//    int alpha = -100000;
//    int beta = 100000;
//    int best_score = -1;
//    int best_i = -1;
//    int best_j = -1;
//    int best_k = -1;
//    //BOARD EVALUATION
//    //if cannot find best answer choose by this evaluation
//    int value[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
//    {
//        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}},
//        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
//        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
//        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}}
//    };
//
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            for (int k = 0; k < 4; k++) {
//                if (board[i][j][k] == OK) {
//                    board[i][j][k] = player;
//                    if (i > 0) board[i - 1][j][k] = OK;
//                    int score = -alphaBeta(board, depth, -beta, -alpha, (player % 2) + 1);
//                    //printfDx("%d:%d\n", score, board[i][j][k]);
//                    if (i > 0) board[i - 1][j][k] = NG;
//                    board[i][j][k] = OK;
//                    if (score > alpha) {
//                        alpha = score;
//                        num[0] = i;
//                        num[1] = j;
//                        num[2] = k;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//
//    for (int i = 3; i >= 0; i--) {
//        for (int j = 0; j < 4; j++) {
//            for (int k = 0; k < 4; k++) {
//                if (board[i][j][k] == 0) {
//                    if (value[i][j][k] == 7) {
//                        num[0] = i;
//                        num[1] = j;
//                        num[2] = k;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//    for (int i = 3; i >= 0; i--) {
//        for (int j = 0; j < 4; j++) {
//            for (int k = 0; k < 4; k++) {
//                if (board[i][j][k] == 0) {
//                    break;
//                }
//            }
//        }
//    }
//}