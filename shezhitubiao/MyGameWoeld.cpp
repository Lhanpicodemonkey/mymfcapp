// MyGameWoeld.cpp : 实现文件
//

#include "stdafx.h"
#include "shezhitubiao.h"
#include "MyGameWoeld.h"
#include "afxdialogex.h"


// CMyGameWoeld 对话框

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


// CMyGameWoeld 消息处理程序


void CMyGameWoeld::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	/*if (FALSE == falg)
	{
		m_games = point;
		falg = TRUE;
	}*/
	//CDialogEx::OnLButtonDown(nFlags, point);
}


void CMyGameWoeld::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//falg = FALSE;
	//CDialogEx::OnLButtonUp(nFlags, point);
}


BOOL CMyGameWoeld::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetTimer(2, 1000, 0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CMyGameWoeld::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 2)
	{
		m_Game_x.DrawLine();
	}
	CDialogEx::OnTimer(nIDEvent);
}
