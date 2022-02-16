#include "CmanagerWin.h"

//用vector存窗口
vector<cwin *> cmanwin::winArry;

//将窗口存入
cmanwin::cmanwin()
{
	this->addWin(new clogin(10,5,80,29));//登录0

	this->addWin(new cadmin(10,5,80,29));//管理员1
	this->addWin(new checkers(10,5,80,29));//盘点员2

	this->addWin(new chomepage(10,5,80,29));//主界面3
	this->addWin(new Cregister(10,5,80,29));//注册4
	this->addWin(new out(10,5,80,25));//退出5

	this->addWin(new cquery(10,5,80,29));//查询6
	
	this->addWin(new cwarehousingWin(10,5,80,29));//入库主界面7
	this->addWin(new cwarehousing(10,5,80,29));//入库8

	this->addWin(new cpopup(35,14,30,15));//出入库弹窗9
	this->addWin(new caddgoods(10,5,80,29));//商品添加10

	this->addWin(new cdeliveryWin(10,5,80,29));//出库主界面11
	this->addWin(new cdelivery(10,5,80,29));//出库12

	this->addWin(new ccheckWin(10,5,80,29));//盘点主界面13
	this->addWin(new ccheck(10,5,80,29));//盘点14
	this->addWin(new ccheck_form(10,5,80,29));//盘点表15

	this->addWin(new ccheck_record(10,5,80,29));//盘点记录16
	this->addWin(new ccheck_correct(10,5,120,29));//盘点冲正17
	this->addWin(new cpopup3(35,14,40,17));//盘点冲正弹窗18

	this->addWin(new ccheck_details(10,5,120,29));//盘点详情19
	
}


//保存窗口的函数
void cmanwin::addWin(cwin * win)
{
	this->winArry.push_back(win);
}

cmanwin::~cmanwin(){}