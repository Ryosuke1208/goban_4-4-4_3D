/*
#include "define.h"

int checkBingo(int puzzle[][FIGURE_NUM][FIGURE_NUM], int x, int y, int z, int pNum) {

    int i, m, n;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0, cnt7 = 0;

    for (i = 0; i < FIGURE_NUM; i++) {
        for (m = 0; m < FIGURE_NUM; m++) {
            for (n = 0; n < FIGURE_NUM; n++) {
                //Zラインチェック
                if (x == i && y == m && z != n) {
                    if (puzzle[i][m][n] == pNum) cnt1++;
                }
                //Yラインチェック
                if (x == i && y != m && z == n) {
                    if (puzzle[i][m][n] == pNum) cnt2++;
                }
                //Xラインチェック
                if (x != i && y == m && z == n) {
                    if (puzzle[i][m][n] == pNum) cnt3++;
                }
                //X面ナナメチェック
                if (x == i && y != m && ((m == n && y == z) || (m + n == FIGURE_NUM -1 && y + z == FIGURE_NUM -1))) {
                    if (puzzle[i][m][n] == pNum) cnt4++;
                }
                //Y面ナナメチェック
                if (x != i && y == m && ((i == n && x == z) || (i + n == FIGURE_NUM -1 && x + z == FIGURE_NUM -1))) {
                    if (puzzle[i][m][n] == pNum) cnt5++;
                }
                //Z面ナナメチェック
                if (x != i && z == n && ((i == m && x == y) || (i + m == FIGURE_NUM -1 && x + y == FIGURE_NUM -1))) {
                    if (puzzle[i][m][n] == pNum) cnt6++;
                }
                //ナナメ3Dラインチェック
                if ((x == y && x == z) && (i == m && i == n) && x != i) {
                    if (puzzle[i][m][n] == pNum) cnt7++;
                }
                if (x == y && z == (FIGURE_NUM -1 - x) && i == m && n == (FIGURE_NUM -1 - i) && x != i) {
                    if (puzzle[i][m][n] == pNum) cnt7++;
                }
                if (x == z && y == (FIGURE_NUM -1 - x) && i == n && m == (FIGURE_NUM -1 - i) && x != i) {
                    if (puzzle[i][m][n] == pNum) cnt7++;
                }
                if (y == z && x == (FIGURE_NUM -1 - y) && m == n && i == (FIGURE_NUM -1 - m) && x != i) {
                    if (puzzle[i][m][n] == pNum) cnt7++;
                }
            }
        }
    }
    //ビンゴになりそうなら１を返す
    if (cnt1 == FIGURE_NUM -1 || cnt2 == FIGURE_NUM -1 || cnt3 == FIGURE_NUM -1 || cnt4 == FIGURE_NUM -1 || cnt5 == FIGURE_NUM -1 || cnt6 == FIGURE_NUM -1 || cnt7 == FIGURE_NUM -1) {
        return 1;
    }//なりそうでなければ０を返す
    else {
        return 0;
    }
}
*/
