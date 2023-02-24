//************************************************
// [‚³‚Ì’Tõ‚ÅŒ©‚Â‚©‚ç‚È‚©‚Á‚½‚Æ‚«‚É•]‰¿’l‚Å
// Œˆ’è‚·‚é
//************************************************
#include "define.h"

boolean easyValue(int puzzle[][FIGURE_NUM][FIGURE_NUM], int* x, int* y, int* z) {
    int i, j, k;
    int cnt;
    int max = -999;
    int flag = 1;
    //Šeƒ}ƒX‚Ì•]‰¿’l ’Pƒ‚É‚»‚±‚É’u‚¢‚½Žž‚Ìƒrƒ“ƒS‚É‚È‚è“¾‚é”‚ðŠî‚É‚µ‚Ä‚¢‚é
    int value[FIGURE_NUM][FIGURE_NUM][FIGURE_NUM] =
    {
        {{7,4,4,7},{4,4,4,4},{4,4,4,4},{7,4,4,7}},
        {{4,4,4,4},{4,10,10,4},{4,10,10,4},{4,4,4,4}},
        {{4,4,4,4},{4,4,4,4},{4,4,4,4},{4,4,4,4}},
        {{7,4,4,7},{4,2,2,4},{4,2,2,4},{7,4,4,7}}
    };
    //2’i–ÚŠp‚Ì•]‰¿“_‚Ì•ÏX
    //‘ŠŽè‚ª‚¨‚¢‚½‚Æ‚«‚Í‘jŽ~‚·‚é ‚±‚ê‚ÍNG
    // ‚±‚±‚É‚¨‚¢‚Ä‚µ‚Ü‚¤‚Æ‚R’i–Ú‚ðŽæ‚ç‚ê‚Ä‚µ‚Ü‚¤‚½‚ß
    //if (puzzle[3][0][0] == P1) value[2][0][0] += 20;
    //if (puzzle[3][0][3] == P1) value[2][0][3] += 20;
    //if (puzzle[3][3][0] == P1) value[2][3][0] += 20;
    //if (puzzle[3][3][3] == P1) value[2][3][3] += 20;
    //Ž©•ª‚ª’u‚¢‚½Žž‚à•ÏX
    if (puzzle[3][0][0] == P2) value[2][0][0] += 10;
    if (puzzle[3][0][3] == P2) value[2][0][3] += 10;
    if (puzzle[3][3][0] == P2) value[2][3][0] += 10;
    if (puzzle[3][3][3] == P2) value[2][3][3] += 10;

    //3’i–ÚŠp‚Ì•]‰¿“_‚Ì•ÏX
    //‘ŠŽè‚ª‚¨‚¢‚½‚Æ‚«‚Í‘jŽ~‚·‚é
    if (puzzle[3][0][0] == P1) value[1][0][0] += 30;
    if (puzzle[3][0][3] == P1) value[1][0][3] += 30;
    if (puzzle[3][3][0] == P1) value[1][3][0] += 30;
    if (puzzle[3][3][3] == P1) value[1][3][3] += 30;
    //Ž©•ª‚ª’u‚¢‚½Žž‚à•ÏX
    if (puzzle[3][0][0] == P2 && puzzle[3][0][3] == P2 && puzzle[3][3][0] == P2) value[1][0][0] += 30;
    if (puzzle[3][0][3] == P2 && puzzle[3][0][0] == P2 && puzzle[3][3][3] == P2) value[1][0][3] += 30;
    if (puzzle[3][3][0] == P2 && puzzle[3][0][0] == P2 && puzzle[3][3][3] == P2) value[1][3][0] += 30;
    if (puzzle[3][3][3] == P2 && puzzle[3][0][3] == P2 && puzzle[3][3][0] == P2) value[1][3][3] += 30;

    //ƒNƒƒXƒAƒ^ƒbƒN‘Îô
    if (puzzle[3][1][1] == OK) {
        cnt = 0;
        if (puzzle[3][0][1] == P1) cnt++;
        if (puzzle[3][1][0] == P1) cnt++;
        if (puzzle[3][1][3] == P1) cnt++;
        if (puzzle[3][3][1] == P1) cnt++;
        if (cnt >= 1) {
            *x = 3;
            *y = 1;
            *z = 1;
            return true;
        }
    }
    if (puzzle[3][2][2] == OK) {
        cnt = 0;
        if (puzzle[3][0][2] == P1) cnt++;
        if (puzzle[3][2][0] == P1) cnt++;
        if (puzzle[3][2][3] == P1) cnt++;
        if (puzzle[3][3][2] == P1) cnt++;
        if (cnt >= 1) {
            *x = 3;
            *y = 2;
            *z = 2;
            return true;
        }
    }
    if (puzzle[3][2][1] == OK) {
        cnt = 0;
        if (puzzle[3][2][0] == P1) cnt++;
        if (puzzle[3][0][1] == P1) cnt++;
        if (puzzle[3][3][1] == P1) cnt++;
        if (puzzle[3][2][3] == P1) cnt++;
        if (cnt >= 1) {
            *x = 3;
            *y = 2;
            *z = 1;
            return true;
        }
    }
    if (puzzle[3][1][2] == OK) {
        cnt = 0;
        if (puzzle[3][0][1] == P1) cnt++;
        if (puzzle[3][0][1] == P1) cnt++;
        if (puzzle[3][3][1] == P1) cnt++;
        if (puzzle[3][1][3] == P1) cnt++;
        if (cnt >= 1) {
            *x = 3;
            *y = 1;
            *z = 2;
            return true;
        }
    }
    // •]‰¿’l‚Ì‚‚¢Žè‚ªŒ©‚Â‚©‚Á‚½Žž‚Í‚»‚±‚ð•Ô‚·
    for (i = 3; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (puzzle[i][j][k] == OK) {
                    if (value[i][j][k] > max) {
                        max = value[i][j][k];
                        *x = i;
                        *y = j;
                        *z = k;
                    }
                }
            }
        }
    }
    return true;
}