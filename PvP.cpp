//************************************************
// プレイヤー同士での勝負の時
//************************************************
#include "define.h"

void playerPutProc(int [][FIGURE_NUM][FIGURE_NUM], int);
int isDone(int [][FIGURE_NUM][FIGURE_NUM], int);
void showFinishedStatus(int[][FIGURE_NUM][FIGURE_NUM]);
void showWinPvP(int);
int isReach(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum);
boolean isDraw(int [][FIGURE_NUM][FIGURE_NUM]);
void showDraw();

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
    //ゲーム処理
    while (1) {
        //プレイヤーが出す手を決める処理
        if (playerNum % 2 == 0) {
            playerPutProc(puzzle, (playerNum % 2) + 1);
        }
        else {
            playerPutProc(puzzle, (playerNum % 2) + 1);
        }
        printfDx("P%d:%d ", (playerNum % 2) + 1,isReach(puzzle, (playerNum % 2) + 1));
        //ビンゴになったかどうかのチェック
        if (isDone(puzzle, (playerNum % 2) + 1)) {
            showFinishedStatus(puzzle);
            showWinPvP((playerNum % 2) + 1);
            break;
        }
        if (isDraw(puzzle)) {
            showFinishedStatus(puzzle);
            showDraw();
            break;
        }
        playerNum++;
    }
}