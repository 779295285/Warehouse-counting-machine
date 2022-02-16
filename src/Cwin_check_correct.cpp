#include "Cwin_check_correct.h"
//----------------------盘点冲正页面----------------------------
int ccheck_correct::direction=1;
string ccheck_correct::str;
//盘点冲正窗口默认构造函数
ccheck_correct::ccheck_correct(){}

//盘点冲正窗口构造函数
ccheck_correct::ccheck_correct(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(42,7,10,2,"欢迎使用盘点机系统",LABEL));
	this->addCtrol(new clabel(60,12,10,2,"盘点状态：",LABEL));
	this->addCtrol(new clabel(18,12,10,2,"盘点编号：",LABEL));
	
	this->addCtrol(new cbutton(12,18,0,0,"○",BUTTON));
	this->addCtrol(new cbutton(12,20,0,0,"○",BUTTON));
	this->addCtrol(new cbutton(12,22,0,0,"○",BUTTON));
	this->addCtrol(new cbutton(18,26,12,2,"完成冲正",BUTTON));
	this->addCtrol(new cbutton(35,26,12,2,"  返回",BUTTON));

	
}



//显示盘点冲正商品内容函数
void ccheck_correct::goods_show(int direction)
{
	int j=1;
	int x=0;
	//利用迭代器访问
	map<string,cgoods *>::iterator it;
	
	//用空格去清空表格
	for (j=1;j<4;j++)
	{
		x=0;
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
	}
	j=1;
	//迭代器用页数偏移访问下页数据
	advance(it=goods_map4.begin(),3*direction-3);
	//遍历打印数据
	for( it;it!= goods_map4.end()&&j<4;it++,j++)
	{
		x=0;
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_goods_ID();
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_goods_name();
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_goods_mount();
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_check_mount();
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_difference_mount();
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_rectification();
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_explain();
	}
		
}








//重写盘点冲正show
void ccheck_correct::show()
{
	//显示时间
	cwin::UserandTime();

	//打印边框和控件
	for(int i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}
	ctool::paintWindow(this->x, this->y,this->width,this->height);
	
	//打印表格
	vector<string>label;
	label.push_back("商品编号");
	label.push_back("商品名称");
	label.push_back("库存数量");
	label.push_back("盘点数量");
	label.push_back("差异数量");
	label.push_back("冲正数量");
	label.push_back("冲正说明");
	cform::show_form(15,15,112,8,7,4,label);

	//打印翻页提示
	ctool::gotoxy(60,32);
	cout<<"按← →翻页，按↑↓选择数据";

	//打印页数
	ctool::gotoxy(48,24);
	cout<<"1"<<"/"<<goods_map4.size()/3+1<<"   ";

	//打印盘点编号
	ctool::gotoxy(28,12);
	cout<<ccheck_record::ccheck_str;
	
	//打印盘点状态
	ctool::gotoxy(70,12);
	cout<<check_state[ccheck_record::ccheck_str];

	//打印盘点冲正内容
	goods_show(direction);
	
}

//重写盘点冲正窗口运行函数
void ccheck_correct::winRun()
{
	int i=0;
	int j=1;
	int x=0;
	int key;
	
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
					   ctool::gotoxy(this->ctrolArry[i]->get_x() , this->ctrolArry[i]->get_y());
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
					   ctool::gotoxy(this->ctrolArry[i]->get_x() , this->ctrolArry[i]->get_y());
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
				   
				  ctool::gotoxy (this->ctrolArry[i+1]->get_x() , this->ctrolArry[i+1]->get_y());
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
				  cout<<--direction<<"/"<<goods_map4.size()/3+1<<"   ";
				  //显示商品内容
				  goods_show(direction);
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
					cout<<++direction<<"/"<<goods_map4.size()/3+1<<"   ";
					//显示商品内容
					goods_show(direction);
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





//盘点冲正窗口操作动作
int ccheck_correct::doAction()
{
	map<string,cgoods *>::iterator it;
	//控件为选择盘点内容冲正时
	if(this->focusIndex==3||this->focusIndex==4||this->focusIndex==5)
	{

		//利用map迭代器输入冲正数量和冲正说明
		
		advance(it=goods_map4.begin(),3*direction-3+this->focusIndex-3);
		if (it!=goods_map4.end())
		{
			ccheck_correct::str=it->first;
			cmanwin::winArry[18]->show();
			cmanwin::winArry[18]->winRun();
			return cmanwin::winArry[18]->doAction();
		}
		
		else
		{
			MessageBox(NULL,"没有内容","提示",0);
			//继续操作
			ccheck_correct::winRun();
			return ccheck_correct::doAction();
		}
		
			
	}
		
	//控件为完成冲正
	if(this->focusIndex==6)
	{
		
		for (it=goods_map4.begin();it!=goods_map4.end();it++)
		{
			//如果还有商品数量不等于盘点数量时
			if (it->second->get_goods_mount()!=it->second->get_check_mount())
			{
				MessageBox(NULL,"还有商品未冲正","提示",0);
				//继续操作
				ccheck_correct::winRun();
				return ccheck_correct::doAction();
			}
		}
			cdata::multiMap[ccheck_record::ccheck_str]=goods_map4;
			check_state[ccheck_record::ccheck_str]="已冲正";
			return 16;
	}
	//控件为返回时
	if(this->focusIndex==7)
	{
		return 16;

	}
	

	return -1;
}
ccheck_correct::~ccheck_correct(){}
