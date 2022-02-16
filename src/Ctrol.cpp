#include "Ctrol.h"

//控件默认构造函数
ctrol::ctrol(){}


//控件构造函数
ctrol::ctrol(int x,int y,int width,int height,char *pcontent,int type)
{
	this->x=x;
	this->y=y;
	this->width=width;
	this->height=height;
	this->type=type;

	if(pcontent!=NULL)
	{
		//content需要初始化
		memset (this->content,0,sizeof(this->content));
		//content内容赋值
		strcpy(this->content,pcontent);
	}
}



//控件展示函数
void ctrol::show()
{
	switch(type)
	{
	//标签打印
	case LABEL:		
		ctool::gotoxy(x,y);
		cout<<this->content<<endl;
		break;
    //编辑框打印
	case EDIT:
		ctool::paintWindow(x-3, y-1,width, height);
		break;
	//按钮打印
	case BUTTON:
		ctool::paintWindow(x-3, y-1,width, height);
		ctool::gotoxy(x,y);
		cout<<this->content<<endl;
		break;
	}
}
//析构函数
ctrol::~ctrol(){}
