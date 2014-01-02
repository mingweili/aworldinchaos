#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <fstream>
#include <string>

#include "..\\游戏中道具\\_Key.h"
#include "..\\游戏中道具\\_MobileLadder.h"
#include "..\\游戏中道具\\_Pesticide.h"
#include "..\\游戏中道具\\_Cask.h"
#include "..\\游戏中道具\\_Tortoise1.h"
#include "..\\游戏中道具\\_Tortoise2.h"
#include "..\\游戏中道具\\_Tortoise3.h"
#include "..\\游戏中道具\\_Tortoise4.h"

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