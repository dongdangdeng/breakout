#include "player.hpp"
#include "breakout.hpp"
#include <DxLib.h>

Player::Player() {
	setPosition(100, 400);	//TODO 初期座標をBreakoutクラスの画面サイズメンバ依存にする
	setSize(80, 10);		//TODO MagicNumberを修正
}

ChrType Player::getType() {
	return TYPE_PLAYER;
}

void Player::move() {
	key_t* key = Breakout::getKey();
	if (key->RIGHT) { x += 6; };
	if (key->LEFT) { x -= 6; };
	//TODO フィールドとのあたり判定を追加
}

void Player::draw() {
	DrawBox(x, y, x + width, y + height, GetColor(255, 0, 0), true);
}