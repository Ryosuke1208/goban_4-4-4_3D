//************************************************
// コンピューターとの対戦
//************************************************
#include "define.h"

void playerPutProc(int [][FIGURE_NUM][FIGURE_NUM], int);
void cpuEasyProc(int [][FIGURE_NUM][FIGURE_NUM], int);
int isDone(int [][FIGURE_NUM][FIGURE_NUM], int);
void showFinishedStatus(int[][FIGURE_NUM][FIGURE_NUM]);
void showWinPvC(int);

void PvC() {
    // 変数の定義
    int playerNum = 1;
    int puzzle[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK}}
    };
    // ゲーム処理
    while (1) {
        if (playerNum % 2 == 0) { // プレイヤーが出す手を決める処理
            playerPutProc(puzzle, (playerNum % 2) + 1);
        }
        else { // CPUが出す手を決める処理
            cpuEasyProc(puzzle, (playerNum % 2) + 1);
        }
        // ビンゴになったかどうかのチェック
        if (isDone(puzzle, (playerNum % 2) + 1)) {
            // ビンゴがあったら最後の状態を表示し、勝者を表示して終了
            showFinishedStatus(puzzle);
            showWinPvC((playerNum % 2) + 1);
            break;
        }
        playerNum++;
    }   
}



