#include "InitDefine.h"



public InitDefine::InitDefine() {
	RootStat = new hash_map<string, Stat>();
	RootDefCore = new hash_map<string, DefCore>();
};


public float InitDefine::function( String val ) {
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


private findDefault( string t ) {
	

};


private int InitDefine::findProcedure( string t ) {
	if (t.compare("+") {
		return 1;
	} else if (t.compare("-") {
		return 2;
	} else if (t.compare("*") {
		return 3;
	} else if (t.compare("/") {
		return 4;
	} else if (t.compare("%") {
		return 5;
	}

	return -1;
};


private InitDefine::calc( float v1, int p, float v2 ) {
	switch (p) {
		case 1:
			return v1 + v2;

		case 2:
			return v1 - v2;

		case 3:
			return v1 * v2;
		
		case 4:
			return v1 / v2;

		case 5:
			return v1 % v2;
	}

	return 0;
};



