#pragma once
#include"include\SDL.h"
#include"PlantCollisionAndMotion.h"
#include"LTimer.h"


class Plantlogic
{
public:

	//*********************ӵ�еĳ�Ա*********************
	pColliandMove plantColli;
	LTimer timer;
	bool meetZombie;
	LTimer attackTimer;
	LTimer makeSTimer;

	Plantlogic();
	~Plantlogic();
};