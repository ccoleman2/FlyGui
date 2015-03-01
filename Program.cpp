#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	attached = FALSE;
}

Program::Program(wstring name){
	this->name = name;
	attached = FALSE;
}

void Program::setName(wstring name){
	this->name = name;
}

void Program::setAttached(bool attached){
	this->attached = attached;
}

wstring Program::getName(){
	return name;
}

DWORD Program::getBaseAddress(){
	MODULEENTRY32 moduleentry32;
	moduleentry32.dwSize = sizeof(MODULEENTRY32W);

	windowHandle = FindWindow(NULL, getName().c_str());
	if (windowHandle == NULL)
	{
		return 1;
	}

	GetWindowThreadProcessId(windowHandle, &processId);
	if (processId == NULL)
	{
		return 2;
	}

	programHandle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processId);
	if (programHandle == INVALID_HANDLE_VALUE)
	{
		return 3;
	}

	if (!Module32First(programHandle, &moduleentry32))
	{
		return 4;
	}

	if (setDebugPrivilegesEnabled() == FALSE){
		return 5;
	}

	baseAddress = (DWORD)moduleentry32.modBaseAddr;
	return baseAddress;
}

HANDLE Program::getProgramHandle(){
	programHandle = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_READ | PROCESS_VM_OPERATION, FALSE, processId);
	return programHandle;
}

bool Program::setDebugPrivilegesEnabled(){
	HANDLE              hToken;
	LUID                SeDebugNameValue;
	TOKEN_PRIVILEGES    TokenPrivileges;

	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
	{
		if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &SeDebugNameValue))
		{
			TokenPrivileges.PrivilegeCount = 1;
			TokenPrivileges.Privileges[0].Luid = SeDebugNameValue;
			TokenPrivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

			if (AdjustTokenPrivileges(hToken, FALSE, &TokenPrivileges, sizeof(TOKEN_PRIVILEGES), NULL, NULL))
			{
				CloseHandle(hToken);
			}
			else
			{
				CloseHandle(hToken);
				debugPrivilegesEnabled = false;
				return false;
			}
		}
		else
		{
			CloseHandle(hToken);
			debugPrivilegesEnabled = false;
			return false;
		}
	}
	else
	{
		debugPrivilegesEnabled = false;
		return false;
	}
	debugPrivilegesEnabled = true;
	return true;
}