#pragma once


// MecLayer

class MecLayer : public CStatic
{
	DECLARE_DYNAMIC(MecLayer)

public:
	MecLayer();
	virtual ~MecLayer();
	

protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual HBRUSH CtlColor(CDC* pDC, UINT /*nCtlColor*/);
	virtual HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual VOID PreSubclassWindow();
	virtual BOOL OnEraseBkgnd(CDC *pDC);
	virtual LRESULT OnSetText(WPARAM wParam, LPARAM lParam);
	virtual VOID OnPaint();
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual VOID OnSizing(UINT fwSide, LPRECT pRect);
	virtual VOID OnWindowPosChanged(WINDOWPOS* lpwndpos);
	virtual BOOL OnInitDialog();

	CBrush m_brush;

	DECLARE_MESSAGE_MAP()
};


