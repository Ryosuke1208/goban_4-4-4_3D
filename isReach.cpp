//************************************************
// ���̎��_�Ń��[�`�ɂȂ��Ă���{���𐔂���
// ���菑�� �Ђǂ�
//************************************************
#include "define.h"

int isReach(int puzzle[][FIGURE_NUM][FIGURE_NUM], int playerNum) {
	int x, y, z;
	int cnt1, cnt2;
	int reach = 0;
	for (x = FIGURE_NUM - 1; x >= 0; x--) {
		for (y = 0; y < FIGURE_NUM; y++) {// ��ʂ��Ƃ𕽖ʂɌ����Ƃ��̉����̃`�F�b�N 16�ʂ�
			cnt1 = 0;
			cnt2 = 0;
			if (puzzle[x][y][0] == playerNum) cnt1++;
			if (puzzle[x][y][1] == playerNum) cnt1++;
			if (puzzle[x][y][2] == playerNum) cnt1++;
			if (puzzle[x][y][3] == playerNum) cnt1++;
			if (puzzle[x][y][0] == OK) cnt2++;
			if (puzzle[x][y][1] == OK) cnt2++;
			if (puzzle[x][y][2] == OK) cnt2++;
			if (puzzle[x][y][3] == OK) cnt2++;
			if (cnt1 == 3 && cnt2 == 1) reach++;
		}
	}
	for (x = FIGURE_NUM - 1; x >= 0; x--) {
		for (z = 0; z < FIGURE_NUM; z++) {// ��ʂ��Ƃ𕽖ʂɌ����Ƃ��̏c���̃`�F�b�N 16�ʂ�
			cnt1 = 0;
			cnt2 = 0;
			if (puzzle[x][0][z] == playerNum) cnt1++;
			if (puzzle[x][1][z] == playerNum) cnt1++;
			if (puzzle[x][2][z] == playerNum) cnt1++;
			if (puzzle[x][3][z] == playerNum) cnt1++;
			if (puzzle[x][0][z] == OK) cnt2++;
			if (puzzle[x][1][z] == OK) cnt2++;
			if (puzzle[x][2][z] == OK) cnt2++;
			if (puzzle[x][3][z] == OK) cnt2++;
			if (cnt1 == 3 && cnt2 == 1) reach++;
		}
	}
	for (x = FIGURE_NUM - 1; x >= 0; x--) {// ��ʂ��Ƃ𕽖ʂɌ����Ƃ��̍�������E��ւ̂ȂȂߐ��̃`�F�b�N 4�ʂ�
		cnt1 = 0;
		cnt2 = 0;
		if (puzzle[x][0][0] == playerNum) cnt1++;
		if (puzzle[x][1][1] == playerNum) cnt1++;
		if (puzzle[x][2][2] == playerNum) cnt1++;
		if (puzzle[x][3][3] == playerNum) cnt1++;
		if (puzzle[x][0][0] == OK) cnt2++;
		if (puzzle[x][1][1] == OK) cnt2++;
		if (puzzle[x][2][2] == OK) cnt2++;
		if (puzzle[x][3][3] == OK) cnt2++;
		if (cnt1 == 3 && cnt2 == 1) reach++;
	}
	for (x = FIGURE_NUM - 1; x >= 0; x--) {// ��ʂ��Ƃ𕽖ʂɌ����Ƃ��̍��ォ��E���ւȂȂߐ��̃`�F�b�N 4�ʂ�
		cnt1 = 0;
		cnt2 = 0;
		if (puzzle[x][3][0] == playerNum) cnt1++;
		if (puzzle[x][2][1] == playerNum) cnt1++;
		if (puzzle[x][1][2] == playerNum) cnt1++;
		if (puzzle[x][0][3] == playerNum) cnt1++;
		if (puzzle[x][3][0] == OK) cnt2++;
		if (puzzle[x][2][1] == OK) cnt2++;
		if (puzzle[x][1][2] == OK) cnt2++;
		if (puzzle[x][0][3] == OK) cnt2++;
		if (cnt1 == 3 && cnt2 == 1) reach++;
	}
	for (y = 0; y < FIGURE_NUM; y++) {// �l�ʂ𗧑̂Ɍ����Ƃ��̉����̍��ォ��E���ւȂȂߐ��̃`�F�b�N 4�ʂ�
		cnt1 = 0;
		cnt2 = 0;
		if (puzzle[0][y][0] == playerNum) cnt1++;
		if (puzzle[1][y][1] == playerNum) cnt1++;
		if (puzzle[2][y][2] == playerNum) cnt1++;
		if (puzzle[3][y][3] == playerNum) cnt1++;
		if (puzzle[0][y][0] == OK) cnt2++;
		if (puzzle[1][y][1] == OK) cnt2++;
		if (puzzle[2][y][2] == OK) cnt2++;
		if (puzzle[3][y][3] == OK) cnt2++;
		if (cnt1 == 3 && cnt2 == 1) reach++;
	}
	for (y = 0; y < FIGURE_NUM; y++) {// �l�ʂ𗧑̂Ɍ����Ƃ��̉����̉E�ォ�獶���ւȂȂߐ��̃`�F�b�N 4�ʂ�
		cnt1 = 0;
		cnt2 = 0;
		if (puzzle[0][y][3] == playerNum) cnt1++;
		if (puzzle[1][y][2] == playerNum) cnt1++;
		if (puzzle[2][y][1] == playerNum) cnt1++;
		if (puzzle[3][y][0] == playerNum) cnt1++;
		if (puzzle[0][y][3] == OK) cnt2++;
		if (puzzle[1][y][2] == OK) cnt2++;
		if (puzzle[2][y][1] == OK) cnt2++;
		if (puzzle[3][y][0] == OK) cnt2++;
		if (cnt1 == 3 && cnt2 == 1) reach++;
	}
	for (z = 0; z < FIGURE_NUM; z++) {// �l�ʂ𗧑̂Ɍ����Ƃ��̏c���̎�O���牜�ւȂȂߐ��̃`�F�b�N 4�ʂ�
		cnt1 = 0;
		cnt2 = 0;
		if (puzzle[0][0][z] == playerNum) cnt1++;
		if (puzzle[1][1][z] == playerNum) cnt1++;
		if (puzzle[2][2][z] == playerNum) cnt1++;
		if (puzzle[3][3][z] == playerNum) cnt1++;
		if (puzzle[0][0][z] == OK) cnt2++;
		if (puzzle[1][1][z] == OK) cnt2++;
		if (puzzle[2][2][z] == OK) cnt2++;
		if (puzzle[3][3][z] == OK) cnt2++;
		if (cnt1 == 3 && cnt2 == 1) reach++;
	}
	for (z = 0; z < FIGURE_NUM; z++) {// �l�ʂ𗧑̂Ɍ����Ƃ��̏c���̉������O�ւȂȂߐ��̃`�F�b�N 4�ʂ�
		cnt1 = 0;
		cnt2 = 0;
		if (puzzle[0][3][z] == playerNum) cnt1++;
		if (puzzle[1][2][z] == playerNum) cnt1++;
		if (puzzle[2][1][z] == playerNum) cnt1++;
		if (puzzle[3][0][z] == playerNum) cnt1++;
		if (puzzle[0][3][z] == OK) cnt2++;
		if (puzzle[1][2][z] == OK) cnt2++;
		if (puzzle[2][1][z] == OK) cnt2++;
		if (puzzle[3][0][z] == OK) cnt2++;
		if (cnt1 == 3 && cnt2 == 1) reach++;
	}
	for (y = 0; y < FIGURE_NUM; y++) {
		for (z = 0; z < FIGURE_NUM; z++) {// �l�ʂ𗧑̂Ɍ����Ƃ��̍����̏c�̃`�F�b�N 16�ʂ�
			cnt1 = 0;
			cnt2 = 0;
			if (puzzle[0][y][z] == playerNum) cnt1++;
			if (puzzle[1][y][z] == playerNum) cnt1++;
			if (puzzle[2][y][z] == playerNum) cnt1++;
			if (puzzle[3][y][z] == playerNum) cnt1++;
			if (puzzle[0][y][z] == OK) cnt2++;
			if (puzzle[1][y][z] == OK) cnt2++;
			if (puzzle[2][y][z] == OK) cnt2++;
			if (puzzle[3][y][z] == OK) cnt2++;
			if (cnt1 == 3 && cnt2 == 1) reach++;
		}
	}
	// ���̓I�Ȏ��_�ł̎΂߂̃`�F�b�N
	cnt1 = 0;
	cnt2 = 0;
	if (puzzle[0][0][0] == playerNum) cnt1++;
	if (puzzle[1][1][1] == playerNum) cnt1++;
	if (puzzle[2][2][2] == playerNum) cnt1++;
	if (puzzle[3][3][3] == playerNum) cnt1++;
	if (puzzle[0][0][0] == OK) cnt2++;
	if (puzzle[1][1][1] == OK) cnt2++;
	if (puzzle[2][2][2] == OK) cnt2++;
	if (puzzle[3][3][3] == OK) cnt2++;
	if (cnt1 == 3 && cnt2 == 1) reach++;

	cnt1 = 0;
	cnt2 = 0;
	if (puzzle[0][3][3] == playerNum) cnt1++;
	if (puzzle[1][2][2] == playerNum) cnt1++;
	if (puzzle[2][1][1] == playerNum) cnt1++;
	if (puzzle[3][0][0] == playerNum) cnt1++;
	if (puzzle[0][3][3] == OK) cnt2++;
	if (puzzle[1][2][2] == OK) cnt2++;
	if (puzzle[2][1][1] == OK) cnt2++;
	if (puzzle[3][0][0] == OK) cnt2++;
	if (cnt1 == 3 && cnt2 == 1) reach++;

	cnt1 = 0;
	cnt2 = 0;
	if (puzzle[0][3][0] == playerNum) cnt1++;
	if (puzzle[1][2][1] == playerNum) cnt1++;
	if (puzzle[2][1][2] == playerNum) cnt1++;
	if (puzzle[3][0][3] == playerNum) cnt1++;
	if (puzzle[0][3][0] == OK) cnt2++;
	if (puzzle[1][2][1] == OK) cnt2++;
	if (puzzle[2][1][2] == OK) cnt2++;
	if (puzzle[3][0][3] == OK) cnt2++;
	if (cnt1 == 3 && cnt2 == 1) reach++;

	cnt1 = 0;
	cnt2 = 0;
	if (puzzle[0][0][3] == playerNum) cnt1++;
	if (puzzle[1][1][2] == playerNum) cnt1++;
	if (puzzle[2][2][1] == playerNum) cnt1++;
	if (puzzle[3][3][0] == playerNum) cnt1++;
	if (puzzle[0][0][3] == OK) cnt2++;
	if (puzzle[1][1][2] == OK) cnt2++;
	if (puzzle[2][2][1] == OK) cnt2++;
	if (puzzle[3][3][0] == OK) cnt2++;
	if (cnt1 == 3 && cnt2 == 1) reach++;

	return reach;
}