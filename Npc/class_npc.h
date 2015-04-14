#ifndef CLASS_NPC_H
#define CLASS_NPC_H

#include <iostream>
#include <map>
#include <cstdlib>

#include <string>
#include <iterator>
#include <pthread.h>
#include <unistd.h>

#include "../Lib/preheader.h"
#include "../Lib/dbStat.h"

using namespace std;

class npc {

private:
	// Real Value of dbStat
	multimap<string, dbStat> *status;

	string name;
	pthread_t thread;

	static void* run(void *ptr);


public:
	void initNpc(multimap<string, dbStat>*);
	dbStat getStatus(string);

	void start();
};

#endif
