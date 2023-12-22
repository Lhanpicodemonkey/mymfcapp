#pragma once

#include "afxcmn.h"
#include "MyCanvasCustom.h"
#include "afxwin.h"
#include "SerialPort.h"
#include "MyGameWoeld.h"
#include <vector>
#include <map>
using namespace itas109;
using std::map;
using std::vector;

#define BAUDRATE	9600
#define SERIAL_PORT_TIMER 2000
#define RECEVIVE_TIMER 1000
// CComDlg 对话框
enum {
	MESS_TO_SM_INIT,//进程最开始
	MESS_TO_SM_STATRT_RECEIV,
	MESS_TO_SM_SEND,
	MESS_TO_SM_CLEAR,
	MESS_TO_SM_TIMER,
	MESS_TO_SM_CLOSE_SERIAL,

};

class CComDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CComDlg)

public:
	CComDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CComDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COM_DIALOG };
#endif
protected:
	CMyGameWoeld *m_MyGame;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	LRESULT Main_thread(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	
	CString Serial_P;
	int wh;
	unsigned char iSymCom;
	CSerialPort m_SerialPort;
	CMyCanvasCustom canvas;
	CComboBox m_seiral;
	CComboBox m_Baud;
	CComboBox m_stopbit;
	CComboBox m_DataBits;
	CComboBox m_ParityCheck;
	unsigned char OpenCom(CString csComName);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOpenSerialButton();
	afx_msg void OnBnClickedRefreshButton();
	void OnReceive();
	char mpReceiveBuffM[RECEIVEBUFF_SIZE];
	char mMyReceiveBuff[RECEIVEBUFF_SIZE];
	unsigned int iReceiveBytesNow;
	afx_msg void OnBnClickedSendButton();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedClearButton();
	void send_Data();

	afx_msg void OnBnClickedGameButton();
};
