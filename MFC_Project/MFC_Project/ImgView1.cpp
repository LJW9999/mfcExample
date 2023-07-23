// ImgView1.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFC_Project.h"
#include "ImgView1.h"
#include "afxdialogex.h"


// CImgView1 대화 상자입니다.

IMPLEMENT_DYNAMIC(CImgView1, CDialogEx)

CImgView1::CImgView1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_IMGVIEW1, pParent)
{
	m_pParent = pParent;
}

CImgView1::~CImgView1()
{
}

void CImgView1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CImgView1, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CImgView1 메시지 처리기입니다.


BOOL CImgView1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	initImage();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CImgView1::initImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_Image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8)
	{
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_Image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_Image.GetPitch();
	unsigned char* fm = (unsigned char*)m_Image.GetBits();

	memset(fm, 0, nWidth*nHeight);
}

void CImgView1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	if (m_Image)
	{
		m_Image.Draw(dc, 0, 0);
	}
	drawData(&dc);
}

void CImgView1::drawData(CDC *pDC)
{
	
	int nL = dCenterX - (m_nSize);
	int nT = dCenterY - (m_nSize);
	int nR = dCenterX + (m_nSize);
	int nB = dCenterY + (m_nSize);
	CRect rect(nL, nT, nR, nB);

	CPen  pen;
	pen.CreatePen(PS_SOLID, 5, COLOR_YELLOW);
	CPen* pOldPen = pDC->SelectObject(&pen);

		pDC->Ellipse(rect);
		pDC->MoveTo(dCenterX - 5, dCenterY);
		pDC->LineTo(dCenterX + 5, dCenterY);
		pDC->MoveTo(dCenterX, dCenterY - 5);
		pDC->LineTo(dCenterX, dCenterY + 5);

		
	
	pDC->SelectObject(pOldPen);
}

void CImgView1::DrawCircle(int x, int y, int nRadius, int nGray)
{
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_Image.GetPitch();
	unsigned char* fm = (unsigned char*)m_Image.GetBits();
	memset(fm, 0, m_Image.GetWidth()*m_Image.GetHeight());

		for (int j = y; j < y + nRadius * 2; j++)
		{
			for (int i = x; i < x + nRadius * 2; i++)
			{
				if(isInCircle(i, j, nCenterX, nCenterY, nRadius))
					fm[j*nPitch + i] = nGray;
			}
		}

		m_nSize = nRadius;
		Invalidate();
		//무게중심 구하고, Cross 및 외곽 Circle 그리기
		getCenterData();


		
}
bool CImgView1::isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;
	
	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX*dX + dY*dY;

	if (dDist < nRadius*nRadius)
	{
		bRet = TRUE;
	}

	return bRet;
}

//bool CImgView1::isInCircleEdge(int i, int j, int nCenterX, int nCenterY, int nRadius)
//{
//	bool bRet = false;
//
//	double dX = i - nCenterX;
//	double dY = j - nCenterY;
//	double dDist = dX*dX + dY*dY;
//
//	if (dDist == nRadius*nRadius)
//	{
//		bRet = TRUE;
//	}
//
//	return bRet;
//}


void CImgView1::getCenterData()
{
	unsigned char* fm = (unsigned char*)m_Image.GetBits();
	int nWidth = m_Image.GetWidth();
	int nHeight = m_Image.GetHeight();
	int nPitch = m_Image.GetPitch();

	int nTh = 255;
	CRect rect(0, 0, nWidth, nHeight);
	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;
	for (int j = rect.top; j < rect.bottom; j++)
	{
		for (int i = rect.left; i < rect.right; i++)
		{
			if (fm[j*nPitch + i] >= nTh)
			{
				nSumX += i;
				nSumY += j;
				nCount++;
			}
		}
	}

	dCenterX = (double)nSumX / nCount;
	dCenterY = (double)nSumY / nCount;


}