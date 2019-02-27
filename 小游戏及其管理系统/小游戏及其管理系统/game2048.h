#pragma once
#include"2048_alg.h"

namespace С��Ϸ�������ϵͳ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ManagementSystemV5;

	/// <summary>
	/// My2048 ժҪ
	/// </summary>
	public ref class My2048 : public System::Windows::Forms::Form
	{
	public:
		My2048(void)
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
		~My2048()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  ��ʼToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  x3ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  x4ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  x5ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����AToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox1;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->��ʼToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->x3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->x4ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->x5ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����AToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->��ʼToolStripMenuItem,
					this->����AToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(641, 32);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ��ʼToolStripMenuItem
			// 
			this->��ʼToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->x3ToolStripMenuItem,
					this->x4ToolStripMenuItem, this->x5ToolStripMenuItem
			});
			this->��ʼToolStripMenuItem->Name = L"��ʼToolStripMenuItem";
			this->��ʼToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::S));
			this->��ʼToolStripMenuItem->Size = System::Drawing::Size(80, 28);
			this->��ʼToolStripMenuItem->Text = L"��ʼ(&S)";
			// 
			// x3ToolStripMenuItem
			// 
			this->x3ToolStripMenuItem->Name = L"x3ToolStripMenuItem";
			this->x3ToolStripMenuItem->Size = System::Drawing::Size(126, 30);
			this->x3ToolStripMenuItem->Text = L"3X3";
			this->x3ToolStripMenuItem->Click += gcnew System::EventHandler(this, &My2048::x3ToolStripMenuItem_Click);
			// 
			// x4ToolStripMenuItem
			// 
			this->x4ToolStripMenuItem->Name = L"x4ToolStripMenuItem";
			this->x4ToolStripMenuItem->Size = System::Drawing::Size(126, 30);
			this->x4ToolStripMenuItem->Text = L"4X4";
			this->x4ToolStripMenuItem->Click += gcnew System::EventHandler(this, &My2048::x4ToolStripMenuItem_Click);
			// 
			// x5ToolStripMenuItem
			// 
			this->x5ToolStripMenuItem->Name = L"x5ToolStripMenuItem";
			this->x5ToolStripMenuItem->Size = System::Drawing::Size(126, 30);
			this->x5ToolStripMenuItem->Text = L"5X5";
			this->x5ToolStripMenuItem->Click += gcnew System::EventHandler(this, &My2048::x5ToolStripMenuItem_Click);
			// 
			// ����AToolStripMenuItem
			// 
			this->����AToolStripMenuItem->Name = L"����AToolStripMenuItem";
			this->����AToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::A));
			this->����AToolStripMenuItem->Size = System::Drawing::Size(83, 28);
			this->����AToolStripMenuItem->Text = L"����(&A)";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"����", 20));
			this->textBox1->Location = System::Drawing::Point(46, 67);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(534, 516);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"Welcome\r\nclick menu to start";
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &My2048::textBox1_KeyDown);
			// 
			// My2048
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(641, 627);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"My2048";
			this->Text = L"My2048";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void x3ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		_2048.input(3);
		_2048.start();
		String^s = gcnew String(_2048.board.display().c_str());
		textBox1->Text = s;
	}
private: System::Void x4ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	_2048.input(4);
	_2048.start();
	String^s = gcnew String(_2048.board.display().c_str());
	textBox1->Text = s;
}
private: System::Void x5ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	_2048.input(5);
	_2048.start();
	String^s = gcnew String(_2048.board.display().c_str());
	textBox1->Text = s;
}
private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (_2048.board.block)
	{
		if (!_2048.over)
		{
			switch (e->KeyValue)
			{
			case 37: _2048.board.block_to_left(); break;
			case 38: _2048.board.block_up(); break;
			case 39: _2048.board.block_to_right(); break;
			case 40: _2048.board.block_down(); break;
			default:break;
			}
			String^s = gcnew String(_2048.board.display().c_str());
			textBox1->Text = s;
			_2048.judge();
			if (_2048.over)
				textBox1->AppendText("\r\ngame over\r\nclick menu to restart\r\n");
		}
		else
		{
			String^s = gcnew String(_2048.board.display().c_str());
			textBox1->Text = s;
			textBox1->AppendText("\r\ngame over\r\nclick menu to restart\r\n");
		}
	}
}

};
}
