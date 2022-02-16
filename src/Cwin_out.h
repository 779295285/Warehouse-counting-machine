#ifndef CWIN_OUT_H
#define CWIN_OUT_H

#include <iostream>
using namespace std;
#pragma warning (disable: 4786)
#include <windows.h>

#include "Ctool.h"
#include "Cwin.h"

#include <vector>


//退出窗口类
class out:public cwin
{
public:
	out();
	//退出窗口构造
	out(int x,int y,int width,int height);
	//退出窗口操作动作
	int doAction();
	//退出窗口析构
	~out();

};


#endif