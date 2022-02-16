#ifndef CTROL_BUTTON_H
#define CTROL_BUTTON_H

#include <iostream>
using namespace std;

#include "ctrol.h"


//∞¥≈•¿‡
class cbutton:public ctrol
{
public:
    cbutton();
	cbutton(int x,int y,int width,int height,char *pcontent,int type);
	~cbutton();
	
};
#endif