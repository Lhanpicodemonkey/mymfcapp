// ComDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "shezhitubiao.h"
#include "SerialPortInfo.h"
#include "ComDlg.h"
#include "afxdialogex.h"
#include "WinIoCtl.h"
#include <Dbt.h>


// CComDlg 对话框

IMPLEMENT_DYNAMIC(CComDlg, CDialogEx)

CComDlg::CComDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COM_DIALOG, pParent)
	,wh(0)
{

}

CComDlg::~CComDlg()
{
}

void CComDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CANVAS_CUSTOM, canvas);
	DDX_Control(pDX, IDC_SERIAL_COMBO, m_seiral);
	DDX_Control(pDX, IDC_BAUB_COMBO, m_Baud);
	DDX_Control(pDX, IDC_COMBO3, m_stopbit);
	DDX_Control(pDX, IDC_DATABITS_COMBO, m_DataBits);
	DDX_Control(pDX, IDC_PARITYCHECK_COMBO, m_ParityCheck);
}


BEGIN_MESSAGE_MAP(CComDlg, CDialogEx)
	ON_BN_CLICKED(IDC_OPEN_SERIAL_BUTTON, &CComDlg::OnBnClickedOpenSerialButton)
	ON_MESSAGE(MESS_COM_HANDLE, &CComDlg::Main_thread)
	ON_BN_CLICKED(IDC_REFRESH_BUTTON, &CComDlg::OnBnClickedRefreshButton)
	ON_BN_CLICKED(IDC_SEND_BUTTON, &CComDlg::OnBnClickedSendButton)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, &CComDlg::OnBnClickedClearButton)
	ON_BN_CLICKED(IDC_GAME_BUTTON, &CComDlg::OnBnClickedGameButton)
END_MESSAGE_MAP()


// CComDlg 消息处理程序







BOOL CComDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	OnBnClickedRefreshButton();
	//串口号
	//m_seiral.AddString(_T("COM1"));
	//m_seiral.AddString(_T("COM2"));
	//m_seiral.AddString(_T("COM3"));
	//m_seiral.AddString(_T("COM4"));
	//m_seiral.AddString(_T("COM5"));

	//波特率
	m_Baud.AddString(_T("1382400"));
	m_Baud.AddString(_T("921600"));
	m_Baud.AddString(_T("460800"));
	m_Baud.AddString(_T("256000"));
	m_Baud.AddString(_T("230400"));
	m_Baud.AddString(_T("128000"));
	m_Baud.AddString(_T("115200"));
	m_Baud.AddString(_T("76800"));
	m_Baud.AddString(_T("57600"));
	m_Baud.AddString(_T("43000"));
	m_Baud.AddString(_T("38400"));
	m_Baud.AddString(_T("19200"));
	m_Baud.AddString(_T("14400"));
	m_Baud.AddString(_T("9600"));
	m_Baud.AddString(_T("4800"));
	m_Baud.AddString(_T("4800"));
	m_Baud.AddString(_T("2400"));
	m_Baud.AddString(_T("1200"));
	//————————————————
	//	版权声明：本文为CSDN博主「大道殊同」的原创文章，遵循CC 4.0 BY - SA版权协议，转载请附上原文出处链接及本声明。
	//	原文链接：https ://blog.csdn.net/zero_1778393206/article/details/103395575

	//停止位
	m_stopbit.AddString(_T("1"));
	m_stopbit.AddString(_T("1.5"));
	m_stopbit.AddString(_T("2"));

	//数据位
	m_DataBits.AddString(_T("8"));
	m_DataBits.AddString(_T("7"));
	m_DataBits.AddString(_T("6"));
	m_DataBits.AddString(_T("5"));

	m_ParityCheck.AddString(_T("无"));
	m_ParityCheck.AddString(_T("奇校验"));
	m_ParityCheck.AddString(_T("偶校验"));

	PostMessage(MESS_COM_HANDLE, MESS_TO_SM_INIT,0);
	SetTimer(2, RECEVIVE_TIMER, 0);
	/*
	CRect rect;
	GetClientRect(&rect);
	CDC dc;
	CBitmap bmp;
	CDC *pdc = GetDC();
	dc.CreateCompatibleDC(pdc);
	bmp.CreateCompatibleBitmap(pdc, rect.Width(), rect.Height());
	dc.SelectObject(&bmp);

	canvas.Init(dc);
	*/

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
void CComDlg::OnReceive()
{
	char uasrtbuff[RECEIVEBUFF_SIZE];
	unsigned int num = 0;
	num = m_SerialPort.readAllData(mpReceiveBuffM);
	/*
	CString k;
	k.Format(_T("%d"), num);
	SetDlgItemText(IDC_STATE_EDIT, k);*/

	if (num != 0)
	{
		//mpReceiveBuffM[num] = '\0';
		CString cn;
		cn.Format(_T("sh:%s ju:%d"), CString(mpReceiveBuffM), num);
		SetDlgItemText(IDC_STATE_EDIT, cn);

		CString cs;
		CString mp(mpReceiveBuffM);
		GetDlgItemText(IDC_RECEIVE_EDIT, cs);
		mp = mp + cs;
		SetDlgItemText(IDC_RECEIVE_EDIT, mp);
		SendDlgItemMessage(IDC_RECEIVE_EDIT, WM_VSCROLL, SB_BOTTOM, 0);

		if (num != 0)
		{
			for (int i = 0;i < num;i++)
			{
				for (int j = 0;j < 8;j++)
				{
					if ((mpReceiveBuffM[i] << j) & 0x80)
					{
						canvas.Updata(1 * 100);
					}
					else {
						canvas.Updata(0 * 100);
					}

				}
				/*if (mpReceiveBuffM[i] == '1')//0101 判断数组
				{
					canvas.Updata(1 * 100);
				}
				else if (mpReceiveBuffM[i] == '0')
				{
					canvas.Updata(0 * 100);
				}*/
			}
			
		}
		
	}
	

}
LRESULT CComDlg::Main_thread(WPARAM wParam, LPARAM lParam)
{
	//接收肯定需要延时轮询  可以通过延时进行轮询检测实现数据接收
	switch (wParam)
	{
		case MESS_TO_SM_INIT:
			iSymCom = START_PROCEDURE;
			break;
		case MESS_TO_SM_STATRT_RECEIV:
			if ((iSymCom == TEST_CUTFACILITY) || (iSymCom == START_PROCEDURE))//START_RECEIV_DATA 后续需要更换
			{
				CString dj;
				wh+=1;
				dj.Format(_T("%d"), wh);
				SetDlgItemText(IDC_STATE_EDIT, dj);
				SetTimer(RECEIVE_TIME, RECEVIVE_TIMER, 0);
				OnReceive();
				canvas.Draw();
				iSymCom = START_RECEIV_DATA;
			}
			break;
		case MESS_TO_SM_SEND:
			send_Data();
			SetDlgItemText(IDC_RECEIVE_EDIT, _T("sdfc"));
			iSymCom = SEND_SERIAL_DATA;
			//KillTimer(RECEIVE_TIME);
			break;
		case MESS_TO_SM_CLEAR:
			SetDlgItemText(IDC_RECEIVE_EDIT, _T(""));
			//KillTimer(RECEIVE_TIME);
			iSymCom = TEXT_CLEAR;
			break;
		case MESS_TO_SM_CLOSE_SERIAL:
			KillTimer(RECEIVE_TIME);
			m_SerialPort.close();
			iSymCom = STATE_EXIT;
			break;
	}
	switch (iSymCom)
	{
		case START_PROCEDURE:
			//if (OpenCom(Serial_P))//Serial_P
			//{
			//	SetTimer(RECEIVE_TIME, RECEVIVE_TIMER, 0);
			//	SetDlgItemText(IDC_STATE_EDIT, _T("那个逼崽子这么牛逼？"));
			//	
			//	//return 1;
			//}
			break;
		case START_RECEIV_DATA://串口打开后，实现数据接收
			if (wParam == MESS_TO_SM_TIMER)
			{
				if (lParam == RECEIVE_TIME)
				{
					//SetDlgItemText(IDC_STATE_EDIT, _T("狗东西"));
					//memcpy(mMyReceiveBuff, mpReceiveBuffM, sizeof(mpReceiveBuffM));
					//strcat_s(mMyReceiveBuff, mpReceiveBuffM);
					CString cs;

					CString mp(mpReceiveBuffM);
					GetDlgItemText(IDC_RECEIVE_EDIT, cs);
					mp = mp + cs;

					SetDlgItemText(IDC_RECEIVE_EDIT, mp);
					iSymCom = START_PROCEDURE;
					PostMessage(MESS_COM_HANDLE, MESS_TO_SM_STATRT_RECEIV, 0);
				}
			}
			break;
		case SEND_SERIAL_DATA:
			iSymCom = START_PROCEDURE;
			PostMessage(MESS_COM_HANDLE, MESS_TO_SM_STATRT_RECEIV, 0);
			break;
		case TEXT_CLEAR:
			memset(mpReceiveBuffM, 0, sizeof(mpReceiveBuffM));
			iSymCom = START_PROCEDURE;
			PostMessage(MESS_COM_HANDLE, MESS_TO_SM_STATRT_RECEIV, 0);
			break;
		case STATE_EXIT:
			PostMessage(MESS_COM_HANDLE, MESS_TO_SM_INIT, 0);
			break;
	}
	return 0;
}
unsigned char CComDlg::OpenCom(CString csComName)
{
	string portName;//定义变量
#ifdef UNICODE
	portName = CW2A(temp.GetString());//CW2A将宽字符集（Unicode）转化为多字符集（ASCII）
#else
	portName = csComName.GetBuffer();//缓冲区，获取GetBuffer返回的指针 或获取里边的值
#endif
	if (m_SerialPort.isOpened())//判断是否成功打开串口
	{
		m_SerialPort.close();//关闭端口连接
		Sleep(100);//延时
	}
	m_SerialPort.init(portName);//, BAUDRATE, itas109::Parity(0), itas109::DataBits(8), itas109::StopBits(0));

	m_SerialPort.open();

	if (m_SerialPort.isOpened())
	{
		CString cs = portName.c_str();
		cs += ":串口已打开，逼崽子";
		SetDlgItemText(IDC_STATE_EDIT, cs);
		return 1;
	}
	else {
		CString cs = portName.c_str();
		cs += ":串口打开失败，逼崽子你废了";
		SetDlgItemText(IDC_STATE_EDIT, cs);
	}
}


void CComDlg::OnBnClickedOpenSerialButton()
{
	// TODO: 在此添加控件通知处理程序代码
	static bool flag = FALSE;
	if (!flag)
	{
		//OpenCom("7");
		//获取串口号
		int sserial = m_seiral.GetCurSel();
		CString s;
		string l;
		if (sserial == -1)
		{
			return;
		}
		else {
			m_seiral.GetLBText(sserial, s);
			l = s.GetBuffer();
			Serial_P = s;
			SetDlgItemText(IDC_STATE_EDIT, s);
		}
		//CString n;
		//n.Format(_T("%u"), sjk);
		//SetDlgItemText(IDC_STATE_EDIT, n);
		DWORD Bbuad;//波特率
		BYTE Sstopbit, Ddatabit, Pprity;

		//获取波特率
		int index;
		CString text;
		index = m_Baud.GetCurSel();//获取选定项的序号
		if (index == -1)
		{
			return;
		}
		else {
			m_Baud.GetLBText(index, text);
			SetDlgItemText(IDC_STATE_EDIT, text);
			Bbuad = _ttoi(text);
		}

		//获取停止位
		index = m_stopbit.GetCurSel();
		if (index == -1)
		{
			return;
		}
		else {
			m_stopbit.GetLBText(index, text);
			if (text == "1")
			{
				Sstopbit = 0;
			}
			else if (text == "1.5")
			{
				Sstopbit = 1;
			}
			else if (text == "2")
			{
				Sstopbit = 2;
			}
		}

		//获取数据位
		index = m_DataBits.GetCurSel();
		if (index == -1)
		{
			return;
		}
		else {
			m_DataBits.GetLBText(index, text);
			Ddatabit = _ttoi(text);
		}

		//获取奇偶校验
		index = m_ParityCheck.GetCurSel();
		if (index == -1)
		{
			return;
		}
		else {
			m_ParityCheck.GetLBText(index, text);
			if (text == "无")
			{
				Pprity = 0;
			}
			else if (text == "奇校验")
			{
				Pprity = 1;
			}
			else if (text == "偶校验")
			{
				Pprity = 2;
			}
		}
		m_SerialPort.init(l, Bbuad, itas109::Parity(Pprity), itas109::DataBits(Ddatabit), itas109::StopBits(Sstopbit));
		//OpenCom(s);
		OpenCom(Serial_P);

		PostMessage(MESS_COM_HANDLE, MESS_TO_SM_STATRT_RECEIV, 0);
		//OnReceive();//不需要初始化，我需要的是按键控制开关 只要串口打开按钮一开，我们就开启数据接收
		
		GetDlgItem(IDC_OPEN_SERIAL_BUTTON)->SetWindowText(_T("关闭串口"));
		flag = TRUE;//需要设置
		//开启作为最初的状态
	}
	else
	{
		GetDlgItem(IDC_OPEN_SERIAL_BUTTON)->SetWindowText(_T("打开串口"));
		flag = FALSE;
		PostMessage(MESS_COM_HANDLE, MESS_TO_SM_CLOSE_SERIAL, 0);
	}

}


void CComDlg::OnBnClickedRefreshButton()//刷新及获取串口
{
	// TODO: 在此添加控件通知处理程序代码
	m_seiral.ResetContent();//从列表框中移除所有项，并在组合框中编辑控件(这才是对的)        从列表框中移除所有项，并在组合框中编辑控件。 可以使用此宏或显式发送 CB_RESETCONTENT 消息。
#if 1
	//获取串口号
	vector<SerialPortInfo> m_portsList = CSerialPortInfo::availablePortInfos();
	TCHAR m_regKeyValue[255];
	for (int i = 0;i < m_portsList.size();i++)
	{
#ifdef UINCODE
		int iLength;
		const char* _char = m_portsList[i].portName.c_str();
		iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
		MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, m_regKeyValue, iLength);
#else
		strcpy_s(m_regKeyValue, 255, m_portsList[i].portName.c_str());
#endif
		m_seiral.AddString(m_regKeyValue);//将获取的数值放置于下拉框
	}
	m_seiral.SetCurSel(0);//不再设置
#endif
}
void CComDlg::send_Data()
{
	CString sendText,cs;
	GetDlgItemText(IDC_SEND_EDIT, sendText);
	sendText += "\r\n";
	unsigned char *send;
	//send = (unsigned char *)sendText.GetBuffer(sendText.GetLength());
	//cs.Format(_T("%d"), sizeof(sendText));

	//SetDlgItemText(IDC_SEND_EDIT, cs);
	m_SerialPort.writeData(sendText, sendText.GetLength());
}

void CComDlg::OnBnClickedSendButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//发送数据
	PostMessage(MESS_COM_HANDLE, MESS_TO_SM_SEND, 0);
}


void CComDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	KillTimer(nIDEvent);

	PostMessage(MESS_COM_HANDLE, MESS_TO_SM_TIMER, 0);//MESS_TO_SM_STATRT_RECEIV 暂放，后会改
	//if (nIDEvent == 2)
	//{
		
	//}
	__super::OnTimer(nIDEvent);
}


void CComDlg::OnBnClickedClearButton()
{
	// TODO: 在此添加控件通知处理程序代码
	PostMessage(MESS_COM_HANDLE, MESS_TO_SM_CLEAR, 0);
}


void CComDlg::OnBnClickedGameButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//m_MyGame.DoModal();
	CString game_gou;
	if (NULL == m_MyGame)
	{
		m_MyGame = new CMyGameWoeld;
		m_MyGame->Create(IDD_GAME_DIALOG, this);
	}
	m_MyGame->ShowWindow(SW_SHOW);
	SetDlgItemText(IDC_SEND_EDIT, _T("傻吊"));
	//GetParent()->ShowWindow(SW_HIDE);
}
