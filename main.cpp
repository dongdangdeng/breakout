#include <DxLib.h>
#include "breakout.hpp"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Breakout breakout;
	breakout.init();
	breakout.main();
	breakout.end();
	return 0;
}