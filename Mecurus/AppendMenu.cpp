#include "stdafx.h"
#include "Mecurus.h"

namespace AppendMenuHook
{
	BYTE orgBytesAppendMenuA[5] = { 0, };

	BOOL WINAPI AppendMenuAHookingProcess(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCTSTR lpNewItem)
	{
		ActiveHook::HookFunctionCall("AppendMenuA");

		INT return_val;
		FARPROC OrignFunctionPointer = GetProcAddress(GetModuleHandleA("user32.dll"), "AppendMenuA");

		Hooks::FunctionTampoUnHook("User32.dll", "AppendMenuA", orgBytesAppendMenuA);
		return_val = ((AppendMenuAOriginalFunction)OrignFunctionPointer)(hMenu, uFlags, uIDNewItem, lpNewItem);
		Hooks::FunctionTampoHook("User32.dll", "AppendMenuA", (PROC)AppendMenuAHookingProcess, orgBytesAppendMenuA);

		return return_val;
	}

	HVOID AppendMenuHooking()
	{
		Hooks::FunctionTampoHook("user32.dll", "AppendMenuA", (PROC)AppendMenuAHookingProcess, orgBytesAppendMenuA);
	}
}