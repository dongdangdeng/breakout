#ifndef BREAKOUT_HPP
#define BREAKOUT_HPP

#include <list>
#include "chara.hpp"

class Breakout {
private:
	std::list<ChrRef> chr_list;		//�Q�[�����̃L�����N�^�[��o�^���郊�X�g
	int score;
protected:
public:
	static const int WIDTH, HEIGHT;
	static const int DEFAULT_BG_COLOR_R, DEFAULT_BG_COLOR_G, DEFAULT_BG_COLOR_B;
	static const unsigned int DEFAULT_BG_COLOR;
	static const char* TITLE;	//�E�B���h�E�^�C�g����
	static Breakout *me;		//�������g�̃C���X�^���X�������|�C���^
	unsigned int bgColor;		//�w�i�F
	void addList(ChrRef &);		//�L�����N�^���X�g�ɒǉ�
	void addScore(int);			//�X�R�A�̑���
	void init();				//�Q�[���̏�����
	/*void main();
	void end();*/
};

#endif // !BREAKOUT_HPP

