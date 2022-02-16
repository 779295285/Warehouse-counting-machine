#ifndef CWIN_H
#define CWIN_H

#include <iostream>
using namespace std;
#pragma warning (disable: 4786)
#include "Ctrol_label.h"
#include "Ctrol_button.h"
#include "Ctrol_edit.h"
#include "Ctool.h"
#include "Cuser.h"

#include<ctime>
#include<windows.h>



//窗口基类
class cwin
{
public:
	cwin();
	cwin(int x,int y,int width,int height);
	//添加控件
	void addCtrol(ctrol *ctrolArry);

	//显示
	virtual void show();
	//窗口运行
	virtual void winRun();
	//显示用户和时间
	void UserandTime();
	//窗口操作动作虚函数
	virtual int doAction(){return 0;};
	~cwin();

	static char name[10];
	static int  role;
	 
protected:
	int x;
	int y;
	int width;
	int height;
	int focusIndex;
	int ctrolCount;//控件个数
	int userCount;//控件个数
	
	ctrol *ctrolArry[20];//控件类型指针数组



};


#endif