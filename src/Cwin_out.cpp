#include "Cwin_out.h"

//主页面窗口默认构造函数
out::out(){}

//主页面窗口构造函数
out::out(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(45,7,10,2,"确认关闭？",LABEL));
	this->addCtrol(new cbutton(45,13,12,2,"确认",BUTTON));
	this->addCtrol(new cbutton(45,17,12,2,"返回",BUTTON));
}

//主页面窗口操作动作
int out::doAction()
{
	switch(this->focusIndex)
	{	
	//控件为确定时
	case 1:
		{

			return -1;
		}
	//控件为返回时
	case 2:
		{

			return 3;
		}
	}

	return -1;	
}

//主页面窗口析构函数
out::~out(){}