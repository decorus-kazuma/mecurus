#include "stdafx.h"
#include "Mecurus.h"

namespace DestroyWindowHook
{
	BYTE orgBytes[5] = { 0, };

	VOID WINAPI DestroyWindowBeforeCall(HWND *hwnd)
	{
		if (Draw::LayerLoad == TRUE)
		{
			Draw::picLayer->Invalidate(false);
		}
	}

	VOID WINAPI DestroyWindowCall(HWND *hwnd)
	{
		if (Draw::LayerLoad == TRUE)
		{
			Draw::picLayer->Invalidate(false);
		}
	}

	BOOL WINAPI DestroyWindowHookingProcess(HWND hWnd)
	{
		ActiveHook::HookFunctionCall("DestroyWindow");

		DWORD return_val;
		FARPROC OrignFunctionPointer = GetProcAddress(GetModuleHandleA("User32.dll"), "DestroyWindow");

		DestroyWindowBeforeCall(&hWnd);

		Hooks::FunctionTampoUnHook("User32.dll", "DestroyWindow", orgBytes);
		return_val = ((DestroyWindowOriginalFunction)OrignFunctionPointer)(hWnd);
		Hooks::FunctionTampoHook("User32.dll", "DestroyWindow", (PROC)DestroyWindowHookingProcess, orgBytes);

		DestroyWindowCall(&hWnd);

		return return_val;
	}

	HVOID DestroyWindowHooking()
	{
		Hooks::FunctionTampoHook("User32.dll", "DestroyWindow", (PROC)DestroyWindowHookingProcess, orgBytes);
	}
}