
// shezhitubiaoDlg.h : ͷ�ļ�
//

#pragma once
#include "CounterDlg.h"

// CshezhitubiaoDlg �Ի���
class CshezhitubiaoDlg : public CDialogEx
{
// ����
public:
	CshezhitubiaoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHEZHITUBIAO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

private:
	CCounterDlg * m_CounterDlg;
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
