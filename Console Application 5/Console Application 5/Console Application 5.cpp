#include <iostream>
#include "windows.h"
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	setlocale(0, "");
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	char pName[30];
	for (;;)
	{
		string choice1;
		cout << "Для запуска программы \"Расписание\" нажмите 1" << endl;
		cout << "Для запуска программы \"Рацион\" нажмите 2" << endl;
		cin >> choice1;
		cout << endl;
		if (choice1 == "1")
		{
			strcpy_s(pName, "Console Application 2.exe");
		}
		else if (choice1 == "2")
		{
			strcpy_s(pName, "Console Application 3.exe");
		}
		else
		{
			break;
		}
		string choice2;
		cout << "Для запуска в существующей консоли нажмите 1" << endl;
		cout << "Для запуска в новой консоли нажмите 2" << endl;
		cin >> choice2;
		cout << endl;
		DWORD flag;
		if (choice2 == "1")
		{
			flag = 0;
		}
		else if (choice2 == "2")
		{
			flag = CREATE_NEW_CONSOLE;
		}
		else
		{
			break;
		}
		if (CreateProcess(NULL, pName, NULL, NULL, FALSE, flag, NULL, NULL, &si, &pi))
		{
			WaitForSingleObject(pi.hProcess, INFINITE);
		}
	}
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}