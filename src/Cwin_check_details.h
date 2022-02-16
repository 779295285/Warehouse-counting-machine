#ifndef CWIN_CHECK_DETAILS_H
#define CWIN_CHECK_DETAILS_H

#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cdata.h"
#include <list>
#include "Cwin_popup.h"
#include "CmanagerWin.h"
//--------------------------盘点冲正界面-------------------------------
//盘点冲正窗口类
class ccheck_details:public cwin,public cdata
{
public:
	ccheck_details();
	//盘点冲正窗口构造
	ccheck_details(int x,int y,int width,int height);
	
	void goods_show(int direction);
	
	//重写盘点冲正show
	void show();
	void winRun();
	
	//盘点冲正窗口操作动作
	int doAction();
	//盘点冲正窗口析构
	~ccheck_details();
	static int direction;
};
#endif