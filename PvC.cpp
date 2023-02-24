//************************************************
// �R���s���[�^�[�Ƃ̑ΐ�
//************************************************
#include "define.h"

void playerPutProc(int [][FIGURE_NUM][FIGURE_NUM], int);
void cpuEasyProc(int [][FIGURE_NUM][FIGURE_NUM], int);
void cpuNormalProc(int [][FIGURE_NUM][FIGURE_NUM], int);
int isDone(int [][FIGURE_NUM][FIGURE_NUM], int);
void showFinishedStatus(int[][FIGURE_NUM][FIGURE_NUM]);
void showWinPvC(int);
boolean isDraw(int[][FIGURE_NUM][FIGURE_NUM]);
void showDraw();

void PvC() {
    // �ϐ��̒�`
    // �v���C���[���A0�Ő�s�E1�Ō�U
    int playerNum = 0;
    int puzzle[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK}}
    };
    // �Q�[������
    while (1) {
        if (playerNum % 2 == 0) playerPutProc(puzzle, (playerNum % 2) + 1); // �v���C���[���o��������߂鏈��
        else cpuNormalProc(puzzle, (playerNum % 2) + 1);// CPU���o��������߂鏈��
        // �r���S�ɂȂ������ǂ����̃`�F�b�N
        if (isDone(puzzle, (playerNum % 2) + 1)) {
            showFinishedStatus(puzzle);
            showWinPvC((playerNum % 2) + 1);
            break;
        }
        //�h���[�ɂȂ������ǂ����̃`�F�b�N
        if (isDraw(puzzle)) {
            showFinishedStatus(puzzle);
            showDraw();
            break;
        }
        playerNum++;
    }   
}



