
// MFC_ProjectDlg.h : 헤더 파일
//

#include "ImgView1.h"

#pragma once


// CMFC_ProjectDlg 대화 상자
class CMFC_ProjectDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFC_ProjectDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

	CImgView1 *m_pDlgImgView1;//ImageViewer1

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_PROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
