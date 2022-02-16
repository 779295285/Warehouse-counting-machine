#ifndef CWIN_CHECK_H
#define CWIN_CHECK_H

#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cdata.h"
#include <list>
#include "Cwin_popup.h"
#include "CmanagerWin.h"
//--------------------------盘点主界面-------------------------------
//盘点界面窗口类
class ccheckWin:public cwin,public cdata
{
public:
	ccheckWin();
	//盘点界面窗口构造
	ccheckWin(int x,int y,int width,int height);	
	//盘点界面窗口操作动作
	int doAction();
	//盘点界面窗口析构
	~ccheckWin();
};

//--------------------------盘点页面-------------------------------
//盘点窗口类
class ccheck:public cwin,public cdata
{
public:
	ccheck();
	//盘点窗口构造
	ccheck(int x,int y,int width,int height);
	//重写盘点show
	void show();
	//盘点窗口操作动作
	int doAction();
	//盘点窗口析构
	~ccheck();

	static string str;
	static int ccheck_num;
	static string ccheck_str;
};

//--------------------------盘点表-------------------------------

class ccheck_form:public cwin,public cdata
{
public:
	ccheck_form();
	//盘点窗口构造
	ccheck_form(int x,int y,int width,int height);
	//重写盘点表窗口运行函数
	void winRun();
	//显示盘点商品内容函数
	void goods_show(int direction);
	//盘点窗口操作动作
	int doAction();
	//重写盘点窗口show
	void show();
	//盘点窗口析构
	~ccheck_form();
};
#endif