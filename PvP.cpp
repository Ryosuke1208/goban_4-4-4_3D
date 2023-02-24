//************************************************
// �v���C���[���m�ł̏����̎�
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
    // �ϐ��̒�`
    int playerNum = 0;
    int puzzle[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK}}
    };
    //�Q�[������
    while (1) {
        //�v���C���[���o��������߂鏈��
        if (playerNum % 2 == 0) {
            playerPutProc(puzzle, (playerNum % 2) + 1);
        }
        else {
            playerPutProc(puzzle, (playerNum % 2) + 1);
        }
        printfDx("P%d:%d ", (playerNum % 2) + 1,isReach(puzzle, (playerNum % 2) + 1));
        //�r���S�ɂȂ������ǂ����̃`�F�b�N
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