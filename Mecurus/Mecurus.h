#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"		// 주 기호입니다.

class CMecurusApp : public CWinApp
{
public:
	CMecurusApp();

// 재정의입니다.
public:
	virtual BOOL InitInstance();
	virtual INT ExitInstance();

	DECLARE_MESSAGE_MAP()
};