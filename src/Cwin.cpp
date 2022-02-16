#include "Cwin.h"

//窗口默认构造函数
cwin::cwin(){}



//窗口构造函数
cwin::cwin(int x,int y,int width,int height)
{
	this->x=x;
	this->y=y;
	this->width=width;
	this->height=height;
	this->ctrolCount=0;
	this->userCount=0;
	
}



//显示用户和时间
void cwin::UserandTime()
{
	if(cwin::role==1||cwin::role==2)
	{
		//时间显示
		ctool::gotoxy(61,9); 
		time_t now = time(0); 
		tm *ltm = localtime(&now);
		printf("日期：%d-%02d-%d",1900+ltm->tm_year,1+ltm->tm_mon,ltm->tm_mday);

		//用户显示
		if(cwin::role==1)
		{
			ctool::gotoxy(22,9); 
			cout<<"欢迎："<<cwin::name<<"管理员"<<endl;
		}
		if(cwin::role==2)
		{
			ctool::gotoxy(22,9); 
			cout<<"欢迎："<<cwin::name<<"盘点员"<<endl;
		}
	}		
}


//添加控件函数
void cwin::addCtrol(ctrol *ctrolArry)
{

	this->ctrolArry[this->ctrolCount++]=ctrolArry;
}


//显示控件
void cwin::show()
{
	cwin::UserandTime();

    //画框
	ctool::paintWindow(this->x, this->y,this->width,this->height);

	for(int i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}

}

//窗口运行函数
void cwin::winRun()
{
	int i=0;
	int key;
	//光标定位
	for(i=0; i<this->ctrolCount;i++)
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
	while(1)
	{
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

		   break;

	   case RIGHT:

		   break;

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

//窗口析构函数
cwin::~cwin()
{
	for(int i=0; i<this->ctrolCount;i++)
	{
		delete this->ctrolArry[i];
	}
	
}