#include "Ctool.h"

//光标标定
void ctool::gotoxy(int x,int y)
{
	HANDLE hOut;
	COORD pos= {x,y};                       
	hOut = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition (hOut, pos); 

} 


//画框函数
void ctool::paintWindow(int X,int Y,int width,int height)
{
	int i=0;
	int j=0;

	gotoxy(X,Y);
	printf("┏");
	gotoxy(X+width,Y);
	printf("┓");
	gotoxy(X,Y+height);
	printf("┗"); 
	gotoxy(X+width,Y+height);
	printf("┛"); 
	
    //绘制上部和下部
	 	
		for(j=2;j<width;j+=2)
		{		
			gotoxy(X+j,Y+height);
			printf("━");
			gotoxy(X+j,Y);
		    printf("━");
		}

    //绘制左边和右边
		for(j=1;j<height;j+=1)
		{
			gotoxy(X+width,Y+j);
			printf("┃");
			gotoxy(X,Y+j);
		   	printf("┃");
		}
}


//获取键盘值
//ENTER值13；ESC值27；BACK值8；UP值72；down值80；LEFT值75；RIGHT值77
int ctool::getKey()
{
	int key;
	key=getch();
	if(key==ENTER)//ENTER值13
	{
		return ENTER;
	}
	else if(key==ESC)//ESC值27
	{
		return ESC;
	}
	else if(key==BACK)//BACK值8
	{
		return BACK;
	}
	else if(key==224)//方向键有两个值，需要获取两次
	{
		key=getch();
		switch(key)
		{
		   case UP:
			   return UP;//UP值72
		   case DOWN:
			   return DOWN;//DOWN值80
		   case LEFT:
			   return LEFT;//LEFT值75
		   case RIGHT:
			   return RIGHT;//RIGHT值77
		}
	}
	else
	{
		return key;
	}
	return 0;
}


