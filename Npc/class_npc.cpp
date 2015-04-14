#include "class_npc.h"



void npc::initNpc(hash_map<int, dbStat> *st) {
	status = hash_map<int, float>();

	hash_map<int, dbStat>::iterator i;
	for (i=st->begin(); i!=st->end(); ++i) {
		cout << (i->second).name << endl;
	}

};

