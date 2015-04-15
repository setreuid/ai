#ifndef CLASS_NPC_H
#define CLASS_NPC_H

#include <iostream>
#include <map>
#include <cstdlib>

#include <string>
#include <iterator>
#include <pthread.h>
#include <unistd.h>

#include "../Lib/InitDefine.h"
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
	multimap<float, dbTask> *prTaskTable;

	class InitDefine *coredb;
	multimap<string, npc> *npcs;

	multimap<string, dbTask> *taskTable;
	multimap<string, dbTask> :: iterator it;

	string name;
	pthread_t thread;
	string lastTaskName;

	static void* run(void *);
	static void* doTask(void *);
	static void* reduceProcess(void *);
	
	void setStatusValue(string, float);


public:
	npc();
	npc(InitDefine *, multimap<string, npc> *);

	void initNpc();
	dbStat getStatus(string);
	//void setStatus(string, float);

	void newNpc();

	void start();
	string getName();

	float function( dbTask );
	void todoTask( dbTask );

	float calc( float, int, float );
	int findProcedure( string );
	int findDefault( dbTask, string );
};

#endif
