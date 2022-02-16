#ifndef CWIN_QUERY_H
#define CWIN_QUERY_H

#include "Ctool_form.h"
#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cuser.h"
#include "Cdata.h"
#include <list>
#include<windows.h>
#include <algorithm>
#include <iomanip>

//查询窗口类
class cquery:public cwin,public cdata
{
public:
	cquery();
	//查询窗口构造
	cquery(int x,int y,int width,int height);
	//重写查询窗口展示
	void show();

	//重写窗口运行函数
	void winRun();
	//查询窗口操作动作
	int doAction();

	void goods_show(int direction);


	//查询窗口析构
	~cquery();

};


#endif