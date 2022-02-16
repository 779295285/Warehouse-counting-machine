#ifndef CTOOL_FORM_H
#define CTOOL_FORM_H

#include "Ctool.h"

#include <iostream>
using namespace std;
#include "Ctrol.h"
#include <vector>
#include <string>

class cform
{
public:

	//默认构造函数
	cform();

	static void show_form(int X,int Y,int width,int height,int row,int col,vector<string> label);
     //画表格
	static void paint_form(int X,int Y,int width,int height,int row,int col);

protected:

	char *form_label[20];//控件类型指针数组
	int labelCount;//控件个数
};
#endif