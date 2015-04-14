#include <iostream>
#include <string>
#include <ext/hash_map>

#include "Lib/Stat.h"
#include "Lib/DefCore.h"

using namespace __gnu_cxx;


class InitDefine {
private:
	hash_map<std::string, Stat> RootStat;
	hash_map<std::string, DefCore> RootDefCore;

	calc( float, int, float );
	findProcedure( std::string );

public:
	InitDefine();
	
	function( std::string );
	
};

