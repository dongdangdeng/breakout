#include "player.hpp"
#include "breakout.hpp"
#include <DxLib.h>

Player::Player() {
	setPosition(100, 400);	//TODO �������W��Breakout�N���X�̉�ʃT�C�Y�����o�ˑ��ɂ���
	setSize(80, 10);		//TODO MagicNumber���C��
}

ChrType Player::getType() {
	return TYPE_PLAYER;
}

void Player::move() {
	key_t* key = Breakout::getKey();
	if (key->RIGHT) { x += 6; };
	if (key->LEFT) { x -= 6; };
	//TODO �t�B�[���h�Ƃ̂����蔻���ǉ�
}

void Player::draw() {
	DrawBox(x, y, x + width, y + height, GetColor(255, 0, 0), true);
}