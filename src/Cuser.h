#ifndef CUSER_H
#define CUSER_H

#include <iostream>
using namespace std;

#include <string.h>
#include <stdio.h>
#include "Ctool.h"


#define ADMIN 1
#define CHECKERS 2


//员工基类
class cuser
{
public:

	cuser();
	cuser(int ID,char name[10],char pwd[10],int role);
	~cuser();

	//类的接口
	int get_ID(){return ID;};
	char *get_name(){return name;};
	char *get_pwd(){return pwd;};
	int get_role(){return role;};

protected:
	int ID;
	char name[10];//用户名
	char pwd[10];//密码
	int role ;//角色

};
#endif