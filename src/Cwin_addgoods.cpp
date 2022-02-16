#include "Cwin_addgoods.h"

//添加商品窗口默认构造函数
caddgoods::caddgoods(){}

//添加商品窗口构造函数
caddgoods::caddgoods(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(42,7,10,2,"欢迎使用盘点机",LABEL));
	this->addCtrol(new cbutton(31,13,10,2,"商品编号：",LABEL));
	this->addCtrol(new clabel(31,16,10,2,"商品名称：",LABEL));
	this->addCtrol(new clabel(31,19,10,2,"商品类型：",LABEL));
	this->addCtrol(new clabel(31,22,10,2,"商品价格：",LABEL));
	this->addCtrol(new clabel(31,25,10,2,"仓位编号：",LABEL));
	this->addCtrol(new cedit(45,16,20,2,12,4,1,"",EDIT));
	this->addCtrol(new cedit(45,19,20,2,10,4,1,"",EDIT));
	this->addCtrol(new cedit(45,22,20,2,10,3,1,"",EDIT));
	this->addCtrol(new cbutton(36,30,10,2,"确定",BUTTON));
	this->addCtrol(new cbutton(56,30,10,2,"取消",BUTTON));
	
}


//重写添加商品show
void caddgoods::show()
{

	//显示时间
	cwin::UserandTime();
	 char newID[256]={0};
	 char newPosition[256]={0};

	 ctool::paintWindow(42,12,20,2);
	 ctool::paintWindow(42,24,20,2);
	 
	 sprintf(newID,"%s%d","G",cdata::goods_map.size()+1001);
	 sprintf(newPosition,"%s%d","A",cdata::goods_map.size()+1001);
	 ctool::gotoxy(44,13);
	 cout<<newID;
	 ctool::gotoxy(44,25);
	 cout<<newPosition;
	 ctool::paintWindow(this->x, this->y,this->width,this->height);

	 for(int i=0; i<this->ctrolCount; i++)
	 {
		 this->ctrolArry[i]->show();
	 }
}




//注册窗口操作动作
int caddgoods::doAction()
{
	char newID[20]={0};
	char newposition[256]={0};
	string goods_newID;
	string goods_name;//用户名
	string goods_type;//密码
	double goods_price;
	string goods_Position;//角色

	//控件为确定时
	if(this->focusIndex==9)
	{
		//判断编辑框是否为空。
		if((strlen(this->ctrolArry[6]->get_content())==0)||(strlen(this->ctrolArry[7]->get_content())==0)
		 ||(strlen(this->ctrolArry[8]->get_content())==0))
		{
			//清空编辑框数据。
			memset (this->ctrolArry[6]->get_content(),0,sizeof(this->ctrolArry[6]->get_content()));
			memset (this->ctrolArry[7]->get_content(),0,sizeof(this->ctrolArry[7]->get_content()));
			memset (this->ctrolArry[8]->get_content(),0,sizeof(this->ctrolArry[8]->get_content()));


			ctool::gotoxy(40,27);
			cout<<"内容不能为空！请重新填写。";
			system("pause");
			return 10;

		}
		else
		{
		
			//获取编辑框添加商品信息
			goods_name=this->ctrolArry[6]->get_content();
			goods_type=this->ctrolArry[7]->get_content();
			goods_price=atof(this->ctrolArry[8]->get_content());
			

			//将添加商品信息存入map
			sprintf(newID,"%s%d","G",cdata::goods_map.size()+1001);
			sprintf(newposition,"%s%d","A",cdata::goods_map.size()+1001);

			goods_newID=newID;
			goods_Position=newposition;
			////新商品存入商品map
			cdata::goods_map.insert(make_pair(goods_newID,(new cgoods(goods_newID,goods_name,goods_type, goods_price,1,goods_Position))));
			//新商品存入文件
			ofstream fs("data/goods.txt",ios_base::app);
			fs<<goods_newID<<" "<<goods_name<<" "<<goods_type<<" "<<1<<" "<<goods_Position<<endl;
			fs.close();


			//清空编辑框数据。
			memset (this->ctrolArry[6]->get_content(),0,sizeof(this->ctrolArry[6]->get_content()));
			memset (this->ctrolArry[7]->get_content(),0,sizeof(this->ctrolArry[7]->get_content()));
			memset (this->ctrolArry[8]->get_content(),0,sizeof(this->ctrolArry[8]->get_content()));

			ctool::gotoxy(40,27);
			cout<<"添加成功！继续添加";
			system("pause");
			return 10;
		}
	}
	//当控件为取消时
	if(this->focusIndex==10)
	{
		return 7;
	}
	return -1;
}

//注册窗口析构函数
caddgoods::~caddgoods(){}