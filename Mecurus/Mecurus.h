#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.

class CMecurusApp : public CWinApp
{
public:
	CMecurusApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual INT ExitInstance();

	DECLARE_MESSAGE_MAP()
};