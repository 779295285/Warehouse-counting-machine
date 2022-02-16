#include "Cuser.h"

//用户默认构造函数
cuser::cuser(){}

//用户构造函数
cuser::cuser(int ID,char name[10],char pwd[10],int role)
{
	this->ID=ID;
	strcpy(this->name,name);
	strcpy(this->pwd,pwd);
	this->role=role;
}

//用户析构函数
cuser::~cuser(){}