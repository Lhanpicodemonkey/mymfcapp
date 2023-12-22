// MyCanvasCustom.cpp : 实现文件
//

#include "stdafx.h"
#include "shezhitubiao.h"
#include "MyCanvasCustom.h"
//#include "VI.h"


// CMyCanvasCustom

IMPLEMENT_DYNAMIC(CMyCanvasCustom, CWnd)


CMyCanvasCustom::CMyCanvasCustom()
{
	RegisterWndClass();
	x = y = 0;
	width = height = 300;
	this->datalen = width / 25;
}

CMyCanvasCustom::~CMyCanvasCustom()
{
}


BEGIN_MESSAGE_MAP(CMyCanvasCustom, CWnd)
END_MESSAGE_MAP()



// CMyCanvasCustom 消息处理程序
BOOL CMyCanvasCustom::RegisterWndClass()
{
	WNDCLASS windowclass;
	HINSTANCE hInst = AfxGetInstanceHandle();
	if (!::GetClassInfo(hInst, "MyDrawPad", &windowclass))
	{
		windowclass.style = CS_DBLCLKS;
		windowclass.lpfnWndProc = ::DefWindowProc;
		windowclass.cbClsExtra = windowclass.cbWndExtra = 0;
		windowclass.hInstance = hInst;
		windowclass.hIcon = NULL;
		windowclass.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		windowclass.hbrBackground = ::GetSysColorBrush(COLOR_WINDOW);
		windowclass.lpszMenuName = NULL;
		windowclass.lpszClassName = "MyDrawPad";
		if (!AfxRegisterClass(&windowclass))
		{
			AfxThrowResourceException();
			return FALSE;
		}
	}
	return TRUE;
}

void CMyCanvasCustom::Set()
{
	CRect rect;
	GetClientRect(&rect);
	x = y = 0;
	width = rect.Width();//
	height = rect.Height();
	this->datalen = width / 25;
}
void CMyCanvasCustom::Init(CDC &dc)//做一个画布
{
	Set();
	CBrush bru(RGB(0, 0, 0));//设置背景颜色为黑色
	dc.SelectObject(bru);//SelectObject 函数将对象选择到指定的设备上下文 (DC) 。 新的 对象替换相同类型的上一个对象。 替换嘛，类似设置
	dc.Rectangle(x, y, width + x, height + y);//rectangle函数是用来绘制一个矩形框的，通常用在图片的标记上。

	//画背景
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(37, 37, 37));
	dc.SelectObject(&pen);

	//画横线
	for (int i = height / 2;i <= height;i += 25)
	{
		dc.MoveTo(0 + x, i + y);
		dc.LineTo(width + x, i + y);
	}
	for (int i = height / 2;i >= 0;i -= 25)
	{
		dc.MoveTo(0 + x, i + y);
		dc.LineTo(width + x, i + y);
	}
	//画竖线
	for (int j = width / 2;j < width;j += 25)
	{
		dc.MoveTo(x + j, 0 + y);
		dc.LineTo(x + j, height + y);
	}
	for (int j = width / 2;j >= 0;j -= 25)
	{
		dc.MoveTo(x + j, 0 + y);
		dc.LineTo(x + j, height + y);
	}
}
//画正弦函数
void CMyCanvasCustom::DrawTest()
{
	CRect rect;
	GetClientRect(&rect);
	CDC dc;
	CBitmap bap;//内存中承载临时图像的位图
	CDC *pdc = GetDC();
	if (!pdc)
	{
		return;
	}
	dc.CreateCompatibleDC(pdc);//依附窗口DC创建兼容内存DC
							   //创建兼容位图（必须用PDC创建，否则画出来的图形变成黑色）
	bap.CreateCompatibleBitmap(pdc, rect.Width(), rect.Height());
	dc.SelectObject(&bap);

	Updata();
	Init(dc);

	CPen pen;
	pen.CreatePen(PS_SOLID, 2, RGB(20, 99, 253));//设置画笔
	dc.SelectObject(&pen);
	for (int j = 0;j < VI_date1.size();j++)
	{
		int x = this->x + (this->width / (float)VI_date1.size())*j;//处理x坐标
		int y = this->y + this->height / 2 - VI_date1[j];//处理y轴坐标
		if (j == 0)
		{
			dc.MoveTo(x, y);//话最开始的点
		}
		else {
			dc.LineTo(x, y);
		}
	}
	pdc->BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);//BitBlt 用于从原设备中复制位图到目标设备，语法格式如下：
	pdc->DeleteDC();
}
void CMyCanvasCustom::Draw()
{
	CRect rect;
	GetClientRect(&rect);
	CDC dc;
	CBitmap bmp;//内存中承载临时图像的位图

	CDC * pdc = GetDC();
	if (!pdc)
	{
		return;
	}
	dc.CreateCompatibleDC(pdc);//依附窗口DC创建兼容内存DC
	//创建兼容位图（必须用PDC创建，否则画出来的图形变成黑色）
	bmp.CreateCompatibleBitmap(pdc, rect.Width(), rect.Height());
	dc.SelectObject(&bmp);

	Init(dc);//画栅格

	CPen pen;
	pen.CreatePen(PS_SOLID, 2, RGB(20, 99, 253));
	dc.SelectObject(&pen);

	//应该就是如何绘制波形的
	for (int j = 0;j < VI_data2.size();j++)
	{
		int x = this->x + j * 25;
		int y = this->y + this->height / 2 - VI_data2[j];
		if (j == 0)
			dc.MoveTo(x, y);
		else
			dc.LineTo(x, y);
		dc.LineTo(x + 25, y);
	}
	//还是要升华自己
	pdc->BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);
	pdc->DeleteDC();
}
void CMyCanvasCustom::Updata()
{
	int static d1 = 0;
	while (VI_date1.size() <= this->datalen)
	{
		float y = 100 * sin(2 * PI*0.01*d1);
		VI_date1.push_back(y);
		d1++;
	}
	if (VI_date1.size() > this->datalen)
	{
		vector<float>::iterator it = VI_date1.begin();
		VI_date1.erase(it);
	}
}
void CMyCanvasCustom::Updata(float data)
{
	VI_data2.push_back(data);
	if (VI_data2.size() > this->datalen)
	{
		vector<float>::iterator it = VI_data2.begin();
		VI_data2.erase(it);
	}
}

