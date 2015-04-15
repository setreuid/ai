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


