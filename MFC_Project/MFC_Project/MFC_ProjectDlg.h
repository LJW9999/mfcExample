
// MFC_ProjectDlg.h : ��� ����
//

#include "ImgView1.h"

#pragma once


// CMFC_ProjectDlg ��ȭ ����
class CMFC_ProjectDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMFC_ProjectDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	CImgView1 *m_pDlgImgView1;//ImageViewer1

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_PROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAction();
	int m_nCircleSize;
	afx_msg void OnDestroy();
private:
	void DrawCircle(unsigned char* fm, int i, int j, int nRadius, int nGray);
};
