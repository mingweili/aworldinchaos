#include "GameInitialize.h"

void GameInitialize()
{

	//设置初始值
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_LOGFILE,         "馄饨的世界__程序日志.log");
	hge->System_SetState(HGE_FPS,             50);
	hge->System_SetState(HGE_WINDOWED,        false);
	hge->System_SetState(HGE_HIDEMOUSE,       false);
	hge->System_SetState(HGE_SCREENWIDTH,     1280);
	hge->System_SetState(HGE_SCREENHEIGHT,    800);
	hge->System_SetState(HGE_SCREENBPP,       32);
	hge->System_SetState(HGE_ZBUFFER,         true);

	//从文件中读出上一次玩游戏时的存档
	//如果上次有存档，则直接进入主菜单
	if(InitializeFromFile())
	{
		//在初始化的时候将两个函数设定为主菜单函数
		hge->System_SetState(HGE_RENDERFUNC, RenderFunc_menu);
		hge->System_SetState(HGE_FRAMEFUNC, FrameFunc_menu);
	}
	else  
	{
		//出现新建用户的窗口，将新建的用户存入GameInfo.txt中
		int a;
	}

	if(hge->System_Initiate()) 
	{
		//初始化资源管理器，加载资源
		hge -> Resource_Load("resources.res");

		//开始游戏的渲染，出现画面
		hge -> System_Start();
	}
	else
	{
		MessageBox(NULL, "Game can't be initialized successful", "WARNING", MB_OK);
		exit(1);//以后尝试用异常处理
	}
}

bool InitializeFromFile()
{

	ifstream GameInfo("D:\\GameInfo.txt"/*暂时这么写*/, ios :: in);

	if(GameInfo)
	{

		//获取上一个用户当做默认用户
		string CurrentPlayerName;
		GameInfo >> CurrentPlayerName;
		Account* AccountNow = Account :: getAccount(CurrentPlayerName);

		//获取用户列表
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

