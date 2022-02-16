#include <iostream>
#include <stdio.h>
#include <string>
#pragma warning (disable: 4786)
using namespace std;
#include "CmanagerWin.h"
#include "Cwin_homepage.h"
#include "Cdata.h"
#include "Ctool_form.h"
void main()
{

			
	cdata::goods_Initialization();
 
 
 	cdata::userToList();
 
 	int res=3;
 	cmanwin *managerWin=new cmanwin;
 	while(1)
 	{
 		system("cls");
 		managerWin->winArry[res]->show();
 		managerWin->winArry[res]->winRun();
 		res=managerWin->winArry[res]->doAction();
  	}
}