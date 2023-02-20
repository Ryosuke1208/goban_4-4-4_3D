#pragma once
#define DEBUG_ON //while make ON
//#define DEBUG_OFF // finished make OFF

#include "DxLib.h"
//FIGURE
#define LINE_NUM 5 //line num
#define LINE_START_X 150 //top figure start X-point (left-down-point)
#define LINE_START_Y 220 //top figure start Y-point (left-down-point)
#define LINE_COL_W 80 //vertical-line width 
#define LINE_ROW_H 30 //horizontal-line height
#define FIGURE_NUM 4 //figure num
#define FIGURE_INTERVAL 150 //each figure distance
#define TRIANGLE_GAP_X 5 //X-point gap between line and triangle 
#define TRIANGLE_GAP_Y 1.5f //Y-point gap between line and triangle 
//COLOR
#define BLACK GetColor(0,0,0)
#define LIGHT_GRAY GetColor(224, 224, 224)
#define LIGHT_RED GetColor(255, 153, 153)
#define LIGHT_BLUE GetColor(153, 204, 255)
//BOARD STATUS
#define NG -1
#define OK 0
#define P1 1
#define P2 2
