#include "start.h"



int main()
{
	cout << "AI World 2015. START!" << endl;


	/**
	 * Load DB
	 */
	coredb = new InitDefine();
	coredb.loadDB();

	return 0;
}




