#include <iostream>
#include <string>
#include <ext/hash_map>

#include "Lib/Stat.h"
#include "Lib/DefCore.h"

using namespace __gnu_cxx;


class InitDefine {
	hash_map<std::string, Stat> RootStat;
	hash_map<std::string, DefCore> RootDefCore;

};

