#ifndef CWIN_WAREHOUSING_H
#define CWIN_WAREHOUSING_H

#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cdata.h"
#include <list>
#include "Cwin_popup.h"
#include "CmanagerWin.h"
//入库界面窗口类
class cwarehousingWin:public cwin,public cdata
{
public:
	cwarehousingWin();
	//入库界面窗口构造
	cwarehousingWin(int x,int y,int width,int height);	
	//入库界面窗口操作动作
	int doAction();
	//入库界面窗口析构
	~cwarehousingWin();

};


//入库窗口类
class cwarehousing:public cwin,public cdata
{
public:
	cwarehousing();
	//入库窗口构造
	cwarehousing(int x,int y,int width,int height);	
	//入库窗口操作动作
	int doAction();

	void show();
	//入库窗口析构
	~cwarehousing();

	static string str;

};

#endif