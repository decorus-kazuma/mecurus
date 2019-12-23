// Mecurus.cpp : 해당 DLL의 초기화 루틴을 정의합니다.
//

#include "stdafx.h"
#include "Mecurus.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


BEGIN_MESSAGE_MAP(CMecurusApp, CWinApp)
END_MESSAGE_MAP()


// CMecurusApp 생성

CMecurusApp::CMecurusApp()
{

}

CMecurusApp theApp;

BOOL CMecurusApp::InitInstance()
{
	CWinApp::InitInstance();

	AfxInitRichEdit();
	AfxInitRichEdit2();
	::LoadLibraryA("Riched32.dll");
	::LoadLibraryA("Riched20.dll");
	::LoadLibraryA("msftedit.dll");

	WinMainHook::TenhouHook_WinMainHookStart();
	CreateWindowHook::CreateWindowHooking();
	SetWindowPosHook::SetWindowPosHooking();
	MoveWindowHook::MoveWindowHooking();
	Draw::ConsoleDialogInit();

	SetWinEventHook(EVENT_MIN, EVENT_MAX, GetModuleHandleA(0), Th::DefMsg, GetCurrentProcessId(), 0, WINEVENT_OUTOFCONTEXT);

	return TRUE;
}

INT CMecurusApp::ExitInstance()
{


	return 0;
}