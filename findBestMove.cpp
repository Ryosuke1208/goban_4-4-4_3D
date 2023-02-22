//************************************************
//cpu find best move
//************************************************
#include "define.h"

int alphaBeta(int board[][FIGURE_NUM][FIGURE_NUM], int, int, int, int);

void find_best_move(int board[][4][4], int depth, int player, int num[3]) {
    int alpha = -1000;
    int beta = 1000;
    int best_score = -1000;
    int best_i = -1;
    int best_j = -1;
    int best_k = -1;
    //BOARD EVALUATION
    //if cannot find best answer choose by this evaluation
    int value[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{4,4,4,4},{4,7,7,4},{4,7,7,4},{4,4,4,4}},
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}}
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (board[i][j][k] == OK) {
                    board[i][j][k] = player;
                    if (i > 0) board[i - 1][j][k] = OK;
                    int score = -alphaBeta(board, depth - 1, -beta, -alpha, (player % 2) + 1);
                    printfDx("%d:%d\n", score, board[i][j][k]);
                    if (i > 0) board[i - 1][j][k] = NG;
                    if (score > best_score) {
                        best_score = score;
                        num[0] = i;
                        num[1] = j;
                        num[2] = k;
                    }
                    if (score > alpha) {
                        alpha = score;
                    }
                    // ƒÀƒJƒbƒg
                        if (alpha >= beta) {
                            // Žè‚ð–ß‚·
                            board[i][j][k] = OK;
                            if (i > 0) board[i - 1][j][k] = NG;
                            break;
                        }

                    // Žè‚ð–ß‚·
                    board[i][j][k] = OK;
                    if (i > 0) board[i - 1][j][k] = NG;
                }
            }
        }
    }

    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (board[i][j][k] == 0) {
                    if (value[i][j][k] == 7) {
                        num[0] = i;
                        num[1] = j;
                        num[2] = k;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (board[i][j][k] == 0) {
                    break;
                }
            }
        }
    }
}
