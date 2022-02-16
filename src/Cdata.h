#ifndef CDATA_H
#define CDATA_H

#pragma warning (disable: 4786)
#include <iostream>

#include <fstream>
using namespace std;
#include "Cuser.h"
#include "Cgoods.h"
#include <list>
#include <map>
#include <vector>

//数据类
class cdata
{
public:
    cdata();
	//将货物信息初始化
    static void goods_Initialization();
	//将员工信息写入文件
	static void userToFile();
	//将货物信息写入文件
	static void goodsToFile();
	//将员工信息写入list
	static void userToList();

	void userToFile(cuser *newuser);
	//静态用户list
	static list<cuser *> user_list;
	//静态用户map
	static map<int,cuser *> user_map;
	//静态商品map
	static map<string ,cgoods *> goods_map;
	//静态查询商品map
	static map<string,cgoods *> goods_map2;
	//静态盘点商品map
	static map<string,cgoods *> goods_map3;
	//静态冲正商品map
	static map<string,cgoods *> goods_map4;
	//静态商品状态map
	static map<string,string>check_state;

	static map<string,map<string,cgoods *> >multiMap;




	~cdata();
	
};
#endif
