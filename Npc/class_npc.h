#ifndef CLASS_NPC_H
#define CLASS_NPC_H

#include <iostream>
#include <ext/hash_map>

#include <string>
#include <iterator>

#include "../Lib/dbStat.h"

using namespace __gnu_cxx;


class npc {

private:
	// Real Value of dbStat
	hash_map<int, float> status;

	std::string name;


public:
	void initNpc(hash_map<int, dbStat>*);

};

#endif
