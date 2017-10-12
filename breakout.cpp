#include "breakout.hpp"
#include <DxLib.h>

const int Breakout::WIDTH = 640;
const int Breakout::HEIGHT = 480;
const char* Breakout::TITLE = "Break out";
const int Breakout::DEFAULT_BG_COLOR_R = 0;
const int Breakout::DEFAULT_BG_COLOR_G = 0;
const int Breakout::DEFAULT_BG_COLOR_B = 0;
const unsigned int Breakout::DEFAULT_BG_COLOR = GetColor
(
	Breakout::DEFAULT_BG_COLOR_R, 
	Breakout::DEFAULT_BG_COLOR_G, 
	Breakout::DEFAULT_BG_COLOR_B
);

Breakout* Breakout::me;

void Breakout::init() {
	me = this;
	score = 0;
	bgColor = Breakout::DEFAULT_BG_COLOR;
	ChangeWindowMode(TRUE);		//ウィンドウ表示モード
	SetGraphMode(Breakout::WIDTH, Breakout::HEIGHT, 16);
	SetBackgroundColor(Breakout::DEFAULT_BG_COLOR_R, Breakout::DEFAULT_BG_COLOR_G, Breakout::DEFAULT_BG_COLOR_B);

	SetWindowText(Breakout::TITLE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
}