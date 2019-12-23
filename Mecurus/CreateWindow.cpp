#include "stdafx.h"
#include "Mecurus.h"

namespace CreateWindowHook
{
	VOID WINAPI CreateWindowExCall(HWND hWnd, DWORD extStyle, LPCTSTR Class, DWORD WindowName, DWORD Style, DWORD X, DWORD Y, DWORD Width, DWORD Height, DWORD hParent, DWORD hMenu, DWORD hInst)
	{
		if ((DWORD)Class < 0x300000) return;

		switch ((DWORD)Class)
		{
			case _TH_CLASS_WC_TENHOU_WIN_APP_MAIN_:
			{
				Th::WinMainHWND = hWnd;

				//::SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
				//SetLayeredWindowAttributes(hWnd, RGB(255, 255, 255), 200, LWA_COLORKEY | LWA_ALPHA);
				//SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);

				Draw::CreateConsoleDialog(hWnd);
				Draw::DebugMessage();
			}
			break;
			case _TH_CLASS_WC_VIEW_:
			{
				Th::TenhouLoaded = TRUE;
				Th::GameMainHWND = hWnd;
				Th::LayerLoaded = TRUE;
			}
			break;
			case _TH_CLASS_WC_LOBBY_:
			{
				RemoveMenu((HMENU)hMenu, SC_MOVE, MF_BYCOMMAND);
				RemoveMenu((HMENU)hMenu, SC_SIZE, MF_BYCOMMAND);
				RemoveMenu((HMENU)hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
			}
			break;
			default:
			break;
		}

		//@always
		if (Draw::LayerLoad == TRUE)
		{
			Draw::picLayer->Invalidate(false);
		}
	}

	BYTE orgBytes[5] = { 0, };

	HWND WINAPI CreateWindowHookingProcess(DWORD dwExStyle, LPCTSTR lpClassName, LPCTSTR lpWindowName, DWORD dwStyle, INT x, INT y, INT nWidth, INT nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
	{
		HWND return_val;
		FARPROC OrignFunctionPointer = GetProcAddress(GetModuleHandleA("user32.dll"), "CreateWindowExA");
	
		Hooks::FunctionTampoUnHook("User32.dll", "CreateWindowExA", orgBytes);
		return_val = ((CreateWindowExAOriginalFunction)OrignFunctionPointer)(dwExStyle, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
		Hooks::FunctionTampoHook("User32.dll", "CreateWindowExA", (PROC)CreateWindowHookingProcess, orgBytes);

		CreateWindowExCall(return_val, dwExStyle, lpClassName, (DWORD)lpWindowName, dwStyle, x, y, nWidth, nHeight, (DWORD)hWndParent, (DWORD)hMenu, (DWORD)hInstance);

		return return_val;
	}

	VOID CreateWindowHooking()
	{
		Hooks::FunctionTampoHook("user32.dll", "CreateWindowExA", (PROC)CreateWindowHookingProcess, orgBytes);
	}
}