#include "Ctrol_button.h"
//按钮默认构造函数
cbutton::cbutton(){}

//按钮构造函数
cbutton::cbutton(int x,int y,int width,int height,char *pcontent,int type)
:ctrol(x,y,width,height,pcontent,type)
{

}

//按钮析构函数
cbutton::~cbutton(){}