#include "class_npc.h"


void npc::initNpc(multimap<string, dbStat> *st) {
	status = new multimap<string, dbStat>();

	multimap<string, dbStat>::iterator i;
	for (i=st->begin(); i!=st->end(); ++i) {
		// Insert Default Stat
		status->insert (pair<string, dbStat>( i->first, i->second ));

	}

	string name = "식량";
	dbStat meal = this->getStatus(name);
	cout << meal.name << ": " << meal.value << endl;
};


dbStat npc::getStatus(string key) {
	multimap<string, dbStat> :: const_iterator result = status->find(key);
	
	if (result != status->end()) {
		return result->second;
	}

	cout << "Cant Found! " << key << endl;
	return dbStat();
};




