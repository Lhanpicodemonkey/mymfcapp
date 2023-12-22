// MyCanvasCustom.cpp : ʵ���ļ�
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



// CMyCanvasCustom ��Ϣ�������
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
void CMyCanvasCustom::Init(CDC &dc)//��һ������
{
	Set();
	CBrush bru(RGB(0, 0, 0));//���ñ�����ɫΪ��ɫ
	dc.SelectObject(bru);//SelectObject ����������ѡ��ָ�����豸������ (DC) �� �µ� �����滻��ͬ���͵���һ������ �滻���������
	dc.Rectangle(x, y, width + x, height + y);//rectangle��������������һ�����ο�ģ�ͨ������ͼƬ�ı���ϡ�

	//������
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(37, 37, 37));
	dc.SelectObject(&pen);

	//������
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
	//������
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
//�����Һ���
void CMyCanvasCustom::DrawTest()
{
	CRect rect;
	GetClientRect(&rect);
	CDC dc;
	CBitmap bap;//�ڴ��г�����ʱͼ���λͼ
	CDC *pdc = GetDC();
	if (!pdc)
	{
		return;
	}
	dc.CreateCompatibleDC(pdc);//��������DC���������ڴ�DC
							   //��������λͼ��������PDC���������򻭳�����ͼ�α�ɺ�ɫ��
	bap.CreateCompatibleBitmap(pdc, rect.Width(), rect.Height());
	dc.SelectObject(&bap);

	Updata();
	Init(dc);

	CPen pen;
	pen.CreatePen(PS_SOLID, 2, RGB(20, 99, 253));//���û���
	dc.SelectObject(&pen);
	for (int j = 0;j < VI_date1.size();j++)
	{
		int x = this->x + (this->width / (float)VI_date1.size())*j;//����x����
		int y = this->y + this->height / 2 - VI_date1[j];//����y������
		if (j == 0)
		{
			dc.MoveTo(x, y);//���ʼ�ĵ�
		}
		else {
			dc.LineTo(x, y);
		}
	}
	pdc->BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);//BitBlt ���ڴ�ԭ�豸�и���λͼ��Ŀ���豸���﷨��ʽ���£�
	pdc->DeleteDC();
}
void CMyCanvasCustom::Draw()
{
	CRect rect;
	GetClientRect(&rect);
	CDC dc;
	CBitmap bmp;//�ڴ��г�����ʱͼ���λͼ

	CDC * pdc = GetDC();
	if (!pdc)
	{
		return;
	}
	dc.CreateCompatibleDC(pdc);//��������DC���������ڴ�DC
	//��������λͼ��������PDC���������򻭳�����ͼ�α�ɺ�ɫ��
	bmp.CreateCompatibleBitmap(pdc, rect.Width(), rect.Height());
	dc.SelectObject(&bmp);

	Init(dc);//��դ��

	CPen pen;
	pen.CreatePen(PS_SOLID, 2, RGB(20, 99, 253));
	dc.SelectObject(&pen);

	//Ӧ�þ�����λ��Ʋ��ε�
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
	//����Ҫ�����Լ�
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

