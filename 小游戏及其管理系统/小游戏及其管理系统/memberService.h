//memberService.h
#pragma once
#include"user.h"
#include"typeDefinition.h"
#include"Storage.h"
#include<vector>
//���������ռ� ManagementSystemV5
namespace ManagementSystemV5
{
	using namespace Runtime::InteropServices;
	//�����û�������User,ʵ�ֵ�½���޸�����
	public class User
	{
	public:
		//login()��������Ϊ  id�����룬����
		player*login(char*id, char*passwd, loginUsertype type)
		{
			Storage storage;
			return storage.login(id, passwd, type);//���õ�½����
		}
		//�޸�����
		bool updatePasswd(int flag, char*idName, char*oldpw, char*passwd)
		{
			Storage storage;
			return storage.updateInfo(flag, idName, oldpw, passwd);
		}
	};//User�ඨ�����
	public class Fchildplayer :public User
	{
	public:
		//����˺����뵽��½��Ϣ�ļ�
		bool writeInitLoginInfo(char*id, char*passwd, int type) {
			Storage storage;
			player*p = new player();
			p->setid(id);
			p->setpassword(passwd);
			p->settype(type);
			return storage.writeLoginInfo(p);
		}
		//�����������������**********************************
		int test()
		{
			Storage storage;
			return storage.testRandSforchild();
		}
		//����ɨ���������**************************************
		int CM_test()
		{
			Storage storage;
			return storage.testCMRandSforchild();
		}
		//���δ�������û���Ϣ���ļ�
		bool writechild(childplayer*p) {
			Storage storage;
			return storage.writechild(p);
		}
		//����Ϸ�и����û��������ܺ���
		bool writeaddSforchild(childplayer*p, int sorce)
		{
			//childplayer*pp = p;
			Storage storage;
			return storage.writeRandSforchild(p, sorce);
		}
		//����û�ʱ��ʼ����Ϸ���������ļ�
		bool InitRandSforchildplayer(childplayer*p) {
			Storage storage;
			return storage.InitRandSforchild(p);
		}
//ɨ����Ϸ�������й��ܿ�*******************************************************************
		//����Ϸ�и����û��������ܺ���
		bool CMwriteaddSforchild(childplayer*p, int sorce)
		{
			//childplayer*pp = p;
			Storage storage;
			return storage.writeCMRandSforchild(p, sorce);
		}
		//����û�ʱ��ʼ����Ϸ���������ļ�
		bool InitCMRandSforchildplayer(childplayer*p) {
			Storage storage;
			return storage.InitCMRandSforchild(p);
		}

	};
	public class Fadplayer :public User
	{
	public:
		//����˺����뵽��½��Ϣ�ļ�
		bool writeInitLoginInfo(char*id, char*passwd, int type) {
			Storage storage;
			player*p = new player();
			p->setid(id);
			p->setpassword(passwd);
			p->settype(type);
			return storage.writeLoginInfo(p);
		}
		//�������û�������ӳ����˺�δ�������û�
		bool writeadult(adplayer*p) {
			Storage storage;
			return storage.writeadult(p);
		}
		bool writechild(childplayer*p) {
			Storage storage;
			return storage.writechild(p);
		}
		//����û�ʱ��ʼ����Ϸ���������ļ�
		bool InitRandSforadplayer(adplayer*p) {
			Storage storage;
			return storage.InitRandSforadult(p);
		}
		//����Ϸ�и����û��������ܺ���
		bool writeaddSforadult(adplayer*p, int sorce)
		{
			Storage storage;
			return storage.writeRandSforadult(p, sorce);
		}
//ɨ����Ϸ�������й��ܿ�*******************************************************************
       //����û�ʱ��ʼ����Ϸ���������ļ�
		bool InitCMRandSforadplayer(adplayer*p) {
			Storage storage;
			return storage.InitCMRandSforadult(p);
		}
		//����Ϸ�и����û��������ܺ���
		bool CMwriteaddSforadult(adplayer*p, int sorce)
		{
			Storage storage;
			return storage.writeCMRandSforadult(p, sorce);
		}

		//ɾ��ָ��ID�˻�
		bool deleteAccount(char*id) {
			Storage storage;
			player *p = storage.readLoginInfo(id);
			if (!storage.deleteLoginInfo(id)) return false;
			if (!storage.deleteUserdata(id, p->gettype())) return false;
			return true;
		}
	
		//����ҵ�½��Ϣ
		player *readplayerInfo(char *id) {
			Storage storage;
			return storage.readLoginInfo(id);
		}
	};
}