// MecurusDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Mecurus.h"
#include "MecurusDialog.h"
#include "afxdialogex.h"


// MecurusDialog ��ȭ �����Դϴ�.

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


// MecurusDialog �޽��� ó�����Դϴ�.
