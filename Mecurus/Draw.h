#pragma once
#include "stdafx.h"
#include "Mecurus.h"

namespace Draw
{
	extern MecurusLayer *layer;
	extern CString LastErrorStack;
	extern BOOL LayerInit;
	extern BOOL LayerLoad;
	extern MecLayer *picLayer;

	VOID STDCAL DebugMessage();
	BOOL STDCAL LayerFlag(BOOL flag);
	BOOL STDCAL LayerSetMostTop();
	VOID STDCAL SetLastDrawError(CString errmsg);
	CString STDCAL GetLastDrawError();
	BOOL STDCAL CreateConsoleDialog(HWND hWndParent);
	VOID STDCAL ConsoleDialogInit();
}