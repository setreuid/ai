#include "start.h"



int main()
{
	char ch;
	cout << "AI World 2015. START!" << endl;


	/**
	 * Load DB
	 */
	coredb = new InitDefine();
	coredb->loadDB();


	/**
	 * Create Npcs
	 */
	npc *n = new npc(coredb->getRootTask());
	n->initNpc(coredb->getRootStat());
	n->start();



	// if Type AnyKey with NewLine, Exit
	cin >> ch;

	return 0;
}




