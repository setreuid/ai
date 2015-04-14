#include "class_npc.h"
#include <map>


void npc::initNpc(hash_map<const char*, dbStat> *st) {
	status = new hash_map<const char*, dbStat>();

	hash_map<const char*, dbStat>::iterator i;
	for (i=st->begin(); i!=st->end(); ++i) {
		// Debug
		//cout << (i->second).name << endl;

		// Insert Default Stat
		status->insert (hash_map<const char*, dbStat>::value_type( i->first, i->second ));
		cout << i->first << " - Default: " << i->second.value << endl;

	}

	string name = "식량";
	dbStat meal = this->getStatus(name.c_str());
	cout << meal.name << ": " << meal.value << endl;

	cout << endl;

	typedef multimap<string, int> Map;
	Map map;
	map.insert (pair<string, int> (name, 2));
	cout << map.find("식량")->second << endl;


};


dbStat npc::getStatus(const char* key) {
	hash_map<const char*, dbStat> :: const_iterator result = status->find(key);
	
	if (result != status->end()) {
		return result->second;
	}

	cout << "Cant Found! " << key << endl;
	return dbStat();
};




