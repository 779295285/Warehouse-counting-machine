#include "Cwin_homepage.h"

//主页面窗口默认构造函数
chomepage::chomepage(){}



//主页面窗口构造函数
chomepage::chomepage(int x,int y,int width,int height)
:cwin(x,y,width,height)
{

	this->addCtrol(new clabel(42,7,10,2,"盘点机项目",LABEL));
	this->addCtrol(new clabel(60,28,10,2,"OMO2101吕梁林",LABEL));
	this->addCtrol(new cbutton(45,13,12,2," 登录",BUTTON));
	this->addCtrol(new cbutton(45,17,12,2," 注册",BUTTON));
	this->addCtrol(new cbutton(45,21,12,2," 关闭",BUTTON));
	
}

//主页面窗口操作动作
int chomepage::doAction()
{
	
	switch(this->focusIndex)
	{	
	//控件为登录时
	case 2:
		{
			return 0;
		}
	//控件为注册时
	case 3:
		{

			return 4;
		}
	//控件为取消时
	case 4:
		{
			return 5;
		}
		
	}

	return 0;	
}

//主页面窗口析构函数
chomepage::~chomepage(){}