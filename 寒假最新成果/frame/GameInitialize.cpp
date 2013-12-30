#include "GameInitialize.h"

void GameInitialize()
{

	//���ó�ʼֵ
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_LOGFILE,         "��⽵�����__������־.log");
	hge->System_SetState(HGE_FPS,             50);
	hge->System_SetState(HGE_WINDOWED,        false);
	hge->System_SetState(HGE_HIDEMOUSE,       false);
	hge->System_SetState(HGE_SCREENWIDTH,     1280);
	hge->System_SetState(HGE_SCREENHEIGHT,    800);
	hge->System_SetState(HGE_SCREENBPP,       32);
	hge->System_SetState(HGE_ZBUFFER,         true);

	//���ļ��ж�����һ������Ϸʱ�Ĵ浵
	//����ϴ��д浵����ֱ�ӽ������˵�
	if(InitializeFromFile())
	{
		//�ڳ�ʼ����ʱ�����������趨Ϊ���˵�����
		hge->System_SetState(HGE_RENDERFUNC, RenderFunc_menu);
		hge->System_SetState(HGE_FRAMEFUNC, FrameFunc_menu);
	}
	else  
	{
		//�����½��û��Ĵ��ڣ����½����û�����GameInfo.txt��
		int a;
	}

	if(hge->System_Initiate()) 
	{
		//��ʼ����Դ��������������Դ
		hge -> Resource_Load("resources.res");

		//��ʼ��Ϸ����Ⱦ�����ֻ���
		hge -> System_Start();
	}
	else
	{
		MessageBox(NULL, "Game can't be initialized successful", "WARNING", MB_OK);
		exit(1);//�Ժ������쳣����
	}
}

bool InitializeFromFile()
{

	ifstream GameInfo("D:\\GameInfo.txt"/*��ʱ��ôд*/, ios :: in);

	if(GameInfo)
	{

		//��ȡ��һ���û�����Ĭ���û�
		string CurrentPlayerName;
		GameInfo >> CurrentPlayerName;
		Account* AccountNow = Account :: getAccount(CurrentPlayerName);

		//��ȡ�û��б�
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

