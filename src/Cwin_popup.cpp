#include "Cwin_popup.h"

//弹窗窗口默认构造函数
cpopup::cpopup(){}

//弹窗窗口构造函数
cpopup::cpopup(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(x+3,y+2,10,2,"提示：",LABEL));
	this->addCtrol(new clabel(x+6,y+4,10,2,"未找到对应的商品：",LABEL));
	this->addCtrol(new cbutton(x+11,y+7,12,2,"重新输入",BUTTON));
	this->addCtrol(new cbutton(x+11,y+11,12,2,"新增商品",BUTTON));
	
}
void cpopup::show()
{
	for (int i=0;i<this->height;i++)
	{
		ctool::gotoxy(this->x+2,this->y+1+i);
		cout<<"                            ";
	}
	ctool::paintWindow(this->x, this->y,this->width,this->height);

	for(i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}

}
//弹窗窗口操作动作
int cpopup::doAction()
{
	switch(this->focusIndex)
	{	
	//控件为确定时
	case 2:
		{
			return 8;
		}
	//控件为返回时
	case 3:
		{
			return 10;
		}
	}

	return -1;	
}

//弹窗窗口析构函数
cpopup::~cpopup(){}

//----------------------------------------------------------

//弹窗窗口默认构造函数
cpopup2::cpopup2(){}

//弹窗窗口构造函数
cpopup2::cpopup2(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(x+3,y+2,10,2,"提示：",LABEL));
	this->addCtrol(new clabel(x+6,y+4,10,2,"未找到对应的商品：",LABEL));
	this->addCtrol(new cbutton(x+11,y+7,12,2,"重新输入",BUTTON));

	
}
void cpopup2::show()
{
	for (int i=0;i<this->height;i++)
	{
		ctool::gotoxy(this->x+2,this->y+1+i);
		cout<<"                            ";
	}
	ctool::paintWindow(this->x, this->y,this->width,this->height);

	for(i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}

}
//弹窗窗口操作动作
int cpopup2::doAction()
{
	switch(this->focusIndex)
	{	
	//控件为重新输入时
	case 2:
		{

			return 8;
		}


	}

	return -1;	
}

//弹窗窗口析构函数
cpopup2::~cpopup2(){}




//---------------------盘点冲正的弹窗---------------------------

//盘点冲正的弹窗窗口默认构造函数
cpopup3::cpopup3(){}

//盘点冲正的弹窗窗口构造函数
cpopup3::cpopup3(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(x+3,y+2,10,2,"冲正记录：",LABEL));
	this->addCtrol(new clabel(x+3,y+5,10,2,"冲正数量：",LABEL));
	this->addCtrol(new clabel(x+3,y+8,10,2,"冲正说明：",LABEL));
	this->addCtrol(new cedit(x+15,y+5,18,2,10,3,1,"",EDIT));
	this->addCtrol(new cedit(x+15,y+8,18,4,10,3,1,"",EDIT));
	this->addCtrol(new clabel(x+10,y+14,10,2,"确定",BUTTON));
	this->addCtrol(new cbutton(x+25,y+14,10,2,"取消",BUTTON));

	
}
//盘点冲正的弹窗窗口内容打印
void cpopup3::show()
{
	
	for (int i=0;i<this->height;i++)
	{
		ctool::gotoxy(this->x+2,this->y+1+i);
		cout<<"                                     ";
	}
	ctool::paintWindow(this->x, this->y,this->width,this->height);

	for(i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}

}
//盘点冲正的弹窗窗口操作动作
int cpopup3::doAction()
{
	switch(this->focusIndex)
	{	
	case 5:
		{
			//利用map迭代器输入冲正数量和冲正说明
			map<string,cgoods *>::iterator  it=cdata::goods_map4.find(ccheck_correct::str);
			if(it != goods_map4.end())
			{
				//如果冲正数量大于差异数量就提示
				if (atoi(this->ctrolArry[3]->get_content())>it->second->get_difference_mount())
				{
					MessageBox(NULL,"盘点数量不能大于差异数量","提示",0);
					cmanwin::winArry[18]->winRun();
					return cmanwin::winArry[18]->doAction();	
				}
				//反之就修改内容
				else
				{
				
				it->second->get_rectification(atoi(this->ctrolArry[3]->get_content()));
				it->second->get_explain(this->ctrolArry[4]->get_content());	
				it->second->get_modify();
				
				}
			}
			//清空两个编辑框内容
			memset (this->ctrolArry[3]->get_content(),0,strlen(this->ctrolArry[3]->get_content()));
			memset (this->ctrolArry[4]->get_content(),0,strlen(this->ctrolArry[4]->get_content()));

			return 17;
		}
	//控件为返回时
	case 6:
		{

			return 17;
		}


	}

	return -1;	
}
//弹窗窗口析构函数
cpopup3::~cpopup3(){}