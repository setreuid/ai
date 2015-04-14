#include "InitDefine.h"



InitDefine::InitDefine() {
	RootStat = new hash_map<string, dbStat>();
	RootDefCore = new hash_map<string, DefCore>();
};


void InitDefine::function( string val, npc *n ) {
	int i;
	string tmp = "";
	float ret;
	float value = 0;
	float yetValue = 0;
	int procedure = 0;

	for (i=0 ; i<val.size() ; i++) {
		tmp += val.at(i);

		if ((ret = findDefault(tmp)) != -1) {
			if (yetValue != 0) {
				value += calc (yetValue, procedure, ret);
				procedure = 0;
				ret = 0;
			}

			tmp = "";
			yetValue = ret;
		} else if ((procedure = findProcedure(tmp)) != -1) {
			tmp = "";
		}
	}

};


void InitDefine::loadDB() {
	ifstream dbstat("Res/stat.txt");
	ifstream dbtask("Res/task.txt");

	std::string tmp = "";
	char ch;

	// Load stat defines
	while (!dbstat.eof()) {
		dbstat.get(ch);
		if (ch == '\n') {
			dbStat stat;
			stringstream sp(tmp);

			sp >> stat.name;
			sp >> stat.maxValue;
			sp >> stat.value;
			sp >> stat.cycleValue;

			tmp = "";

			// Debug
			std::cout << stat.name << ": " << stat.maxValue << " " << stat.value << " " << stat.cycleValue << endl;
		} else {
			tmp += ch;
		}
	}

	ch = 0;
	tmp = "";

	// Load task defines
	while (!dbtask.eof()) {
		dbtask.get(ch);
		if (ch == '\n') {
			DefCore task;
			stringstream sp(tmp);

			sp >> task.name;
			sp >> task.statString;
			sp >> task.value;
			sp >> task.function;
			sp >> task.cycleFunction;

			tmp = "";

			// Debug
			std::cout << task.name << ": " << task.statString << " " << task.value << " " << task.function << " " << task.cycleFunction << endl;
		} else {
			tmp += ch;
		}
	}


	cout << "DB LOADED!" << endl;
};


int InitDefine::findDefault( string t ) {
	
	return 0;
};


int InitDefine::findProcedure( string t ) {
	if (t.compare("+") == 0) {
		return 1;
	} else if (t.compare("-") == 0) {
		return 2;
	} else if (t.compare("*") == 0) {
		return 3;
	} else if (t.compare("/") == 0) {
		return 4;
	}

	return -1;
};


float InitDefine::calc( float v1, int p, float v2 ) {
	switch (p) {
		case 1:
			return v1 + v2;

		case 2:
			return v1 - v2;

		case 3:
			return v1 * v2;
		
		case 4:
			return v1 / v2;
	}

	return 0;
};



