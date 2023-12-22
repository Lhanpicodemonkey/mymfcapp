#pragma once


// BmpTexButton

class BmpTexButton : public CButton
{
	DECLARE_DYNAMIC(BmpTexButton)

public:
	BmpTexButton();
	virtual ~BmpTexButton();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


