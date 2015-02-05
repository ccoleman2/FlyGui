// # Paperino's code @
// http://stackoverflow.com/questions/2221103/how-to-get-process-handle-from-process-id

#include "stdafx.h"
#include "getbaseaddress.h"

using namespace System::Windows::Forms;

void EnableDebugPriv(void)
{
    HANDLE              hToken;
    LUID                SeDebugNameValue;
    TOKEN_PRIVILEGES    TokenPrivileges;

    if(OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
    {
        if(LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &SeDebugNameValue))
        {
            TokenPrivileges.PrivilegeCount              = 1;
            TokenPrivileges.Privileges[0].Luid          = SeDebugNameValue;
            TokenPrivileges.Privileges[0].Attributes    = SE_PRIVILEGE_ENABLED;

            if(AdjustTokenPrivileges(hToken, FALSE, &TokenPrivileges, sizeof(TOKEN_PRIVILEGES), NULL, NULL))
            {
                CloseHandle(hToken);
            }
            else
            {
                CloseHandle(hToken);
                MessageBox::Show("Couldn't adjust token privileges!");              
            }
        }
        else
        {
            CloseHandle(hToken);
            MessageBox::Show("Couldn't look up privilege value!");
        }
    }
    else
    {
        MessageBox::Show("Couldn't open process token!");
    }
}