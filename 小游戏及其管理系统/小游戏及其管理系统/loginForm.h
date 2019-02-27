#pragma once
#include"user.h"
#include"typeDefinition.h"
#include"Storage.h"
#include"memberService.h"
#include"adplayerForm.h"
#include"childplayerForm.h"
#include"addchild.h"
#include"addadplayer.h"
#include<cstring>
#include<fstream>
#include<string>
#include<iostream>
#include<cstdio>

using namespace std;
using namespace ManagementSystemV5;
namespace С��Ϸ�������ϵͳ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// loginForm ժҪ
	/// </summary>
	public ref class loginForm : public System::Windows::Forms::Form
	{
	public:
		loginForm(void)
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
		~loginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  createbutton;

	private: System::Windows::Forms::Button^  loginbutton;
	private: System::Windows::Forms::RadioButton^  childradio;


	private: System::Windows::Forms::RadioButton^  adradio;

	private: System::Windows::Forms::TextBox^  pstbox;
	private: System::Windows::Forms::TextBox^  acctbox;
	private: System::Windows::Forms::Label^  pslabel;
	private: System::Windows::Forms::Label^  acclabel;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(loginForm::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->createbutton = (gcnew System::Windows::Forms::Button());
			this->loginbutton = (gcnew System::Windows::Forms::Button());
			this->childradio = (gcnew System::Windows::Forms::RadioButton());
			this->adradio = (gcnew System::Windows::Forms::RadioButton());
			this->pstbox = (gcnew System::Windows::Forms::TextBox());
			this->acctbox = (gcnew System::Windows::Forms::TextBox());
			this->pslabel = (gcnew System::Windows::Forms::Label());
			this->acclabel = (gcnew System::Windows::Forms::Label());
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"����", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox1->Location = System::Drawing::Point(155, 26);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(224, 53);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"��ӭʹ��";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::Transparent;
			this->groupBox2->Controls->Add(this->createbutton);
			this->groupBox2->Controls->Add(this->loginbutton);
			this->groupBox2->Controls->Add(this->childradio);
			this->groupBox2->Controls->Add(this->adradio);
			this->groupBox2->Controls->Add(this->pstbox);
			this->groupBox2->Controls->Add(this->acctbox);
			this->groupBox2->Controls->Add(this->pslabel);
			this->groupBox2->Controls->Add(this->acclabel);
			this->groupBox2->Location = System::Drawing::Point(35, 108);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(447, 176);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			// 
			// createbutton
			// 
			this->createbutton->Location = System::Drawing::Point(256, 137);
			this->createbutton->Name = L"createbutton";
			this->createbutton->Size = System::Drawing::Size(87, 39);
			this->createbutton->TabIndex = 7;
			this->createbutton->Text = L"ע��";
			this->createbutton->UseVisualStyleBackColor = true;
			this->createbutton->Click += gcnew System::EventHandler(this, &loginForm::createbutton_Click);
			// 
			// loginbutton
			// 
			this->loginbutton->Location = System::Drawing::Point(54, 137);
			this->loginbutton->Name = L"loginbutton";
			this->loginbutton->Size = System::Drawing::Size(87, 39);
			this->loginbutton->TabIndex = 6;
			this->loginbutton->Text = L"��½";
			this->loginbutton->UseVisualStyleBackColor = true;
			this->loginbutton->Click += gcnew System::EventHandler(this, &loginForm::loginbutton_Click);
			// 
			// childradio
			// 
			this->childradio->AutoSize = true;
			this->childradio->Location = System::Drawing::Point(239, 103);
			this->childradio->Name = L"childradio";
			this->childradio->Size = System::Drawing::Size(105, 22);
			this->childradio->TabIndex = 5;
			this->childradio->TabStop = true;
			this->childradio->Text = L"δ������";
			this->childradio->UseVisualStyleBackColor = true;
			// 
			// adradio
			// 
			this->adradio->AutoSize = true;
			this->adradio->Location = System::Drawing::Point(54, 103);
			this->adradio->Name = L"adradio";
			this->adradio->Size = System::Drawing::Size(69, 22);
			this->adradio->TabIndex = 4;
			this->adradio->TabStop = true;
			this->adradio->Text = L"�ҳ�";
			this->adradio->UseVisualStyleBackColor = true;
			this->adradio->CheckedChanged += gcnew System::EventHandler(this, &loginForm::adplayer_CheckedChanged);
			// 
			// pstbox
			// 
			this->pstbox->Location = System::Drawing::Point(83, 60);
			this->pstbox->Name = L"pstbox";
			this->pstbox->Size = System::Drawing::Size(282, 28);
			this->pstbox->TabIndex = 3;
			this->pstbox->UseSystemPasswordChar = true;
			// 
			// acctbox
			// 
			this->acctbox->Location = System::Drawing::Point(83, 10);
			this->acctbox->Name = L"acctbox";
			this->acctbox->Size = System::Drawing::Size(282, 28);
			this->acctbox->TabIndex = 2;
			this->acctbox->TextChanged += gcnew System::EventHandler(this, &loginForm::acctbox_TextChanged);
			// 
			// pslabel
			// 
			this->pslabel->AutoSize = true;
			this->pslabel->Location = System::Drawing::Point(17, 60);
			this->pslabel->Name = L"pslabel";
			this->pslabel->Size = System::Drawing::Size(44, 18);
			this->pslabel->TabIndex = 1;
			this->pslabel->Text = L"����";
			// 
			// acclabel
			// 
			this->acclabel->AutoSize = true;
			this->acclabel->Location = System::Drawing::Point(17, 10);
			this->acclabel->Name = L"acclabel";
			this->acclabel->Size = System::Drawing::Size(44, 18);
			this->acclabel->TabIndex = 0;
			this->acclabel->Text = L"�˺�";
			// 
			// loginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(517, 296);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"loginForm";
			this->Text = L"С��Ϸ����ϵͳ";
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private:player*thisLogin;
	private: System::Void acctbox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void adplayer_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void loginbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	//��֤�û���½��Ϣ
	String^accstr = acctbox->Text;
	String^psstr = pstbox->Text;
	char id[30], passwd[30];
	sprintf(id, "%s", accstr);
	sprintf(passwd, "%s", psstr);
	
    if (childradio->Checked)
	 {
		//δ�����˵�½
		Fchildplayer*child = new Fchildplayer();
		//thisLogin��¼��ǰ��½�û���������id ���� ����
		thisLogin = child->login(id, passwd, loginUsertype::login_childplayer);
		if (thisLogin != nullptr)
		{
			//childplayerFormΪδ��������ҳ������
			childplayerForm^ch = gcnew childplayerForm(thisLogin);
			this->Visible = false;
			ch->Show();
		}
		else {
			MessageBox::Show("�˻������������");
		}
	 }
	else
     {
	   //�ҳ���½,��ѡ��Ĭ�ϼҳ���½
		//Fadplayer�Ǽҳ������࣬ʵ�ּҳ�����
		Fadplayer*adult = new Fadplayer();
		thisLogin = adult->login(id, passwd, loginUsertype::login_adplayer);
		if (thisLogin != nullptr)
		{
			//�ҳ�������
			adplayerForm ^ad = gcnew adplayerForm(thisLogin);
			this->Hide();
			ad->Show();
		}
		//��Ĭ���˺�����ע��������û�
		else if ( accstr->Equals( "iamdad") && psstr->Equals( "iammom")) {
			if (Application::OpenForms["addadplayer"] == nullptr) {
				//��һ����ʾ�������´���
				addadplayer^adone = gcnew addadplayer();
				adone->Show();//��ʾ
			}
			else {
				Application::OpenForms["addadplayer"]->Show();//ֱ����ʾ
			}
		}
		else {
			MessageBox::Show("�˻������������");
		}
     }
}
private: System::Void createbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Application::OpenForms["addchild"] == nullptr) {
		//�����һ����ʾ�������´���
		addchild^adone = gcnew addchild();
		adone->Show();
	}
	else {
		Application::OpenForms["addchild"]->Show();//ֱ����ʾ
	}
}
};
}
