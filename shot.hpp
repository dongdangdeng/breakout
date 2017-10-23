#ifndef SHOT_HPP
#define SHOT_HPP
#include "chara.hpp"

class Shot : public Chr{
	static const int DEFAULT_SIZE;
	int size;
	double dx, dy,
		rad;
public:
	Shot();
	ChrType getType();	//return TYPE_SHOT
	ChrType hitType();	//return TYPE_BLOCK
	void move();
	void draw();
	void hit();
};

#endif //SHOT_HPP