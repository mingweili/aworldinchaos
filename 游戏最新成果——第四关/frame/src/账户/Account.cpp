#include "..\\..\\include\\账户\\Account.h"

Account* Account :: instance = NULL;
int Account :: level_id = 0;
string Account :: PlayerName = "";

Account :: Account(string _PlayerName)
{
	PlayerName = _PlayerName;
	for(int index = 0; index < 10; ++index)
		properties[index] = NULL;
	getDataFromFile();
}

Account* Account :: getAccount(string _PlayerName)
{
	if( (!instance) || (_PlayerName != "" && _PlayerName != PlayerName) )
		instance = new Account(_PlayerName);
	return instance;
}

void Account :: getDataFromFile()
{
	string FileName = "D:\\" + PlayerName + ".txt";
	ifstream AccountFile(FileName.c_str(), ios :: in);
	
	AccountFile >> level_id;
	int index = -1;
	string str = "";
	while(AccountFile >> str)
	{
		//若干道具，若该用户有某个道具，就新建一个，勿忘木桶
		if(str == "_KEY")
			properties[_KEY] = new _Key();
		else if(str == "_PESTICIDE")
			properties[_PESTICIDE] = new _Pesticide();
		else if(str == "_MOBILE_LADDER")
			properties[_MOBILE_LADDER] = new _MobileLadder();
	}
	AccountFile.close();
}

void Account :: setPlayerList(string* _PlayerList)
{
	memcpy(PlayerList, _PlayerList, sizeof(_PlayerList));
}

void Account :: getPlayerList(string* _PlayerList) const
{
	memcpy(_PlayerList, PlayerList, sizeof(PlayerList));
}

int Account :: getLevelId()
{
	return level_id;
}

void Account :: setLevelId(int _level_id)
{
	level_id = _level_id;
}

void Account :: AddProperty(PropertyName name)
{
	switch (name)
	{
	case _KEY :
		properties[name] = new _Key();
		break;
	case _MOBILE_LADDER :
		properties[name] = new _MobileLadder();
		break;
	case _PESTICIDE :
		properties[name] = new _Pesticide();
		break;
	case _CASK :
		properties[name] = new _Cask();
		break;
	case _TORTOISE1 :
		properties[name] = new _Tortoise1();
		break;
	case _TORTOISE2 :
		properties[name] = new _Tortoise2();
		break;
	case _TORTOISE3 :
		properties[name] = new _Tortoise3();
		break;
	case _TORTOISE4 :
		properties[name] = new _Tortoise4();
		break;

	//等等，是一些道具
	}
}

Property* Account :: getProperty(PropertyName name)
{
	return properties[name];
}

void Account :: PropertyLogic(Player* player, DoohSpecies* map)
{
	int index = 0;
	while(index < 10)
	{
		if(properties[index] != NULL && properties[index]->getUsing())
			properties[index]->logic(player, map);
		++index;
	}
}

void Account :: PropertyRender()
{
	for(int index = 0; index < 10; ++index)
	{
		if(properties[index] != NULL)
			properties[index] -> render();
	}
}