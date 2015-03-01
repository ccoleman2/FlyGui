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
	bool attached;
	bool debugPrivilegesEnabled;
	DWORD processId;
	DWORD baseAddress;
	HWND windowHandle;
	HANDLE programHandle;

// methods
	void setName(wstring);
	void setAttached(bool);
	wstring getName();
	DWORD getBaseAddress();
	HANDLE getProgramHandle();
	bool setDebugPrivilegesEnabled();

};

