#include "Cwin_check_record.h"
//----------------------盘点记录页面----------------------------
int ccheck_record::direction=1;
string ccheck_record::ccheck_str;
//盘点记录窗口默认构造函数
ccheck_record::ccheck_record(){}

//盘点记录窗口构造函数
ccheck_record::ccheck_record(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(42,7,10,2,"欢迎使用盘点机系统",LABEL));
	this->addCtrol(new cbutton(27,18,0,0,"○",BUTTON));
	this->addCtrol(new cbutton(27,20,0,0,"○",BUTTON));
	this->addCtrol(new cbutton(27,22,0,0,"○",BUTTON));
	this->addCtrol(new cbutton(30,26,12,2,"  返回",BUTTON));
}



//显示盘点冲正商品内容函数
void ccheck_record::goods_show(int direction)
{
	int j=1;
	int x=0;

	//利用迭代器访问
	map<string,map<string,cgoods *> >::iterator it;

	//用空格去清空表格
	for (j=1;j<4;j++)
	{
		x=0;
		ctool::gotoxy(32+20*x++,16+2*j);
		cout<<"                  ";
		ctool::gotoxy(32+20*x++,16+2*j);
		cout<<"                  ";
	}
	j=1;
	//迭代器用页数偏移访问下页数据
	advance(it=multiMap.begin(),3*direction-3);
	//遍历打印数据
	for(it;it!=multiMap.end()&&j<4;it++,j++)
	{				
		x=0;
		ctool::gotoxy(32+20*x++,16+2*j);
		cout<<it->first;
		ctool::gotoxy(32+20*x++,16+2*j);
		cout<<check_state[it->first];
		
   }

}

//重写盘点记录show
void ccheck_record::show()
{

	
	//显示时间
	cwin::UserandTime();
	vector<string>label;
	label.push_back("     盘点编号");
	label.push_back("     盘点状态");
	cform::show_form(30,15,40,8,2,4,label);

	ctool::gotoxy(60,32);
	cout<<"按← →翻页，按↑↓选择数据";

	ctool::paintWindow(this->x, this->y,this->width,this->height);

	for(int i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}

	ctool::gotoxy(24,17);
	cout<<" ";
	ctool::gotoxy(24,19);
	cout<<" ";
	ctool::gotoxy(24,21);
	cout<<" ";
	
	goods_show(direction);
	ctool::gotoxy(50,24);
	cout<<"1"<<"/"<<multiMap.size()/3+1<<"   ";
}


//重写盘点表窗口运行函数
void ccheck_record::winRun()
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
				    
					//显示商品内容

				  ctool::gotoxy(48,24);
				  cout<<--direction<<"/"<<multiMap.size()/3+1<<"   ";
				  goods_show(direction);
				  
				  break;
			   }
			   
		   case RIGHT:	
			   {
				   //如果页数是最后一页就提示
				   

				    //显示商品内容

				   if(direction==multiMap.size()/3+1)
				   {
					   MessageBox(NULL,"已经是最后一页！","提示",0);
					   break;										   
				   }	  
				    ctool::gotoxy(48,24);
					cout<<++direction<<"/"<<multiMap.size()/3+1<<"   ";
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

//盘点界面窗口操作动作
int ccheck_record::doAction()
{
	//控件为新建盘点时
	if(this->focusIndex==1||this->focusIndex==2||this->focusIndex==3)
	{
		
			
		map<string,map<string,cgoods *> >::iterator it;
		advance(it=multiMap.begin(),3*direction-3+this->focusIndex-1);
				
		if (it!=multiMap.end())
		{
			ccheck_record::ccheck_str=it->first;
			//盘点员不能操作不是已冲正的内容
			if (cwin::role==2&&check_state[ccheck_record::ccheck_str]!="已冲正")
			{
				MessageBox(NULL,"不能操作","提示",0);
				ccheck_record::winRun();
				return ccheck_record::doAction();

			}
			//已经冲正就跳到盘点详情
			if (check_state[ccheck_record::ccheck_str]=="已冲正")
			{
				
				return 19;
			}
			//不是已冲正的就跳转到盘点冲正
			else
			{
				
				goods_map4=it->second;
				check_state[ccheck_record::ccheck_str]="冲正中";
				return 17;
			}
		}
		else
		{
			//没有内容就提示
			MessageBox(NULL,"没有内容","提示",0);
			ccheck_record::winRun();
			return ccheck_record::doAction();

		}
		
	}
	//控件为返回时
	if(this->focusIndex==4)
	{
		//如果是管理员就返回管理员的页面，盘点员就返回盘点员界面
		if (cwin::role==1)
		{
			return 1;
		}
		else
		{
			return 13;
		}
		
	}
	return -1;
}
ccheck_record::~ccheck_record(){}
