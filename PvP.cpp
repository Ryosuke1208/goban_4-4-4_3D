//************************************************
// �v���C���[���m�ł̏����̎�
//************************************************
#include "define.h"

void playerPutProc(int puzzle[][FIGURE_NUM][FIGURE_NUM], int);
int isDone(int puzzle[][FIGURE_NUM][FIGURE_NUM], int);
void showFinishedStatus(int[][FIGURE_NUM][FIGURE_NUM]);
void showWinPvP(int);
int isReach(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum);
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
        //�r���S�ɂȂ������ǂ����̃`�F�b�N
        if (isDone(puzzle, (playerNum % 2) + 1)) {
            showFinishedStatus(puzzle);
            showWinPvP((playerNum % 2) + 1);
            break;
        }
        printfDx("reach:%d ", isReach(puzzle, (playerNum % 2) + 1));
        playerNum++;
    }
}