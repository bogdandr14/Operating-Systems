#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
    HANDLE hProcess = 0; //Handle for Process
    HANDLE hThread = 0; //Handle for Thread
    STARTUPINFO si; //StartupInfo Structure;
    PROCESS_INFORMATION pi; //ProcessInfo Structure
    DWORD dwProcessID = 0;
    BOOL bProcess;

    for (int i = 1; i <= 3; ++i)
    {   
        ZeroMemory(&si, sizeof(si));
        ZeroMemory(&pi, sizeof(pi));
        bProcess = CreateProcess(
            L"C:\\WINDOWS\\system32\\notepad.exe",//App Name
            NULL,//Command Line
            NULL, //Process Attribute
            NULL, //Thread Attribute
            FALSE, //Inherit handle
            0, //Creation Flag
            NULL, //Environment Variable
            NULL, //Current Directory
            &si, //StartInfo
            &pi);//ProcessInfo
        if (bProcess == TRUE)
        {
            cout << "Process " << i << " ID = " << pi.dwProcessId << "\n";
            WaitForSingleObject(pi.hProcess, i * 1000);
            TerminateProcess(pi.hProcess, 0);
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
            cout << "Process " << i << " finished\n";
        }
    }
    cout << "All processes finished execution\n";
    system("PAUSE");
    return 0;
}