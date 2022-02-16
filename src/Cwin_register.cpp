#include "Cwin_register.h"

//注册窗口默认构造函数
Cregister::Cregister(){}

//注册窗口构造函数
Cregister::Cregister(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(42,7,10,2,"用户注册",LABEL));
	this->addCtrol(new cbutton(32,13,10,2,"ID",LABEL));
	this->addCtrol(new clabel(32,16,10,2,"用户名",LABEL));
	this->addCtrol(new clabel(32,19,10,2,"角色",LABEL));
	this->addCtrol(new clabel(32,22,10,2,"密码",LABEL));
	this->addCtrol(new clabel(28,25,10,2,"确认密码",LABEL));
	this->addCtrol(new cedit(39,16,20,2,12,4,1,"",EDIT));
	this->addCtrol(new cedit(39,19,20,2,10,2,1,"",EDIT));
	this->addCtrol(new cedit(39,22,20,2,10,2,0,"",EDIT));
	this->addCtrol(new cedit(39,25,20,2,10,2,0,"",EDIT));
	this->addCtrol(new cbutton(34,30,10,2,"确定",BUTTON));
	this->addCtrol(new cbutton(52,30,10,2,"取消",BUTTON));
	this->addCtrol(new clabel(60,19,10,2,"1管理员，2盘点员",LABEL));
	
}
//重写注册show
void Cregister::show()
{
	//显示时间
	cwin::UserandTime();
		ctool::paintWindow(36,12,20,2);
		int newID=cdata::user_map.size()+1001;
		ctool::gotoxy(38,13);
		cout<<newID;
		ctool::paintWindow(this->x, this->y,this->width,this->height);

		for(int i=0; i<this->ctrolCount; i++)
		{
			this->ctrolArry[i]->show();
		}
		memset (this->ctrolArry[6]->get_content(),0,strlen(this->ctrolArry[6]->get_content()));
		memset (this->ctrolArry[7]->get_content(),0,strlen(this->ctrolArry[7]->get_content()));
		memset (this->ctrolArry[8]->get_content(),0,strlen(this->ctrolArry[8]->get_content()));
		memset (this->ctrolArry[9]->get_content(),0,strlen(this->ctrolArry[9]->get_content()));
}



//注册窗口操作动作
int Cregister::doAction()
{
	int newID;
	char name[10];//用户名
	char pwd[10];//密码
	int role ;//角色

	//控件为确定时
	if(this->focusIndex==10)
	{
		//判断编辑框是否为空。
		if((strlen(this->ctrolArry[6]->get_content())==0)||(strlen(this->ctrolArry[7]->get_content())==0)
		 ||(strlen(this->ctrolArry[8]->get_content())==0)||(strlen(this->ctrolArry[9]->get_content())==0))
		{
		
			ctool::gotoxy(30,27);
			cout<<"内容不能为空！请重新填写。";
			system("pause");
			return 4;

		}
		
		//密码和确认密码一致时候
		if(strcmp(this->ctrolArry[8]->get_content(),this->ctrolArry[9]->get_content())==0)
		{
			//密码长度不是6-10之间时
			if((strlen(this->ctrolArry[8]->get_content())<4||strlen(this->ctrolArry[8]->get_content())>11))
			{
			
				ctool::gotoxy(30,27);
				cout<<"密码长度为6-10位";
				system("pause");
				return 4;

			}
			//获取编辑框注册信息
			strcpy(name,this->ctrolArry[6]->get_content());
			role=atoi(this->ctrolArry[7]->get_content());
			strcpy(pwd,this->ctrolArry[8]->get_content());
			

			//将注册信息存入list、map和文件
			newID=cdata::user_map.size()+1001;
			cdata::user_list.push_back(new cuser(newID,name,pwd,role));
			cdata::user_map.insert(make_pair(newID,(new cuser(newID,name,pwd,role))));
			cdata::userToFile(new cuser(newID,name,pwd,role));

			ctool::gotoxy(30,27);
			cout<<"注册成功！账号为"<<newID<<"。";
			system("pause");
			return 3;
		}

		//密码和确认密码不一致时候
		else
		{
			
			ctool::gotoxy(37,27);
			cout<<"密码和确认密码不一致！";
			system("pause");
			return 4;
		}

	}
	if(this->focusIndex==11)
	{
		
		return 3;
	}
	return -1;
}

//注册窗口析构函数
Cregister::~Cregister(){}