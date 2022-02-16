#ifndef CTOOL_H
#define CTOOL_H

#include <windows.h>
#include <stdio.h>
#include<conio.h>

#define DOWN 80
#define UP 72

#define LEFT 75 
#define RIGHT 77
#define ENTER 13
#define ESC 27
#define BACK 8


class ctool
{
public:

	//默认构造函数
	ctool();
     //光标定位函数，起始位置为x和y轴
	static void gotoxy(int x,int y);

	//画框函数，起始位置x和y轴，width和height代表框的宽度和高度
	static void paintWindow(int X,int Y,int width,int height);

	//获取键盘按键
	static int getKey();


};
#endif