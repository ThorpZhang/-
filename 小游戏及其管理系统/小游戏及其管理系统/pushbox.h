#pragma once
#include <stdio.h>  
#include <stdlib.h>
#include <conio.h>
#include<iostream>
#include"user.h"
#include"Storage.h"
#include"memberService.h"
#include"typeDefinition.h"
#define GameScreen_Height 10
#define GameScreen_Width  20
using namespace std;
//���������ռ�ManagementSystemV5
namespace ManagementSystemV5 {
	//int GameScreen[GameScreen_Height][GameScreen_Width] = {}; //������Ϸ��Ļ
	//char key;//�����û�����
	struct people
	{
		int x;
		int y;
	};
	struct box
	{
		int x;
		int y;
	};
	struct goal
	{
		int x;
		int y;
	};
	//static people gamer;//�������
	//char control;//���尴��
	void drawWall();//��ǽ
	void refreshScreen();//����
	void printfMassage();//�����Ϸ����
	void drawScreen(int *x);//��ӡ��Ļ
	void CheckBoxGamerStatus();//���ȫ������ ��ҵ�״̬ һ���ص��͸���ʾ
	void gamerMove();//����ƶ���ʱ��ˢ��
	void initGamer();//��ʼ����Ϸ���λ��
	void refreshGamer();//����Ϸ��Ҽ�����Ϸ
	char getDirection();//��ȡ�û���ǰ����
	void gameControl(char x);//�û��ƶ��¼�
	bool detectionWin();//���ʤ������
	void CheckBoxGamerStatus();
	void useMap(int x);
	void useMap1();
	void useMap2();
	void useMap3();
	void initGameScreen();
	//void putBoxStatus(); //���Է���  �������λ��
	void putGamerStatus();//���Է��� �������λ��
	//void putGoalStatus();//���Է���  ���Ŀ�ĵ�λ��
	/*
	0    �յ�
	1 �� ��
	2 �� Ŀ�ĵ�
	3 �� ����
	4 �� ǽ��
	5 ��  �˺�Ŀ�ĵ��ص�
	6 �� ���Ӻ�Ŀ�ĵ��ص�
	*/
	void play1(childplayer*p);
	void play2(adplayer*p);
}