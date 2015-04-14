#ifndef CLASS_NPC_H
#define CLASS_NPC_H

#include <iostream>
#include <map>

#include <string>
#include <iterator>

#include "../Lib/dbStat.h"

using namespace std;


class npc {

private:
	// Real Value of dbStat
	multimap<string, dbStat> *status;

	string name;


public:
	void initNpc(multimap<string, dbStat>*);
	dbStat getStatus(string);

};

#endif
