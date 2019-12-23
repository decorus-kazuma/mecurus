// MecurusDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Mecurus.h"
#include "MecurusDialog.h"
#include "afxdialogex.h"


// MecurusDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(MecurusDialog, CDialogEx)

MecurusDialog::MecurusDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MECURUSDIALOG, pParent)
{

}

MecurusDialog::~MecurusDialog()
{
}

void MecurusDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MecurusDialog, CDialogEx)
END_MESSAGE_MAP()


// MecurusDialog 메시지 처리기입니다.
