#pragma once

#include "Game.h"
// CMyGameWoeld 对话框

class CMyGameWoeld : public CDialogEx
{
	DECLARE_DYNAMIC(CMyGameWoeld)

public:
	CMyGameWoeld(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyGameWoeld();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAME_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CGame m_Game_x;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
