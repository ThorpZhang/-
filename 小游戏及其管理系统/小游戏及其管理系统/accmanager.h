#pragma once
#include"user.h"
#include"typeDefinition.h"
#include"Storage.h"
#include"memberService.h"
#include"addadplayer.h"
#include"deleteplayer.h"

namespace С��Ϸ�������ϵͳ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ManagementSystemV5;
	/// <summary>
	/// accmanager ժҪ
	/// </summary>
	public ref class accmanager : public System::Windows::Forms::Form
	{
	public:
		accmanager(void)
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
		~accmanager()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  createadplayer;
	private: System::Windows::Forms::Button^  deleteacc;
	protected:

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
			this->createadplayer = (gcnew System::Windows::Forms::Button());
			this->deleteacc = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// createadplayer
			// 
			this->createadplayer->Location = System::Drawing::Point(56, 48);
			this->createadplayer->Name = L"createadplayer";
			this->createadplayer->Size = System::Drawing::Size(134, 63);
			this->createadplayer->TabIndex = 0;
			this->createadplayer->Text = L"ע����������";
			this->createadplayer->UseVisualStyleBackColor = true;
			this->createadplayer->Click += gcnew System::EventHandler(this, &accmanager::createadplayer_Click);
			// 
			// deleteacc
			// 
			this->deleteacc->Location = System::Drawing::Point(56, 152);
			this->deleteacc->Name = L"deleteacc";
			this->deleteacc->Size = System::Drawing::Size(134, 64);
			this->deleteacc->TabIndex = 1;
			this->deleteacc->Text = L"ɾ���û�";
			this->deleteacc->UseVisualStyleBackColor = true;
			this->deleteacc->Click += gcnew System::EventHandler(this, &accmanager::deleteacc_Click);
			// 
			// accmanager
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(247, 267);
			this->Controls->Add(this->deleteacc);
			this->Controls->Add(this->createadplayer);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"accmanager";
			this->Text = L"accmanager";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void createadplayer_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Application::OpenForms["addadplayer"] == nullptr) {
			//�����״���ʾ�������´���
			addadplayer^adone = gcnew addadplayer();
			adone->Show();//��ʾ
		}
		else {
			Application::OpenForms["addadplayer"]->Show();//ֱ����ʾ
		}
	}
	private: System::Void deleteacc_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Application::OpenForms["deleteplayer"] == nullptr) {
			//�״Σ������´���
			deleteplayer^adone = gcnew deleteplayer();
			adone->Show();//��ʾ
		}
		else {
			Application::OpenForms["deleteplayer"]->Show();//ֱ����ʾ
		}
	}
	};
}
