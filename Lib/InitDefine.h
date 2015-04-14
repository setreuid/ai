#ifndef INITDEFINE_H
#define INITDEFINE_H

#include <iostream>
#include <string>
#include <sstream>
#include <ext/hash_map>

#include "dbStat.h"
#include "DefCore.h"
#include "../Npc/class_npc.h"
#include <fstream>

using namespace __gnu_cxx;


class InitDefine {
private:
	hash_map<std::string, dbStat> *RootStat;
	hash_map<std::string, DefCore> *RootDefCore;

	float calc( float, int, float );
	int findProcedure( std::string );
	int findDefault( std::string );

public:
	InitDefine();
	
	void function( std::string, npc* );
	void loadDB();
	
};

#endif
