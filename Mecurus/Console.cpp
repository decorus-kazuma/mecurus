#include "stdafx.h"
#include "Mecurus.h"

namespace Console
{
	HANDLE hConsoleOutput, hConsoleInput;
	BOOL UseConsole = FALSE;

	BOOL STDCAL OpenConsole()
	{
		if (AllocConsole())
		{
			return FALSE;
		}
		else
		{
			hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
			hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);

			if (hConsoleInput != 0 && hConsoleOutput != 0) return TRUE;
			else return FALSE;
		}
	}
}