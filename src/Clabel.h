#ifndef CLABEL_H
#define CLABEL_H

#include <iostream>
using namespace std;

#include "Ctrol.h"

//标签类
class clabel:public ctrol
{
public:
	//默认构造函数
    clabel();
	//带参数构造函数
	clabel(int x,int y,int width,int height,char *pcontent,int type);
	~clabel();

};

#endif