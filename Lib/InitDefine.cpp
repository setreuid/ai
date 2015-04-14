#include "InitDefine.h"



InitDefine::InitDefine() {
	RootStat = new multimap<string, dbStat>();
	RootTask = new multimap<string, dbTask>();
};

multimap<string, dbStat>* InitDefine::getRootStat() {
	return this->RootStat;
};

multimap<string, dbTask>* InitDefine::getRootTask() {
	return this->RootTask;
};




/**
 * 우선순위 연산 함수
 */

float InitDefine::function( dbTask task, npc *n ) {
	int i;
	string tmp = "";
	float ret = -1;
	float value = 0;
	int ret2 = -1;
	int procedure = -1;

	string val = task.function;

	for (i=0 ; i<val.size() ; i++) {
		tmp += val.at(i);

		//cout << tmp << endl;
		
		// Task, 수식, Npc
		if ((ret = findDefault(task, tmp, n)) != -1) {
			if (procedure != -1) {
				value = calc (value, procedure, ret);				// 우선순위 연산 수식 계산
				procedure = ret2 = ret = -1;
			} else {
				value = ret;
			}

			tmp = "";
		} else if ((ret2 = findProcedure(tmp)) != -1) {
			procedure = ret2;
			tmp = "";
		} else if (i >= val.size()-1) {								// 마지막 연산부는 숫자도 가능하다
			ret = StringToNumber<float>(tmp.c_str());
			value = calc (value, procedure, ret);

			//cout << task.statString << ": " << value << " = " << value << " " << procedure << " " << ret << endl;
			break;
		}
	}

	return value;
};


void InitDefine::loadDB() {
	ifstream dbstat("Res/stat.txt");
	ifstream dbtask("Res/task.txt");

	std::string tmp = "";
	char ch;
	int i=0;

	// Load stat defines
	while (!dbstat.eof()) {
		dbstat.get(ch);
		if (ch == '\n') {
			dbStat stat;
			stringstream sp(tmp);

			stat.no = i++;
			sp >> stat.name;
			sp >> stat.maxValue;
			sp >> stat.value;
			sp >> stat.cycleValue;

			if (stat.name.compare("") != 0) {
				RootStat->insert (pair<string, dbStat>(stat.name, stat));
				
				// Debug
				//cout << stat.name << ": " << stat.maxValue << " / " << stat.value << " / " << stat.cycleValue << endl;
			}

			tmp = "";

		} else {
			tmp += ch;
		}
	}

	ch = i = 0;
	tmp = "";

	// Load task defines
	while (!dbtask.eof()) {
		dbtask.get(ch);
		if (ch == '\n') {
			dbTask task;
			stringstream sp(tmp);

			task.no = i++;
			sp >> task.name;
			sp >> task.statString;
			sp >> task.value;
			sp >> task.function;
			sp >> task.cycleFunction;

			if (task.name.compare("") != 0) {
				RootTask->insert (pair<string, dbTask>(task.name, task));
				
				// Debug
				//cout << task.name << ": " << task.statString << " / " << task.value << " / " << task.function << " / " << task.cycleFunction << endl;
			}

			tmp = "";

		} else {
			tmp += ch;
		}
	}


	cout << "DB LOADED!" << endl;
};


int InitDefine::findDefault( dbTask task, string t, npc *n ) {
	dbStat tmp_stat = n->getStatus(task.statString);

	if (!t.compare("maxValue")) {
		return tmp_stat.maxValue;
	} else if (!t.compare("value")) {
		return tmp_stat.value;
	}

	return -1;
};


int InitDefine::findProcedure( string t ) {

	if (!t.compare("+")) {
		return 1;
	} else if (!t.compare("-")) {
		return 2;
	} else if (!t.compare("*")) {
		return 3;
	} else if (!t.compare("/")) {
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



