#pragma once
#include "stdafx.h"
#include "Mecurus.h"

#define NAKED __declspec(naked)
#define STDCAL __stdcall
#define EXTERN extern

/* Type */
typedef void HVOID;
typedef DWORD HOOKLOC;
typedef DWORD HOOKPAT;
typedef int(*FARPNT)(HWND, LPCTSTR, LPCTSTR, UINT);
typedef void INFUNC;
typedef int FUNC(void);
typedef int INT;
typedef const char LCHAR;
typedef std::map<HWND, DWORD> WCMAP;