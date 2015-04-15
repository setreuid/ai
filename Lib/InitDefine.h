#ifndef INIT_DEFINE_H
#define INIT_DEFINE_H

#include <iostream>
#include <string>
#include <sstream>
#include <map>

#include "../Npc/class_npc.h"
#include "preheader.h"
#include "dbStat.h"
#include "dbTask.h"
#include <fstream>

using namespace std;


class InitDefine {
private:
	multimap<string, dbStat> *RootStat;
	multimap<string, dbTask> *RootTask;


public:
	InitDefine();
	
	void loadDB();

	multimap<string, dbStat> *getRootStat();
	multimap<string, dbTask> *getRootTask();
	
};



#endif
