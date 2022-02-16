#ifndef CTROL_EDIT_H
#define CTROL_EDIT_H

#include <iostream>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "Ctrol.h"

//编辑框类
class cedit:public ctrol
{
public:
    cedit();

	cedit(int x,int y,int width,int height,int maxLen,int iputType,int ips,char *pcontent,int type);
	void editKeyListen(int key);

	~cedit();
	
private:
	
	int maxLen;//允许输入最大长度
	
	int iputType;//允许输入数据类型: 1-数字，2-字母，3-数字字母
	
	int ips;//显示格式: 明文1，密文0
	
	int key;//键盘按键


};

#endif