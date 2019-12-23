#include "stdafx.h"
#include "Mecurus.h"

namespace Protect
{
	BOOL isDebugOnline;

	VOID STDCAL AntiProcess()
	{

	}

	VOID STDCAL ShutdownThisProcess()
	{

	}

	VOID STDCAL ShutdownProcess()
	{

	}

	VOID STDCAL ProcessDebuggerCheck()
	{
		CheckRemoteDebuggerPresent(GetCurrentProcess(), &isDebugOnline);

		if (IsDebuggerPresent() == TRUE)
			isDebugOnline = TRUE;
	}

	VOID STDCAL ProcessProtectThread()
	{
		ProcessDebuggerCheck();
	}

	VOID STDCAL ProcessProtectStart(INT ProtectLevel)
	{
		switch (ProtectLevel)
		{
		case 1:
		{

		}
		break;
		default:
			break;
		}

		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ProcessProtectThread, NULL, NULL, NULL);
	}

	VOID STDCAL ProtectInit()
	{
		isDebugOnline = FALSE;
	}
}