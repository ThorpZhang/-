#pragma once
#include"ZombCollisionAndMotion.h"
#include"LTimer.h"

class Zombies
{
public:
	//*******************ӵ�еĳ�Ա****************************
	zColliAndMove zCAM;
	LTimer timer;
	int HP;
	bool attackflag;

	Zombies();
	~Zombies();
};