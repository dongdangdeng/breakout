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

void Chr::setHitArea(int hx, int hy, int hw, int hh) {
	hit_x = hx; hit_y = hy;
	hit_width = hw; hit_height = hh;
}

bool Chr::isRemove() {
	return remove_flag;
}

ChrType Chr::hitType() {	//‰¼‘zŠÖ”
	return TYPE_NONE;
}

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