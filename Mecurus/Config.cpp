#include "stdafx.h"
#include "Mecurus.h"

namespace Config
{
	std::map<CString, CString> Option;

	VOID STDCAL GetCurrentPath(DWORD szCurrentPathSize, TCHAR* CurrentPath)
	{
		::GetCurrentDirectory(szCurrentPathSize, CurrentPath);
	}

	VOID STDCAL GetProcessPath(DWORD szCurrentPathSize, TCHAR* CurrentEXEPath)
	{
		::GetModuleFileName(NULL, CurrentEXEPath, szCurrentPathSize);
	}

	VOID STDCAL WriteConfig(TCHAR* cfgFilePath, TCHAR* cfgFileName)
	{
		CString szPath, szSection, szValue;

		szPath.Format("%s\\%s", cfgFilePath, cfgFileName);
	}

	BOOL STDCAL GetConfig(TCHAR* cfgFilePath, TCHAR* cfgFileName)
	{
		DWORD INILoadErrorCount = 0;
		TCHAR szBuffer[_CFG_MAX_SIZE_] = { 0, };
		CString szPath, szSection, szValue;

		szPath.Format("%s\\%s", cfgFilePath, cfgFileName);

		/* Global Option */
		szSection = _T("GLOBAL_OPTION");

		GetPrivateProfileString(szSection, _T("DebugMode"), _T(""), szBuffer, _CFG_MAX_SIZE_, szPath);
		INILoadErrorCount = INILoadErrorCount + GetLastError();
		Option.insert(std::map<CString, CString>::value_type("DebugMode", szBuffer));

		return FALSE;
	}
}