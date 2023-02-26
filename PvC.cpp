//************************************************
// コンピューターとの対戦
//************************************************
#include "define.h"

void playerPutProc(int [][FIGURE_NUM][FIGURE_NUM], int);
void cpuEasyProc(int [][FIGURE_NUM][FIGURE_NUM]);
void cpuNormalProc(int [][FIGURE_NUM][FIGURE_NUM]);
int isDone(int [][FIGURE_NUM][FIGURE_NUM], int);
void showFinishedStatus(int[][FIGURE_NUM][FIGURE_NUM]);
void showWinPvC(int);
boolean isDraw(int[][FIGURE_NUM][FIGURE_NUM]);
void showDraw();

void PvC(int d, int f) {
    // 変数の定義
    // プレイヤーが、0で先行・1で後攻
    int playerNum = 0;
    //int i, j;
    int puzzle[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK}}
    };
    // 考え中
    char think[4][12] = { "thinking","thinking.","thinking..","thinking..." };
    if (f == 0) playerNum = 0;
    else playerNum = 1;
    // ゲーム処理
    while (1) {
        SetFontSize(80);
        if (playerNum % 2 == 0) playerPutProc(puzzle, (playerNum % 2) + 1); // プレイヤーが出す手を決める処理
        else {
            /*
            //************************************************
            //thinking表記の作成
            //************************************************
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 4; j++) {
                    DrawString(10, 10, think[j], LIGHT_BLUE);
                    ScreenFlip();
                    WaitTimer(250);
                    DrawString(10, 10, think[j], LIGHT_BLUE);
                }
            }
            */
            if (d == 0) {
                cpuEasyProc(puzzle);
            }
            else if (d == 1) {
                cpuNormalProc(puzzle);// CPUが出す手を決める処理
            }
        }
        // ビンゴになったかどうかのチェック
        if (isDone(puzzle, (playerNum % 2) + 1)) {
            showFinishedStatus(puzzle);
            showWinPvC((playerNum % 2) + 1);
            break;
        }
        //ドローになったかどうかのチェック
        if (isDraw(puzzle)) {
            showFinishedStatus(puzzle);
            showDraw();
            break;
        }
        playerNum++;
    }   
}



