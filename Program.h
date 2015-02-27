#pragma once

using namespace std;

class Program
{
public:
// constructors
	Program();
	Program(wstring name);

// fields
	wstring name;
	DWORD processId;
	bool debugPrivilegesEnabled;
	bool attached;
	DWORD baseAddress;
	HWND windowHandle;
	HANDLE programHandle;

// methods
	wstring getName();
	DWORD getBaseAddress();
	//DWORD getProcessId();
	//HWND getWindowHandle();
	HANDLE getProgramHandle();
	//bool getDebugPrivilegesEnabled();
	void setName(wstring);
	void setDebugPrivilegesEnabled(bool);
	void setAttached(bool);

};

