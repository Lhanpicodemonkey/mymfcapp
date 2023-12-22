// BmpTexButton.cpp : 实现文件
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



// BmpTexButton 消息处理程序




void BmpTexButton::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CButton::OnPaint()
}
