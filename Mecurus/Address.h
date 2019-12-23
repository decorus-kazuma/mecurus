#pragma once
#include "stdafx.h"
#include "Mecurus.h"

#define _TH_CLASS_WC_TENHOU_WIN_APP_MAIN_ 0x004F30F8
#define _TH_CLASS_WC_VIEW_ 0x004F3DA4
#define _TH_CLASS_WC_WELCOME_ 0x004F3D04
#define _TH_CLASS_WC_SOUND_ 0x004EC708
#define _TH_CLASS_WC_EDIT_ 0x004ECE00
#define _TH_CLASS_WC_ITEM_BTN_ 0x004ECEB4
#define _TH_CLASS_WC_ITEM_ANCHOR_ 0x004F5B2C
#define _TH_CLASS_WC_WWW_ 0x004ECE08
#define _TH_CLASS_WC_CLIENT_ 0x004ECE58
#define _TH_CLASS_WC_ITEM_TAB_ 0x004EEB38
#define _TH_CLASS_WC_ITEM_STATIC_ 0x004EEB28
#define _TH_CLASS_WC_LOBBY_RULE_ 0x004EE850
#define _TH_CLASS_ATL_AX_WIN_ 0x004F3148
#define _TH_CLASS_WC_LOBBY_JOIN_ 0x004EE814
#define _TH_CLASS_WC_LOBBY_WG_ 0x004EE824
#define _TH_CLASS_WC_LOBBY_MAIN_ 0x004EE830
#define _TH_CLASS_WC_LOBBY_ 0x004EE860
#define _TH_CLASS_WC_ITEM_POPUP_ 0x004EFAF4
#define _TH_CLASS_WC_ITEM_COUNT_ 0x004F4C98

#define _TH_FUNC_WinMain_ 0x0045EE60
#define _TH_FUNC_ClientLoad_ 0x0045F6A9

namespace Th
{
	extern HWND WinMainHWND;
	extern BOOL TenhouLoaded;
	extern INT DebugFlagCounter;
	extern BOOL LayerLoaded;
	extern HWND GameMainHWND;

	VOID CALLBACK DefMsg(HWINEVENTHOOK hook, DWORD events, HWND hwnd, LONG idObject, LONG idChild, DWORD dwEventThread, DWORD dwmsEventTime);
}

typedef INT(WINAPI *WinMainOriginalFunction)(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

/* Windows API */
typedef HWND(WINAPI *CreateWindowExAOriginalFunction)(DWORD dwExStyle, LPCTSTR lpClassName, LPCTSTR lpWindowName, DWORD dwStyle, INT x, INT y, INT nWidth, INT nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
typedef BOOL(WINAPI *DestroyWindowOriginalFunction)(HWND hWnd);
typedef BOOL(WINAPI *SetWindowPosOriginalFunction)(HWND hWnd, HWND hWndInsertAfter, INT X, INT Y, INT cx, INT cy, UINT uFlags);
typedef INT(WINAPI *DrawTextExOriginalFunction)(HDC hdc, LPTSTR lpchText, INT cchText, LPRECT lprc, UINT dwPTFormat, LPDRAWTEXTPARAMS lpDTParams);
typedef BOOL(WINAPI *DestroyMenuOriginalFunction)(HMENU hMenu);
typedef BOOL(WINAPI *GetClientRectOriginalFunction)(HWND hWnd, LPRECT lpRect);
typedef BOOL(WINAPI *AppendMenuAOriginalFunction)(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCTSTR lpNewItem);
typedef INT(WINAPI *MessageBoxOriginalFunction)(HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType);
typedef INT(WINAPI *GetClassNameAOriginalFunction)(HWND hWnd, LPTSTR lpClassName, INT nMaxCount);
typedef ATOM(WINAPI *RegisterClassAOriginalFunction)(const WNDCLASS *lpWndClass);
typedef HANDLE(WINAPI *CreateThreadOriginalFunction)(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
typedef BOOL(WINAPI *SetWindowPosOriginalFunction)(HWND hWnd, HWND hWndInsertAfter, INT x, INT y, INT cx, INT cy, UINT uFlags);
typedef BOOL(WINAPI *MoveWindowOriginalFunction)(HWND hWnd, INT x, INT y, INT nWidth, INT nHeight, BOOL bRepaint);