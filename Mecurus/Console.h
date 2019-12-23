#pragma once
#include "stdafx.h"
#include "Mecurus.h"

namespace Console
{
	extern HANDLE hConsoleOutput;
	extern HANDLE hConsoleInput;
	extern BOOL UseConsole;

	BOOL STDCAL OpenConsole();
}