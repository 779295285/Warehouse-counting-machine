#include "Ctrol_edit.h"
//编辑框默认构造函数
cedit::cedit(){}


//编辑框构造函数
cedit::cedit(int x,int y,int width,int height,int maxLen,int iputType,int ips,char *pcontent,int type)
:ctrol(x,y,width,height,pcontent,type)
{

	this->maxLen=maxLen;
	this->iputType=iputType;
	this->ips=ips;	
}


//编辑框监听函数
void cedit::editKeyListen(int key)
{
	int count=strlen(this->content);
	
	if(count>0 && key=='\b')
	{
		//如果是中文
		if(this->iputType==4)
		{
			cout<<"\b \b";
			cout<<"\b \b";
			this->content[--count]='\0';
			this->content[--count]='\0';
			
		}
		cout<<"\b \b";
		this->content[--count]='\0';
	}
	if(count==this->maxLen)
	{
		return;
	}
	else
	{
		//输入类型是字母
		if(this->iputType==1)
		{
			if(key>='a'&& key<='z'|| key>='A'&& key<='Z')
			{
				if(this->ips==1)
				{
					putch(key);
				}
				else if(this->ips==0)
				{
					putch('*');					
				}
				this->content[count]=key;
			}
		}

		//输入类型是数字
		else if(this->iputType==2)
		{
			if(key>='0'&& key<='9')
			{
				if(this->ips==1)
				{
					putch(key);
				}
				else if(this->ips==0)
				{
					putch('*');
				}
				this->content[count]=key;				
			}
		}

		//输入类型是数字和字母
		else if(this->iputType==3)
		{
			if(key>='0'&& key<='9'||key>='a'&& key<='z'|| key>='A'&& key<='Z')
			{
				if(this->ips==1)
				{
					putch(key);

				}
				else if(this->ips==0)
				{
					putch('*');
				}
				this->content[count]=key;			
			}
		}
		//输入类型是中文
		else if(this->iputType==4)
		{
			char ch2= getch();

			if((unsigned char)key>=0xA1 && (unsigned char)key<=0xFE)
			{
				if((unsigned char)ch2>=0xA1 && (unsigned char)ch2<=0xFE)
				{
					printf("%c%c",key,ch2);
					this->content[count++]=key;
					this->content[count]=key;
				}
			}
		}
	}
}
//编辑框析构函数
cedit::~cedit(){}