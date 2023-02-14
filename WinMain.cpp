#include "DxLib.h"
#include "define.h"
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) 
{
	if (DxLib_Init() == -1)	return -1; //�G���[�N������I��	

	SetBackgroundColor(241, 237, 238);
	SetGraphMode(800, 800, 32);
	ChangeWindowMode(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
    SetMouseDispFlag(TRUE);

    int x, y;
    unsigned int Cr;
    int mouseX, mouseY;
    int triangleX, triangleY;
    //************************************************
    //�Q�[�����
    //************************************************
    while (1) {
        ClearDrawScreen();
        Cr = GetColor(61, 84, 103);
        //************************************************
        //�}�`�̍쐬
        //************************************************
        for (x = 0; x < FIGURE_NUM; x++) {// �c4�쐬
            for (y = 0; y < LINE_NUM; y++) {// ���̐� ��ʂ̍쐬
                DrawLineAA(LINE_START_X + y * (LINE_COL_W - LINE_ROW_H), LINE_START_Y + y * -LINE_ROW_H + x * FIGURE_INTERVAL, LINE_START_X + (LINE_COL_W * (LINE_NUM - 1)) + y * (LINE_COL_W - LINE_ROW_H), LINE_START_Y + y * -LINE_ROW_H + x * FIGURE_INTERVAL, Cr);
            }
            for (y = 0; y < LINE_NUM; y++) {// �c�̐� ��ʂ̍쐬
                DrawLineAA(LINE_START_X + y * LINE_COL_W, LINE_START_Y + x * FIGURE_INTERVAL, LINE_START_X + (LINE_COL_W - LINE_ROW_H) * (LINE_NUM - 1) + y * LINE_COL_W, LINE_START_Y + (LINE_NUM - 1) * -LINE_ROW_H + x * FIGURE_INTERVAL, Cr);
            }
        }
        Cr = GetColor(209, 204, 220);
        //************************************************
        //�}�`���XYZ���W�̎擾
        //************************************************
        GetMousePoint(&mouseX, &mouseY);

        DrawFormatString(0, 0, Cr, "���W�w %d�@�@���W�x %d", mouseX, mouseY);

        int X, Y, Z = 0;
        for (int i = 0; i < FIGURE_NUM; i++) {
            if (mouseY < LINE_START_Y + i * FIGURE_INTERVAL && mouseY > LINE_START_Y + i * FIGURE_INTERVAL - (LINE_ROW_H * (LINE_NUM - 1))) Z = i;
        }
        Y = (LINE_START_Y + FIGURE_INTERVAL * Z - mouseY) / LINE_ROW_H;
        X = (mouseX - (LINE_START_X + Y * (LINE_COL_W - LINE_ROW_H))) / LINE_COL_W;
        if (LINE_START_X + LINE_COL_W * X + Y * (LINE_COL_W - LINE_ROW_H) < mouseX && mouseX < LINE_START_X + LINE_COL_W * X + (LINE_COL_W - LINE_ROW_H) + Y * (LINE_COL_W - LINE_ROW_H) 
            && (float)(mouseX - (LINE_START_X + LINE_COL_W * X + Y * (LINE_COL_W - LINE_ROW_H))) * 0.6f < (LINE_START_Y + FIGURE_INTERVAL * Z - (Y * LINE_ROW_H)) - mouseY) X--;

        DrawFormatString(0, 30, Cr, "�w %d�@�@�x %d�@�@�y %d", X, Y, Z);

        //************************************************
        //�}�`���XYZ���W�̍����̍��W�̎擾
        //************************************************
        triangleX = LINE_START_X + (LINE_COL_W * X) + ((LINE_COL_W - LINE_ROW_H) * Y);
        triangleY = LINE_START_Y + (-LINE_ROW_H * Y) + FIGURE_INTERVAL * Z;

        DrawFormatString(0, 60, Cr, "triangleX %d�@�@triangleY %d", triangleX, triangleY);

        //triangleX += TRIANGLE_GAP;
        //triangleY -= TRIANGLE_GAP;
        //�����A��A�E��
        DrawTriangleAA(triangleX + 5, triangleY, triangleX + (LINE_COL_W - LINE_ROW_H), triangleY - LINE_ROW_H + 3,
            triangleX + LINE_COL_W - 3, triangleY, Cr, TRUE);
        //�E��A����A��
        DrawTriangleAA(triangleX + LINE_COL_W + (LINE_COL_W - LINE_ROW_H) - 1, triangleY - LINE_ROW_H + 1, triangleX + (LINE_COL_W - LINE_ROW_H), triangleY - LINE_ROW_H + 3,
            triangleX + LINE_COL_W - 5, triangleY, Cr, TRUE);

        ScreenFlip();
            //if (CheckHitKey(KEY_INPUT_RETURN)) break;
        //}
        if (CheckHitKey(KEY_INPUT_RETURN)) break;
    }
    /*for (x = 0; x < 4; x++) {
        for (y = 0; y < 8; y++) {
            DrawLineAA(line[y][0], (float)(line[y][1] + 150 * x), line[y][2], (float)(line[y][3] + 150 * x), Cr);
        }
    }*/
	//WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}