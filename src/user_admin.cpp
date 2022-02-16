#include "user_admin.h"

//管理员窗口默认构造函数
cadmin::cadmin(){}

//管理员窗口构造函数
cadmin::cadmin(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	
	this->addCtrol(new clabel(40,7,10,2,"欢迎使用盘点机系统",LABEL));
	this->addCtrol(new cbutton(30,13,12,2,"商品查询",BUTTON));
	this->addCtrol(new cbutton(60,13,12,2,"导入商品",BUTTON));
	this->addCtrol(new cbutton(30,17,12,2,"商品入库",BUTTON));
	this->addCtrol(new cbutton(60,17,12,2,"商品出库",BUTTON));
	this->addCtrol(new cbutton(30,21,12,2,"盘点冲正",BUTTON));
	this->addCtrol(new cbutton(60,21,12,2,"退出程序",BUTTON));
}

//管理员窗口操作动作
int cadmin::doAction()
{
	//控件为商品查询
	if(this->focusIndex==1)
	{
		return 6;
	}
	
	//控件为商品入库
	if(this->focusIndex==3)
	{
		return 7;
	}
	//控件为商品出库
	if(this->focusIndex==4)
	{
		
			
		return 11;
	}
	if(this->focusIndex==5)
	{
		
			
		return 16;
	}
	//控件为退出程序
	if(this->focusIndex==6)
	{
		
		cwin::role=0;	
		return 3;
	}

	return -1;
}

//管理员窗口析构函数
cadmin::~cadmin(){}