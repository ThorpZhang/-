#pragma once
#include"user.h"
#include"memberService.h"
#include"typeDefinition.h"
#include"Storage.h"
#include<stdlib.h>
#include"pushbox.h"
#include"RandSUI.h"
#include"pushboxUI.h"
#include<ctime>
#include"G2048.h"
#include"cleanmines.h"
#include"CMRandSUI.h"
//#include"cleanmines.h"

//#include"outputRandS.h"

namespace С��Ϸ�������ϵͳ {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace ManagementSystemV5;
	/// <summary>
	/// childplayerForm ժҪ
	/// </summary>
/*	public  ref class mythread
	{
	public:
		childplayer* thechild;
		mythread(childplayer * child1) { thechild = child1; }
		void playgame()
		{
			play1(this->thechild);
		}
	};*/
/*	public  ref class mythread
	{
	public:
		childplayer* thechild;
		mythread(childplayer * child1) { thechild = child1; }
		void playgame()
		{
			child_play_cleanmines(this->thechild);
		}
	};  */
	public ref class childplayerForm : public System::Windows::Forms::Form
	{
	public:
		childplayerForm(player*a)
		{
			//��player����ת��Ϊchildplayer����
			childplayer*p = new childplayer();
			fstream f;
			char path[100];
			sprintf(path, "D:\\С��Ϸ����ϵͳ�洢\\childplayer\\%s.dat",a->getid() );
			f.open(path, ios::in | ios::binary);
			if (!f) { f.close(); now = (childplayer*)a; }
			f.read((char*)p, sizeof(childplayer));
			f.close();
			now = p;
//			now = a;
			InitializeComponent();
			//
			//TODO:  �ڴ˴���ӹ��캯������
			//
		}
	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~childplayerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  game1;
	protected:

	protected:

			 childplayer*now;
	private: System::Windows::Forms::Button^  button2;

	protected:

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  RandS;


	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ�޸�
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(childplayerForm::typeid));
			this->game1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->RandS = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// game1
			// 
			this->game1->Location = System::Drawing::Point(33, 26);
			this->game1->Name = L"game1";
			this->game1->Size = System::Drawing::Size(175, 40);
			this->game1->TabIndex = 0;
			this->game1->Text = L"ֲ���ս��ʬ";
			this->game1->UseVisualStyleBackColor = true;
			this->game1->Click += gcnew System::EventHandler(this, &childplayerForm::game1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(33, 72);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(175, 47);
			this->button2->TabIndex = 1;
			this->button2->Text = L"������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &childplayerForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(33, 201);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(175, 47);
			this->button3->TabIndex = 2;
			this->button3->Text = L"̹�˴�ս";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &childplayerForm::button3_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(33, 138);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(175, 47);
			this->button1->TabIndex = 3;
			this->button1->Text = L"2048";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &childplayerForm::button1_Click);
			// 
			// RandS
			// 
			this->RandS->Location = System::Drawing::Point(341, 107);
			this->RandS->Name = L"RandS";
			this->RandS->Size = System::Drawing::Size(161, 68);
			this->RandS->TabIndex = 4;
			this->RandS->Text = L"�鿴�����ӻ��ֺ�����";
			this->RandS->UseVisualStyleBackColor = true;
			this->RandS->Click += gcnew System::EventHandler(this, &childplayerForm::button4_Click);
			// 
			// childplayerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(529, 300);
			this->Controls->Add(this->RandS);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->game1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"childplayerForm";
			this->Text = L"δ�����˴��ڶ�";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		srand((unsigned int)time(0));        //��ʱ������
		if (Application::OpenForms["G2048"] == nullptr) {
			G2048^adone = gcnew G2048();
			adone->Show();
		}
		else {
			Application::OpenForms["G2048"]->Show();
		}
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
/*		Fchildplayer*test = new Fchildplayer();
		cout << test->test() << endl;*/
		//doRandS();
		if (Application::OpenForms["RandSUI"] == nullptr) {
			RandSUI^adone = gcnew RandSUI();
			adone->Show();
		}
		else {
			Application::OpenForms["RandSUI"]->Show();
		}
	}
private: System::Void game1_Click(System::Object^  sender, System::EventArgs^  e) {
/*	ThreadStart^threadDelegate = gcnew ThreadStart(&ManagementSystemV5::play1);
	//Thread ^thread1 = gcnew Thread (gcnew ThreadStart());
	Thread ^newthread = gcnew Thread(threadDelegate);
	newthread->Start();*/
	WinExec("./res_s/Debug/Plants vs Zombies.exe", SW_SHOW); //D:\A���ѧϰ\Visual Studio\PVZ\Plants vs Zombies\Debug
/*	mythread ^t = gcnew mythread((childplayer*)now);
	ThreadStart ^ts = gcnew ThreadStart(t,&mythread::playgame);
	Thread ^thread = gcnew Thread(ts);
	thread->Start();*/
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Application::OpenForms["pushboxUI"] == nullptr) {
		pushboxUI^adone = gcnew pushboxUI(now);
		adone->Show();
	}
	else{
		Application::OpenForms["pushboxUI"]->Show();
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	/*if (Application::OpenForms["CMRandSUI"] == nullptr) {
		CMRandSUI^adone = gcnew CMRandSUI();
		adone->Show();
	}
	else {
		Application::OpenForms["CMRandSUI"]->Show();
	}*/
	WinExec("./res_s/MyTankWar/64.exe", SW_SHOW);
}
};
}
