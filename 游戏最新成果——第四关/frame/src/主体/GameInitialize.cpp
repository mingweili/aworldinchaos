#include "..\\..\\include\\主体\\GameInitialize.h"

void GameInitialize()
{

	//ÉèÖÃ³õÊ¼Öµ
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_LOGFILE,         "log.log");
	hge->System_SetState(HGE_FPS,             50);
	hge->System_SetState(HGE_WINDOWED,        false);
	hge->System_SetState(HGE_HIDEMOUSE,       false);
	hge->System_SetState(HGE_SCREENWIDTH,     1280);
	hge->System_SetState(HGE_SCREENHEIGHT,    800);
	hge->System_SetState(HGE_SCREENBPP,       32);
	hge->System_SetState(HGE_ZBUFFER,         true);

	//´ÓÎÄ¼þÖÐ¶Á³öÉÏÒ»´ÎÍæÓÎÏ·Ê±µÄ´æµµ
	//Èç¹ûÉÏ´ÎÓÐ´æµµ£¬ÔòÖ±½Ó½øÈëÖ÷²Ëµ¥
	if(InitializeFromFile())
	{
		//ÔÚ³õÊ¼»¯µÄÊ±ºò½«Á½¸öº¯ÊýÉè¶¨ÎªÖ÷²Ëµ¥º¯Êý
		hge->System_SetState(HGE_RENDERFUNC, RenderFunc_menu);
		hge->System_SetState(HGE_FRAMEFUNC, FrameFunc_menu);
	}
	else  
	{
		//³öÏÖÐÂ½¨ÓÃ»§µÄ´°¿Ú£¬½«ÐÂ½¨µÄÓÃ»§´æÈëGameInfo.txtÖÐ
		int a;
	}

	if(hge->System_Initiate()) 
	{
		//³õÊ¼»¯资源管理Æ÷£¬¼ÓÔØ×ÊÔ´
		hge -> Resource_Load("resources.res");

		//¿ªÊ¼ÓÎÏ·µÄäÖÈ¾£¬³öÏÖ»­Ãæ
		hge -> System_Start();
	}
	else
	{
		MessageBox(NULL, "Game can't be initialized successful", "WARNING", MB_OK);
		exit(1);//ÒÔºó³¢ÊÔÓÃÒì³£´¦Àí
	}
}

bool InitializeFromFile()
{

	ifstream GameInfo("D:\\GameInfo.txt", ios :: in);

	if(GameInfo)
	{

		//»ñÈ¡ÉÏÒ»¸öÓÃ»§µ±×öÄ¬ÈÏÓÃ»§
		string CurrentPlayerName;
		GameInfo >> CurrentPlayerName;
		Account* AccountNow = Account :: getAccount(CurrentPlayerName);

		//»ñÈ¡ÓÃ»§ÁÐ±í
		string* PlayerList = new string;
		int index = -1;
		while(GameInfo >> PlayerList[++index]);

		if(PlayerList[0] == CurrentPlayerName)
			AccountNow -> setPlayerList(PlayerList);
		GameInfo.close();

		return true;
	}
	else 
		return false;
}

