#pragma once

namespace flyGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::TextBox^  textBox1;
		System::Windows::Forms::TextBox^  textBox2;
		System::Windows::Forms::Button^  button1;
		System::Windows::Forms::Button^  button2;
		System::Windows::Forms::Button^  button3;
		System::Windows::Forms::CheckBox^  checkBox1;
		System::Windows::Forms::CheckBox^  checkBox2;
		System::Windows::Forms::CheckBox^  checkBox3;
		System::Windows::Forms::CheckBox^  checkBox4;
		System::Windows::Forms::CheckBox^  checkBox5;
		System::Windows::Forms::CheckBox^  checkBox6;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();

			// label1
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Location = System::Drawing::Point(8, 94);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 19);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Field of View";

			// label2
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label2->Location = System::Drawing::Point(231, 94);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 19);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Zoom";

			// textBox1
			this->textBox1->Location = System::Drawing::Point(12, 116);
			this->textBox1->MaxLength = 5;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(96, 27);
			this->textBox1->TabIndex = 11;
			this->textBox1->Text = L"1.57";

			// textBox2
			this->textBox2->Location = System::Drawing::Point(186, 116);
			this->textBox2->MaxLength = 6;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(96, 27);
			this->textBox2->TabIndex = 13;
			this->textBox2->Text = L"19.569";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;

			// button1
			this->button1->Location = System::Drawing::Point(12, 32);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(269, 34);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Attach";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);

			// button2
			this->button2->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(12, 149);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(96, 27);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Change FoV";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);

			// button3
			this->button3->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(186, 149);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(96, 27);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Change Zoom";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);

			// checkBox1
			this->checkBox1->AutoSize = true;
			this->checkBox1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->checkBox1->Location = System::Drawing::Point(17, 211);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(79, 23);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Terrain";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);

			// checkBox2
			this->checkBox2->AutoSize = true;
			this->checkBox2->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->checkBox2->Location = System::Drawing::Point(17, 240);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(49, 23);
			this->checkBox2->TabIndex = 6;
			this->checkBox2->Text = L"M2";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);

			// checkBox3
			this->checkBox3->AutoSize = true;
			this->checkBox3->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->checkBox3->Location = System::Drawing::Point(17, 269);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(66, 23);
			this->checkBox3->TabIndex = 7;
			this->checkBox3->Text = L"WMO";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox3_CheckedChanged);

			// checkBox4
			this->checkBox4->AutoSize = true;
			this->checkBox4->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->checkBox4->Location = System::Drawing::Point(180, 211);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(71, 23);
			this->checkBox4->TabIndex = 8;
			this->checkBox4->Text = L"Liquid";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox4_CheckedChanged);

			// checkBox5
			this->checkBox5->AutoSize = true;
			this->checkBox5->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->checkBox5->Location = System::Drawing::Point(180, 240);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(101, 23);
			this->checkBox5->TabIndex = 9;
			this->checkBox5->Text = L"Wireframe";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox5_CheckedChanged);

			// checkBox6
			this->checkBox6->AutoSize = true;
			this->checkBox6->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->checkBox6->Location = System::Drawing::Point(180, 269);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(88, 23);
			this->checkBox6->TabIndex = 10;
			this->checkBox6->Text = L"Collision";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox6_CheckedChanged);

			// Form1
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Desktop;
			this->ClientSize = System::Drawing::Size(294, 309);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"flyui";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e){}

	// ATTACH
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);

	// TERRAIN
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	// M2
	private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	// WMO
	private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	// LIQUID
	private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	// WIREFRAME
	private: System::Void checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	// COLLISION
	private: System::Void checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	// FOV
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);

	// ZOOM
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
};
}

