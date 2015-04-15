#include "class_npc.h"


npc::npc( InitDefine *df, multimap<string, npc> * ns ) {
	coredb = df;
	npcs = ns;

	taskTable = coredb->getRootTask();	
	npcs->insert( pair<string, npc>(this->getName(), *this) );
};


void npc::newNpc() {
	npc *n = new npc(coredb, npcs);
	n->initNpc();
	n->start();
};


string npc::getName() {
	return this->name;
};


void npc::initNpc() {
	multimap<string, dbStat> *st = coredb->getRootStat();
	status = new multimap<string, dbStat>();
	srand ((unsigned int)time(NULL));

	multimap<string, dbStat>::iterator i;
	for (i=st->begin(); i!=st->end(); ++i) {
		// Insert Default Stat
		status->insert (pair<string, dbStat>( i->first, i->second ));
	}

	this->prTaskTable = new multimap<float, dbTask>();

	this->name = "NPC";
	this->name.append (to_string((rand() % 1000) + 1));

	//this->setStatusValue("증식치", (rand() % 3) + 1);
};


dbStat npc::getStatus(string key) {
	multimap<string, dbStat> :: const_iterator result = status->find(key);
	
	if (result != status->end()) {
		return result->second;
	}

	return dbStat();
};


npc::npc() {
	//
};


/**
 * 우선순위에 의해 일을 시행한다
 */

void *npc::doTask(void *ptr) {
	npc *n = (npc*) ptr;
	n->prTaskTable->clear();

	for (n->it = n->taskTable->begin(); n->it != n->taskTable->end() ; ++(n->it)) {
		n->prTaskTable->insert (pair<float, dbTask>(n->function(n->it->second), n->it->second));
	}

	multimap<float, dbTask>::iterator e = n->prTaskTable->end();
	e--;

	n->todoTask (e->second);
	return 0;
};


/**
 * todoTask
 */

void npc::todoTask( dbTask task ) {
	int i;
	string tmp = "";
	dbStat ret;
	dbStat statValue;
	float value = 0;
	int ret2 = -1;
	int procedure = -1;

	string val = task.cycleFunction;

	if (!val.compare("fnewNpc")) {
		if (this->getStatus("증식치").value > 0) {
			this->newNpc();
			this->setStatusValue("증식치", this->getStatus("증식치").value-1);
		}
		return;
	}

	for (i=0 ; i<val.size() ; i++) {
		tmp += val.at(i);

		// cout << tmp << endl;
		
		// Task, 수식, Npc
		if ((ret = getStatus(tmp)).name.compare("") != 0) {
			if (procedure != -1) {
				value = calc (statValue.value, procedure, ret.value);
				// cout << value << " = " << statValue.value << " " << ret.value << endl;
				setStatusValue (statValue.name, value);

				procedure = ret2 = -1;
			} else {
				statValue = ret;
			}

			tmp = "";
		} else if ((ret2 = findProcedure(tmp)) != -1) {
			procedure = ret2;
			tmp = "";
		} else if (i >= val.size()-1 || val.at(i) == '&') {
			if (val.at(i) == '&')
				tmp = tmp.substr (0, tmp.size()-1);
			value = StringToNumber<float>(tmp.c_str());
			value = calc (statValue.value, procedure, value);
			
			// cout << value << " = " << statValue.value << " " << value << endl;
			setStatusValue (statValue.name, value);

			procedure = ret2 = -1;
			tmp = "";
		}
	}

	return;
};


void npc::setStatusValue( string key, float val ) {
	multimap<string, dbStat> :: iterator result = status->find(key);
	
	if (result != status->end()) {
		result->second.value = val;
	}
};


/**
 * Thread
 */

void *npc::run(void *ptr) {
	npc *me = (npc *) ptr;

	while (1) {
		doTask(ptr);			// 우선순위 일 시행
		reduceProcess(ptr);		// 1 사이클에 따른 스탯 감산 수행

		sleep (1);
	};

	return 0;
};


void npc::start() {
	pthread_create(&thread, NULL, &npc::run, this);
};


/**
 * 사이클당 증감 스탯 적용
 */

void *npc::reduceProcess( void *ptr ) {
	npc *n = (npc *) ptr;

	for (n->is = n->status->begin(); n->is != n->status->end() ; ++(n->is)) {
		n->is->second.value += n->is->second.cycleValue;
	}
};


/**
 * 우선순위 연산 함수
 */

float npc::function( dbTask task ) {
	int i;
	string tmp = "";
	float ret = -1;
	float value = 0;
	int ret2 = -1;
	int procedure = -1;

	string val = task.function;

	for (i=0 ; i<val.size() ; i++) {
		tmp += val.at(i);

		// cout << tmp << endl;
		
		// Task, 수식, Npc
		if ((ret = findDefault(task, tmp)) != -1) {
			if (procedure != -1) {
				value = calc (value, procedure, ret);				// 우선순위 연산 수식 계산
				procedure = ret2 = ret = -1;
			} else {
				value = ret;
				// cout << ret << endl;
			}

			tmp = "";
		} else if ((ret2 = findProcedure(tmp)) != -1) {
			procedure = ret2;
			tmp = "";
		} else if (i >= val.size()-1) {								// 마지막 연산부는 숫자도 가능하다
			ret = StringToNumber<float>(tmp.c_str());
			value = calc (value, procedure, ret);

			// cout << task.statString << ": " << value << " = " << value << " " << procedure << " " << ret << endl;
			break;
		}
	}

	return value;
};


int npc::findDefault( dbTask task, string t ) {
	dbStat stat = this->getStatus(task.statString);

	if (!t.compare("maxValue")) {
		return stat.maxValue;
	} else if (!t.compare("value")) {
		return stat.value;
	} else {
		return -1;
	}
};


int npc::findProcedure( string t ) {

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


float npc::calc( float v1, int p, float v2 ) {
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



