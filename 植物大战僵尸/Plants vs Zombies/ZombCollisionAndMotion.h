#pragma once
#include"include\SDL.h"
#include"include\SDL_image.h"
#include"PlantCollisionAndMotion.h"

enum Meet
{
	meetNothing,//û�����κζ���
	meetPlant,//����ֲ��
	meetHouse//���뷿��
};


class zColliAndMove
{
public:
	zColliAndMove();
	zColliAndMove(int posx, int posy );
	~zColliAndMove();

	void setPos(int x, int y);

	void setVel(int v);

    Meet move(SDL_Rect &plants,plantflag f1);//���ؽ�ʬ�Ƿ�����ֲ��,�Ƿ���������(���Ӳ�����ײ����,���zPosX����

	SDL_Rect & getColli();

//	virtual void render() = 0;  ��Ⱦ���ܷ����������

	int getPosX();
	int getPosY();
protected:
	int zPosX, zPosY;

	int zVelX;//ֻ��x�����ٶȣ������Խ�У�ÿ����ʬ���Լ���ͬ���ٶ� 

	SDL_Rect ZombCollision;//��ZombWidth �� ZombHeight ��ֵ

	Meet meetflag;
};

class zombieMove :zColliAndMove
{
public:
	zombieMove(int zposx, int zposy, int zvelx);
	~zombieMove();
private:
	//int zVelX;

};