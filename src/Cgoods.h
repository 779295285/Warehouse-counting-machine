#ifndef CGOODS_H
#define CGOODS_H

#include <iostream>
using namespace std;

#include <string>
#include <stdio.h>
#include "Ctool.h"



//商品类
class cgoods
{
public:

	cgoods();
	cgoods(string goods_ID,string goods_name,string goods_type,double goods_price,int goods_mount,string goods_Position);
	cgoods(string goods_ID,string goods_name,string goods_type,double goods_price,int goods_mount,string goods_Position,int check_mount);
	~cgoods();

	//获取商品ID
	string get_goods_ID(){return goods_ID;};
	//获取商品名字
	string get_goods_name(){return goods_name;};
	//获取商品种类
	string get_goods_type(){return goods_type;};
	//获取商品仓位编号
	string get_goods_Position(){return goods_Position;};
	//获取冲正说明
	string get_explain(){return goods_explain;};
	//获取商品价格
	float get_goods_price(){return goods_price;};
	//获取商品数量
	int get_goods_mount(){return goods_mount;};
	//获取盘点数量
	int get_check_mount(){return check_mount;};
	//获取冲正数量
	int get_rectification(){return rectification;};
	//获取差异数量
	int get_difference_mount(){return check_mount>=goods_mount?check_mount-goods_mount:goods_mount-check_mount;};
	//添加商品数量
	void get_goods_mount_add(int i){this->goods_mount=this->goods_mount+i;};
	//减少商品数量
	void get_goods_mount_sub(int i){this->goods_mount=this->goods_mount-i;};
	//修改盘点数量
	void get_check_mount(int i){this->check_mount=this->check_mount+i;};
	//修改冲正数量
	void get_rectification(int i){this->rectification=i;};
	//修改冲正说明
	void get_explain(string str){this->goods_explain=str;};
	//修改库存数量
	void get_modify(){this->check_mount>=this->goods_mount?this->goods_mount=this->goods_mount+this->rectification:this->goods_mount=this->goods_mount-this->rectification;};



protected:
	string goods_ID;//商品编号
	string goods_name;//商品名称
	string goods_type;//商品类型
	string goods_Position;
	string goods_explain;
	float goods_price;
	int goods_mount;
	int check_mount;
	int rectification;
	


};
#endif