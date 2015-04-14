#ifndef DBTASK_H
#define DBTASK_H

#include <iostream>
#include <string>
#include "dbStat.h"
using namespace std;


struct dbTask {
	int		no;
	string	name;
	string	statString;
	float	value;
	string	function;
	string	cycleFunction;
};

#endif



