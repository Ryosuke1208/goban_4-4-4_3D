//************************************************
// �R���s���[�^�[�Ƃ̑ΐ�
//************************************************
#include "define.h"

void playerPutProc(int [][FIGURE_NUM][FIGURE_NUM], int);
void cpuEasyProc(int [][FIGURE_NUM][FIGURE_NUM], int);
int isDone(int [][FIGURE_NUM][FIGURE_NUM], int);
void showFinishedStatus(int[][FIGURE_NUM][FIGURE_NUM]);
void showWinPvC(int);

void PvC() {
    // �ϐ��̒�`
    int playerNum = 1;
    int puzzle[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK}}
    };
    // �Q�[������
    while (1) {
        if (playerNum % 2 == 0) { // �v���C���[���o��������߂鏈��
            playerPutProc(puzzle, (playerNum % 2) + 1);
        }
        else { // CPU���o��������߂鏈��
            cpuEasyProc(puzzle, (playerNum % 2) + 1);
        }
        // �r���S�ɂȂ������ǂ����̃`�F�b�N
        if (isDone(puzzle, (playerNum % 2) + 1)) {
            // �r���S����������Ō�̏�Ԃ�\�����A���҂�\�����ďI��
            showFinishedStatus(puzzle);
            showWinPvC((playerNum % 2) + 1);
            break;
        }
        playerNum++;
    }   
}



