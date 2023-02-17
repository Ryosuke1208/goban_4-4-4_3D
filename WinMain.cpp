#define DEBUG_ON

#include "define.h"

void fill(int, int, int, int);
void makeFigure(int [][FIGURE_NUM][FIGURE_NUM]);
int getMouseXYZ(int[][FIGURE_NUM][FIGURE_NUM], int*, int*, int*);

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) 
{
	if (DxLib_Init() == -1)	return -1; //�G���[�N������I��	

	SetBackgroundColor(241, 237, 238);
	SetGraphMode(800, 800, 32);
	ChangeWindowMode(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
    SetMouseDispFlag(TRUE);

    int x, y, z;
    int canPutFlag; //�v���C���[��������ӏ����ǂ����̃t���O
    int i, j, k;
    //�N�_�͈�ԏ�̐}�`�̍����AX��(�E����)��x�AY��(���̕���)��x,�c����z
    int puzzle[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{-1,-1,0,-1},{-1,-1,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1}},
        {{-1,-1,-1,-1},{-1,-1,-1,0},{-1,-1,0,-1},{0,-1,-1,-1}},
        {{-1,0,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1},{0,-1,-1,-1}},
        //{{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}}
        {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}
    };
    //************************************************
    //�Q�[�����
    //************************************************
    while (1) {
        ClearDrawScreen();   
        canPutFlag = 0;
        makeFigure(puzzle);
        //************************************************
        //�v���C���[���̏���
        //************************************************
        canPutFlag = getMouseXYZ(puzzle, &x, &y, &z); //�}�E�X��XYZ���W�̓ǂݎ��
        if (canPutFlag) {
            fill(x, y, z, 1);
            if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 1) {
                puzzle[z][y][x] = 1;
            }
        }
        //************************************************

        ScreenFlip();

        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}