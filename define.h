#pragma once

#include "DxLib.h"
// 図形関係
#define LINE_NUM 5 // 線の数
#define LINE_START_X 150 // 一番上の図形のX座標(図形の左下の座標)
#define LINE_START_Y 220 // 一番上の図形のY座標(図形の左下の座標)
#define LINE_COL_W 80 // 縦の線の幅
#define LINE_ROW_H 30 // 横の線の幅
#define FIGURE_NUM 4 // 図形の数(4面)
#define FIGURE_INTERVAL 150 // 図形ごとのY軸の距離
#define TRIANGLE_GAP_X 5 // 色を塗る際の三角形と線との隙間のX座標 
#define TRIANGLE_GAP_Y 1.5f //  色を塗る際の三角形と線との隙間のY座標 
// 色関係
#define BLACK GetColor(0,0,0)
#define LIGHT_GRAY GetColor(224, 224, 224)
#define LIGHT_RED GetColor(255, 153, 153)
#define LIGHT_BLUE GetColor(153, 204, 255)
// 盤面関係
#define NG -1
#define OK 0
#define P1 1
#define P2 2
