//************************************************
// プレイヤー同士での勝負の時
//************************************************
#include "define.h"

int playerPutProc(int [][FIGURE_NUM][FIGURE_NUM], int, int, int, int temp[][3]);
int isDone(int [][FIGURE_NUM][FIGURE_NUM], int);
int showFinishedStatus(int[][FIGURE_NUM][FIGURE_NUM], int, int, int, struct BINGO);
void showWinPvP(int);
boolean isDraw(int [][FIGURE_NUM][FIGURE_NUM]);
void showDraw();
struct BINGO getBingoLine(int[][FIGURE_NUM][FIGURE_NUM], int);

void PvP() {
    // 変数の定義
    int playerNum = 0;
    int puzzle[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK}}
    };
    int temp[2][3];
    struct BINGO b = { {-10,-10,-10,-10},{-1,-1,-1,-1},{-1,-1,-1,-1} };
    // ゲーム処理
    while (1) {
        // プレイヤーが出す手を決める処理
        if (playerNum % 2 == 0) playerPutProc(puzzle, (playerNum % 2) + 1, -1, 0, temp);
        else playerPutProc(puzzle, (playerNum % 2) + 1, -1, 0, temp);
        // ビンゴになったかどうかのチェック
        if (isDone(puzzle, (playerNum % 2) + 1)) {
            b = getBingoLine(puzzle, (playerNum % 2) + 1);
            showFinishedStatus(puzzle, -1, 0, playerNum, b);
            showWinPvP((playerNum % 2) + 1);
            break;
        }
        // ドローになったかどうかのチェック
        if (isDraw(puzzle)) {
            showFinishedStatus(puzzle, -1, 0, playerNum, b);
            showDraw();
            break;
        }
        playerNum++;
    }
}