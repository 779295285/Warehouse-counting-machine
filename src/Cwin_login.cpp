#include "Cwin_login.h"
char cwin::name[10]={0};
int cwin::role=0;
//登录窗口默认构造函数
clogin::clogin(){}



//登录窗口构造函数
clogin::clogin(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	
	this->addCtrol(new clabel(40,7,10,2,"欢迎使用盘点机系统",LABEL));
	this->addCtrol(new clabel(35,13,10,2,"用户名",LABEL));
	this->addCtrol(new clabel(35,17,10,2,"密码",LABEL));
	this->addCtrol(new cedit(42,13,20,2,12,3,1,"",EDIT));
	this->addCtrol(new cedit(42,17,20,2,10,2,0,"",EDIT));
	this->addCtrol(new cbutton(37,21,10,2,"确定",BUTTON));
	this->addCtrol(new cbutton(55,21,10,2,"取消",BUTTON));

}

//登录窗口操作动作
int clogin::doAction()
{
	//控件为确定时
	if(this->focusIndex==5)
	{
		int irole=loginJudge();

		//密码账号不正确时
		if(irole==0)
		{
			//密码或账号错误且为空时候
			if((strlen(this->ctrolArry[3]->get_content())==0)||(strlen(this->ctrolArry[4]->get_content())==0))
			{

				ctool::gotoxy(this->ctrolArry[4]->get_x()-2, this->ctrolArry[4]->get_y()+2);
				printf("账号或密码不能为空!\n");
				Sleep(1000);
				
			}
			//密码或账号错误且不为空时候
			else
			{
				ctool::gotoxy(this->ctrolArry[4]->get_x()-2, this->ctrolArry[4]->get_y()+2);
				printf("账号或密码不正确!\n");
				Sleep(1000);
			}
		}

		//清空编辑框里数据
		memset (this->ctrolArry[3]->get_content(),0,strlen(this->ctrolArry[3]->get_content()));
		memset (this->ctrolArry[4]->get_content(),0,strlen(this->ctrolArry[4]->get_content()));

		return irole;
	}

	//控件为返回时
	if(this->focusIndex==6)
	{
		//清空编辑框里数据
		memset (this->ctrolArry[3]->get_content(),0,strlen(this->ctrolArry[3]->get_content()));
		memset (this->ctrolArry[4]->get_content(),0,strlen(this->ctrolArry[4]->get_content()));

		return 3;
	}
	return 0;
}


//登录验证函数
int clogin::loginJudge()
{
	//利用迭代器遍历
	list<cuser*>::iterator it;
	for (it=cdata::user_list.begin();it!=user_list.end();it++)
	{
		if(atoi(this->ctrolArry[3]->get_content())==(*it)->get_ID()
		   &&strcmp(this->ctrolArry[4]->get_content(),(*it)->get_pwd())==0)
		{
			strcpy(clogin::name,(*it)->get_name());
			clogin::role=(*it)->get_role();

			
			//登录验证成功后返回角色
			return (*it)->get_role();
		}
	}
	//登录验证失败返回0
	return 0;

}

//登录窗口析构函数
clogin::~clogin(){}