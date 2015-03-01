#include "stdafx.h"
#include "WoW.h"


WoW::WoW()
{
	setName(L"World of Warcraft");
	attached = FALSE;
}

bool WoW::changeFoV(float newFoV){
	DWORD WoWbase_Plus_ActiveCamera;
	void * stepA = new DWORD;
	void * CameraPtr = new DWORD;
	void * stepC = new DWORD;

	WoWbase_Plus_ActiveCamera = getBaseAddress() + 14885016; // E32098

	int goodA = ReadProcessMemory(getProgramHandle(), (void*)WoWbase_Plus_ActiveCamera, &stepA, 4, 0);
	if (goodA == 0)
	{
		flyGui::MessageBox::Show("Step A: ReadProcessMemory() failed. GetLastError() produced: " + GetLastError().ToString());
		return FALSE;
	}

	stepA = (char*)stepA + 0x7610; // Adds 0x7610 to pointer
	int goodB = ReadProcessMemory(getProgramHandle(), stepA, &CameraPtr, 4, 0);
	if (goodB == 0)
	{
		flyGui::MessageBox::Show("Step B: ReadProcessMemory() failed. GetLastError() produced: " + GetLastError().ToString());
		return FALSE;
	}

	CameraPtr = (char*)CameraPtr + 0x38; // Adds 0x38 to pointer
	int goodC = ReadProcessMemory(getProgramHandle(), CameraPtr, &stepC, 4, 0);
	if (goodC == 0)
	{
		flyGui::MessageBox::Show("Step C: ReadProcessMemory() failed. GetLastError() produced: " + GetLastError().ToString());
		return FALSE;
	}

	int success = WriteProcessMemory(getProgramHandle(), CameraPtr, &newFoV, 4, 0);
	if (success == 0)
	{
		flyGui::MessageBox::Show("4: Did not write FOV successfully. GetLastError() produced: " + GetLastError().ToString());
		return FALSE;
	}

	return TRUE;
}

bool WoW::changeZoom(float newZoom){
	DWORD WoWbase_Plus_ActiveCamera;
	void * stepA = new DWORD;
	void * CameraPtr = new DWORD;
	void * stepC = new DWORD;

	WoWbase_Plus_ActiveCamera = getBaseAddress() + 14885016; // E32098

	int goodA = ReadProcessMemory(getProgramHandle(), (void*)WoWbase_Plus_ActiveCamera, &stepA, 4, 0);
	if (goodA == 0)
	{
		flyGui::MessageBox::Show("Step A: ReadProcessMemory() failed. GetLastError() produced: " + GetLastError().ToString());
		return FALSE;
	}

	stepA = (char*)stepA + 0x7610; // Adds 0x7610 to pointer
	int goodB = ReadProcessMemory(getProgramHandle(), stepA, &CameraPtr, 4, 0);
	if (goodB == 0)
	{
		flyGui::MessageBox::Show("Step B: ReadProcessMemory() failed. GetLastError() produced: " + GetLastError().ToString());
		return FALSE;
	}

	CameraPtr = (char*)CameraPtr + 0x38; // Adds 0x38 to pointer

	void * firstV = new DWORD;
	void * secondV = new DWORD;
	firstV = (char*)CameraPtr + 0xEC; // EC
	secondV = (char*)firstV + 0xE4; // ^ + E4

	int success1 = WriteProcessMemory(getProgramHandle(), firstV, &newZoom, 4, 0);
	int error1 = GetLastError();
	int success2 = WriteProcessMemory(getProgramHandle(), secondV, &newZoom, 4, 0);
	int error2 = GetLastError();
	if (success1 == 0 || success2 == 0)
	{
		flyGui::MessageBox::Show("Did not write zoom successfully. GetLastError() produced: " + error1 + " + " + error2);
		return FALSE;
	}

	return TRUE;
}