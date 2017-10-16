#include "breakout.hpp"
#include "player.hpp"
#include <DxLib.h>
#include <algorithm>

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
key_t Breakout::key;

Breakout::Breakout() {
	key.UP = false;
	key.DOWN = false;
	key.RIGHT = false;
	key.LEFT = false;
	key.SHIFT = false;
	key.SPACE = false;
	key.RETURN = false;
	key.ESCAPE = false;
}

key_t* Breakout::getKey() {
	if (CheckHitKeyAll != 0) {	//�����ꂩ�̃L�[��������Ă����Ԃ̂݋�̓I�ȃL�[������
		char buf[256];			//���s��GetHitKeyStateAll()�ɂ���ăL�[�R�[�h�̔z��ɉ������ꂽ�L�[�̏�񂪑�������
		GetHitKeyStateAll(buf);	//0...��������Ă��Ȃ� 1...�������ꂽ

		key.UP = buf[KEY_INPUT_UP] == 1 || buf[KEY_INPUT_W] == 1;
		key.DOWN = buf[KEY_INPUT_DOWN] == 1 || buf[KEY_INPUT_S] == 1;
		key.RIGHT = buf[KEY_INPUT_RIGHT] == 1 || buf[KEY_INPUT_D] == 1;
		key.LEFT = buf[KEY_INPUT_LEFT] == 1 || buf[KEY_INPUT_A] == 1;
		key.SHIFT = buf[KEY_INPUT_RSHIFT] == 1 || buf[KEY_INPUT_LSHIFT] == 1;
		key.SPACE = buf[KEY_INPUT_SPACE] == 1;
		key.RETURN = buf[KEY_INPUT_RETURN] == 1;
		key.ESCAPE = buf[KEY_INPUT_ESCAPE] == 1;
	}
	return &key;
}

void Breakout::addList(ChrRef &c) {
	chr_list.push_back(c);
}

void Breakout::addScore(int s) {
	score += s;
}

void Breakout::init() {
	me = this;
	score = 0;
	bgColor = Breakout::DEFAULT_BG_COLOR;
	ChangeWindowMode(TRUE);		//�E�B���h�E�\�����[�h
	SetGraphMode(Breakout::WIDTH, Breakout::HEIGHT, 16);
	SetBackgroundColor(Breakout::DEFAULT_BG_COLOR_R, Breakout::DEFAULT_BG_COLOR_G, Breakout::DEFAULT_BG_COLOR_B);

	SetWindowText(Breakout::TITLE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	// �v���C���[����
	ChrRef player(new Player());
	addList(player);
}

void Breakout::main() {
	while (!ProcessMessage()) {
		ClearDrawScreen();
		// �ړ�
		std::for_each(chr_list.begin(), chr_list.end(), [](ChrRef& c) {c->move(); });
		// �`��
		std::for_each(chr_list.begin(), chr_list.end(), [](ChrRef& c) {c->draw(); });
		
		ScreenFlip();
		// �����ׂ��L�����N�^�̏���
		auto end = std::remove_if(chr_list.begin(), chr_list.end(), [](ChrRef& c) {return c->isRemove(); });
		chr_list.erase(end, chr_list.end());
	}
}

void Breakout::end() {
	DxLib_End();
}