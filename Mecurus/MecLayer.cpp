// MecLayer.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Mecurus.h"
#include "MecLayer.h"


// MecLayer

IMPLEMENT_DYNAMIC(MecLayer, CStatic)

MecLayer::MecLayer()
{

}

MecLayer::~MecLayer()
{

}

BOOL MecLayer::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.dwExStyle |= WS_EX_TRANSPARENT;
	return CStatic::PreCreateWindow(cs);
}

HBRUSH MecLayer::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	pDC->SetBkMode(TRANSPARENT);
	return m_brush;
}

HBRUSH MecLayer::CtlColor(CDC* pDC, UINT /*nCtlColor*/)
{
	pDC->SetBkMode(TRANSPARENT);
	return (HBRUSH)GetStockObject(NULL_BRUSH);
}

VOID MecLayer::PreSubclassWindow()
{
	CStatic::PreSubclassWindow();

	const LONG_PTR exStyle = GetWindowLongPtr(m_hWnd, GWL_EXSTYLE);
	SetWindowLongPtr(m_hWnd, GWL_EXSTYLE, exStyle | WS_EX_TRANSPARENT);
}

LRESULT MecLayer::OnSetText(WPARAM wParam, LPARAM lParam)
{
	LRESULT Result = Default();
	CRect Rect;
	GetWindowRect(&Rect);
	GetParent()->ScreenToClient(&Rect);
	GetParent()->InvalidateRect(&Rect);
	GetParent()->UpdateWindow();
	return Result;
}

BOOL MecLayer::OnEraseBkgnd(CDC *pDC)
{
	CRect Rect, ParentRect;
	GetClientRect(&Rect);
	GetParent()->GetClientRect(&ParentRect);
	CPoint ptLeftTop = CPoint(0, 0);
	ClientToScreen(&ptLeftTop);
	GetParent()->ScreenToClient(&ptLeftTop);
	CDC MemDC;
	CBitmap Bmp;

	MemDC.CreateCompatibleDC(NULL);
	Bmp.CreateBitmap(ParentRect.Width(), ParentRect.Height(),
		MemDC.GetDeviceCaps(PLANES),
		MemDC.GetDeviceCaps(BITSPIXEL), NULL);
	CBitmap* pOldBmp = MemDC.SelectObject(&Bmp);
	GetParent()->SendMessage(WM_ERASEBKGND, (WPARAM)MemDC.m_hDC);
	pDC->BitBlt(0, 0, Rect.Width(), Rect.Height(), &MemDC, ptLeftTop.x, ptLeftTop.y, SRCCOPY);
	MemDC.SelectObject(pOldBmp);
	return true;

	return FALSE;
}

VOID MecLayer::OnPaint()
{
	CPaintDC dc(this); 
	dc.SetBkMode(TRANSPARENT);
}

VOID MecLayer::OnSizing(UINT fwSide, LPRECT pRect)
{
	CStatic::OnSizing(fwSide, pRect);
}

BOOL MecLayer::OnInitDialog()
{
	m_brush.CreateSolidBrush(RGB(255, 255, 255));

	return true;
}

LRESULT MecLayer::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	
	switch (message)
	{
	case WM_ENTERSIZEMOVE:
		
		break;
	case WM_EXITSIZEMOVE:
		
		break;
	}

	return CStatic::DefWindowProc(message, wParam, lParam);
}

VOID MecLayer::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CStatic::OnWindowPosChanged(lpwndpos);
}

BEGIN_MESSAGE_MAP(MecLayer, CStatic)
	ON_WM_ERASEBKGND()
	ON_WM_MOVE()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_WINDOWPOSCHANGED()
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()



// MecLayer 메시지 처리기입니다.


