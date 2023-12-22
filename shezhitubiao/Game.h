#pragma once


// CGame

class CGame : public CWnd
{
	DECLARE_DYNAMIC(CGame)

public:
	CGame();
	virtual ~CGame();
protected:
	int x, y, width, height;
	int datalen;
protected:
	DECLARE_MESSAGE_MAP()
public:
	BOOL falg;
	CDC cpen;
	CPoint m_games;
	BOOL RegisterGameClass();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	void DrawLine();
};


