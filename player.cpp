#include "player.hpp"
#include "shot.hpp"
#include "breakout.hpp"
#include "debug.hpp"
#include <DxLib.h>
#include <algorithm>
#include <list>
#include <string>

Player::Player() {
	setPosition(100, 400);	//TODO �������W��Breakout�N���X�̉�ʃT�C�Y�����o�ˑ��ɂ���
	setSize(80, 10);		//TODO MagicNumber���C��
	setColor(GetColor(255, 0, 0));
	shots = 0;

	Debug::me->addData("player_x", x);
	Debug::me->addData("shots", shots);
}

ChrType Player::getType() {
	return TYPE_PLAYER;
}

void Player::move() {
	key_t* key = Breakout::getKey();
	if (key->RIGHT) { x += 6; };
	if (key->LEFT) { x -= 6; };

	//�t�B�[���h�Ƃ̂����蔻��
	if (Breakout::WIDTH < x + width) { x = Breakout::WIDTH - width; };
	if (0 > x) { x = 0; };

	if (key->SPACE && shots == 0) {
		shot();
		
	}
	Debug::me->changeData("player_x", x);
	Debug::me->changeData("shots", shots);
}

void Player::shot() {
	ChrRef shot(new Shot());
	shot->setPosition(x + (width / 2), y);
	Breakout::me->addList(shot);
	shots++;
}

void Player::removeShot() {
	shots--;
}

void Player::draw() {
	DrawBox(x, y, x + width, y + height, color, true);
}

void Player::hit(ChrRef& dst) {

}