#include "Cwin_warehousing.h"

//入库界面窗口默认构造函数
cwarehousingWin::cwarehousingWin(){}

//入库界面窗口构造函数
cwarehousingWin::cwarehousingWin(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(40,7,10,2,"欢迎使用盘点机系统",LABEL));
	this->addCtrol(new cbutton(30,13,12,2,"  入库",BUTTON));
	this->addCtrol(new cbutton(60,13,12,2,"入库记录",BUTTON));
	this->addCtrol(new cbutton(30,17,12,2,"  返回",BUTTON));
}

//入库界面窗口操作动作
int cwarehousingWin::doAction()
{
	//当控件为入库时
	if(this->focusIndex==1)
	{
		return 8;
	}
	//当控件为返回时
	if(this->focusIndex==3)
	{
		return 1;
	}
	return -1;
}
cwarehousingWin::~cwarehousingWin(){}




//-------------------------------------------------------------------------------


//入库窗口默认构造函数
cwarehousing::cwarehousing(){}
string cwarehousing::str;
//入库窗口构造函数
cwarehousing::cwarehousing(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(20,17,10,2,"商品名称：",LABEL));
	this->addCtrol(new clabel(20,20,10,2,"商品类型：",LABEL));
	this->addCtrol(new clabel(20,23,10,2,"商品价格：",LABEL));
	this->addCtrol(new clabel(20,26,10,2,"商品数量：",LABEL));
	this->addCtrol(new clabel(20,29,10,2,"仓位编号：",LABEL));
	this->addCtrol(new clabel(40,7,10,2,"欢迎使用盘点机系统",LABEL));
	this->addCtrol(new clabel(18,12,10,2,"请输入商品编号：",LABEL));
	this->addCtrol(new clabel(64,17,10,2,"请输入入库数量[1-10000]",LABEL));
	this->addCtrol(new cedit(37,12,20,2,12,3,1,"",EDIT));
	this->addCtrol(new cbutton(68,12,8,2,"查询",BUTTON));
	this->addCtrol(new cedit(66,20,22,2,12,2,1,"",EDIT));
	this->addCtrol(new cbutton(66,24,8,2,"确定",BUTTON));
	this->addCtrol(new cbutton(80,24,8,2,"返回",BUTTON));
}

//重写入库show
void cwarehousing::show()
{
	//显示时间

	cwin::UserandTime();
		ctool::paintWindow(16,15,42,17);

		ctool::paintWindow(this->x, this->y,this->width,this->height);

		for(int i=0; i<this->ctrolCount; i++)
		{
			this->ctrolArry[i]->show();
		}
		memset (this->ctrolArry[8]->get_content(),0,strlen(this->ctrolArry[8]->get_content()));
		memset (this->ctrolArry[10]->get_content(),0,strlen(this->ctrolArry[10]->get_content()));

}
//入库窗口操作动作
int cwarehousing::doAction()
{

	//控件为查询时
	if(this->focusIndex==9)
	{
		//利用map迭代器来查询
		map<string,cgoods *>::iterator  it=goods_map.find(this->ctrolArry[8]->get_content());
		if(it != goods_map.end())
		{	

			//利用空格覆盖之前的内容
			ctool::gotoxy(30,17);
			cout<<"             ";
			ctool::gotoxy(30,20);				
			cout<<"             ";
			ctool::gotoxy(30,23);				
			cout<<"             ";
			ctool::gotoxy(30,26);				
			cout<<"             ";
			ctool::gotoxy(30,29);				
			cout<<"             ";
			
			//查询到就打印货物信息
			ctool::gotoxy(30,17);
			cout<<it->second->get_goods_name();
			ctool::gotoxy(30,20);				
			cout<<it->second->get_goods_type();
			ctool::gotoxy(30,23);				
			cout<<fixed<<setprecision(2)<<it->second->get_goods_price();
			ctool::gotoxy(30,26);				
			cout<<it->second->get_goods_mount();
			ctool::gotoxy(30,29);				
			cout<<it->second->get_goods_Position();
			
			str=this->ctrolArry[8]->get_content();
		}

		//当查询不到该信息就弹窗提示
		else
		{

			cmanwin::winArry[9]->show();
			cmanwin::winArry[9]->winRun();
			return cmanwin::winArry[9]->doAction();	
		}
		
		cwarehousing::winRun();
		return cwarehousing::doAction();
	}

	//当控件为确定时候
	if(this->focusIndex==11)
	{
		//如果没有输入查询的编号，编辑框数据为空时，便提示没有查询，无法入库
		if (strlen(this->ctrolArry[8]->get_content())==0)
		{
			ctool::gotoxy(66,27);
			cout<<"未查询商品，无法入库！";
			ctool::gotoxy(66,29);
			system("pause");
			return 8;
		}

		//利用map迭代器查询
		map<string,cgoods *>::iterator  it=goods_map.find(str);
		if(it != goods_map.end())
		{
			//如果输入的数量不在1-10000之间就提示
			if (atoi(this->ctrolArry[10]->get_content())>10000 || atoi(this->ctrolArry[10]->get_content())<1)
			{
				ctool::gotoxy(62,27);
				cout<<"入库库数量在[1-10000]之间！";
			
			}
			else
			{			
				//调用函数接口修改货物数量
				it->second->get_goods_mount_add(atoi(this->ctrolArry[10]->get_content()));
				
				ctool::gotoxy(30,26);				
				cout<<"             ";
				ctool::gotoxy(62,27);				
				cout<<"                          ";	
				ctool::gotoxy(30,26);
				cout<<it->second->get_goods_mount();
			}

			cwarehousing::winRun();
			return cwarehousing::doAction();	
		}
	}


	//控件为返回时候
	if(this->focusIndex==12)
	{
		return 7;
	}
	return -1;
}
cwarehousing::~cwarehousing(){}
