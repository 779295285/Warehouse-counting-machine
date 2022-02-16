#include "Cwin_check.h"
//----------------------盘点主页面----------------------------
//盘点界面窗口默认构造函数
ccheckWin::ccheckWin(){}

//盘点界面窗口构造函数
ccheckWin::ccheckWin(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(40,7,10,2,"欢迎使用盘点机系统",LABEL));
	this->addCtrol(new cbutton(30,13,12,2,"新建盘点",BUTTON));
	this->addCtrol(new cbutton(60,13,12,2,"盘点记录",BUTTON));
	this->addCtrol(new cbutton(30,17,12,2,"  返回",BUTTON));
}

//盘点界面窗口操作动作
int ccheckWin::doAction()
{
	//控件为新建盘点时
	if(this->focusIndex==1)
	{
		return 14;
	}
	//当控件为盘点记录时
	if(this->focusIndex==2)
	{
		return 16;
	}
	//控件为返回时
	if(this->focusIndex==3)
	{
		return 2;
	}
	return -1;
}
ccheckWin::~ccheckWin(){}





//--------------------------盘点页面-------------------------------



//盘点窗口默认构造函数
ccheck::ccheck(){}
string ccheck::str;
int ccheck::ccheck_num=1;
string ccheck::ccheck_str;
//盘点窗口构造函数
ccheck::ccheck(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	
	this->addCtrol(new clabel(18,12,10,2,"盘点编号：",LABEL));
	this->addCtrol(new clabel(20,20,10,2,"商品名称：",LABEL));
	this->addCtrol(new clabel(20,23,10,2,"商品类型：",LABEL));
	this->addCtrol(new clabel(20,26,10,2,"商品价格：",LABEL));
	this->addCtrol(new clabel(20,29,10,2,"仓位编号：",LABEL));
	this->addCtrol(new clabel(40,7,10,2,"欢迎使用盘点机系统",LABEL));
	this->addCtrol(new clabel(18,15,10,2,"请输出商品编号：",LABEL));
	this->addCtrol(new clabel(64,19,10,2,"请输入盘点数量[1-10000]",LABEL));
	this->addCtrol(new cedit(37,15,20,2,12,3,1,"",EDIT));
	this->addCtrol(new cbutton(68,15,8,2,"查询",BUTTON));
	this->addCtrol(new cedit(66,22,22,2,12,2,1,"",EDIT));
	this->addCtrol(new cbutton(66,26,8,2,"确定",BUTTON));
	this->addCtrol(new cbutton(80,26,8,2,"返回",BUTTON));
	this->addCtrol(new cbutton(66,30,22,2,"    生成盘点表",BUTTON));

}

//重写盘点show
void ccheck::show()
{
	char num[20]={0};
	//显示时间
	cwin::UserandTime();
	ctool::paintWindow(16,18,42,14);

	//命名编号
	time_t now = time(0); 
	tm *ltm = localtime(&now);
	sprintf(num,"%d%02d%d-%03d",1900+ltm->tm_year,1+ltm->tm_mon,ltm->tm_mday,ccheck_num);
	ccheck_str=num;
	//打印编号
	ctool::gotoxy(28,12);
	cout<<num;
	//打印边框和控件
	ctool::paintWindow(this->x, this->y,this->width,this->height);
	for(int i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}
	//清空两个编辑框内容，以便再次查询
	memset (this->ctrolArry[8]->get_content(),0,strlen(this->ctrolArry[8]->get_content()));
	memset (this->ctrolArry[10]->get_content(),0,strlen(this->ctrolArry[10]->get_content()));

}




//盘点窗口操作动作
int ccheck::doAction()
{
	
	if(this->focusIndex==9)
	{
		//利用map迭代器来查询
		map<string,cgoods *>::iterator  it=goods_map.find(this->ctrolArry[8]->get_content());
		if(it != goods_map.end())
		{	
			//利用空格覆盖之前的内容
			ctool::gotoxy(30,20);				
			cout<<"             ";
			ctool::gotoxy(30,23);				
			cout<<"             ";
			ctool::gotoxy(30,26);				
			cout<<"             ";
			ctool::gotoxy(30,29);				
			cout<<"             ";
			
			//查询到就打印货物信息
			ctool::gotoxy(30,20);				
			cout<<it->second->get_goods_name();
			ctool::gotoxy(30,23);				
			cout<<fixed<<setprecision(2)<<it->second->get_goods_type();
			ctool::gotoxy(30,26);				
			cout<<it->second->get_goods_price();
			ctool::gotoxy(30,29);				
			cout<<it->second->get_goods_Position();
			//获取当前的商品编号，便于存入数据
			str=this->ctrolArry[8]->get_content();
			//继续操作
			ccheck::winRun();
			return ccheck::doAction();
		}

		//当查询不到该信息就弹窗提示
		else
		{
			MessageBox(NULL,"未查询到，请重新输入","提示",0);
			return 14;			
		}
	
	}
	if(this->focusIndex==11)
	{
		//如果没有输入查询的编号，编辑框数据为空时，便提示没有查询，无法入库
		if (strlen(this->ctrolArry[8]->get_content())==0)
		{
			
			ctool::gotoxy(66,27);
			cout<<"未查询商品，无法盘点！";
			ctool::gotoxy(66,29);
			system("pause");
			return 14;
		}


		//如果输入的数量不在1-10000之间就提示
		if (atoi(this->ctrolArry[10]->get_content())>10000 || atoi(this->ctrolArry[10]->get_content())<1)
		{
			MessageBox(NULL,"出库库数量在[1-10000]之间！","提示",0);

		}
		else
		{
			//利用map迭代器存入要盘点的内容
			map<string,cgoods *>::iterator  it=goods_map.find(str);
			if(it != goods_map.end())
			{
				it->second->get_check_mount(atoi(this->ctrolArry[10]->get_content()));
		
				cdata::goods_map3[str]=new cgoods(it->second->get_goods_ID(),it->second->get_goods_name(),it->second->get_goods_type(),
						                                       it->second->get_goods_price(),it->second->get_goods_mount(),
															   it->second->get_goods_Position(),it->second->get_check_mount());
				
			}				
		}
		//继续操作
		ccheck::winRun();
		return ccheck::doAction();
	}
	

	if(this->focusIndex==12)
	{
		goods_map3.clear();	
		return 13;
	}
	if(this->focusIndex==13)
	{
		
		
		cdata::check_state[ccheck_str]="进行中";

		
		return 15;
	}
	return -1;
}
ccheck::~ccheck(){}


//--------------------------盘点表页面-------------------------------
//盘点表窗口默认构造函数
ccheck_form::ccheck_form(){}

//盘点表窗口构造函数
ccheck_form::ccheck_form(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	
	
	this->addCtrol(new clabel(40,7,10,2,"欢迎使用盘点机系统",LABEL));
	this->addCtrol(new clabel(60,12,10,2,"盘点状态：",LABEL));
	this->addCtrol(new clabel(18,12,10,2,"盘点编号：",LABEL));
	this->addCtrol(new cbutton(20,26,12,2,"结束盘点",BUTTON));
	this->addCtrol(new cbutton(40,26,8,2,"返回",BUTTON));
}



//重写盘点show
void ccheck_form::show()
{
	int direction=1;
	char num[20]={0};
	//显示时间
	cwin::UserandTime();
	vector<string>label;
	label.push_back("  商品编号");
	label.push_back("  商品名称");
	label.push_back("  库存数量");
	label.push_back("  盘点数量");
	label.push_back("  差异数量");
	cform::show_form(14,15,70,8,5,4,label);

	//打印提示
	ctool::gotoxy(60,32);
	cout<<"按← →翻页，按↑↓选择数据";
	//打印盘点编号
	ctool::gotoxy(28,12);
	cout<<ccheck::ccheck_str;
	//打印页数
	ctool::gotoxy(48,24);
	cout<<"1"<<"/"<<goods_map3.size()/3+1<<"   ";
	//打印盘点状态
	ctool::gotoxy(70,12);
	cout<<check_state[ccheck::ccheck_str];

	//打印边框和控件
	ctool::paintWindow(this->x, this->y,this->width,this->height);
	for(int i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}


	ccheck_form::goods_show(direction);
	
}



//重写盘点表窗口运行函数
void ccheck_form::winRun()
{	
	int i=0;
	int j=1;
	int x=0;
	int key;
	int direction=1;
	//光标定位
	for(i=0; i<this->ctrolCount;i++)
	{
		if(this->ctrolArry[i]->get_type() == EDIT)//编辑框
		{
			ctool::gotoxy (this->ctrolArry[i]->get_x()-1  ,this->ctrolArry[i]->get_y());
			break;
		}
		else if(this->ctrolArry[i]->get_type() == BUTTON)//按钮
		{
			ctool::gotoxy(this->ctrolArry[i]->get_x() , this->ctrolArry[i]->get_y());
			break;
		}
	}
	while(1)
	{
		map <int,cgoods *>::iterator it;
		
		//获取键盘值
		key=ctool::getKey();
		
	   switch(key)
	   {
		   case DOWN:
			   i++;
			   if(i==this->ctrolCount)
			   {
				   i=0;
			   }
			   for(;i<this->ctrolCount;i++)
			   {
				   if(this->ctrolArry[i]->get_type() == EDIT)//编辑框
				   {
				   
					   ctool::gotoxy (this->ctrolArry[i]->get_x()-1+strlen(this->ctrolArry[i]->get_content()) ,this->ctrolArry[i]->get_y());
					   break;
				   }
				   else if(this->ctrolArry[i]->get_type() == BUTTON)//按钮
				   {
					   ctool::gotoxy(this->ctrolArry[i]->get_x()-1 , this->ctrolArry[i]->get_y());
					   break;
				   }
			   }
			   break;
		   case UP:
			   i--;
			   if(i==-1)
			   {
				   i=this->ctrolCount-1;
			   }
			   while(this->ctrolArry[i]->get_type()==LABEL) //遇到标签
			   {
					i--;
					if(i<0)  //返回最后一个控件
					{
						i=this->ctrolCount-1;
					}
			   }
			   
			   for(;i>0;i--)
			   {
				   if(this->ctrolArry[i]->get_type() == EDIT)//编辑框
				   {
					   ctool::gotoxy (this->ctrolArry[i]->get_x()-1+strlen(this->ctrolArry[i]->get_content()),this->ctrolArry[i]->get_y());
					   break;
				   }
				   else if(this->ctrolArry[i]->get_type() == BUTTON)//按钮
				   {
					   ctool::gotoxy(this->ctrolArry[i]->get_x()-1 , this->ctrolArry[i]->get_y());
					   break;
				   }
			   }
			   
			   break;
		   case ENTER:
			   if(this->ctrolArry[i]->get_type() == BUTTON)//按钮
			   {
				   this->focusIndex=i;
				   
				   return;
			   }
			   
			   if(this->ctrolArry[i]->get_type() == EDIT)//编辑框
			   {
				   
				  ctool::gotoxy (this->ctrolArry[i+1]->get_x()-1 , this->ctrolArry[i+1]->get_y());
				  i++;		  
			   }
			   break;
		   
		   case LEFT:
			   {
				   //如果页数是1就提示
				   if(direction==1)
				   {
					   MessageBox(NULL,"已经是第一页！","提示",0);
					   break;
				   }				   			
				  //显示页数
				  ctool::gotoxy(48,24);
				  cout<<--direction<<"/"<<goods_map3.size()/3+1<<"   ";
				  //显示商品内容
				  ccheck_form::goods_show(direction);
				  break;
			   }
			   
		   case RIGHT:	
			   {				   			
				    //如果页数是最后一页就提示
				   if(direction==goods_map3.size()/3+1)
				   {
					   MessageBox(NULL,"已经是最后一页！","提示",0);
					   break;										   
				   }	  
				    ctool::gotoxy(48,24);
					cout<<++direction<<"/"<<goods_map3.size()/3+1<<"   ";
					//显示商品内容
					ccheck_form::goods_show(direction);
					break;
			   }
			   
		   default:

			   if(this->ctrolArry[i]->get_type() == EDIT)//编辑框
			   {
				   this->ctrolArry[i]->editKeyListen(key); 
				   break;
			   }
			   break;
	   }
	}
}





//显示盘点商品内容函数
void ccheck_form::goods_show(int direction)
{
	int j=1;
	int x=0;

	//利用迭代器访问
	map <string,cgoods *>::iterator it;

	//用空格去清空表格
	for (j=1;j<4;j++)
	{
		x=0;
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<"            ";
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<"            ";
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<"            ";
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<"            ";
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<"            ";
	}
	j=1;
	//迭代器用页数偏移访问下页数据
	advance(it=goods_map3.begin(),3*direction-3);
	//遍历打印数据
	for(it;it!=goods_map3.end()&&j<4;it++,j++)
	{
							
		x=0;
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<it->second->get_goods_ID();
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<it->second->get_goods_name();					
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<it->second->get_goods_mount();
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<it->second->get_check_mount();
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<it->second->get_difference_mount();
   }

}



//盘点窗口操作动作
int ccheck_form::doAction()
{
	//当控件为结束盘点时
	if(this->focusIndex==3)
	{
		//将内容存入map里
		cdata::multiMap.insert(make_pair(ccheck::ccheck_str, goods_map3));
		//该编号下盘点状态变成未冲正
		check_state[ccheck::ccheck_str]="未冲正";
		ccheck::ccheck_num++;
		//清除链表内容，以便下次使用
		goods_map3.clear();

		return 13;
	}

	//当控件为返回时
	if(this->focusIndex==4)
	{
		return 14;
	}
	return -1;
}
	
ccheck_form::~ccheck_form(){}
