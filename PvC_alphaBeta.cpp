//************************************************
//player vs computer
//************************************************
#include "define.h"

void fill(int, int, int, int);
void makeFigure(int[][FIGURE_NUM][FIGURE_NUM]);
boolean playerCanPut(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
int isDone(int puzzle[][FIGURE_NUM][FIGURE_NUM], int);
void showWinPvC(int);
void find_best_move(int board[][4][4], int depth, int player, int num[3]);

void PvC_Alpha() {
    int x = 0, y = 0, z = 0;
    int playerNum = 0;
    int num[3];
    int puzzle[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK}}
    };

    while (1) {
        ClearDrawScreen();
        //make figure
        makeFigure(puzzle);
        /**********************player vs computer***********************/
        //player proc
        if (playerNum % 2 == 0) {
            if(playerCanPut(puzzle, &x, &y, &z)) { //scan Mouse-XYZ-point and player can put, return true
                fill(x, y, z, (playerNum % 2) + 1);
                if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 1) {
                    puzzle[x][y][z] = (playerNum % 2) + 1; //left-click on, change status to player
                    if (x > 0)puzzle[x - 1][y][z] = 0;
                    //if (checkBingo(puzzle, x, y, z, (playerNum % 2) + 1)) break;
                    if (x > 0) puzzle[x - 1][y][z] = OK;
                    if (isDone(puzzle, (playerNum % 2) + 1)) {
                        showWinPvC((playerNum % 2) + 1);
                        break;
                    }
                    playerNum++;
                }

            }
        }
        else {
            find_best_move(puzzle, 3, (playerNum % 2) + 1, num);
            puzzle[num[0]][num[1]][num[2]] = (playerNum % 2) + 1;
            if (num[0] > 0) puzzle[num[0] - 1][num[1]][num[2]] = OK;
            if (isDone(puzzle, (playerNum % 2) + 1)) {
                showWinPvC((playerNum % 2) + 1);
                break;
            }
            playerNum++;
        }
        
        
        /************************************************************/

        ScreenFlip();

        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }
}