#pragma once
#include <msclr\marshal.h>  
#include"user.h"
#include"Storage.h"
#include"memberService.h"
#include"typeDefinition.h"

namespace С��Ϸ�������ϵͳ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ManagementSystemV5;
	using namespace msclr::interop;
	/// <summary>
	/// RandSUI ժҪ
	/// </summary>
	struct Player
	{
		char name[30];
		int sorce;
		int rank;
		char id[30];
	};
	public ref class RandSUI : public System::Windows::Forms::Form
	{
	public:
		RandSUI(void)
		{
			InitializeComponent();
			//
			//TODO:  �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~RandSUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	protected:

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
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Font = (gcnew System::Drawing::Font(L"����", 12));
			this->listView1->Location = System::Drawing::Point(12, 23);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(952, 441);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &RandSUI::listView1_SelectedIndexChanged);
			// 
			// RandSUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(974, 482);
			this->Controls->Add(this->listView1);
			this->Name = L"RandSUI";
			this->Text = L"���ֺ�����";
			this->Load += gcnew System::EventHandler(this, &RandSUI::RandSUI_Load);
			this->ResumeLayout(false);

		}

		void InitializeListView() {
			//**********************************����*********************************************************
			int sum = 0;//��ȡ�������
			Fchildplayer*child = new Fchildplayer();
			sum = child->test();
			Player pa[11];//���а�ֻ��ʾ10λ���
			if (sum > 10) sum = 10;
			//��sorce����������жϱ�־
			for (int i = 0; i < 11; i++) {
				pa[i].sorce = -1;
			}
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
			//*********************************************�������*********************************************************
			this->listView1->View = System::Windows::Forms::View::Details;
			ColumnHeader^columnHeader1 = gcnew ColumnHeader;
			columnHeader1->Text = "����";
			columnHeader1->TextAlign = HorizontalAlignment::Left;
			columnHeader1->Width = 200;
			ColumnHeader^columnHeader2 = gcnew ColumnHeader;
			columnHeader2->Text = "����";
			columnHeader2->TextAlign = HorizontalAlignment::Center;
			columnHeader2->Width = 200;
			ColumnHeader^columnHeader3 = gcnew ColumnHeader;
			columnHeader3->Text = "����";
			columnHeader3->TextAlign = HorizontalAlignment::Right;
			columnHeader3->Width = 200;
			this->listView1->Columns->Add(columnHeader1);
			this->listView1->Columns->Add(columnHeader2);
			this->listView1->Columns->Add(columnHeader3);
			cli::array<String^>^rankList = { "��һ��","�ڶ���","������","������","������","������","������","�ڰ���","�ھ���","��ʮ��" };
			cli::array<String^>^namelist = gcnew cli::array<String^,1>(rankList->Length);
			cli::array<String^>^sorce = gcnew	cli::array<String^>(rankList->Length);
			for (int count = 0; count < rankList->Length; count++) {
				if (pa[(count + 1)].sorce != -1) {
					namelist[count] = marshal_as<String^>(pa[(count + 1)].name);
				}
				else namelist[count] = "  ";
			}
			for (int count = 0; count < rankList->Length; count++) {
//				int a = -1;
				if (pa[(count + 1)].sorce !=-1 ) {
					sorce[count] = pa[(count + 1)].sorce.ToString();
//					sorce[count] = marshal_as<String^>(pa[(count+1)].sorce.ToString());
				}
				else sorce[count] = "   ";
			}
			for (int count = 0; count < rankList->Length; count++) {
				ListViewItem^listItem = gcnew ListViewItem(rankList[count]);
				listItem->SubItems->Add(namelist[count]);
				listItem->SubItems->Add(sorce[count]);
				this->listView1->Items->Add(listItem);
			}
		}
#pragma endregion
	private: System::Void RandSUI_Load(System::Object^  sender, System::EventArgs^  e) {
		InitializeListView();
	}
	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
