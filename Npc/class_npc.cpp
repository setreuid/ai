#include "class_npc.h"



void npc::init_Npc(InitDefine *st)
	status = hash_map<int, float>();

	hash_map<int, dbStat>::iterator i;
	for (i=st->begin(); i!=st->end(); ++i) {
		cout << (i->first)->name << endl;
	}

};

