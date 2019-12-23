#include "stdafx.h"
#include "Mecurus.h"

namespace Mecurus
{
	MecurusDialog* MecurusDlg;
	MecurusLayer* MecurusLlg;
	WCMAP ClassMap;
}

namespace ActiveHook
{
	VOID HookFunctionCall(TCHAR* str)
	{

	}
}

namespace Hooks
{
	std::map<CString, FARPROC> IATHookOriginFunction;

	BOOL FunctionTampoUnHook(LPCSTR szDllName, LPCSTR szFuncName, BYTE* orgBuf)
	{
		FARPROC pFunc;
		DWORD dwOldProtect;
		PBYTE pByte;

		pFunc = GetProcAddress(GetModuleHandleA(szDllName), szFuncName);
		pByte = (PBYTE)pFunc;

		if (pByte[0] != 0xE9)
			return FALSE;

		VirtualProtect((LPVOID)pFunc, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		memcpy(pFunc, orgBuf, 5);

		VirtualProtect((LPVOID)pFunc, 5, dwOldProtect, &dwOldProtect);

		return TRUE;
	}

	BOOL FunctionTampoHook(LPCSTR szDllName, LPCSTR szFuncName, PROC pfNew, BYTE* saveOrgBuf)
	{
		FARPROC pfOrg;
		DWORD dwOldProtect, dwAddress;
		BYTE pBuf[5] = { 0xE9, 0, };
		PBYTE pByte;

		pfOrg = (FARPROC)GetProcAddress(GetModuleHandleA(szDllName), szFuncName);
		pByte = (PBYTE)pfOrg;

		if (pByte[0] == 0xE9)
			return FALSE;

		VirtualProtect((LPVOID)pfOrg, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		memcpy(saveOrgBuf, pfOrg, 5);

		dwAddress = (DWORD)pfNew - (DWORD)pfOrg - 5;
		memcpy(&pBuf[1], &dwAddress, 4);

		memcpy(pfOrg, pBuf, 5);

		VirtualProtect((LPVOID)pfOrg, 5, dwOldProtect, &dwOldProtect);

		return TRUE;
	}

	BOOL FunctionHijackRecover(LPCSTR szFuncName, DWORD functionAddress, BYTE* orgBuf)
	{
		BYTE* originLoc = (BYTE*)functionAddress;
		DWORD dwOldProtect;

		VirtualProtect((LPVOID)functionAddress, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);
		memcpy(originLoc, orgBuf, 5);
		VirtualProtect((LPVOID)functionAddress, 5, dwOldProtect, &dwOldProtect);

		return TRUE;
	}

	BOOL FunctionHijack(LPCSTR szFuncName, DWORD functionAddress, PROC pfNew, BYTE* orgBuf)
	{
		PBYTE pByte = (PBYTE)functionAddress;
		DWORD dwOldProtect, dwAddress;
		BYTE pBuf[5] = { 0xE9, 0x90, 0x90, 0x90, 0x90 };
		BYTE pfOrgBuf[5] = { 0, };
		BYTE* originLoc = (BYTE*)functionAddress;

		VirtualProtect((LPVOID)functionAddress, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);
		memcpy(pfOrgBuf, originLoc, 5);

		memcpy(orgBuf, (LPVOID)functionAddress, 5);

		dwAddress = (DWORD)pfNew - functionAddress - 0x5;
		memcpy(&pBuf[1], &dwAddress, 4);

		WriteProcessMemory(GetCurrentProcess(), (LPVOID)functionAddress, pBuf, 5, 0);

		VirtualProtect((LPVOID)functionAddress, 5, dwOldProtect, &dwOldProtect);

		return TRUE;
	}

	BOOL FunctionIATHook(LPCSTR szDllName, LPCSTR functionName, PROC pfnOrg, PROC pfnNew, FARPROC pOriginFunctionAddress)
	{
		HMODULE hMod;
		LPCSTR szLibName;
		PIMAGE_IMPORT_DESCRIPTOR pImportDesc;
		PIMAGE_THUNK_DATA pThunk;
		DWORD dwOldProtect, dwRVA;
		PBYTE pAddr;

		hMod = GetModuleHandle(NULL);

		pAddr = (PBYTE)hMod;          
		pAddr += *((DWORD*)&pAddr[0x3C]); 
		dwRVA = *((DWORD*)&pAddr[0x80]);   

		pImportDesc = (PIMAGE_IMPORT_DESCRIPTOR)((DWORD)hMod + dwRVA);

		for (; pImportDesc->Name; pImportDesc++)
		{
			szLibName = (LPCSTR)((DWORD)hMod + pImportDesc->Name);

			if (!_stricmp(szLibName, szDllName))   
			{
				pThunk = (PIMAGE_THUNK_DATA)((DWORD)hMod + pImportDesc->FirstThunk);

				for (; pThunk->u1.Function; pThunk++)
				{
					if (pThunk->u1.Function == (DWORD)pfnOrg)  
					{
						VirtualProtect((LPVOID)&pThunk->u1.Function, 4, PAGE_EXECUTE_READWRITE, &dwOldProtect);
						pThunk->u1.Function = (DWORD)pfnNew; 
						VirtualProtect((LPVOID)&pThunk->u1.Function, 4, dwOldProtect, &dwOldProtect);

						CString FuncNameFind;
						FuncNameFind.Format("%s", functionName);

						IATHookOriginFunction.insert(std::map<CString, FARPROC>::value_type(FuncNameFind, pOriginFunctionAddress));

						return TRUE;
					}
				}
			}
		}

		return FALSE;
	}
}