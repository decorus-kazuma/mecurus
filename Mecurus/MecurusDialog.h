#pragma once


// MecurusDialog ��ȭ �����Դϴ�.

class MecurusDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MecurusDialog)

public:
	MecurusDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~MecurusDialog();
	CEdit m_Edit;
	BOOL isLoaded;

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MecurusDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
