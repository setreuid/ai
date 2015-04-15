#include "start.h"



int main()
{
	char ch;
	cout << "AI World 2015. START!" << endl;

	npcs = new multimap<string, npc>();

	/**
	 * Load DB
	 */
	coredb = new InitDefine();
	coredb->loadDB();


	/**
	 * Create Npcs
	 */
	npc n = npc(coredb, npcs);
	n.initNpc();
	n.start();




	// if Type AnyKey with NewLine, Exit
	cin >> ch;

	return 0;
}




