#include "stdafx.h"
#include "Mecurus.h"

namespace Draw
{
	BOOL LayerInit = FALSE;
	BOOL LayerLoad = FALSE;
	HWND parentHWND = 0;
	MecLayer *picLayer;
	HANDLE ThreadHandle;
	DWORD ThreadId;

	CString LastErrorStack;

	unsigned int WINAPI DrawKeepUpdateThread(void* arg)
	{
		for (;;)
		{
			picLayer->Invalidate(false);
			Sleep(2000);
		}
	}

	VOID STDCAL DebugMessage()
	{
		CDC* p = picLayer->GetWindowDC();
		CString t = "Mecurus (Layer debug.md)\r\n\r\n-fokkia@pas3ive.com or admin@pas3ive.com\r\n";

		p->SetBkColor(TRANSPARENT);
		p->SetTextColor(RGB(216, 27, 27));
		p->DrawText(t, CRect(0, 0, 100, 20), DT_WORDBREAK | DT_CENTER);
		p->MoveTo(10, 10);
		p->LineTo(10, 10);
		picLayer->ReleaseDC(p);
	}

	VOID STDCAL SetLastDrawError(CString errmsg)
	{
		LastErrorStack = errmsg;
	}

	CString STDCAL GetLastDrawError()
	{
		return LastErrorStack;
	}

	BOOL STDCAL CreateConsoleDialog(HWND hWndParent)
	{
		if (LayerInit != TRUE)
		{
			SetLastDrawError("0010");
			return FALSE;
		}
		
		parentHWND = hWndParent;
		picLayer->CreateEx(WS_EX_TOPMOST, "STATIC", NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, CRect(0, 0, 1024, 1024), CWnd::FromHandle(hWndParent), IDC_STATIC);
		picLayer->SetWindowPos(&CWnd::wndTopMost, NULL, NULL, 1024, 1024, SWP_NOSIZE | SWP_NOZORDER);
		picLayer->ShowWindow(TRUE);
		picLayer->UpdateWindow();
		picLayer->EnableWindow(TRUE);

		LayerLoad = TRUE;
		ThreadHandle = (HANDLE)_beginthreadex(NULL, 0, DrawKeepUpdateThread, NULL, 0, (unsigned*)&ThreadId);

		return TRUE;
	}

	VOID STDCAL ConsoleDialogInit()
	{
		picLayer = new MecLayer;

		LayerInit = TRUE;
	}
}