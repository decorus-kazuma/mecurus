#include "stdafx.h"
#include "Mecurus.h"

namespace WinMainHook
{
	BYTE orgWinMainBuffer[5] = { 0, };

	INT WINAPI WinHookAction(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
	{
		Hooks::FunctionHijackRecover("WinMain", _TH_FUNC_WinMain_, orgWinMainBuffer);
		DWORD ReturnValue = ((WinMainOriginalFunction)_TH_FUNC_WinMain_)(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
		Hooks::FunctionHijack("WinMain", _TH_FUNC_WinMain_, (PROC)WinHookAction, orgWinMainBuffer);

		return ReturnValue;
	}
	HVOID TenhouHook_WinMainHookStart()
	{
		Hooks::FunctionHijack("WinMain", _TH_FUNC_WinMain_, (PROC)WinHookAction, orgWinMainBuffer);
		DWORD POINT = 0X0045EED3;

		DWORD oldProtect;
		if (VirtualProtect((LPVOID)POINT, 28, PAGE_EXECUTE_READWRITE, &oldProtect))
		{
			BYTE JMP[28] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };

			WriteProcessMemory(GetCurrentProcess(), (LPVOID)POINT, JMP, 28, 0);
		}
		else
		{
			AfxMessageBox("ERR");
		}
	}
}