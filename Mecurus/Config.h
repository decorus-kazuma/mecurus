#pragma once
#include "stdafx.h"
#include "Mecurus.h"

#define _CFG_PATH_SIZE_ 1024
#define _CFG_MAX_SIZE_ 1024

namespace Config
{
	extern std::map<CString, CString> Option;

	VOID STDCAL GetCurrentPath(DWORD szCurrentPathSize, TCHAR* CurrentPath);
	VOID STDCAL GetProcessPath(DWORD szCurrentPathSize, TCHAR* CurrentEXEPath);
	VOID STDCAL WriteConfig(TCHAR* cfgFilePath, TCHAR* cfgFileName);
	BOOL STDCAL GetConfig(TCHAR* cfgFilePath, TCHAR* cfgFileName);
}