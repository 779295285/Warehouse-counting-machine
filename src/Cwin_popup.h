#ifndef CWIN_POPUP_H
#define CWIN_POPUP_H

#include <iostream>
#pragma warning (disable: 4786)
#include <map>
using namespace std;

#include "Ctool.h"
#include "Cwin.h"
#include "Cdata.h"
#include "Cgoods.h"
#include "Cwin_check_record.h"

//弹窗窗口类
class cpopup:public cwin
{
public:
	cpopup();
	//弹窗窗口构造
	cpopup(int x,int y,int width,int height);
	//弹窗窗口操作动作
	int doAction();
	void show();
	//弹窗窗口析构
	~cpopup();

};


//弹窗窗口类
class cpopup2:public cwin
{
public:
	cpopup2();
	//弹窗窗口构造
	cpopup2(int x,int y,int width,int height);
	//弹窗窗口操作动作
	int doAction();
	void show();
	//弹窗窗口析构
	~cpopup2();

};

//弹窗窗口类
class cpopup3:public cwin,public cdata
{
public:
	cpopup3();
	//弹窗窗口构造
	cpopup3(int x,int y,int width,int height);
	//弹窗窗口操作动作
	int doAction();
	void show();
	//弹窗窗口析构
	~cpopup3();

};



#endif