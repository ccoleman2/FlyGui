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
	void setName(wstring);
	wstring getName();
	DWORD getBaseAddress();
	HANDLE getProgramHandle();
	bool setDebugPrivilegesEnabled();
	void setAttached(bool);

};

