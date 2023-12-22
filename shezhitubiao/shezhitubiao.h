
// shezhitubiao.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CshezhitubiaoApp: 
// 有关此类的实现，请参阅 shezhitubiao.cpp
//

#define MESS_COUNTER WM_USER+106
#define MESS_COM_HANDLE WM_USER+105

#define RECEIVEBUFF_SIZE 1024

class CshezhitubiaoApp : public CWinApp
{
public:
	CshezhitubiaoApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CshezhitubiaoApp theApp;

enum {
	START_PROCEDURE,//启动程序->开始工作
	START_RECEIV_DATA,
	TEST_CUTFACILITY,
	SEND_SERIAL_DATA,
	TEXT_CLEAR,
	STATE_EXIT,
};
enum {
	RECEIVE_TIME,//接收数据的延时

};

typedef struct {
	unsigned int value_1;
	unsigned int value_2;
	unsigned int value_3;
	unsigned int value_4;
	unsigned int value_5;
	unsigned int value_6;
	unsigned int value_7;
	unsigned int value_8;
	unsigned int value_9;
	unsigned int value_0;
	unsigned int value_d;
	unsigned int Value_h;
	unsigned int Value_g;
	unsigned char symbol_jia[2];
	unsigned char symbol_jian[2];
	unsigned char symbol_cheng[2];
	unsigned char symbol_chu[2];
}StrCounter;
typedef struct {
	unsigned int values_1[9];
	unsigned int values_2[9];
	unsigned int values_3[9];
	unsigned int values_4[9];
	unsigned int values_5[9];
	unsigned int values_6[9];
	unsigned int values_7[9];
	unsigned int values_8[9];
	unsigned int values_9[9];
	unsigned int values_0[9];
	unsigned int values_he[10];
}StrCounters;