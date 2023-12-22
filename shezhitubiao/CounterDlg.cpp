// CounterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "shezhitubiao.h"
//#include "CounterDlg.h"
#include "afxdialogex.h"
#include "ComDlg.h"
#include "shezhitubiaoDlg.h"


// CCounterDlg 对话框

IMPLEMENT_DYNAMIC(CCounterDlg, CDialogEx)

CCounterDlg::CCounterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COUNTER_DIALOG, pParent)
	,bnm(0)
	,bnm1(0)
	,comj(0)
	,comj1(0)
	,mnu(0)
	,Value_all(0)
	,Value_h(0)
	,Value_2(0)
	,Value_nm(0)
	,Value_a2(0)
	,wali(0)
	,guga(0)
	,hj(0)
	,ke(0)
	, m_Values(_T(""))
{

}

CCounterDlg::~CCounterDlg()
{
}

void CCounterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_ZHI_EDIT, m_Values);
}


BEGIN_MESSAGE_MAP(CCounterDlg, CDialogEx)
	ON_BN_CLICKED(IDC_1_BUTTON, &CCounterDlg::OnBnClicked1Button)
	ON_BN_CLICKED(IDC_2_BUTTON, &CCounterDlg::OnBnClicked2Button)
	ON_BN_CLICKED(IDC_JIA_BUTTON, &CCounterDlg::OnBnClickedJiaButton)
	ON_MESSAGE(MESS_COUNTER, &CCounterDlg::Dispose_Counter)
	ON_BN_CLICKED(IDC_DENG_BUTTON, &CCounterDlg::OnBnClickedDengButton)
END_MESSAGE_MAP()


// CCounterDlg 消息处理程序


BOOL CCounterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


LRESULT CCounterDlg::Dispose_Counter(WPARAM wParam, LPARAM lParam)
{
	int i = 0;
	switch (wParam)
	{
		case MASS_COUNTER_JIA:
			bnm = 1;
			bnm1 = 1;
			break;
		case MASS_COUNTER_1:
			if (Value_h > 1&& mstrCounter.Value_g == 1)
			{
				//m_Value.Format(_T("%u"), Value_h);
				//Show_info(m_Value);
				//SetDlgItemText(IDC_EDIT1, m_Value);
				mstrCounter.Value_g = 0;
				if (bnm != 1)
				{
					Value_all++;
					//comj = Value_all;
					if (Value_all <= 9)
					{
						for (i = 0;i <= 10;i++)
						{
							if (Value_h == i)
							{
								Value_nm = 1;
								mstrCounter.value_1 = msterCounter.values_he[i] * 10 + 1;
								Value_a2 = mstrCounter.value_1;
								m_Value.Format(_T("%u"), mstrCounter.value_1);
								Show_info(m_Value);
								SetDlgItemText(IDC_ZHI_EDIT, m_Value);
								msterCounter.values_1[comj1] = mstrCounter.value_1;
								msterCounter.values_he[1] = mstrCounter.value_1;
							}
						}
					}
					else {
						//Value_all = 0;
					}
					
				}
				else if (bnm == 1)
				{
					bnm = 0;
					comj = 0;
					comj1++;
					msterCounter.values_1[comj1] = mstrCounter.value_1;
					if (comj1 == 9)
						comj1 = 0;
				}
				Value_h = 0;
			}
			else {
				if (bnm != 1)
				{
					comj++;
					
					Value_all = comj;
					if (comj1 <= 9)
					{
						if (mnu != 0)
						{
							mnu = 0;
							comj = comj + 1;
						}
						if (comj <= 9)
						{
							if (Value_nm == 1)
							{
								//Value_nm = 0;
								mstrCounter.value_1 = Value_a2;
								wali = 9 - sizeof(Value_a2);
								//for (i = 1;i < comj- guga;i++)
							//	{
									if (comj <= wali)
									{
										for (i = 1;i < comj - guga;i++)
										{
											mstrCounter.value_1 = mstrCounter.value_1 * 10 + 1;
											m_Value.Format(_T("%u"), mstrCounter.value_1);
											Show_info(m_Value);
											SetDlgItemText(IDC_EDIT1, m_Value);
										}
										//ke = 1;
									}
									else if ((comj > sizeof(Value_a2)))
									{
										//ke = 0;
										hj = comj - wali;
										for (i = 1;i < hj;i++)
										{
											mstrCounter.value_1 = mstrCounter.value_1 * 10 + 1;
										}
										//mstrCounter.value_1 = mstrCounter.value_1 * 10 + 1;
									}
									else
									{
										Value_a2 = 0;
										wali = 0;
										Value_nm = 0;
										comj = 0;
										guga = 0;
									}
									
							//	}
								//guga = comj;
								msterCounter.values_he[1] = mstrCounter.value_1;
							}
							else
							{
								for (i = 1;i < comj;i++)
								{
									guga++;
									mstrCounter.value_1 = mstrCounter.value_1 * 10 + 1;
								}
								msterCounter.values_he[1] = mstrCounter.value_1;
								Value_a2 = 1;
							}
							
							msterCounter.values_he[1] = mstrCounter.value_1;
						}
						else
						{
							Value_a2 = 0;
							Value_nm = 0;
							guga = 0;
							comj = 0;
						}
						msterCounter.values_1[comj1] = mstrCounter.value_1;
						m_Value.Format(_T("%u"), msterCounter.values_1[comj1]);
						Show_info(m_Value);
						SetDlgItemText(IDC_ZHI_EDIT, m_Value);
						
					}
				}
				else if (bnm == 1)
				{
					bnm = 0;
					comj = 0;
					comj1++;
					mnu = 1;
					Value_nm = 0;
					msterCounter.values_1[comj1] = mstrCounter.value_1;
					if (comj1 == 9)
						comj1 = 0;
				}
			}
			
			break;
		case MASS_COUNTER_2:
			if (Value_2 >= 1 && mstrCounter.Value_g == 2)
			{
				//m_Value.Format(_T("%u"), Value_h);
				//Show_info(m_Value);
				//SetDlgItemText(IDC_EDIT1, m_Value);
				mstrCounter.Value_g = 0;
				if (bnm != 1)
				{
					Value_all++;
					if (Value_all <= 9)
					{
						for (i = 0;i <= 10;i++)
						{
							if (Value_2 == i)
							{
								mstrCounter.value_2 = msterCounter.values_he[i] * 10 + 2;
								m_Value.Format(_T("%u"), mstrCounter.value_2);
								Show_info(m_Value);
								SetDlgItemText(IDC_ZHI_EDIT, m_Value);
								msterCounter.values_2[comj1] = mstrCounter.value_2;
								msterCounter.values_he[2] = mstrCounter.value_2;
							}
						}
					}
					else
					{
						//Value_all = 0;
					}
					
				}
				else if (bnm == 1)
				{
					bnm = 0;
					comj = 0;
					comj1++;
					msterCounter.values_2[comj1] = mstrCounter.value_2;
					if (comj1 == 9)
						comj1 = 0;
				}
				Value_2 = 0;
			}
			else
			{
				if (bnm != 1)
				{
					comj++;
					Value_all = comj;
					if (comj1 <= 9)
					{
						if (mnu != 0)
						{
							mnu = 0;
							comj = comj + 1;
						}
						if (comj <= 9)
						{
							for (i = 1;i < comj;i++)
							{
								mstrCounter.value_2 = mstrCounter.value_2 * 10 + 2;
							}
							msterCounter.values_he[2] = mstrCounter.value_2;
						}
						else
						{
							comj = 0;
						}
						msterCounter.values_2[comj1] = mstrCounter.value_2;
						m_Value.Format(_T("%u"), msterCounter.values_2[comj1]);
						Show_info(m_Value);
						SetDlgItemText(IDC_ZHI_EDIT, m_Value);
					}
				}
				else if (bnm == 1)
				{
					bnm = 0;
					comj = 0;
					comj1++;
					mnu = 1;
					msterCounter.values_2[comj1] = mstrCounter.value_2;
					if (comj1 == 9)
						comj1 = 0;
				}
			}
			
			break;
		case MASS_COUNTER_DENG:
			if (bnm1 == 1)
			{
				bnm = 0;
				bnm1 = 0;
				mnu = 0;
				for (i = 0;i < comj1;i++)
				{
					if (i < 1)
					{
						mstrCounter.value_d = (msterCounter.values_1[i] + msterCounter.values_1[i + 1]);
					}
					else if(comj1 >= 2){
						mstrCounter.value_d = mstrCounter.value_d + msterCounter.values_1[i + 1];
					}
					m_Value.Format(_T("%u"), msterCounter.values_1[i]);
					SetDlgItemText(IDC_HEHE_EDIT, m_Value);
					m_Value.Format(_T("%u"), msterCounter.values_1[i+1]);
					SetDlgItemText(IDC_EDIT1, m_Value);
				}
				m_Value.Format(_T("%u"), mstrCounter.value_d);
				Show_info(m_Value);
				SetDlgItemText(IDC_ZHI_EDIT, m_Value);
				
				comj1 = 0;
				comj = 0;
			}
			break;
	}
	return 0;
}

void CCounterDlg::OnBnClicked1Button()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	//m_Value = 1;
	

	GetDlgItemText(IDC_1_BUTTON, cs);
	mstrCounter.value_1 = _ttoi(cs);
	mstrCounter.Value_g = mstrCounter.value_1;
	Value_2 = mstrCounter.value_1;
	//mstrCounter.Value_h = mstrCounter.value_1;
	//m_Value.Format(_T("%u"), mstrCounter.value_1);
	//mstrCounter.value_1 = bnm++;
	//m_Value.Format(_T("%u"), mstrCounter.value_1);
	//Show_info(m_Value);
	//GetDlgItem(IDC_1_BUTTON)->GetWindowText(m_Value);
	SetDlgItemText(IDC_ZHI_EDIT, m_Value);
	PostMessage(MESS_COUNTER, MASS_COUNTER_1, 0);
}
void CCounterDlg::Show_info(CString csInfo)
{
	m_List.AddString(csInfo);
	m_List.SetCurSel(m_List.GetCount() - 1);
}


void CCounterDlg::OnBnClicked2Button()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	//UINT bnm;
	GetDlgItemText(IDC_2_BUTTON, cs);
	mstrCounter.value_2 = _ttoi(cs);
	Value_h = mstrCounter.value_2;
	mstrCounter.Value_g = mstrCounter.value_2;
	cs.Format(_T("%u"), mstrCounter.value_2);
	Show_info(cs);
	SetDlgItemText(IDC_ZHI_EDIT, cs);
	PostMessage(MESS_COUNTER, MASS_COUNTER_2, 0);
}


void CCounterDlg::OnBnClickedJiaButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;

	GetDlgItemText(IDC_JIA_BUTTON, cs);
	//strcpy((char *)mstrCounter.symbol_jia, cs);
	Show_info(cs);
	SetDlgItemText(IDC_ZHI_EDIT, cs);
	PostMessage(MESS_COUNTER, MASS_COUNTER_JIA, 0);

}


void CCounterDlg::OnBnClickedDengButton()
{
	// TODO: 在此添加控件通知处理程序代码
	PostMessage(MESS_COUNTER, MASS_COUNTER_DENG, 0);
}
