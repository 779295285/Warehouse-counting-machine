#ifndef USER_ADMIN_H
#define USER_ADMIN_H

#include "Ctool.h"
#include "Cwin.h"


//管理员的类：
class cadmin:public cwin
{
public:
	cadmin();
	//管理员窗口构造
	cadmin(int x,int y,int width,int height);
	//管理员窗口操作动作
	int doAction();
	//管理员窗口析构
	~cadmin();
};

#endif