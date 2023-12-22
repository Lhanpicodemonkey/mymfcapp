
// shezhitubiaoDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CshezhitubiaoDlg �Ի���



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


// CshezhitubiaoDlg ��Ϣ�������

BOOL CshezhitubiaoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CshezhitubiaoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CshezhitubiaoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int CshezhitubiaoDlg::DrawButton(int iID, int nBMPID, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	UINT uStyle = DFCS_BUTTONPUSH;//��ȡDFCS_BUTTONPUSH�����°�ť��ֵ������ uStyle
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);//Attach �� Windows �豸�����ĸ��ӵ��� CDC ����

	CWnd *pWnd = GetDlgItem(iID);
	CRect r;
	CString strCaption;
	if (NULL != pWnd)//�жϿؼ�ID�Ƿ�Ϊ��,��Ϊ�ս����жϣ�Ϊ���򲻽���
	{
		pWnd->GetClientRect(&r);//��ȡ�ͻ�����С
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	INT_PTR nRes;
	CComDlg comDlg;//����Ի���ComDlgʵ��
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
