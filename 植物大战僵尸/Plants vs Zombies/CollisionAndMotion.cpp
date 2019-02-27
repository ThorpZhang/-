#pragma once
#include"ZombCollisionAndMotion.h"
#include"PlantCollisionAndMotion.h"
#include"Pea.h"
//���ӵ�x��λ��
const int HousePosX=200;//δ��ֵ

//�����ײ�ĺ���
bool checkCollision(SDL_Rect a, SDL_Rect b)
{
	int RightA, RightB;
	int LeftA, LeftB;
	int TopA, TopB;
	int BottomA, BottomB;
	
	RightA = a.x + a.w;
	RightB = b.x + b.w;
	LeftA = a.x;
	LeftB = b.x;
	TopA = a.y;
	TopB = b.y;
	BottomA = a.y + a.h;
	BottomB = b.y + b.h;

	if (RightA < LeftB) 
		return false;	// {//	if(LeftA>800)printf("false11\n");return false; }
	if (RightB < LeftA) 
		return false;//{ if(LeftA<800)printf("false2\n"); return false; }
	if (BottomB < TopA) 
		return false;//{ printf("false3\n"); return false; }
	if (BottomA < TopB) 
		return false;//{ printf("false4\n"); return false; }

	return true;
}

bool checkCollision(SDL_Rect a, SDL_Rect b,int weaponArea)//aһ��Ҫ��ֲ��
{
	int RightA, RightB;
	int LeftA, LeftB;
	int TopA, TopB;
	int BottomA, BottomB;

	RightA = a.x + a.w+weaponArea*75;
	RightB = b.x + b.w;
	LeftA = a.x;
	LeftB = b.x;
	TopA = a.y;
	TopB = b.y;
	BottomA = a.y + a.h;
	BottomB = b.y + b.h;

	if (RightA < LeftB) return false;
	if (RightB < LeftA) return false;
	if (BottomB < TopA) return false;
	if (BottomA < TopB) return false;

	return true;
}


zColliAndMove::zColliAndMove()
{
	zPosX = 0;
	zPosY = 0;

	zVelX = 0;

	ZombCollision = { 0,0,0,0 };
}

zColliAndMove::zColliAndMove(int posx, int posy)
{
	zPosX = posx;
	zPosY = posy;

	zVelX = 0;

	ZombCollision = { 0,0,0,0 };
}

zColliAndMove::~zColliAndMove()
{
	//�ο�ʵ��
}

void zColliAndMove::setPos(int posx, int posy)
{
	zPosX = posx;
	zPosY = posy;

	zVelX = 0;

	ZombCollision = { zPosX,zPosY,79,95 };
}

void zColliAndMove::setVel(int v)
{
	zVelX = v;
}

int zColliAndMove::getPosX()
{
	return zPosX;
}
int zColliAndMove::getPosY()
{
	return zPosY;
}

Meet zColliAndMove::move(SDL_Rect & plants,plantflag f1)//�˶�ʱ���ÿ�е�һ��ֲ��ͷ���
{
	zPosX -= zVelX;
	ZombCollision.x = zPosX;
//	printf("%d  %d\n", zPosX, ZombCollision.x);

	if (zPosX < HousePosX)//��������
	{
		meetflag = meetHouse;
		return meetHouse;
	}
	else if (checkCollision(ZombCollision,plants) && f1!=Nothing)
	{
//		printf("true\n");
		int temp = zPosX;
		zPosX += zVelX;//�ָ�ԭ����ʬ��λ��
		
//		zPosX += zVelX;
//		zPosX += zVelX;
		ZombCollision.x = zPosX;
//		printf("%d  %d\n", zPosX, temp);
		meetflag = meetPlant;
		return meetPlant;
	}
	else
	{
		meetflag = meetNothing;
		return meetNothing;
	}
}

SDL_Rect & zColliAndMove::getColli()
{
	return ZombCollision;
}

zombieMove::zombieMove(int zposx, int zposy, int zvelx):zColliAndMove(zposx,zposy){}
zombieMove::~zombieMove(){}





//********************************************ֲ����ײ���ʵ��********************************************
pColliandMove::pColliandMove()
{
	mPosX = 0;
	mPosY = 0;
	plantCollision = { 0,0,79,96 };//ֲ��Ŀ��Ϊ79���߶�Ϊ96����ֲ��ӳߴ�һ�£�
	type = Nothing;
	attackflag = false;
	weaponArea = 0;
}
pColliandMove::~pColliandMove(){}

plantflag & pColliandMove::changeplantflag()
{
	return type;
}

const plantflag pColliandMove::getflag()const
{
	return type;
}

int pColliandMove::getPosX()
{
	return mPosX;
}

int pColliandMove::getPosY()
{
	return mPosY;
}

void pColliandMove::setAttackState()
{
	attackflag = true;
}

bool pColliandMove::getAttackFlag()
{
	return attackflag;
}

void pColliandMove::cancelAttack()
{
	attackflag = false;
}

void  pColliandMove::checkZombie(SDL_Rect & zombie)
{
	if (checkCollision(plantCollision, zombie, weaponArea))
	{
		setAttackState();
	}
	if (attackflag == true && !checkCollision(plantCollision, zombie, weaponArea))
	{
		cancelAttack();
	}
}

void pColliandMove::setPos(int x, int y)
{
	mPosX = x;
	mPosY = y;
//	plantCollision.x = x;
//	plantCollision.y = y;
	plantCollision = { x,y,79,96 };
	weaponArea = 9 - (x - 280) / 79;
}

SDL_Rect& pColliandMove::getColli()
{
	return plantCollision;
}


//****************************************************�㶹ʵ��***************************
Peabulletlogic::Peabulletlogic()
{
	posX = 0;
	posY = 0;
	bulletColli = { 0,0,0,0 };
	broken = true;
	velX = 0;
	row = 0;
}
Peabulletlogic::~Peabulletlogic(){}

void Peabulletlogic::setPos(int x, int y)
{
	posX = x+50;
	posY = y+20;
	bulletColli.x = posX;
	bulletColli.y = posY;
	bulletColli.w = 30;
	bulletColli.h = 30;
	velX = 10;
	broken = false;
}

void Peabulletlogic::move(SDL_Rect & zombie,int HP)
{
	posX += velX;
	bulletColli.x = posX;
	if (posX > 1000)
	{
		broken = true;//������ͼ
	}
	else if (checkCollision(bulletColli, zombie)&& HP>0)
	{
		posX -= velX;
		bulletColli.x = posX;
		broken = true;//������ʬ
	}
	else{}//ɶҰ����
}

void Peabulletlogic::setRow(int r)
{
	row = r;
}

int Peabulletlogic::getRow()
{
	return row;
}

bool Peabulletlogic::getBroken()
{
	return broken;
}

SDL_Rect Peabulletlogic::getColli()
{
	return bulletColli;
}

void Peabulletlogic::broke()
{
	broken = true;
}

int Peabulletlogic::getPosX()
{
	return posX;
}