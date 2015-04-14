#ifndef INIT_DEFINE_H
#define INIT_DEFINE_H

#include <iostream>
#include <string>
#include <sstream>
#include <ext/hash_map>

#include "dbStat.h"
#include "dbTask.h"
#include "../Npc/class_npc.h"
#include <fstream>

using namespace __gnu_cxx;


class InitDefine {
private:
	hash_map<const char*, dbStat> *RootStat;
	hash_map<const char*, dbTask> *RootTask;

	float calc( float, int, float );
	int findProcedure( std::string );
	int findDefault( std::string );

public:
	InitDefine();
	
	void function( std::string, npc* );
	void loadDB();

	hash_map<const char*, dbStat> *getRootStat();
	
};

#endif
