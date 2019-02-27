//cleanmines.cpp
#include"cleanmines.h"

namespace ManagementSystemV5 {
	Cube cube[MAXX][MAXY];
	time_t  time0;//��¼ʱ��
	void GoTo(int x, int y) {
		//��λ���
		COORD coord = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void setBomb(int bombNumber = BOMBNUMBER) {
		//����bombNumber��ը�����ҷŽ�����ķ�����
		srand((unsigned)GetCurrentTime());
		while (bombNumber--) {
			int x = MAXX + 1, y = MAXY + 1;
			while ((x >= MAXX || y >= MAXY) || cube[x][y].getIfHaveBomb() == true) {
				x = rand() % MAXX;
				y = rand() % MAXY;
			}
			cube[x][y].haveBomb();
		}
	}

	void show() {
		//��ʾ������
		system("cls");
		showXY();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);
		for (int i = 0; i < MAXY; i++) {
			GoTo(STARTX, STARTY + i);
			for (int j = 0; j < MAXX; j++) {
				if (cube[j][i].getOpen() == true) {
					if (cube[j][i].getIfHaveBomb() == false) {
						if (cube[j][i].getNearBombNumber() == 0) { //�ڿ����׵ķ�����ʾ�÷�����Χ���ٸ����麬�ף���Ϊ0����ʾ�ո�
							printf("  ");
						}
						else {
							printf(" %d", cube[j][i].getNearBombNumber());
						}
					}
					else {
						printf("��");//���׵ķ��鱻�ڿ�����ʾ��
					}
				}
				else {
					printf("��");//δ�����ķ����á���ʾ
				}
			}
		}
	}

	void showXY() {
		//��ʾ������
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);
		GoTo(STARTX - 3, STARTY + MAXY / 2);
		printf("Y");
		GoTo(STARTX + MAXX, STARTY - 2);
		printf("X");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
		for (int i = 0; i < MAXY; i++) {
			GoTo(STARTX - 1, STARTY + i);
			printf("%d ", i);
		}
		for (int i = 0; i < 2 * MAXX; i += 2) {
			GoTo(STARTX + i + 1, STARTY - 1);
			printf("%d ", i / 2);
		}
	}

	int checkAndSetNearBombNumber(int x, int y) {
		//��鵱ǰ������Χ��������
		int num = 0;

		if (cube[x][y].getIfHaveBomb() == true) {
			//���÷����е��ף������ж�����Χ�м�����
			return 0;
		}
		else {
			//������ѭ����ǰ������Χ8��ɨһ��
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					int nx = x + i;
					int ny = y + j;
					if (!(ny == y && nx == x) && (nx >= 0 && nx <= MAXX - 1) &&
						(ny >= 0 && ny <= MAXY - 1)) {
						if (cube[nx][ny].getIfHaveBomb()) {
							num++;
						}
					}
				}
			}
			cube[x][y].setNearBombNumber(num);//���ø÷��鸽���ĵ��׵�����
			return 0;
		}
	}

	void gameStart() {
		//��ʼ����Ϸ
		for (int i = 0; i < MAXY; i++) {
			for (int j = 0; j < MAXX; j++) {
				cube[j][i].resetCube();
			}
		}
		setBomb();
		for (int i = 0; i < MAXY; i++) {
			for (int j = 0; j < MAXX; j++) {
				checkAndSetNearBombNumber(j, i);
			}
		}

		time0 = time(NULL);
	}

	bool Splayers(bool &life) {
		//����������귭������
		int x, y;
		GoTo(STARTX - 3, STARTY + MAXY + 1);
		printf("����������(x,y),x��y�ÿո����");
		GoTo(STARTX + MAXX / 2, STARTY + MAXY + 2);
		scanf_s("%d%d", &x, &y);
		if ((x < 0) || (x > MAXX - 1) || (y < 0) || (y > MAXY - 1)) {
			//�������������곬����Χʱ
			show();
			GoTo(STARTX - 3, STARTY + MAXY + 3);
			printf("�����겻���ڣ���������������");
			GoTo(STARTX + MAXX / 2, STARTY + MAXY + 2);
		}
		else if (cube[x][y].getIfHaveBomb() == true) {
			//����ҷ����ķ����е���ʱ
			cube[x][y].setOpen();
			show();
			life = false;
			return false;
		}
		else if (cube[x][y].getOpen() == false) {
			//����ҷ����ķ�������ʱ
			if (cube[x][y].getNearBombNumber() == 0) {
				autoOpen(x, y);
				cube[x][y].setOpen();
				show();
			}
			else {
				cube[x][y].setOpen();
				show();
			}
		}
		else if (cube[x][y].getOpen() == true) {
			//����������ѷ������������ʱ
			show();
			GoTo(STARTX, STARTY + MAXY + 3);
			printf("�÷����ѱ��ڿ������ٴ���������");
			GoTo(STARTX + MAXX / 2, STARTY + MAXY + 2);
		}
		ifWin();
		return true;
	}

	void ch_message(bool result,childplayer*cp) {
		if (result == true) {
			//���ʤ��ʱ�������Ϣ
			showBomb();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			GoTo(STARTX - 1, STARTY + MAXY + 1);
			printf("ף���㣬��ʤ���ˣ���ʱ��");
			time_t time1;
			time1 = time(NULL) - time0;
			Fchildplayer *child = new Fchildplayer();
			if (!child->CMwriteaddSforchild(cp, time1)) cout << "�ӷ�ʧ�ܣ�" << endl;
			cout << time1;
			printf("��");
			GoTo(STARTX, STARTY + MAXY + 2);
		}
		else {
			//���ʧ��ʱ�������Ϣ
			showBomb();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), PURPLE);
			GoTo(STARTX - 1, STARTY + MAXY + 1);
			printf("��������е����ˡ���");
			GoTo(STARTX, STARTY + MAXY + 2);
		}
	}

	void ad_message(bool result, adplayer*cp) {
		if (result == true) {
			//���ʤ��ʱ�������Ϣ
			showBomb();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			GoTo(STARTX - 1, STARTY + MAXY + 1);
			printf("ף���㣬��ʤ���ˣ���ʱ��");
			time_t time1;
			time1 = time(NULL) - time0;
			Fadplayer *adult = new Fadplayer();
			if (!adult->CMwriteaddSforadult(cp, time1)) cout << "�ӷ�ʧ�ܣ�" << endl;
			cout << time1;
			printf("��");
			GoTo(STARTX, STARTY + MAXY + 2);
		}
		else {
			//���ʧ��ʱ�������Ϣ
			showBomb();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), PURPLE);
			GoTo(STARTX - 1, STARTY + MAXY + 1);
			printf("��������е����ˡ���");
			GoTo(STARTX, STARTY + MAXY + 2);
		}
	}

	void autoOpen(int x, int y) {
		//��ҷ����ķ���Ϊ����������Χ���׵ķ���ʱ���Զ�������Χ���׵ķ���
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int nx = x + i;
				int ny = y + j;
				if (!(ny == y && nx == x) && (nx >= 0 && nx <= MAXX - 1) &&
					(ny >= 0 && ny <= MAXY - 1) && cube[nx][ny].getOpen() == false) {
					if (cube[nx][ny].getNearBombNumber() == 0) {
						cube[nx][ny].setOpen();
						autoOpen(nx, ny);
					}
					else {
						cube[nx][ny].setOpen();
					}
				}
			}
		}
	}

	bool ifWin() {
		//�ж�����Ƿ�ɨ�׳ɹ��ﵽ��Ϸ��������
		int num = 0;
		for (int i = 0; i < MAXX; i++) {
			for (int j = 0; j < MAXY; j++) {
				if (cube[j][i].getOpen() == false) {
					num++;
				}
			}
		}
		if (num == BOMBNUMBER) {
			return true;
		}
		else {
			return false;
		}
	}

	void showBomb() {
		//��Ϸ��������ʾ����λ��
		for (int i = 0; i < MAXY; i++) {
			for (int j = 0; j < MAXX; j++) {
				if (cube[j][i].getIfHaveBomb() == true) {
					cube[j][i].setOpen();
				}
			}
		}
		show();
	}


	void child_play_cleanmines(childplayer*cp) {

	P:gameStart();
		show();
		bool life = true, win = true;
		while (Splayers(life) && !ifWin()) {
		}
		ch_message(life && ifWin(),cp);
		cout << "�Ƿ����¿�ʼ��Ϸ����Y or N��";
		char ch;
		cin >> ch;
		if (ch == 'Y')
			goto P;
		//return 0;
	}

	void adult_play_cleanmines(adplayer*ap) {

	P:gameStart();
		show();
		bool life = true, win = true;
		while (Splayers(life) && !ifWin()) {
		}
		ad_message(life && ifWin(), ap);
		cout << "�Ƿ����¿�ʼ��Ϸ����Y or N��";
		char ch;
		cin >> ch;
		if (ch == 'Y')
			goto P;
		//return 0;
	}

}

