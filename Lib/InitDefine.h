#ifndef INIT_DEFINE_H
#define INIT_DEFINE_H

#include <iostream>
#include <string>
#include <sstream>
#include <map>

#include "dbStat.h"
#include "dbTask.h"
#include "../Npc/class_npc.h"
#include "preheader.h"
#include <fstream>

using namespace std;


class InitDefine {
private:
	multimap<string, dbStat> *RootStat;
	multimap<string, dbTask> *RootTask;

	float calc( float, int, float );
	int findProcedure( string );
	int findDefault( dbTask, string, npc* );

public:
	InitDefine();
	
	float function( dbTask, npc* );
	void loadDB();

	multimap<string, dbStat> *getRootStat();
	multimap<string, dbTask> *getRootTask();
	
};



#endif
