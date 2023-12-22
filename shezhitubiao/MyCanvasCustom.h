#pragma once

#include <vector>
using namespace std;
// CMyCanvasCustom
#define PI 3.14159265853

class CMyCanvasCustom : public CWnd
{
	DECLARE_DYNAMIC(CMyCanvasCustom)

public:
	CMyCanvasCustom();
	virtual ~CMyCanvasCustom();
protected:
	int x, y, width, height;
	int datalen;
	vector<float> VI_date1, VI_data2;
protected:
	DECLARE_MESSAGE_MAP()
public:
	BOOL RegisterWndClass();
	void Set();
	void Init(CDC &dc);
	void DrawTest();
	void Draw();
	void Updata();
	void Updata(float data);
};


