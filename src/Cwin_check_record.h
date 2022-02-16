#ifndef CWIN_CHECK_RECORD_H
#define CWIN_CHECK_RECORD_H

#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cdata.h"
#include <list>
#include "Cwin_popup.h"
#include "CmanagerWin.h"
//--------------------------盘点记录界面-------------------------------
//盘点记录窗口类
class ccheck_record:public cwin,public cdata
{
public:
	ccheck_record();
	//盘点记录窗口构造
	ccheck_record(int x,int y,int width,int height);	
	void goods_show(int direction);
	//重写盘点记录show
	void show();
	void winRun();
	//盘点记录窗口操作动作
	int doAction();
	//盘点记录窗口析构
	~ccheck_record();
	static int direction;
	static string ccheck_str;
};
#endif