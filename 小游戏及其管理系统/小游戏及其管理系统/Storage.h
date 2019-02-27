//Storage.h
#pragma once
#include"user.h"
#include"typeDefinition.h"
#include<fstream>
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
//���������ռ� ManagementSystemV5
namespace ManagementSystemV5
{
	using namespace System;
	using namespace System::IO;
	//�洢��Storage ��ʼ
	public ref class Storage
	{
	public:
		/*login()�ǵ�½����
		        ��������½ID����½���롢��½�û����͡���½�ɹ��󣬷���һ��player����ָ�룬ָ��ǰ��½���û�����*/
		player* login(char*id, char*password, loginUsertype type)
		{
			char buffer[100];
			char loginInfo[100];
			ifstream input;
			char *path = "D:\\С��Ϸ����ϵͳ�洢\\login\\admin.txt";
			player*p = new player();
			p = readLoginInfo(id);
			if (!p)return nullptr;//�û���������
			//У���û����������Ƿ�һ��
			if (strcmp(p->getpassword(), password) == 0 && (p->gettype() == (int)type)) { return p; }
			return nullptr;
		}//login��������
		//writeLogininfo()�������û���Ϣд���ļ�
		bool writeLoginInfo(player*p)
		{
			ofstream output;//�ļ�д�����
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\login\\%s.dat", p->getid());
			output.open(path, ios::out | ios::binary);
			if (!output) { MessageBox::Show("�ļ�д���쳣!1"); output.close(); return false; }
			output.write((char*)p, sizeof(player));
			output.close();
			delete p;
			return true;
		}
		//readLoginInfo()�����ӵ�½�����ļ���ȡ�û���Ϣ
		player*readLoginInfo(char*id)
		{
			player*p = new player();
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\login\\%s.dat", id);
			f. open(path, ios::in | ios::binary);
			if (!f) { f.close(); return nullptr; }
			f.read((char*)p, sizeof(player));
			f.close();
			return p;
		}
		//updateInfo()�����޸�����
		bool updateInfo(int type, char*id, char*oldpw, char*passwd)
		{
			player*p = new player();
			p = readLoginInfo(id);//��ȡ�û���Ϣ
			if(strcmp(oldpw,p->getpassword())==0&&p->gettype()==type)
			{//У��ɹ�
				p->setpassword(passwd);
				writeLoginInfo(p);
				return true;
			}
			delete p;
			return false;
		}
		//writechild()������δ��������Ϣд���ļ�
		bool writechild(childplayer*p)
		{
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\childplayer\\%s.dat", p->getid());
			f.open(path, ios::out | ios::binary);
			if (!f) { f.close(); MessageBox::Show("�ļ�д���쳣��2"); return false; }
			f.write((char*)p, sizeof(childplayer));
			f.close();
			return true;
		}
		//writeadult()��������������Ϣд���ļ�
		bool writeadult(adplayer*p)
		{
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\adplayer\\%s.dat", p->getid());
			f.open(path, ios::out | ios::binary);
			if (!f) { f.close(); MessageBox::Show("�ļ�д���쳣��3"); return false; }
			f.write((char*)p, sizeof(adplayer));
			f.close();
			return true;
		}
		//����InitRandSforchild����****���������������**********************
		int testRandSforchild()
		{
			int sum=9999999;
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\RandS\\RandS.dat");
			f.open(path, ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("�ļ���ȡ����3.4"); }
			f.read((char*)&sum, sizeof(int));
			f.close();
			return sum;
		}
		//��������ע��ʱд���û��������ͷ���������Ϊ�û�����
		bool InitRandSforchild(childplayer*p)
		{
			int sum;
			int rank;
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\RandS\\RandS.dat");
			f.open(path, ios::in | ios::out | ios::binary);
			if (!f)//��һ�δ����ļ�
			{
				f.close();
				sum = 0;
				f.open(path, ios::out | ios::binary);
				if (!f) { f.close(); MessageBox::Show("�ļ���д�쳣��3.5");	return false; }
				f.write((char*)&sum, sizeof(int));
				f.close();
			}
			else f.close();
			f.open(path, ios::in | ios::out | ios::binary);
			if (!f) { f.close(); MessageBox::Show("�ļ���д�쳣��4"); return false; }
			f.read((char*)&sum, sizeof(int));// write the sum of player
			/*if (sum == NULL)// ��һ�δ����ļ�
			{
				sum = 1;
				f.seekp(-long(sizeof(int)), ios::cur);
				f.write((char*)&sum, sizeof(int));
			}*/
			//else
			//{
				sum += 1;
				f.seekp(-long(sizeof(int)), ios::cur);
				f.write((char*)&sum, sizeof(int));
			//}
			f.seekg(0, ios::beg);//���ļ�ĩβ���һ����¼
			f.read((char*)&rank, sizeof(int));
			p->setscore(0);
			p->setrank(sum);
/*			f.seekp(long(sizeof(int)), ios::beg);
			f.seekp(long(sizeof(childplayer))*(sum-1), ios::cur);*/
			f.seekp(0, ios::end);
			f.write((char*)p, sizeof(childplayer));
			f.close();
			return true;
		}
		//��������ע��ʱд���û��������ͷ���������Ϊ�û�����adult
		bool InitRandSforadult(adplayer*p)
		{
			int sum;
			int rank ;
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\RandS\\RandS.dat");
			f.open(path, ios::in | ios::out | ios::binary);
			if (!f)//��һ�δ����ļ�
			{
				f.close();
				sum = 0;
				f.open(path, ios::out | ios::binary);
				if (!f) { f.close(); MessageBox::Show("�ļ���д�쳣��3.5");	return false; }
				f.write((char*)&sum, sizeof(int));
				f.close();
			}
			else f.close();
			f.open(path, ios::out | ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("�ļ���д�쳣��4"); return false; }
			f.read((char*)&sum, sizeof(int));// write the sum of player
/*			if (sum == NULL)// ��һ�δ����ļ�
			{
				sum = 1;
				f.seekp(-long(sizeof(int)), ios::cur);
				f.write((char*)&sum, sizeof(int));
			}
			else
			{*/
				sum += 1;
				f.seekp(-long(sizeof(int)), ios::cur);
				f.write((char*)&sum, sizeof(int));
//			}
			f.seekg(0, ios::beg);
			f.read((char*)&rank, sizeof(int));
			p->setscore(0);
			p->setrank(sum);
			f.seekp(0, ios::end);
			f.write((char*)p, sizeof(adplayer));
			f.close();
			return true;
		}
		//�������ڸ�����ҷ���
		bool writeRandSforadult(adplayer*p, int addsorce)
		{
			adplayer temp;
			int sum;
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\RandS\\RandS.dat");
			f.open(path, ios::out | ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("�ļ���д�쳣��5"); return false; }
			f.read((char*)&sum, sizeof(int));
			f.seekg(long(sizeof(int)), ios::beg);
			for (int i = 0; i < sum; i++)
			{
				//f.seekg(long(sizeof(childplayer))*i, ios::cur);
				f.read((char*)&temp, sizeof(adplayer));
				if (strcmp(temp.getid(), p->getid()) == 0) {
					//cout << "1" << endl;
					break;
				}
			}
			/*			do
						{
							//��һ��adplayer��¼
							f.read((char*)&temp, sizeof(adplayer));
						} while (temp.getid() != p->getid());*/
			if (strcmp(temp.getid(), p->getid()) == 0)
			{
				int Sorce = temp.getscore() + addsorce;
				p->setscore(Sorce);
				f.seekp(-long(sizeof(adplayer)), ios::cur);
				f.write((char*)p, sizeof(adplayer));
			}
			else { cout << "not find����" << endl; f.close(); return false; }
			f.close();
			return true;
		}
		
		//�������ڸ�����ҷ���
		bool writeRandSforchild(childplayer*p, int addsorce)
		{
			childplayer temp;
//			char tempp[30] = {0};
//			strcpy(tempp, p->getid());
			int sum;
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\RandS\\RandS.dat");
			f.open(path, ios::out | ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("�ļ���д�쳣��5"); return false; }
			f.read((char*)&sum, sizeof(int));
			f.seekg(long(sizeof(int)), ios::beg);
			for (int i = 0; i < sum; i++)
			{
				//f.seekg(long(sizeof(childplayer))*i, ios::cur);
				f.read((char*)&temp, sizeof(childplayer));
				if (strcmp(temp.getid(), p->getid()) == 0) {
					//cout << "1" << endl; 
					break;
				}
			}
/*			do
			{
				//��һ��adplayer
				f.read((char*)&temp, sizeof(childplayer));
			} while (temp->getid() != p->getid());*/
			if (strcmp(temp.getid(), p->getid()) == 0)
			{
				int Sorce = temp.getscore() + addsorce;
				p->setscore(Sorce);
				f.seekp(-long(sizeof(childplayer)), ios::cur);
				f.write((char*)p, sizeof(childplayer));
			}
			else { cout << "not find����" << endl; f.close(); return false; }
			f.close();
			return true;
		}
//ɨ�ס�cleanmines����Ϸ��ע��ʱ�����������а���Ϸʱ���ķ���***********************************************************
//*************************���������������**********************
		int testCMRandSforchild()
		{
			int sum = 9999999;
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\RandS\\CMRandS.dat");
			f.open(path, ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("�ļ���ȡ����3.4"); }
			f.read((char*)&sum, sizeof(int));
			f.close();
			return sum;
		}
		//��������ע��ʱд���û��������ͷ���������Ϊ�û�����
		bool InitCMRandSforchild(childplayer*p)
		{
			int sum;
			int rank;
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\RandS\\CMRandS.dat");
			f.open(path, ios::in | ios::out | ios::binary);
			if (!f)//��һ�δ����ļ�
			{
				f.close();
				sum = 0;
				f.open(path, ios::out | ios::binary);
				if (!f) { f.close(); MessageBox::Show("�ļ���д�쳣��3.5");	return false; }
				f.write((char*)&sum, sizeof(int));
				f.close();
			}
			else f.close();
			f.open(path, ios::in | ios::out | ios::binary);
			if (!f) { f.close(); MessageBox::Show("�ļ���д�쳣��4"); return false; }
			f.read((char*)&sum, sizeof(int));// write the sum of player
											 /*if (sum == NULL)// ��һ�δ����ļ�
											 {
											 sum = 1;
											 f.seekp(-long(sizeof(int)), ios::cur);
											 f.write((char*)&sum, sizeof(int));
											 }*/
											 //else
											 //{
			sum += 1;
			f.seekp(-long(sizeof(int)), ios::cur);
			f.write((char*)&sum, sizeof(int));
			//}
			f.seekg(0, ios::beg);//���ļ�ĩβ���һ����¼
			f.read((char*)&rank, sizeof(int));
			p->setscore(0);
			p->setrank(sum);
			/*			f.seekp(long(sizeof(int)), ios::beg);
			f.seekp(long(sizeof(childplayer))*(sum-1), ios::cur);*/
			f.seekp(0, ios::end);
			f.write((char*)p, sizeof(childplayer));
			f.close();
			return true;
		}
		//��������ע��ʱд���û��������ͷ���������Ϊ�û�����adult
		bool InitCMRandSforadult(adplayer*p)
		{
			int sum;
			int rank;
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\RandS\\CMRandS.dat");
			f.open(path, ios::in | ios::out | ios::binary);
			if (!f)//��һ�δ����ļ�
			{
				f.close();
				sum = 0;
				f.open(path, ios::out | ios::binary);
				if (!f) { f.close(); MessageBox::Show("�ļ���д�쳣��3.5");	return false; }
				f.write((char*)&sum, sizeof(int));
				f.close();
			}
			else f.close();
			f.open(path, ios::out | ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("�ļ���д�쳣��4"); return false; }
			f.read((char*)&sum, sizeof(int));// write the sum of player
											 /*			if (sum == NULL)// ��һ�δ����ļ�
											 {
											 sum = 1;
											 f.seekp(-long(sizeof(int)), ios::cur);
											 f.write((char*)&sum, sizeof(int));
											 }
											 else
											 {*/
			sum += 1;
			f.seekp(-long(sizeof(int)), ios::cur);
			f.write((char*)&sum, sizeof(int));
			//			}
			f.seekg(0, ios::beg);
			f.read((char*)&rank, sizeof(int));
			p->setscore(0);
			p->setrank(sum);
			f.seekp(0, ios::end);
			f.write((char*)p, sizeof(adplayer));
			f.close();
			return true;
		}
		//�������ڸ�����ҷ���
		bool writeCMRandSforadult(adplayer*p, int addsorce)
		{
			adplayer temp;
			int sum;
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\RandS\\CMRandS.dat");
			f.open(path, ios::out | ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("�ļ���д�쳣��5"); return false; }
			f.read((char*)&sum, sizeof(int));
			f.seekg(long(sizeof(int)), ios::beg);
			for (int i = 0; i < sum; i++)
			{
				//f.seekg(long(sizeof(childplayer))*i, ios::cur);
				f.read((char*)&temp, sizeof(adplayer));
				if (strcmp(temp.getid(), p->getid()) == 0) {
					//cout << "1" << endl;
					break;
				}
			}
			/*			do
			{
			//��һ��adplayer��¼
			f.read((char*)&temp, sizeof(adplayer));
			} while (temp.getid() != p->getid());*/
			if (strcmp(temp.getid(), p->getid()) == 0)
			{
				int Sorce = temp.getscore() + addsorce;
				p->setscore(Sorce);
				f.seekp(-long(sizeof(adplayer)), ios::cur);
				f.write((char*)p, sizeof(adplayer));
			}
			else { cout << "not find����" << endl; f.close(); return false; }
			f.close();
			return true;
		}

		//�������ڸ�����ҷ���
		bool writeCMRandSforchild(childplayer*p, int addsorce)
		{
			childplayer temp;
			//			char tempp[30] = {0};
			//			strcpy(tempp, p->getid());
			int sum;
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\RandS\\CMRandS.dat");
			f.open(path, ios::out | ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("�ļ���д�쳣��5"); return false; }
			f.read((char*)&sum, sizeof(int));
			f.seekg(long(sizeof(int)), ios::beg);
			for (int i = 0; i < sum; i++)
			{
				//f.seekg(long(sizeof(childplayer))*i, ios::cur);
				f.read((char*)&temp, sizeof(childplayer));
				if (strcmp(temp.getid(), p->getid()) == 0) {
					//cout << "��" ;
					break;
				}
			}
			/*			do
			{
			//��һ��adplayer
			f.read((char*)&temp, sizeof(childplayer));
			} while (temp->getid() != p->getid());*/
			if (strcmp(temp.getid(), p->getid()) == 0)
			{
				int Sorce = temp.getscore() + addsorce;
				p->setscore(Sorce);
				f.seekp(-long(sizeof(childplayer)), ios::cur);
				f.write((char*)p, sizeof(childplayer));
			}
			else { cout << "not find����" << endl; f.close(); return false; }
			f.close();
			return true;
		}


		//deleteLoginInfo()����ɾ���û���½��Ϣ
		bool deleteLoginInfo(char*id)
		{
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\login\\%s.dat",id);
			if (!remove(path)) {
				return true;
			}
			return false;
		}

		//deleteUserdata()����ɾ���û�����
		bool deleteUserdata(char*id, int type)
		{
			char path[100];
			if (type == (int)userTypecode::user_adplayer)//ɾ�����������
				sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\adplayer\\%s.dat", id);
			else if (type == (int)userTypecode::user_childplayer)//ɾ��δ���������
				sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\childplayer\\%s.dat", id);
			if (!remove(path)) {
				return true;
			}
			return false;
		}
	};
}