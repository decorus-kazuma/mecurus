#pragma once
#include "stdafx.h"
#include "Mecurus.h"

namespace MoveWindowHook
{
	VOID MoveWindowHooking();
}

namespace SetWindowPosHook
{
	VOID SetWindowPosHooking();
}

namespace CreateWindowHook
{
	VOID CreateWindowHooking();
}

namespace ActiveHook
{
	VOID HookFunctionCall(TCHAR* str);
}

namespace Hooks
{
	typedef struct ByteClass {
		BYTE code[5];
	} BC;

	extern std::map<CString, FARPROC> IATHookOriginFunction;

	BOOL FunctionHijack(LPCSTR szFuncName, DWORD functionAddress, PROC pfNew, BYTE* orgBuf);
	BOOL FunctionHijackRecover(LPCSTR szFuncName, DWORD functionAddress, BYTE* orgBuf);
	BOOL FunctionTampoUnHook(LPCSTR szDllName, LPCSTR szFuncName, BYTE* orgBuf);
	BOOL FunctionTampoHook(LPCSTR szDllName, LPCSTR szFuncName, PROC pfNew, BYTE* saveOrgBuf);
	BOOL FunctionIATHook(LPCSTR szDllName, LPCSTR functionName, PROC pfnOrg, PROC pfnNew, FARPROC pOriginFunctionAddress);
}

