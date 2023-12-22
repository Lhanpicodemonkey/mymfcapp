
// shezhitubiaoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "shezhitubiao.h"
#include "shezhitubiaoDlg.h"
#include "afxdialogex.h"
#include "BmpTexButton.h"
#include "ComDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CshezhitubiaoDlg 对话框



CshezhitubiaoDlg::CshezhitubiaoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHEZHITUBIAO_DIALOG, pParent)
	, m_CounterDlg(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CshezhitubiaoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CshezhitubiaoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DRAWITEM()
	ON_BN_CLICKED(IDC_BUTTON1, &CshezhitubiaoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CshezhitubiaoDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CshezhitubiaoDlg 消息处理程序

BOOL CshezhitubiaoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CshezhitubiaoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CshezhitubiaoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CshezhitubiaoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int CshezhitubiaoDlg::DrawButton(int iID, int nBMPID, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	UINT uStyle = DFCS_BUTTONPUSH;//获取DFCS_BUTTONPUSH（按下按钮的值）赋予 uStyle
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);//Attach 将 Windows 设备上下文附加到此 CDC 对象。

	CWnd *pWnd = GetDlgItem(iID);
	CRect r;
	CString strCaption;
	if (NULL != pWnd)//判断控件ID是否为空,不为空进入判断，为空则不进入
	{
		pWnd->GetClientRect(&r);//获取客户区大小
		pWnd->GetWindowText(strCaption);
	}
	if (lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		r.left += 5;
		r.top += 5;
		uStyle |= DFCS_PUSHED;
	}
	::DrawFrameControl(lpDrawItemStruct->hDC, &lpDrawItemStruct->rcItem, DFC_BUTTON, uStyle);
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap bmp;
	bmp.LoadBitmap(nBMPID);
	memDC.SelectObject(&bmp);
	dc.BitBlt(r.left + 5, r.top + (r.Height() - 19) / 2, 32, 19, &memDC, 1, 1, SRCCOPY);
	dc.SetTextColor(RGB(0xFF, 0, 0));
	dc.SetBkMode(TRANSPARENT);
	r.left = r.left + 42;
	dc.DrawText(strCaption, &r, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	return 0;
}


void CshezhitubiaoDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDCtl)
	{
		case IDC_BUTTON1:
			DrawButton(IDC_BUTTON1, IDB_W_BITMAP, lpDrawItemStruct);
			break;
		case IDC_BUTTON2:
			DrawButton(IDC_BUTTON2, IDB_G_BITMAP, lpDrawItemStruct);
			break;
		case IDC_BUTTON3:
			DrawButton(IDC_BUTTON3, IDB_L_BITMAP, lpDrawItemStruct);
			break;
		case IDC_BUTTON4:
			DrawButton(IDC_BUTTON4, IDB_S_BITMAP, lpDrawItemStruct);
			break;
	}

	__super::OnDrawItem(nIDCtl, lpDrawItemStruct);
}


void CshezhitubiaoDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;
	CComDlg comDlg;//构造对话框ComDlg实例
	CString kaka;
	nRes = comDlg.DoModal();
	if (nRes == IDOK)
	{
		GetDlgItem(IDC_BUTTON1)->GetWindowText(kaka);
		SetDlgItemText(IDC_xianshi_EDIT, kaka);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	}
	
}


void CshezhitubiaoDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//INT_PTR nRes;
	//CCounterDlg counterDlg;
	//nRes = counterDlg.DoModal();
	//GetDlgItem(IDD_SHEZHITUBIAO_DIALOG)->ShowWindow(SW_HIDE);
	//if (IDCANCEL == nRes)
	//	return;
	CString wanduzi;
	if (NULL == m_CounterDlg) {
		m_CounterDlg = new CCounterDlg;
		m_CounterDlg->Create(IDD_COUNTER_DIALOG, this);
	}
	m_CounterDlg->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON2)->GetWindowText(wanduzi);
	SetDlgItemText(IDC_xianshi_EDIT, wanduzi);
}
