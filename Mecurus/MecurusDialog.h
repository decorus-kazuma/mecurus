#pragma once


// MecurusDialog 대화 상자입니다.

class MecurusDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MecurusDialog)

public:
	MecurusDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~MecurusDialog();
	CEdit m_Edit;
	BOOL isLoaded;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MecurusDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
