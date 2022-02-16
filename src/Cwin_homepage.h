#ifndef CWIN_HOMEPAGE_H
#define CWIN_HOMEPAGE_H
#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include <windows.h>


#include "Ctool.h"
#include "Cwin.h"
#include "Cwin_login.h"
#include "Cwin_register.h"
#include <vector>


//主界面类
class chomepage:public cwin
{
public:
	chomepage();
	//主界面窗口构造
	chomepage(int x,int y,int width,int height);
	//主界面窗口操作动作
	int doAction();
	//主界面窗口析构
	~chomepage();

};


#endif