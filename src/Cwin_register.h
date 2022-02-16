#ifndef CWIN_REGISTER_H
#define CWIN_REGISTER_H

#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cuser.h"
#include "Cdata.h"
#include <list>


//注册窗口类
class Cregister:public cwin,public cdata
{
public:
	Cregister();
	//注册窗口构造
	Cregister(int x,int y,int width,int height);	
	//重写注册窗口展示
	void show();
	//注册窗口操作动作
	int doAction();
	//注册窗口析构
	~Cregister();

};


#endif