//************************************************
//player vs player
//************************************************
#include "define.h"

void fill(int, int, int, int);
void makeFigure(int[][FIGURE_NUM][FIGURE_NUM]);
boolean playerCanPut(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);
int isDone(int puzzle[][FIGURE_NUM][FIGURE_NUM], int);
void showWinner(int);

void PvP() {
    int x, y, z;
    int playerNum = 0;
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
        /**********************player vs player***********************/
        //player proc
        if (playerCanPut(puzzle, &x, &y, &z)) { //scan Mouse-XYZ-point and player can put, return true
            fill(x, y, z, (playerNum % 2) + 1); //1 ¨ P1, 2 ¨ P2
            if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 1) {
                puzzle[x][y][z] = (playerNum % 2) + 1; //left-click on, change status to player

                if (x > 0)puzzle[x - 1][y][z] = 0;
                //if (checkBingo(puzzle, x, y, z, (playerNum % 2) + 1)) break;
                if (x > 0) puzzle[x - 1][y][z] = OK;
                if (isDone(puzzle, (playerNum % 2) + 1)) {
                    showWinner((playerNum % 2) + 1);
                    break;
                }
                playerNum++;
            }
        }
        /************************************************************/

        ScreenFlip();

        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }
}