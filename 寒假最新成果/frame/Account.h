#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <fstream>
#include <string>

#include "_Key.h"
#include "_MobileLadder.h"
#include "_Pesticide.h"

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