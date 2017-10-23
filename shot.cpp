#define _USE_MATH_DEFINES
#include "shot.hpp"
#include "debug.hpp"
#include "breakout.hpp"
#include <DxLib.h>
#include <math.h>

const int Shot::DEFAULT_SIZE = 6;

Shot::Shot() {
	size = DEFAULT_SIZE;
	setSize(size, size);
	setColor(GetColor(255, 255,255));
	rad = fmod(rand(), 0.5 * M_PI) + 0.25 * M_PI;	//�e�̎ˏo�p�x(0����P�W�O�x�܂ł̗���)
	rad = 0.75 * M_PI;	//!DEBUG
	dx = -cos(rad) * 6;	//x�̑�����
	dy = -sin(rad) * 6;	//y�̑�����
	Debug::me->addData("shot_x", x);
	Debug::me->addData("shot_y", y);
	Debug::me->addData("rad", rad);
	Debug::me->addData("dx", dx);
	Debug::me->addData("dy", dy);
}

ChrType Shot::hitType() {
	return TYPE_BLOCK;
}

ChrType Shot::getType() {
	return TYPE_SHOT;
}

void Shot::move() {
	x += dx;
	y += dy;
	if (x + size > Breakout::me->WIDTH) {	//�E�[�Ƃ̓����蔻��
		x = 2 * Breakout::me->WIDTH - 2 * size - x;
		dx *= -1;
	}
	if (x - size < 0) {		//���[�Ƃ̓����蔻��
		x = 2 * size - x;
		dx *= -1;
	}
	if (y - size < 0) {		//��[�Ƃ̓����蔻��
		y = 2 * size - y;
		dy *= -1;
	}
}

void Shot::hit() {

}

void Shot::draw() {
	Debug::me->changeData("shot_x", x + size / 2);
	Debug::me->changeData("shot_y", y + size / 2);
	DrawCircle(x + size / 2, y + size / 2, size, GetColor(255,255,255), true);
}