//cleanmines.h
#pragma once
#include<stdio.h>
#include<Windows.h>
#include<iostream>
#include<ctime>
#include"user.h"
#include"Storage.h"
#include"memberService.h"
#include"typeDefinition.h"

#define YELLOW FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define CYAN FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define ORANGE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define PURPLE FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY

using namespace std;
namespace ManagementSystemV5 {
	const int STARTX = 30;
	const int STARTY = 6;
	const int MAXX = 9;//�����Ŀ�
	const int MAXY = 9;//�����ĸ�
	const int BOMBNUMBER = 10;//��������
//	time_t  time0;//��¼ʱ��

	class Cube {
	private:
		bool ifHaveBomb;//�÷����Ƿ���ը��
		bool ifOpen;//�÷������ޱ���ҷ���
		int nearBombNumber;//��������Χ8��ĺ���ը���ķ��������
	public:
		void setOpen() {
			//��Open��ֵ��Ϊtrue
			ifOpen = true;
		}
		bool getOpen() {
			//��ȡifOpen��ֵ
			return ifOpen;
		}
		void setNearBombNumber(int number) {
			//��nearBombNumber��ֵ
			nearBombNumber = number;
		}
		void haveBomb() {
			//��������õ���
			ifHaveBomb = true;
		}
		bool getIfHaveBomb() {
			//��ȡifHaveBomb��ֵ
			return ifHaveBomb;
		}
		int getNearBombNumber() {
			//��ȡnearBombNumber��ֵ
			return nearBombNumber;
		}
		void resetCube(bool ifhavebomb = false, bool ifopen = false, int nearbombnumber = 0) {
			//��ʼ����Ա����
			ifHaveBomb = ifhavebomb;
			ifOpen = ifopen;
			nearBombNumber = nearbombnumber;
		}
	};//�ඨ�����
	//Cube cube[MAXX][MAXY];

	void GoTo(int x, int y);//��λ���
	void setBomb(int bombNumber);//����bombNumber��ը�����ҷŽ�����ķ�����
	void show();//��ʾ������
	int checkAndSetNearBombNumber(int x, int y);//��鵱ǰ������Χ��������
	void gameStart();//��ʼ����Ϸ
	void showXY();//��ʾ��������
	bool Splayers(bool &life);//����������귭������
	void ch_message(bool life,childplayer*p);//δ���������Ϸ�������������Ϣ
	void ad_message(bool life, adplayer*p);//�����������Ϸ�����������Ϣ
	void autoOpen(int x, int y);//��ҷ����ķ���Ϊ����������Χ���׵ķ���ʱ���Զ�������Χ���׵ķ���
	bool ifWin();//�ж�����Ƿ�ɨ�׳ɹ�
	void showBomb();//��Ϸ��������ʾ����λ��
	void adult_play_cleanmines(adplayer*ap);//���������������Ϸ����
	void child_play_cleanmines(childplayer*cp);//δ���������������Ϸ����
}