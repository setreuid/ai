#include "start.h"



int main()
{
	cout << "AI World 2015. START!" << endl;


	/**
	 * Load DB
	 */
	coredb = new InitDefine();
	coredb->loadDB();


	/**
	 * Create Npcs
	 */
	npc *n = new npc();
	n->initNpc(coredb);


	return 0;
}




