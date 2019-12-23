#include "stdafx.h"
#include "Mecurus.h"

namespace CreateThreadHook
{
	BYTE orgBytes[5] = { 0, };

	HANDLE WINAPI CreateThreadHookingProcess(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId)
	{
		ActiveHook::HookFunctionCall("CreateThread");

		HANDLE return_val;
		FARPROC OrignFunctionPointer = GetProcAddress(GetModuleHandleA("user32.dll"), "CreateThread");

		Hooks::FunctionTampoUnHook("User32.dll", "CreateThread", orgBytes);
		return_val = ((CreateThreadOriginalFunction)OrignFunctionPointer)(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
		Hooks::FunctionTampoHook("User32.dll", "CreateThread", (PROC)CreateThreadHookingProcess, orgBytes);

		return return_val;
	}

	HVOID CreateThreadHooking()
	{
		Hooks::FunctionTampoHook("user32.dll", "CreateThread", (PROC)CreateThreadHookingProcess, orgBytes);
	}
}