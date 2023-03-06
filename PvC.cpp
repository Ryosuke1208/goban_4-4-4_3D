//************************************************
// コンピューターとの対戦
//************************************************
#include "define.h"

int playerPutProc(int [][FIGURE_NUM][FIGURE_NUM], int, int, int, int [][3]);
void cpuPutProc(int [][FIGURE_NUM][FIGURE_NUM], int [][3], int);
int isDone(int [][FIGURE_NUM][FIGURE_NUM], int);
int showFinishedStatus(int[][FIGURE_NUM][FIGURE_NUM], int, int, int, struct BINGO);
void showWinPvC(int);
boolean isDraw(int[][FIGURE_NUM][FIGURE_NUM]);
void showDraw();
struct BINGO getBingoLine(int[][FIGURE_NUM][FIGURE_NUM], int);

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
    if (f == 0) playerNum = 0;
    else playerNum = 1;
    int temp[2][3] = { -1 };
    struct BINGO b = { {-1,-1,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1} };
    // ゲーム処理
    while (1) {
        SetFontSize(80);
        if (playerNum % 2 == 0) {
            while (1) {
                if (playerPutProc(puzzle, (playerNum % 2) + 1, d, 1, temp) == 1) {
                    break;
                }
                else {
                    if (temp[0][0] != -1) {
                        puzzle[temp[0][0]][temp[0][1]][temp[0][2]] = OK;
                        puzzle[temp[1][0]][temp[1][1]][temp[1][2]] = OK;
                        if (temp[0][0] > 0) puzzle[temp[0][0] - 1][temp[0][1]][temp[0][2]] = NG;
                        if (temp[1][0] > 0) puzzle[temp[1][0] - 1][temp[1][1]][temp[1][2]] = NG;
                        temp[0][0] = -1;
                    }
                }
            }
        }
        else {
            cpuPutProc(puzzle, temp, d);
        }
        // ビンゴになったかどうかのチェック
        if (isDone(puzzle, (playerNum % 2) + 1)) {
            // BACKキーで一手戻す
            b = getBingoLine(puzzle, (playerNum % 2) + 1);
            if (showFinishedStatus(puzzle, d, 1, playerNum, b) == 1) {
                if (temp[0][0] != -1) {
                    puzzle[temp[0][0]][temp[0][1]][temp[0][2]] = OK;
                    puzzle[temp[1][0]][temp[1][1]][temp[1][2]] = OK;
                    if (temp[0][0] > 0) puzzle[temp[0][0] - 1][temp[0][1]][temp[0][2]] = NG;
                    if (temp[1][0] > 0) puzzle[temp[1][0] - 1][temp[1][1]][temp[1][2]] = NG;
                    temp[0][0] = -1;
                    playerNum--;
                }
                continue;
            }
            showWinPvC((playerNum % 2) + 1);
            break;
        }
        // ドローになったかどうかのチェック
        if (isDraw(puzzle)) {
            showFinishedStatus(puzzle, d, 1, playerNum, b);
            showDraw();
            break;
        }
        playerNum++;
    }   
}



