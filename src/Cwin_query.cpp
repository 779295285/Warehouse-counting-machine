#include "Cwin_query.h"

//查询窗口默认构造函数
cquery::cquery(){}

//查询窗口构造函数
cquery::cquery(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	
	this->addCtrol(new clabel(40,7,10,2,"欢迎使用盘点机系统",LABEL));
	this->addCtrol(new clabel(18,12,10,2,"请输入商品编号：",LABEL));
	this->addCtrol(new cedit(37,12,20,2,12,3,1,"",EDIT));
	this->addCtrol(new cbutton(68,12,8,2,"查询",BUTTON));
	this->addCtrol(new cbutton(26,26,16,2,"导出商品信息",BUTTON));
	this->addCtrol(new cbutton(60,26,16,2,"   返回",BUTTON));
	goods_map2=goods_map;
}

void cquery::show()
{
	int j=1;
	int direction=1;
	//显示边框
	ctool::paintWindow(this->x, this->y,this->width,this->height);
	//显示时间
	cwin::UserandTime();
	//显示控件
	for(int i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}
	//显示表格
		vector<string>label;
		label.push_back("商品编号");
		label.push_back("商品名称");
		label.push_back("商品类型");
		label.push_back("商品价格");
		label.push_back("商品数量");
		label.push_back("仓位编号");

		cform::show_form(14,15,72,8,6,4,label);

	//显示货物内容

		cquery::goods_show(direction);
		ctool::gotoxy(48,24);
		cout<<"1"<<"/"<<goods_map2.size()/3+1<<"   ";
}



//重写查询窗口运行函数
void cquery::winRun()
{
	//vector <cgoods *>::iterator it;
	
	
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
			ctool::gotoxy (this->ctrolArry[i]->get_x()-1+strlen(this->ctrolArry[i]->get_content()),this->ctrolArry[i]->get_y());
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
				   cout<<--direction<<"/"<<goods_map2.size()/3+1<<"   ";
				   //显示商品内容
				   cquery::goods_show(direction);				   					
				   break;
			   }
			   
		   case RIGHT:	
			   {
				   				    
				   //如果页数是最后一页就提示
				   if(direction==goods_map2.size()/3+1)
				   {
					   MessageBox(NULL,"已经是最后一页！","提示",0);
					   break;
				   }
				   ctool::gotoxy(48,24);
				   cout<<++direction<<"/"<<goods_map2.size()/3+1;
				   //显示商品内容
				   cquery::goods_show(direction);				   				 				   
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



//显示查询商品内容函数
void cquery::goods_show(int direction)
{
	int j=1;
	int x=0;
	//利用迭代器访问
	map <string,cgoods *>::iterator it;

	//用空格去清空表格
	for (j=1;j<4;j++)
	{
		x=0;
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<"          ";
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<"          ";
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<"          ";
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<"          ";
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<"          ";
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<"          ";
	}
	j=1;
	//迭代器用页数偏移访问下页数据
	advance(it=goods_map2.begin(),3*direction-3);
	//遍历打印数据
	for(it;it!=goods_map2.end()&&j<4;it++,j++)
	{
							
		x=0;
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<it->second->get_goods_ID();
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<it->second->get_goods_name();
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<it->second->get_goods_type();
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<fixed<<setprecision(2)<<it->second->get_goods_price();						
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<it->second->get_goods_mount();
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<it->second->get_goods_Position();
   }

}
//查询窗口操作动作
int cquery::doAction()
{
	
	switch(this->focusIndex)
	{	
	//控件为查询时
	case 3:
		{
			//获取查询内容
			string str1=this->ctrolArry[2]->get_content();
			goods_map2.clear();
			//利用迭代器来查询
			map<string,cgoods *>::iterator it;
			for (it=goods_map.begin();it!=goods_map.end();it++)
			{
				string str=it->second->get_goods_ID();
				//查询到存入map2，重新显示
				if (str.find(str1)!=string::npos)
				{	
					goods_map2.insert(make_pair(str,new cgoods(it->second->get_goods_ID(),it->second->get_goods_name(),it->second->get_goods_type(),
						                                       it->second->get_goods_price(),it->second->get_goods_mount(),it->second->get_goods_Position())));
					
				}
				else
				{
					
				}
			}
			if (goods_map2.size()==0)		
			{
				goods_map2=goods_map;
				MessageBox(NULL,"未查询到商品","提示",0);
			}
			cquery::show();
				cquery::winRun();
				return cquery::doAction();
			
			
		}
	//控件为返回时
	case 4:
		{
			char filename[30] = {0};
			
			time_t now = time(0); 
			tm *ltm = localtime(&now);
			//获取时间来命名文件
			sprintf(filename,"data/query/%d%d%dGI.txt",1900+ltm->tm_year,1+ltm->tm_mon,ltm->tm_mday);

			//查询到的信息通过map迭代器存入文件
			ofstream fs(filename);

			//利用迭代器存入文件
			for(map <string,cgoods *>::iterator it=goods_map2.begin();it!=goods_map2.end();it++)
			{
				fs<<it->second->get_goods_ID()<<" "<<it->second->get_goods_name()<<" "
				  <<it->second->get_goods_type()<<" "<<it->second->get_goods_price()<<" "
				  <<it->second->get_goods_mount()<<" "<<it->second->get_goods_Position()<<endl;
			}
			fs.close();
			ctool::gotoxy(43,29);
			cout<<"存入文件成功";
			
			cquery::winRun();
			cquery::doAction();
		}

	case 5:

		goods_map2=goods_map;
		return cwin::role;
	}
	
	return -1;	
}

//查询窗口析构函数
cquery::~cquery(){}

			   