// Game.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "shezhitubiao.h"
#include "Game.h"
#include "MyGameWoeld.h"


// CGame

IMPLEMENT_DYNAMIC(CGame, CWnd)

CGame::CGame()
{
	RegisterGameClass();
	x = y = 0;
	width = height = 400;
	this->datalen = width / 2;//����ֵ����this��
}

CGame::~CGame()
{
}


BEGIN_MESSAGE_MAP(CGame, CWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CGame ��Ϣ�������
BOOL CGame::RegisterGameClass()
{
	WNDCLASS WindowClass;
	HINSTANCE hInst = AfxGetInstanceHandle();
	if (!::GetClassInfo(hInst, "MyGameDraw", &WindowClass))
	{
		WindowClass.style = CS_DBLCLKS;
		WindowClass.lpfnWndProc = ::DefWindowProc;
		WindowClass.cbClsExtra = WindowClass.cbWndExtra = 0;
		WindowClass.hInstance = hInst;
		WindowClass.hIcon = NULL;
		WindowClass.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		WindowClass.hbrBackground = ::GetSysColorBrush(COLOR_WINDOW);
		WindowClass.lpszMenuName = NULL;
		WindowClass.lpszClassName = "MyGameDraw";
		if (!AfxRegisterClass(&WindowClass))
		{
			AfxThrowResourceException();
			return FALSE;
		}
	}
	return TRUE;
}




void CGame::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (FALSE == falg)
	{
		m_games = point;
		falg = TRUE;
	}
	//CWnd::OnLButtonDown(nFlags, point);
}


void CGame::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (TRUE == falg)
	{
		CDC * dc = GetDC();
		dc->MoveTo(m_games);
		dc->LineTo(point);
		m_games = point;
		ReleaseDC(dc);
	}
	CWnd::OnMouseMove(nFlags, point);
}


void CGame::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	falg = FALSE;
	//CWnd::OnLButtonUp(nFlags, point);
}

void CGame::DrawLine()
{
	CRect rect;
	GetClientRect(&rect);
	CDC dc;
	CBitmap bmp;
	CDC * pdc = GetDC();
	if (!pdc)
		return;
	dc.CreateCompatibleDC(pdc);
	bmp.CreateCompatibleBitmap(pdc, rect.Width(), rect.Height());
	dc.SelectObject(bmp);

	CBrush bru(RGB(0, 0, 0));
	dc.SelectObject(bru);
	dc.Rectangle(x, y, x + width, y + height);

	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(37, 37, 37));
	dc.SelectObject(&pen);

	//������
	for (int i = height / 2;i <= height;i += 25)
	{
		dc.MoveTo(0 + x, i + y);
		dc.LineTo(width + x, i + y);
	}
	for (int i = height / 2;i >= 0;i -= 25)
	{
		dc.MoveTo(0 + x, i + y);
		dc.LineTo(width + x, i + y);
	}
	CPen penx;
	penx.CreatePen(PS_SOLID, 2, RGB(20, 99, 253));//���û���
	dc.SelectObject(&penx);
	pdc->BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);//BitBlt ���ڴ�ԭ�豸�и���λͼ��Ŀ���豸���﷨��ʽ���£�
	pdc->DeleteDC();
	//��Բ


}



void CGame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CWnd::OnPaint()
	/*
	CRect rect;
	this->GetClientRect(rect);

	dc.MoveTo(0, 0);
	dc.LineTo(rect.right, rect.bottom);*/
	/*
	CRect rect;
	this->GetClientRect(rect);
	CDC *dfg = GetDC();
	dfg->MoveTo(rect.Width()/2, 10);
	dfg->LineTo(10, rect.Height()/2);
	dfg->LineTo(rect.Width() / 2, rect.Height() / 2);
	dfg->LineTo(rect.Height() / 2, 10);
	dfg->LineTo(10, 10);
	ReleaseDC(dfg);*/
	
}
