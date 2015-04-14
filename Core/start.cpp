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
	npc *n = new npc();
	n->initNpc(coredb->getRootStat());


	float res = coredb->function ( coredb->getRootTask()->find("일하기")->second, n );
	cout << "RESULT " << res << endl;

	


	n->start();

	// if Type AnyKey with NewLine, Exit
	cin >> ch;

	return 0;
}




