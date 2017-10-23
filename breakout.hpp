#ifndef BREAKOUT_HPP
#define BREAKOUT_HPP

#include <list>
#include "chara.hpp"

struct key_t {
	bool UP,
		DOWN,
		RIGHT,
		LEFT,
		SHIFT,
		SPACE,
		RETURN,
		ESCAPE;
};

class Breakout {
private:
	std::list<ChrRef> chr_list;		//ゲーム中のキャラクターを登録するリスト
	int score;
	static key_t key;
	//static bool const DEBUG_MODE;	//デバックモード
protected:
public:
	static const int WIDTH, HEIGHT;	//画面全体のサイズ
	
	static const int DEFAULT_BG_COLOR_R, DEFAULT_BG_COLOR_G, DEFAULT_BG_COLOR_B;
	static const unsigned int DEFAULT_BG_COLOR;
	static const char* TITLE;	//ウィンドウタイトル名
	static Breakout *me;		//自分自身のインスタンスを示すポインタ
	Breakout();
	static key_t* getKey();		//入力されたキーを返す
	unsigned int bgColor;		//背景色
	void addList(ChrRef &);		//キャラクタリストに追加
	void addScore(int);			//スコアの増加
	void init();				//ゲームの初期化
	void main();				//メインルーチン
	void end();					//終了処理
};
#endif // !BREAKOUT_HPP