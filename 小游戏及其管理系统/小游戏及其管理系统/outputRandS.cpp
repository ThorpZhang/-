//outputRandS.cpp
#include"outputRandS.h"
using namespace std;
namespace ManagementSystemV5 {
	void doRandS()
	{
		int sum = 0;//��ȡ�������
		Fchildplayer*child = new Fchildplayer();
		sum = child->test();
		Player pa[11];//���а�ֻ��ʾ10λ���
		if (sum > 10) sum = 10;
		childplayer*p = new childplayer();//���ļ���ȡ�û���Ϣ
		fstream f;
		char path[100];
		sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\RandS\\RandS.dat");
		f.open(path, ios::in | ios::binary);
		f.seekg(long(sizeof(int)), ios::beg);
		for (int i = 1; i <= sum&&i <= 10; i++)
		{
			f.read((char*)p, sizeof(childplayer));
			strcpy(pa[i].id, p->getid());
			strcpy(pa[i].name, p->getname());
			pa[i].sorce = p->getscore();
			pa[i].rank = p->getrank();
		}
		Player temp;//ð��������������
		for (int j = 1; j<sum; j++)
			for (int i = 1; i <= sum - j; i++)
				if (pa[i].sorce < pa[i + 1].sorce)
				{
					temp = pa[i];
					pa[i] = pa[i + 1];
					pa[i + 1] = temp;
				}
		for (int i = 1; i <= sum; i++) pa[i].rank = i;//��������ֵ
													  //����
		for (int i = 1; i <= sum; i++)
			cout << pa[i].name << ' ' << pa[i].sorce << ' ' << pa[i].rank << endl;
	}
}