#pragma once
#include "afxwin.h"


// CCounterDlg 对话框
enum
{
	MASS_COUNTER_1,
	MASS_COUNTER_2,
	MASS_COUNTER_3,
	MASS_COUNTER_4,
	MASS_COUNTER_5,
	MASS_COUNTER_6,
	MASS_COUNTER_7,
	MASS_COUNTER_8,
	MASS_COUNTER_9,
	MASS_COUNTER_0,
	MASS_COUNTER_JIA,
	MASS_COUNTER_JIAN,
	MASS_COUNTER_CHENG,
	MASS_COUNTER_CHU,
	MASS_COUNTER_DENG,
};

class CCounterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCounterDlg)

public:
	CCounterDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCounterDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COUNTER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	LRESULT Dispose_Counter(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	StrCounter mstrCounter;
	StrCounters msterCounter;
	CString m_Value;
	unsigned int Value_a2;
	int ke;
	int hj;
	int guga;
	int wali;
	int Value_all;
	int Value_nm;
	int Value_h;
	int Value_2;
	int mnu;
	int bnm;
	int bnm1;
	int comj;
	int comj1;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClicked1Button();
	CListBox m_List;
	void Show_info(CString csInfo);
	afx_msg void OnBnClicked2Button();
	CString m_Values;
	afx_msg void OnBnClickedJiaButton();
	afx_msg void OnBnClickedDengButton();
};
