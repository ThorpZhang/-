#pragma once
#include"include\SDL.h"
#include"include\SDL_image.h"
#include<string>

using namespace std;

enum plantflag
{
	Nothing = 0,
	SunFlower=1,
	PeaShooter=2
};
class pColliandMove
{
public:
	pColliandMove();
	~pColliandMove();

	void setPos(int x, int y);

//	void handleEvent(SDL_Event &e);

	plantflag& changeplantflag();

	const plantflag getflag()const;

	void setAttackState();
	bool getAttackFlag();
	void cancelAttack();

	void checkZombie(SDL_Rect & zombie);

	SDL_Rect & getColli();

	int getPosX();
	int getPosY();
protected:
	int mPosX, mPosY;

	SDL_Rect plantCollision;

	int weaponArea;//�������

	plantflag type;

	bool attackflag;//���ֲ���Ƿ�Ҫ����
	//������������ֲ�ﶼ�У�weaponCollision����ʵ��
};