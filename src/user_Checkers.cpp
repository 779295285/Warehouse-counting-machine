#include "user_Checkers.h"

//盘点员窗口默认构造函数
checkers::checkers(){}	

//盘点员窗口构造函数
checkers::checkers(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(40,7,10,2,"欢迎使用盘点机系统",LABEL));
	this->addCtrol(new cbutton(30,13,12,2,"商品查询",BUTTON));
	this->addCtrol(new cbutton(60,13,12,2,"仓库盘点",BUTTON));
	this->addCtrol(new cbutton(30,17,12,2,"退出程序",BUTTON));
}


int checkers::doAction()
{
	//控件为商品查询
	if(this->focusIndex==1)
	{
		return 6;
	}
	//控件为仓库盘点
	if(this->focusIndex==2)
	{
		return 13;
	}
	
	//控件为退出程序
	if(this->focusIndex==3)
	{
		cwin::role=0;
		return 3;
	}
	
	return -1;
}


//盘点员窗口析构函数
checkers::~checkers(){}





