#include "Ctrol_label.h"
//标签默认构造函数
clabel::clabel(){}


//标签构造函数
clabel::clabel(int x,int y,int width,int height,char *pcontent,int type)
:ctrol(x,y,width,height,pcontent,type)
{
    
}

//标签析构函数
clabel::~clabel(){}
