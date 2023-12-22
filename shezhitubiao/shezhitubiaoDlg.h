
// shezhitubiaoDlg.h : 头文件
//

#pragma once
#include "CounterDlg.h"

// CshezhitubiaoDlg 对话框
class CshezhitubiaoDlg : public CDialogEx
{
// 构造
public:
	CshezhitubiaoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHEZHITUBIAO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

private:
	CCounterDlg * m_CounterDlg;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	int DrawButton(int iID, int nBMPID, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
