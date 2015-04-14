#include "class_npc.h"


void npc::initNpc(multimap<string, dbStat> *st) {
	status = new multimap<string, dbStat>();
	srand ((unsigned int)time(NULL));

	multimap<string, dbStat>::iterator i;
	for (i=st->begin(); i!=st->end(); ++i) {
		// Insert Default Stat
		status->insert (pair<string, dbStat>( i->first, i->second ));
	}

	this->name = "NPC";
	this->name.append (to_string((rand() % 100) + 1));
};


dbStat npc::getStatus(string key) {
	multimap<string, dbStat> :: const_iterator result = status->find(key);
	
	if (result != status->end()) {
		return result->second;
	}

	//cout << "Cant Found! " << key << endl;
	return dbStat();
};


/**
 * Thread
 */

void *npc::run(void *ptr) {
	npc *me = (npc *) ptr;

	while (1) {
		//cout << me->name << endl;
		sleep (1);
	};

	return 0;
};


void npc::start() {
	pthread_create(&thread, NULL, &npc::run, this);
};

