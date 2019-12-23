#include "stdafx.h"
#include "Mecurus.h"

namespace SetWindowPosHook
{
	BYTE orgBytes[5] = { 0, };

	VOID WINAPI SetWindowPosBeforeCall(HWND *hWnd, HWND *hWndInsertAfter, INT *x, INT *y, INT *cx, INT *cy, UINT *uFlags)
	{
		
	}

	VOID WINAPI SetWindowPosCall(BOOL return_val, HWND hWnd, HWND hWndInsertAfter, INT x, INT y, INT cx, INT cy, UINT uFlags)
	{
		if (Draw::LayerLoad == TRUE)
		{
			Draw::picLayer->Invalidate(false);
		}
	}

	BOOL WINAPI SetWindowPosHookingProcess(HWND hWnd, HWND hWndInsertAfter, INT x, INT y, INT cx, INT cy, UINT uFlags)
	{
		BOOL return_val;
		FARPROC OrignFunctionPointer = GetProcAddress(GetModuleHandleA("User32.dll"), "SetWindowPos");

		SetWindowPosBeforeCall(&hWnd, &hWndInsertAfter, &x, &y, &cx, &cy, &uFlags);

		Hooks::FunctionTampoUnHook("User32.dll", "SetWindowPos", orgBytes);
		return_val = ((SetWindowPosOriginalFunction)OrignFunctionPointer)(hWnd, hWndInsertAfter, x, y, cx, cy, uFlags);
		Hooks::FunctionTampoHook("User32.dll", "SetWindowPos", (PROC)SetWindowPosHookingProcess, orgBytes);

		SetWindowPosCall(return_val, hWnd, hWndInsertAfter, x, y, cx, cy, uFlags);

		return return_val;
	}

	VOID SetWindowPosHooking()
	{
		Hooks::FunctionTampoHook("User32.dll", "SetWindowPos", (PROC)SetWindowPosHookingProcess, orgBytes);
	}
}