// MyGameWoeld.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "shezhitubiao.h"
#include "MyGameWoeld.h"
#include "afxdialogex.h"


// CMyGameWoeld �Ի���

IMPLEMENT_DYNAMIC(CMyGameWoeld, CDialogEx)

CMyGameWoeld::CMyGameWoeld(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GAME_DIALOG, pParent)
{

}

CMyGameWoeld::~CMyGameWoeld()
{
}

void CMyGameWoeld::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GAME_SCREEN_CUSTOM, m_Game_x);
}


BEGIN_MESSAGE_MAP(CMyGameWoeld, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMyGameWoeld ��Ϣ�������


void CMyGameWoeld::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	/*if (FALSE == falg)
	{
		m_games = point;
		falg = TRUE;
	}*/
	//CDialogEx::OnLButtonDown(nFlags, point);
}


void CMyGameWoeld::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*if (TRUE == falg)
	{
		CDC * dc = GetDC();
		dc->MoveTo(m_games);
		dc->LineTo(point);
		m_games = point;
		ReleaseDC(dc);
	}*/
	//CDialogEx::OnMouseMove(nFlags, point);
}


void CMyGameWoeld::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//falg = FALSE;
	//CDialogEx::OnLButtonUp(nFlags, point);
}


BOOL CMyGameWoeld::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetTimer(2, 1000, 0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CMyGameWoeld::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nIDEvent == 2)
	{
		m_Game_x.DrawLine();
	}
	CDialogEx::OnTimer(nIDEvent);
}
