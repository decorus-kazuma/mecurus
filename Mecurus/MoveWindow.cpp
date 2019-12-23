#include "stdafx.h"
#include "Mecurus.h"

namespace MoveWindowHook
{
	BYTE orgBytes[5] = { 0, };

	VOID WINAPI MoveWindowBeforeCall(HWND *hWnd, INT *x, INT *y, INT *nWidth, INT *nHeight, BOOL *bRepaint)
	{

	}

	VOID WINAPI MoveWindowCall(BOOL return_val, HWND hWnd, INT x, INT y, INT nWidth, INT nHeight, BOOL bRepaint)
	{
		if (Draw::LayerLoad == TRUE)
		{
			Draw::picLayer->Invalidate(false);
		}
	}

	BOOL WINAPI MoveWindowHookingProcess(HWND hWnd, INT x, INT y, INT nWidth, INT nHeight, BOOL bRepaint)
	{
		BOOL return_val;
		FARPROC OrignFunctionPointer = GetProcAddress(GetModuleHandleA("User32.dll"), "MoveWindow");

		MoveWindowBeforeCall(&hWnd, &x, &y, &nWidth, &nHeight, &bRepaint);

		Hooks::FunctionTampoUnHook("User32.dll", "MoveWindow", orgBytes);
		return_val = ((MoveWindowOriginalFunction)OrignFunctionPointer)(hWnd, x, y, nWidth, nHeight, bRepaint);
		Hooks::FunctionTampoHook("User32.dll", "MoveWindow", (PROC)MoveWindowHookingProcess, orgBytes);

		MoveWindowCall(return_val, hWnd, x, y, nWidth, nHeight, bRepaint);

		return return_val;
	}

	VOID MoveWindowHooking()
	{
		Hooks::FunctionTampoHook("User32.dll", "MoveWindow", (PROC)MoveWindowHookingProcess, orgBytes);
		
	}
}