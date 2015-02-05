#include "stdafx.h"
#include "getbaseaddress.h"

using namespace System::Windows::Forms;

DWORD getbaseaddress()
{
	DWORD* processID = new DWORD;
	MODULEENTRY32 moduleentry32WoW;
	moduleentry32WoW.dwSize = sizeof(MODULEENTRY32W);
	HANDLE handleWoW;

	HWND windowHandle = FindWindow(NULL, L"Heroes of the Storm");
	error = GetLastError();
	if (windowHandle == NULL)
	{
		MessageBox::Show("windowHandle == NULL | Error = " + error.ToString());
		return 0;
	}

	GetWindowThreadProcessId(windowHandle, processID);
	error = GetLastError();
	if (processID == NULL)
	{
		MessageBox::Show("processID == NULL | Error = " + error.ToString());
	}

	handleWoW = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, *processID);
	error = GetLastError();
	if (handleWoW == INVALID_HANDLE_VALUE)
	{
		MessageBox::Show("handleWoW == INVALID_HANDLE_VALUE | Error = " + error.ToString());
	}
	
	if (!Module32First(handleWoW, &moduleentry32WoW))
	{
		error = GetLastError();
		MessageBox::Show("Module32First returned FALSE | Error = " + error.ToString());
	}

	CloseHandle(handleWoW);
	return (DWORD) moduleentry32WoW.modBaseAddr;
}
