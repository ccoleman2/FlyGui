#pragma once

#include "getbaseaddress.h"
#include "setdebug.h"

extern HWND windowHandle;
extern HANDLE actualWoWhandle;
extern DWORD WoWprocessID;
extern DWORD WoWbaseaddress;
extern DWORD currentRender;
extern int error;
extern int attached;
extern int buttonone, buttontwo, buttonthree, buttonfour, buttonfive, buttonsix;
extern int userAction;

namespace flyGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::CheckBox^  checkBox1;


	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button3;

	protected: 

	protected: 

	protected: 




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 32);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(269, 34);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Attach";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Location = System::Drawing::Point(8, 94);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 19);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Field of View";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label2->Location = System::Drawing::Point(231, 94);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 19);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Zoom";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->checkBox1->Location = System::Drawing::Point(17, 211);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(79, 23);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Terrain";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->checkBox2->Location = System::Drawing::Point(17, 240);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(49, 23);
			this->checkBox2->TabIndex = 6;
			this->checkBox2->Text = L"M2";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->checkBox3->Location = System::Drawing::Point(17, 269);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(66, 23);
			this->checkBox3->TabIndex = 7;
			this->checkBox3->Text = L"WMO";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox3_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->checkBox4->Location = System::Drawing::Point(180, 211);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(71, 23);
			this->checkBox4->TabIndex = 8;
			this->checkBox4->Text = L"Liquid";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox4_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->checkBox5->Location = System::Drawing::Point(180, 240);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(101, 23);
			this->checkBox5->TabIndex = 9;
			this->checkBox5->Text = L"Wireframe";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox5_CheckedChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->checkBox6->Location = System::Drawing::Point(180, 269);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(88, 23);
			this->checkBox6->TabIndex = 10;
			this->checkBox6->Text = L"Collision";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox6_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 116);
			this->textBox1->MaxLength = 5;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(96, 27);
			this->textBox1->TabIndex = 11;
			this->textBox1->Text = L"1.57";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(12, 149);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(96, 27);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Change FoV";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(186, 116);
			this->textBox2->MaxLength = 6;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(96, 27);
			this->textBox2->TabIndex = 13;
			this->textBox2->Text = L"19.569";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(186, 149);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(96, 27);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Change Zoom";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
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
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
	}
// ATTACH
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{	
		WoWbaseaddress = getbaseaddress();
		if (WoWbaseaddress == NULL)
		{
			MessageBox::Show("WoWbaseaddress is NULL.");
			return;
		}

		// FIND WINDOW
		windowHandle = FindWindow(0, L"Heroes of the Storm"); // returns HWND
		if (windowHandle == NULL)
		{	
			MessageBox::Show("FindWindow() Failed.");
			return;
		}

		// GET PROCESS' ID
		GetWindowThreadProcessId(windowHandle, &WoWprocessID);
		if (WoWprocessID == NULL)
		{	
			MessageBox::Show("GetWindowThreadProcessId() Failed.");	
			return;
		}
		
		// SET DEBUG PRIV
		EnableDebugPriv();
		error = GetLastError();
		if (error > 0)
		{
			MessageBox::Show("EnableDebugPriv() returned error: " + error);
		}
		
		// OPEN THE PROCESS
		actualWoWhandle = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_READ | PROCESS_VM_OPERATION, FALSE, WoWprocessID);
		error = GetLastError();
		if (actualWoWhandle == NULL)
		{
			MessageBox::Show("OpenProcess() Failed.");
			return;
		}
		MessageBox::Show("Successfully attached.");
		attached = 1;
	}
// TERRAIN
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (attached == 0)
		{
			if(userAction == 1)
			{
				userAction = 0;
				checkBox1->Checked = false;
				MessageBox::Show("Please attach to WoW first");
				return;
			}
			userAction = 1;
			return;
		}
		if (buttonone == 0)
		{
			currentRender = currentRender - 0x2;
			DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
			int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
			error = GetLastError();
			if (isSuccess == 0) 
			{	
				MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error); 
				return;
			}
			buttonone = 1;
		}
		else
		{
			currentRender = currentRender + 0x2;
			DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
			int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
			error = GetLastError();
			if (isSuccess == 0) 
			{	
				MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error); 
				return;
			}
			buttonone = 0;
		}
	}
// M2
	private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (attached == 0)
		{
			if(userAction == 1)
			{
				userAction = 0;
				checkBox2->Checked = false;
				MessageBox::Show("Please attach to WoW first");
				return;
			}
			userAction = 1;
			return;
		}
		if (buttontwo == 0)
		{
			currentRender = currentRender - 0x1;
			DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
			int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
			error = GetLastError();
			if (isSuccess == 0) 
			{	
				MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error); 
				return;
			}
			buttontwo = 1;
		}
		else
		{
			currentRender = currentRender + 0x1;
			DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
			int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
			error = GetLastError();
			if (isSuccess == 0) 
			{	
				MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error); 
				return;
			}
			buttontwo = 0;
		}
	}
// WMO
	private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (attached == 0)
		{
			if(userAction == 1)
			{
				userAction = 0;
				checkBox3->Checked = false;
				MessageBox::Show("Please attach to WoW first");
				return;
			}
			userAction = 1;
			return;
		}
		if (buttonthree == 0)
		{
			currentRender = currentRender - 0x20;
			DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
			int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
			error = GetLastError();
			if (isSuccess == 0) 
			{	
				MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error); 
				return;
			}
			buttonthree = 1;
		}
		else
		{
			currentRender = currentRender + 0x20;
			DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
			int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
			error = GetLastError();
			if (isSuccess == 0) 
			{	
				MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error); 
				return;
			}
			buttonthree = 0;
		}
	}
// LIQUID
	private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (attached == 0)
		{
			if(userAction == 1)
			{
				userAction = 0;
				checkBox4->Checked = false;
				MessageBox::Show("Please attach to WoW first");
				return;
			}
			userAction = 1;
			return;
		}
		if (buttonfour == 0)
		{
			currentRender = currentRender - 0x200;
			DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
			int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
			error = GetLastError();
			if (isSuccess == 0) 
			{	
				MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error); 
				return;
			}
			buttonfour = 1;
		}
		else
		{
			currentRender = currentRender + 0x200;
			DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
			int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
			error = GetLastError();
			if (isSuccess == 0) 
			{	
				MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error); 
				return;
			}
			buttonfour = 0;
		}
	}
// WIREFRAME
	private: System::Void checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (attached == 0)
		{
			if(userAction == 1)
			{
				userAction = 0;
				checkBox5->Checked = false;
				MessageBox::Show("Please attach to WoW first");
				return;
			}
			userAction = 1;
			return;
		}
		if (buttonfive == 0)
		{
			currentRender = currentRender + 0x08000000;
			DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
			int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
			error = GetLastError();
			if (isSuccess == 0) 
			{	
				MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error); 
				return;
			}
			buttonfive = 1;
		}
		else
		{
			currentRender = currentRender - 0x08000000;
			DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
			int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
			error = GetLastError();
			if (isSuccess == 0) 
			{	
				MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error); 
				return;
			}
			buttonfive = 0;
		}
	}
// COLLISION
	private: System::Void checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (attached == 0)
		{
			if(userAction == 1)
			{
				userAction = 0;
				checkBox6->Checked = false;
				MessageBox::Show("Please attach to WoW first");
				return;
			}
			userAction = 1;
			return;
		}
		if (buttonsix == 0)
		{
			currentRender = currentRender + 0x04000000;
			DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
			int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
			error = GetLastError();
			if (isSuccess == 0) 
			{	
				MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error); 
				return;
			}
			buttonsix = 1;
		}
		else
		{
			currentRender = currentRender - 0x04000000;
			DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
			int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
			error = GetLastError();
			if (isSuccess == 0) 
			{	
				MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error); 
				return;
			}
			buttonsix = 0;

		}
	}
// FOV
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (attached == 0)
		{
			MessageBox::Show("Please attach to WoW first ");
			return;
		}

		DWORD WoWbase_PLUS_D5153C;
		void * stepA = new DWORD;
		void * CameraPtr = new DWORD;
		void * stepC = new DWORD;

		WoWbase_PLUS_D5153C = WoWbaseaddress + 13964604; // 13964604 is decimal notation of D5153C

		int goodA = ReadProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_D5153C, &stepA, 4, 0);
		error = GetLastError();
		if (goodA == 0)
		{
			MessageBox::Show("Step A: ReadProcessMemory() failed. GetLastError() produced: " + error);
			return;
		}

		stepA = (char*)stepA + 0x8150; // Adds 0x8150 to pointer
		int goodB = ReadProcessMemory(actualWoWhandle, stepA, &CameraPtr, 4, 0);
		error = GetLastError();
		if (goodB == 0)
		{
			MessageBox::Show("Step B: ReadProcessMemory() failed. GetLastError() produced: " + error);
			return;
		}

		CameraPtr = (char*)CameraPtr + 0x38; // Adds 0x38 to pointer
		int goodC = ReadProcessMemory(actualWoWhandle, CameraPtr, &stepC, 4, 0);
		error = GetLastError();
		if (goodC == 0)
		{
			MessageBox::Show("Step C: ReadProcessMemory() failed. GetLastError() produced: " + error);
			return;
		}

		float newFoV =  (float)Convert::ToDouble(this->textBox1->Text);
		int success = WriteProcessMemory(actualWoWhandle, CameraPtr, &newFoV, 4, 0);
		error = GetLastError();
		if (success == 0) 
		{	
			MessageBox::Show("4: Did not write FOV successfully. GetLastError() produced: " + error);
			return;
		}
	}
// ZOOM
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (attached == 0)
		{
			MessageBox::Show("Please attach to WoW first");
			return;
		}

		DWORD WoWbase_PLUS_D5153C;
		void * stepA = new DWORD;
		void * CameraPtr = new DWORD;
		void * stepC = new DWORD;

		WoWbase_PLUS_D5153C = WoWbaseaddress + 13964604; // 13964604 is decimal notation of D5153C

		int goodA = ReadProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_D5153C, &stepA, 4, 0);
		error = GetLastError();
		if (goodA == 0)
		{
			MessageBox::Show("Step A: ReadProcessMemory() failed. GetLastError() produced: " + error);
			return;
		}

		stepA = (char*)stepA + 0x8150; // Adds 0x8150 to pointer
		int goodB = ReadProcessMemory(actualWoWhandle, stepA, &CameraPtr, 4, 0);
		error = GetLastError();
		if (goodB == 0)
		{
			MessageBox::Show("Step B: ReadProcessMemory() failed. GetLastError() produced: " + error);
			return;
		}

		CameraPtr = (char*)CameraPtr + 0x38; // Adds 0x38 to pointer
	
		void * firstV = new DWORD; // 108 - 38 = D0 ::: 0x108 from CGCamera pointer
		void * secondV = new DWORD; // D4 relative to FirstV
		firstV = (char*)CameraPtr + 0xD0;
		secondV = (char*)firstV + 0xD4;
		float newZoom = (float)Convert::ToDouble(this->textBox2->Text);
		int success1 = WriteProcessMemory(actualWoWhandle, firstV, &newZoom, 4, 0);
		int error1 = GetLastError();
		int success2 = WriteProcessMemory(actualWoWhandle, secondV, &newZoom, 4, 0);
		int error2 = GetLastError();
		if (success1 == 0 || success2 == 0) 
		{	
			MessageBox::Show("Did not write zoom successfully. GetLastError() produced: " + error1 + " + " + error2); 
			return;
		}
	}
};
}

