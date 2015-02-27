#include "stdafx.h"
#include "Form1.h"
#include "Program.h"
#include "WoW.h"

using namespace std;

WoW program;
int userAction;

// ATTACH
System::Void flyGui::Form1::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	program = WoW();

	switch (program.getBaseAddress())
	{
	case 1:
		MessageBox::Show("FindWindow() Failed.");
		return;
	case 2:
		MessageBox::Show("GetWindowThreadProcessId() Failed.");
		return;
	case 3:
		MessageBox::Show("handleWoW == INVALID_HANDLE_VALUE");
		return;
	case 4:
		MessageBox::Show("Module32First returned FALSE");
		return;
	case 5:
		MessageBox::Show("setDebugPrivilegesEnabled() returned FALSE");
		return;
	}

	if (program.getProgramHandle() == NULL)
	{
		MessageBox::Show("OpenProcess() Failed.");
		return;
	}
	MessageBox::Show("Successfully attached.");
	program.setAttached(true);
}

//// FOV
System::Void flyGui::Form1::button2_Click(System::Object^  sender, System::EventArgs^  e)
{

	if (program.attached == FALSE)
	{
		MessageBox::Show("Please attach to the process first");
		return;
	}

	DWORD WoWbase_PLUS_D5153C;
	void * stepA = new DWORD;
	void * CameraPtr = new DWORD;
	void * stepC = new DWORD;

	WoWbase_PLUS_D5153C = program.getBaseAddress() + 14885016; // 14885016 is decimal notation of E32098

	int goodA = ReadProcessMemory(program.getProgramHandle(), (void*)WoWbase_PLUS_D5153C, &stepA, 4, 0);
	if (goodA == 0)
	{
		MessageBox::Show("Step A: ReadProcessMemory() failed. GetLastError() produced: " + GetLastError().ToString());
		return;
	}

	stepA = (char*)stepA + 0x7610; // Adds 0x7610 to pointer
	int goodB = ReadProcessMemory(program.getProgramHandle(), stepA, &CameraPtr, 4, 0);
	if (goodB == 0)
	{
		MessageBox::Show("Step B: ReadProcessMemory() failed. GetLastError() produced: " + GetLastError().ToString());
		return;
	}

	CameraPtr = (char*)CameraPtr + 0x38; // Adds 0x38 to pointer
	int goodC = ReadProcessMemory(program.getProgramHandle(), CameraPtr, &stepC, 4, 0);
	if (goodC == 0)
	{
		MessageBox::Show("Step C: ReadProcessMemory() failed. GetLastError() produced: " + GetLastError().ToString());
		return;
	}

	float newFoV = (float)Convert::ToDouble(this->textBox1->Text);
	int success = WriteProcessMemory(program.getProgramHandle(), CameraPtr, &newFoV, 4, 0);
	if (success == 0)
	{
		MessageBox::Show("4: Did not write FOV successfully. GetLastError() produced: " + GetLastError().ToString());
		return;
	}
}

// ZOOM
System::Void flyGui::Form1::button3_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		MessageBox::Show("Please attach to WoW first");
		return;
	}
//
//	DWORD WoWbase_PLUS_D5153C;
//	void * stepA = new DWORD;
//	void * CameraPtr = new DWORD;
//	void * stepC = new DWORD;
//
//	WoWbase_PLUS_D5153C = WoWbaseaddress + 13964604; // 13964604 is decimal notation of D5153C
//
//	int goodA = ReadProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_D5153C, &stepA, 4, 0);
//	error = GetLastError();
//	if (goodA == 0)
//	{
//		MessageBox::Show("Step A: ReadProcessMemory() failed. GetLastError() produced: " + error);
//		return;
//	}
//
//	stepA = (char*)stepA + 0x8150; // Adds 0x8150 to pointer
//	int goodB = ReadProcessMemory(actualWoWhandle, stepA, &CameraPtr, 4, 0);
//	error = GetLastError();
//	if (goodB == 0)
//	{
//		MessageBox::Show("Step B: ReadProcessMemory() failed. GetLastError() produced: " + error);
//		return;
//	}
//
//	CameraPtr = (char*)CameraPtr + 0x38; // Adds 0x38 to pointer
//
//	void * firstV = new DWORD; // 108 - 38 = D0 ::: 0x108 from CGCamera pointer
//	void * secondV = new DWORD; // D4 relative to FirstV
//	firstV = (char*)CameraPtr + 0xD0;
//	secondV = (char*)firstV + 0xD4;
//	float newZoom = (float)Convert::ToDouble(this->textBox2->Text);
//	int success1 = WriteProcessMemory(actualWoWhandle, firstV, &newZoom, 4, 0);
//	int error1 = GetLastError();
//	int success2 = WriteProcessMemory(actualWoWhandle, secondV, &newZoom, 4, 0);
//	int error2 = GetLastError();
//	if (success1 == 0 || success2 == 0)
//	{
//		MessageBox::Show("Did not write zoom successfully. GetLastError() produced: " + error1 + " + " + error2);
//		return;
//	}
}

// TERRAIN
System::Void flyGui::Form1::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		if (userAction == 1)
		{
			userAction = 0;
			checkBox1->Checked = false;
			MessageBox::Show("Please attach to WoW first");
			return;
		}
		userAction = 1;
		return;
	}
//	if (buttonone == 0)
//	{
//		currentRender = currentRender - 0x2;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonone = 1;
//	}
//	else
//	{
//		currentRender = currentRender + 0x2;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonone = 0;
//	}
}

// M2
System::Void flyGui::Form1::checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		if (userAction == 1)
		{
			userAction = 0;
			checkBox2->Checked = false;
			MessageBox::Show("Please attach to WoW first");
			return;
		}
		userAction = 1;
		return;
	}
//	if (buttontwo == 0)
//	{
//		currentRender = currentRender - 0x1;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttontwo = 1;
//	}
//	else
//	{
//		currentRender = currentRender + 0x1;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttontwo = 0;
//	}
}

// WMO
System::Void flyGui::Form1::checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		if (userAction == 1)
		{
			userAction = 0;
			checkBox3->Checked = false;
			MessageBox::Show("Please attach to WoW first");
			return;
		}
		userAction = 1;
		return;
	}
//	if (buttonthree == 0)
//	{
//		currentRender = currentRender - 0x20;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonthree = 1;
//	}
//	else
//	{
//		currentRender = currentRender + 0x20;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonthree = 0;
//	}
}

// LIQUID
System::Void flyGui::Form1::checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		if (userAction == 1)
		{
			userAction = 0;
			checkBox4->Checked = false;
			MessageBox::Show("Please attach to WoW first");
			return;
		}
		userAction = 1;
		return;
	}
//	if (buttonfour == 0)
//	{
//		currentRender = currentRender - 0x200;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonfour = 1;
//	}
//	else
//	{
//		currentRender = currentRender + 0x200;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonfour = 0;
//	}
}

// WIREFRAME
System::Void flyGui::Form1::checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		if (userAction == 1)
		{
			userAction = 0;
			checkBox5->Checked = false;
			MessageBox::Show("Please attach to WoW first");
			return;
		}
		userAction = 1;
		return;
	}
//	if (buttonfive == 0)
//	{
//		currentRender = currentRender + 0x08000000;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonfive = 1;
//	}
//	else
//	{
//		currentRender = currentRender - 0x08000000;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonfive = 0;
//	}
}

// COLLISION
System::Void flyGui::Form1::checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		if (userAction == 1)
		{
			userAction = 0;
			checkBox6->Checked = false;
			MessageBox::Show("Please attach to WoW first");
			return;
		}
		userAction = 1;
		return;
	}
//	if (buttonsix == 0)
//	{
//		currentRender = currentRender + 0x04000000;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonsix = 1;
//	}
//	else
//	{
//		currentRender = currentRender - 0x04000000;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonsix = 0;
//
//	}
}