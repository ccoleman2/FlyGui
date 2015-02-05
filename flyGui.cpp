// flyGui.cpp : main project file.

#include "stdafx.h"

using namespace flyGui;	

HWND windowHandle;
HANDLE actualWoWhandle;
DWORD WoWprocessID;
DWORD WoWbaseaddress;
DWORD currentRender = 0x00013FFF;
int error;
int attached = 0;
int buttonone, buttontwo, buttonthree, buttonfour, buttonfive, buttonsix = 0;
int userAction = 1;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
