// BmpTexButton.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "shezhitubiao.h"
#include "BmpTexButton.h"


// BmpTexButton

IMPLEMENT_DYNAMIC(BmpTexButton, CButton)

BmpTexButton::BmpTexButton()
{

}

BmpTexButton::~BmpTexButton()
{
}


BEGIN_MESSAGE_MAP(BmpTexButton, CButton)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// BmpTexButton ��Ϣ�������




void BmpTexButton::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CButton::OnPaint()
}
