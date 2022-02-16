#include "Cdata.h"

list<cuser *> cdata::user_list;
map<int, cuser *> cdata::user_map;
map<string, cgoods *> cdata::goods_map;
map<string, cgoods *> cdata::goods_map2;
map<string,cgoods *> cdata::goods_map3;
map<string,cgoods *> cdata::goods_map4;
map<string,string>cdata::check_state;
map<string,map<string,cgoods *> > cdata::multiMap;


//信息默认构造函数
cdata::cdata(){}


//将货物信息初始化
void cdata::goods_Initialization()
{
	cdata::goods_map.insert(make_pair(string("G1001"),new cgoods("G1001","戴尔笔记本","电子产品",5999.5,2,"A1001")));
	cdata::goods_map.insert(make_pair(string("G1002"),new cgoods("G1002","索尼相机","电子产品",4999.5,2,"A1002")));
	cdata::goods_map.insert(make_pair(string("G1003"),new cgoods("G1003","牙刷","日用品",9.9,10,"A1003")));
	cdata::goods_map.insert(make_pair(string("G1004"),new cgoods("G1004","洗面奶","护肤品",99.9,10,"A1004")));
	cdata::goods_map.insert(make_pair(string("G1005"),new cgoods("G1005","沐浴露","日用品",9.5,6,"A1005")));
	cdata::goods_map.insert(make_pair(string("G1006"),new cgoods("G1006","肥皂","日用品",9.9,10,"A1006")));
	cdata::goods_map.insert(make_pair(string("G1007"),new cgoods("G1007","巧克力","食物",8.9,10,"A1007")));
	cdata::goods_map.insert(make_pair(string("G1008"),new cgoods("G1008","水杯","日用品",9.5,6,"A1008")));
	cdata::goods_map.insert(make_pair(string("G1009"),new cgoods("G1009","薯片","食物",9.9,10,"A1009")));
	cdata::goods_map.insert(make_pair(string("G1010"),new cgoods("G1010","可口可乐","食物",3.0,10,"A1010")));
	cdata::goods_map.insert(make_pair(string("G1011"),new cgoods("G1011","纯牛奶","食物",40.0,10,"A1011")));
	cdata::goods_map.insert(make_pair(string("G1012"),new cgoods("G1012","洗发水","日用品",20.6,6,"A1012")));
	cdata::goods_map.insert(make_pair(string("G1013"),new cgoods("G1013","衣架","日用品",9.9,10,"A1013")));
	cdata::goods_map.insert(make_pair(string("G1014"),new cgoods("G1014","麦片粉","食物",8.9,10,"A1014")));
  

	//将员工信息写入文件
	cdata::goodsToFile();
}


//将员工信息写入文件
void cdata::userToFile()
{
    //放入list，逐个添加
	ofstream fs("data/user.txt");

	//利用迭代器存入文件
	for(list<cuser*>::iterator it=user_list.begin();it!=user_list.end();it++)
	{
		fs<<(*it)->get_ID()<<" "<<(*it)->get_name()<<" "<<(*it)->get_pwd()<<" "<<(*it)->get_role()<<endl;
	}
	fs.close();
}




//将货物信息写入文件
void cdata::goodsToFile()
{
    //放入list，逐个添加
	ofstream fs("data/goods.txt");

	//利用迭代器存入文件
	for(map <string,cgoods *>::iterator it=goods_map.begin();it!=goods_map.end();it++)
	{
		fs<<it->second->get_goods_ID()<<" "<<it->second->get_goods_name()<<" "
		  <<it->second->get_goods_type()<<" "<<it->second->get_goods_price()<<" "
		  <<it->second->get_goods_mount()<<" "<<it->second->get_goods_Position()<<endl;
	}

	fs.close();
}



//将员工信息写入list
void cdata::userToList()
{
    int ID;
	char name[10];//用户名
	char pwd[10];//密码
	int role ;//角色
	char buf[256]={0};
	cdata::user_list.clear();
	ifstream fs("data/user.txt");

	
	while(fs.peek()!=EOF)
	{
		fs.getline(buf,256);
		//获取内容
		sscanf(buf,"%d %s %s %d",&ID,name,pwd,&role);
		//存入list和map
		cdata::user_list.push_back(new cuser(ID,name,pwd,role));
		cdata::user_map.insert(make_pair(ID,(new cuser(ID,name,pwd,role))));
	}
	fs.close();

}


//将注册员工信息写入文件
void cdata::userToFile(cuser *newuser)
{   

	ofstream fs("data/user.txt",ios_base::app);
	fs<<newuser->get_ID()<<" "<<newuser->get_name()<<" "<<newuser->get_pwd()<<" "<<newuser->get_role()<<endl;
	fs.close();
}






cdata::~cdata(){}
