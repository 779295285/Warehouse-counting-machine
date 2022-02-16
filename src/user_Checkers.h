#ifndef USER_CHECKERS_H
#define USER_CHECKERS_H

#include "Ctool.h"
#include "Cwin.h"


//盘点员的类：
class checkers:public cwin
{
public:
	checkers();
	//盘点员窗口构造
	checkers(int x,int y,int width,int height);
	//盘点员窗口操作动作
	int doAction();
	//盘点员窗口析构
	~checkers();

};



#endif