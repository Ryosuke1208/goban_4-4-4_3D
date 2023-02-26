//************************************************
// �R���s���[�^�[�Ƃ̑ΐ�
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
    // �ϐ��̒�`
    // �v���C���[���A0�Ő�s�E1�Ō�U
    int playerNum = 0;
    //int i, j;
    int puzzle[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG},{NG,NG,NG,NG}},
        {{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK},{OK,OK,OK,OK}}
    };
    // �l����
    char think[4][12] = { "thinking","thinking.","thinking..","thinking..." };
    if (f == 0) playerNum = 0;
    else playerNum = 1;
    // �Q�[������
    while (1) {
        SetFontSize(80);
        if (playerNum % 2 == 0) playerPutProc(puzzle, (playerNum % 2) + 1); // �v���C���[���o��������߂鏈��
        else {
            /*
            //************************************************
            //thinking�\�L�̍쐬
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
                cpuNormalProc(puzzle);// CPU���o��������߂鏈��
            }
        }
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



