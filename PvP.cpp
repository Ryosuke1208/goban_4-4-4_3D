//************************************************
// プレイヤー同士での勝負の時
//************************************************
#include "define.h"

void playerPutProc(int puzzle[][FIGURE_NUM][FIGURE_NUM], int);
int isDone(int puzzle[][FIGURE_NUM][FIGURE_NUM], int);
void showFinishedStatus(int[][FIGURE_NUM][FIGURE_NUM]);
void showWinPvP(int);
int isReach(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum);
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
        //ビンゴになったかどうかのチェック
        if (isDone(puzzle, (playerNum % 2) + 1)) {
            showFinishedStatus(puzzle);
            showWinPvP((playerNum % 2) + 1);
            break;
        }
        printfDx("reach:%d ", isReach(puzzle, (playerNum % 2) + 1));
        playerNum++;
    }
}