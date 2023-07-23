#pragma once


// CImgView1 ��ȭ �����Դϴ�.

class CImgView1 : public CDialogEx
{
	DECLARE_DYNAMIC(CImgView1)

public:
	CImgView1(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CImgView1();

	CWnd* m_pParent;
	CImage m_Image;
	int m_nSize = 1;
	double dCenterX;
	double dCenterY;


// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMGVIEW1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
private:
	void initImage();
	void drawData(CDC* pDC);
	bool isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	bool isInCircleEdge(int i, int j, int nCenterX, int nCenterY, int nRadius);
	void getCenterData();
public:
	afx_msg void OnPaint();
	void DrawCircle(int x, int y, int nRadius, int nGray);
};
