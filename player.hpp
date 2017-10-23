#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "chara.hpp"

class Player : public Chr{
	int shots;	//�t�B�[���h��ɑ��݂���e�̐�
public:
	Player();
	ChrType getType();	//return TYPE_PLAYER
	void move();
	void hit(ChrRef&);
	void draw();
	void shot();
	void removeShot();
};

#endif // !PLAYER_HPP

