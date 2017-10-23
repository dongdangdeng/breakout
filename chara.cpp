#include "chara.hpp"

void Chr::remove() {
	remove_flag = true;
}

Chr::Chr() {
	remove_flag = false;
}

void Chr::setPosition(int px, int py) {
	x = px; y = py;
}

void Chr::setSize(int w, int h) {
	width = w; height = h;

	//�ÖٓI�ɓ����蔻����w��(�L�����N�^�T�C�Y�Ɠ���)
	hit_x = 0; hit_y = 0;
	hit_width = w; hit_height = h;	
}

//�����蔻����L�����N�^�T�C�Y(=�L�����N�^�\���G���A)�ƕς������ꍇ�Ɏg�p
void Chr::setHitArea(int hx, int hy, int hw, int hh) {
	hit_x = hx; hit_y = hy;
	hit_width = hw; hit_height = hh;
}

void Chr::setColor(unsigned int c){
	color = c;
}

bool Chr::isRemove() {
	return remove_flag;
}

ChrType Chr::hitType() {	//���z�֐�
	return TYPE_NONE;
}

//�����蔻��
bool Chr::isHit(ChrRef &dst) {
	int x1 = x + hit_x;
	int y1 = y + hit_y;
	int w1 = hit_width;
	int h1 = hit_height;
	int x2 = dst->x + dst->hit_x;
	int y2 = dst->y + dst->hit_y;
	int w2 = dst->hit_width;
	int h2 = dst->hit_height;

	if (x1 + w1 > x2 && x1 < x2 + w2 && y1 + h1 > y2 && y1 < y2 + h2) {
		return true;
	} else {
		return false;
	}
}