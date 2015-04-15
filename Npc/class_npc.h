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
#include "../Lib/dbTask.h"

using namespace std;

class npc {

private:
	// Real Value of dbStat
	multimap<string, dbStat> *status;
	multimap<string, dbStat> :: iterator is;
	
	// Priority Value, Todo
	multimap<float, string> *prTaskTable;

	multimap<string, dbTask> *taskTable;
	multimap<string, dbTask> :: iterator it;

	string name;
	pthread_t thread;

	static void* run(void *);
	static void* doTask(void *);
	static void* reduceProcess(void *);


public:
	npc();
	npc(multimap<string, dbTask>*);

	void initNpc(multimap<string, dbStat>*);
	dbStat getStatus(string);
	//void setStatus(string, float);

	void start();

	float function( dbTask );
	float calc( float, int, float );
	int findProcedure( string );
	int findDefault( dbTask, string );
};

#endif
