// ComDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "shezhitubiao.h"
#include "SerialPortInfo.h"
#include "ComDlg.h"
#include "afxdialogex.h"
#include "WinIoCtl.h"
#include <Dbt.h>


// CComDlg �Ի���

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


// CComDlg ��Ϣ�������







BOOL CComDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	OnBnClickedRefreshButton();
	//���ں�
	//m_seiral.AddString(_T("COM1"));
	//m_seiral.AddString(_T("COM2"));
	//m_seiral.AddString(_T("COM3"));
	//m_seiral.AddString(_T("COM4"));
	//m_seiral.AddString(_T("COM5"));

	//������
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
	//��������������������������������
	//	��Ȩ����������ΪCSDN�����������ͬ����ԭ�����£���ѭCC 4.0 BY - SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
	//	ԭ�����ӣ�https ://blog.csdn.net/zero_1778393206/article/details/103395575

	//ֹͣλ
	m_stopbit.AddString(_T("1"));
	m_stopbit.AddString(_T("1.5"));
	m_stopbit.AddString(_T("2"));

	//����λ
	m_DataBits.AddString(_T("8"));
	m_DataBits.AddString(_T("7"));
	m_DataBits.AddString(_T("6"));
	m_DataBits.AddString(_T("5"));

	m_ParityCheck.AddString(_T("��"));
	m_ParityCheck.AddString(_T("��У��"));
	m_ParityCheck.AddString(_T("żУ��"));

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
				  // �쳣: OCX ����ҳӦ���� FALSE
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
				/*if (mpReceiveBuffM[i] == '1')//0101 �ж�����
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
	//���տ϶���Ҫ��ʱ��ѯ  ����ͨ����ʱ������ѯ���ʵ�����ݽ���
	switch (wParam)
	{
		case MESS_TO_SM_INIT:
			iSymCom = START_PROCEDURE;
			break;
		case MESS_TO_SM_STATRT_RECEIV:
			if ((iSymCom == TEST_CUTFACILITY) || (iSymCom == START_PROCEDURE))//START_RECEIV_DATA ������Ҫ����
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
			//	SetDlgItemText(IDC_STATE_EDIT, _T("�Ǹ���������ôţ�ƣ�"));
			//	
			//	//return 1;
			//}
			break;
		case START_RECEIV_DATA://���ڴ򿪺�ʵ�����ݽ���
			if (wParam == MESS_TO_SM_TIMER)
			{
				if (lParam == RECEIVE_TIME)
				{
					//SetDlgItemText(IDC_STATE_EDIT, _T("������"));
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
	string portName;//�������
#ifdef UNICODE
	portName = CW2A(temp.GetString());//CW2A�����ַ�����Unicode��ת��Ϊ���ַ�����ASCII��
#else
	portName = csComName.GetBuffer();//����������ȡGetBuffer���ص�ָ�� ���ȡ��ߵ�ֵ
#endif
	if (m_SerialPort.isOpened())//�ж��Ƿ�ɹ��򿪴���
	{
		m_SerialPort.close();//�رն˿�����
		Sleep(100);//��ʱ
	}
	m_SerialPort.init(portName);//, BAUDRATE, itas109::Parity(0), itas109::DataBits(8), itas109::StopBits(0));

	m_SerialPort.open();

	if (m_SerialPort.isOpened())
	{
		CString cs = portName.c_str();
		cs += ":�����Ѵ򿪣�������";
		SetDlgItemText(IDC_STATE_EDIT, cs);
		return 1;
	}
	else {
		CString cs = portName.c_str();
		cs += ":���ڴ�ʧ�ܣ������������";
		SetDlgItemText(IDC_STATE_EDIT, cs);
	}
}


void CComDlg::OnBnClickedOpenSerialButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	static bool flag = FALSE;
	if (!flag)
	{
		//OpenCom("7");
		//��ȡ���ں�
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
		DWORD Bbuad;//������
		BYTE Sstopbit, Ddatabit, Pprity;

		//��ȡ������
		int index;
		CString text;
		index = m_Baud.GetCurSel();//��ȡѡ��������
		if (index == -1)
		{
			return;
		}
		else {
			m_Baud.GetLBText(index, text);
			SetDlgItemText(IDC_STATE_EDIT, text);
			Bbuad = _ttoi(text);
		}

		//��ȡֹͣλ
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

		//��ȡ����λ
		index = m_DataBits.GetCurSel();
		if (index == -1)
		{
			return;
		}
		else {
			m_DataBits.GetLBText(index, text);
			Ddatabit = _ttoi(text);
		}

		//��ȡ��żУ��
		index = m_ParityCheck.GetCurSel();
		if (index == -1)
		{
			return;
		}
		else {
			m_ParityCheck.GetLBText(index, text);
			if (text == "��")
			{
				Pprity = 0;
			}
			else if (text == "��У��")
			{
				Pprity = 1;
			}
			else if (text == "żУ��")
			{
				Pprity = 2;
			}
		}
		m_SerialPort.init(l, Bbuad, itas109::Parity(Pprity), itas109::DataBits(Ddatabit), itas109::StopBits(Sstopbit));
		//OpenCom(s);
		OpenCom(Serial_P);

		PostMessage(MESS_COM_HANDLE, MESS_TO_SM_STATRT_RECEIV, 0);
		//OnReceive();//����Ҫ��ʼ��������Ҫ���ǰ������ƿ��� ֻҪ���ڴ򿪰�ťһ�������ǾͿ������ݽ���
		
		GetDlgItem(IDC_OPEN_SERIAL_BUTTON)->SetWindowText(_T("�رմ���"));
		flag = TRUE;//��Ҫ����
		//������Ϊ�����״̬
	}
	else
	{
		GetDlgItem(IDC_OPEN_SERIAL_BUTTON)->SetWindowText(_T("�򿪴���"));
		flag = FALSE;
		PostMessage(MESS_COM_HANDLE, MESS_TO_SM_CLOSE_SERIAL, 0);
	}

}


void CComDlg::OnBnClickedRefreshButton()//ˢ�¼���ȡ����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_seiral.ResetContent();//���б�����Ƴ������������Ͽ��б༭�ؼ�(����ǶԵ�)        ���б�����Ƴ������������Ͽ��б༭�ؼ��� ����ʹ�ô˺����ʽ���� CB_RESETCONTENT ��Ϣ��
#if 1
	//��ȡ���ں�
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
		m_seiral.AddString(m_regKeyValue);//����ȡ����ֵ������������
	}
	m_seiral.SetCurSel(0);//��������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��������
	PostMessage(MESS_COM_HANDLE, MESS_TO_SM_SEND, 0);
}


void CComDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	KillTimer(nIDEvent);

	PostMessage(MESS_COM_HANDLE, MESS_TO_SM_TIMER, 0);//MESS_TO_SM_STATRT_RECEIV �ݷţ�����
	//if (nIDEvent == 2)
	//{
		
	//}
	__super::OnTimer(nIDEvent);
}


void CComDlg::OnBnClickedClearButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PostMessage(MESS_COM_HANDLE, MESS_TO_SM_CLEAR, 0);
}


void CComDlg::OnBnClickedGameButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//m_MyGame.DoModal();
	CString game_gou;
	if (NULL == m_MyGame)
	{
		m_MyGame = new CMyGameWoeld;
		m_MyGame->Create(IDD_GAME_DIALOG, this);
	}
	m_MyGame->ShowWindow(SW_SHOW);
	SetDlgItemText(IDC_SEND_EDIT, _T("ɵ��"));
	//GetParent()->ShowWindow(SW_HIDE);
}
