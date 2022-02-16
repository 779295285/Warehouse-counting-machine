#ifndef CWIN_DELIVERY_H
#define CWIN_DELIVERY_H

#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cdata.h"
#include <list>
#include "Cwin_popup.h"
#include "CmanagerWin.h"
//出库界面窗口类
class cdeliveryWin:public cwin,public cdata
{
public:
	cdeliveryWin();
	//出库界面窗口构造
	cdeliveryWin(int x,int y,int width,int height);	
	//重写出库界面窗口操作动作
	int doAction();
	//出库界面窗口析构
	~cdeliveryWin();

};


//出库窗口类
class cdelivery:public cwin,public cdata
{
public:
	cdelivery();
	//出库窗口构造
	cdelivery(int x,int y,int width,int height);	
	//重写出库窗口操作动作
	int doAction();
	//重写出库窗口显示show
	void show();
	//出库窗口析构
	~cdelivery();

	static string str;

};

#endif