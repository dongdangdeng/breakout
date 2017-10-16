#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "chara.hpp"

class Player : public Chr{
	
public:
	Player();
	ChrType getType();	//return TYPE_PLAYER
	void move();
	void draw();
	//void hit();
};

#endif // !PLAYER_HPP

