#include "class_npc.h"



void npc::initNpc(hash_map<int, dbStat> *st) {
	status = new hash_map<int, float>();
	dbstat = st;

	hash_map<int, dbStat>::iterator i;
	for (i=st->begin(); i!=st->end(); ++i) {
		// Debug
		//cout << (i->second).name << endl;

		// Insert Default Stat
		status->insert(status->begin(), hash_map<int, float>::value_type(i->first, (i->second).value));
	}

	float mealAmount = this->getStatus(3);
	cout << dbstat->find(3)->second.name << ": " << mealAmount << endl;

};


float npc::getStatus(int key) {
	hash_map<int, float>::iterator result = status->find(key);
	
	if (result != status->end()) {
		return result->second;
	}

	return -1;
};




