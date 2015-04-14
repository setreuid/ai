#ifndef INIT_DEFINE_H
#define INIT_DEFINE_H

#include <iostream>
#include <string>
#include <sstream>
#include <map>

#include "dbStat.h"
#include "dbTask.h"
#include "../Npc/class_npc.h"
#include <fstream>

using namespace std;


class InitDefine {
private:
	multimap<string, dbStat> *RootStat;
	multimap<string, dbTask> *RootTask;

	float calc( float, int, float );
	int findProcedure( string );
	int findDefault( string );

public:
	InitDefine();
	
	void function( string, npc* );
	void loadDB();

	multimap<string, dbStat> *getRootStat();
	
};

#endif
