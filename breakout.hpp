#ifndef BREAKOUT_HPP
#define BREAKOUT_HPP

#include <list>
#include "chara.hpp"

class Breakout {
private:
	std::list<ChrRef> chr_list;		//ゲーム中のキャラクターを登録するリスト
	int score;
protected:
public:
	static const int WIDTH, HEIGHT;
	static const int DEFAULT_BG_COLOR_R, DEFAULT_BG_COLOR_G, DEFAULT_BG_COLOR_B;
	static const unsigned int DEFAULT_BG_COLOR;
	static const char* TITLE;
	static Breakout *me;	//自分自身のインスタンスを示すポインタ
	unsigned int bgColor;
	void init();
	/*void main();
	void end();*/
};

#endif // !BREAKOUT_HPP

