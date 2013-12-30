#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <fstream>
#include <string>

#include "..\\��Ϸ�е���\\_Key.h"
#include "..\\��Ϸ�е���\\_MobileLadder.h"
#include "..\\��Ϸ�е���\\_Pesticide.h"
#include "..\\��Ϸ�е���\\_Cask.h"
#include "..\\��Ϸ�е���\\_Tortoise1.h"
#include "..\\��Ϸ�е���\\_Tortoise2.h"
#include "..\\��Ϸ�е���\\_Tortoise3.h"
#include "..\\��Ϸ�е���\\_Tortoise4.h"

using namespace std;

class Account 
{
public :
	static Account* getAccount(string =	"");
	void getDataFromFile();
	static int getLevelId();
	static void setLevelId(int);

	void setPlayerList(string*);
	void getPlayerList(string*) const;
	
	void PropertyLogic(Player*, DoohSpecies*);
	void PropertyRender();
	void AddProperty(PropertyName name);
	Property* getProperty(PropertyName name);

private :
	Account(string);
	static Account* instance;
	static string PlayerName;

	string* PlayerList;
	Property* properties[10];

	static int level_id;
};

#endif