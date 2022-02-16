#ifndef CMANAGERWIN_H_
#define CMANAGERWIN_H_

#pragma warning (disable: 4786)
#include "ctool.h"
#include "cwin.h"
#include "Cwin_login.h"
#include "Cwin_register.h"
#include "Cwin_homepage.h"
#include "Cwin_out.h"
#include "Cwin_query.h"
#include "Cwin_warehousing.h"
#include "Cwin_popup.h"
#include "Cwin_addgoods.h"
#include "Cwin_delivery.h"
#include "Cwin_check.h"
#include "Cwin_check_record.h"
#include "Cwin_check_correct.h"
#include "Cwin_check_details.h"
#include <vector>
using namespace std;


class cmanwin
{
public:
	cmanwin();
	void addWin(cwin *win);
	static vector <cwin *> winArry;
	~cmanwin();
private:


};



#endif