#include "..\\..\\include\\��Ϸ����\\Scene.h"

bool FrameFunc_scene()
{
	float dt = hge -> Timer_GetDelta();

	////�˴��ݶ�Ϊ����E�����л�������scene��
	int level_id = Account :: getLevelId();
	if(hge -> Input_GetKeyState(HGEK_E))
		Account :: setLevelId(++level_id);

	//��ʱ������Ϊ�������ߵķ���
	//���������ݵ�Կ�ף�
	if(hge -> Input_GetKeyState(HGEK_K))
		Account :: getAccount()->getProperty(_KEY) -> setUsing(true);
	//ʹ��ľͰ
	if(hge -> Input_GetKeyState(HGEK_C))
		Account :: getAccount()->getProperty(_CASK) -> setUsing(true);
	//ʹ�ÿ��ƶ�������
	if(hge -> Input_GetKeyState(HGEK_M))
		Account :: getAccount()->getProperty(_MOBILE_LADDER) -> setUsing(true);
	//ʹ��ɱ���
	if(hge -> Input_GetKeyState(HGEK_P))
		Account :: getAccount()->getProperty(_PESTICIDE) -> setUsing(true);
	
	//ͨ������ģʽȡ�ó�����С�˵�ʵ��
	Scene* SceneNow = Scene :: getScene(level_id);
	Player* thePlayer = Player :: getPlayer(level_id);

	//������Ƶļ�⣬�����ڵ�ǰ�����ĵ���
	SceneNow -> TransformJudge(thePlayer);

	//ȡ�õ�ǰ��ά��
	Dimensionality* DimenNow = SceneNow -> getDimenNow();

	//С�˵�������
	thePlayer -> KeyboardInput();

	//С��ײǽ���
	HitMap(thePlayer, DimenNow -> getMap());

	//�����ǰû�н���ά��ת���������������߼�����
	if (SceneNow -> getState() == NORMAL)
	{
		//�˴��ǵ�ǰά�ȵ����п��û��ص��߼�����
		GameState gs = DimenNow -> DoohLogic(thePlayer);
		switch(gs)
		{
		case SUCCESS :
			//��������ˣ��ͽ��ؿ�����1
			Account :: setLevelId(++level_id);
			break;
		case DEAD :
			//������ˣ���������
			MessageBox(NULL, "����", "�����ˣ��ҳɹ��ˣ���", MB_OK | MB_ICONERROR | MB_APPLMODAL);
			exit(0);
		case GOON :
		default :
			break;
		}

		//���ߵ��߼��ж�
		Account :: getAccount() -> PropertyLogic(thePlayer, DimenNow->getMap());
	}
 
	//����״̬�Ĳ�ͬ������С�˵�λ��
	thePlayer -> UpdatePos(dt);
	
	return false;
}


char* get(int x ,int y, Dimensionality* DimenNow)
{
	char* s = NULL;
	DoohSpecies species = DimenNow -> MapSpecies(x, y);
	if(species == AIR)
		s = "AIR";
	else if(species == ROCK)
		s = "ROCK";
	else if(species == SOFTLAND)
		s = "SOFTLAND";
	else if(species == LADDER)
		s = "LADDER";
	else if(species == SEED)
		s = "Seed";
	return s;
}

bool RenderFunc_scene()
{
	unsigned int level_id = Account :: getLevelId();
	Scene* SceneNow = Scene :: getScene(level_id);
	Player* thePlayer = Player :: getPlayer(level_id);

	float x = thePlayer -> getX();
	float y = thePlayer -> getY();

	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);

	//������ͼ����Ⱦ
	SceneNow->background->BackGroundRender();

	//ά�ȵ���Ⱦ
	if(SceneNow -> getState() == NORMAL)
	{
		SceneNow -> getDimenNow() -> DoohRender();

	//һЩ������ߵ���Ⱦ
		Account ::getAccount() -> PropertyRender();
	}


	//С�˵���Ⱦ����
	thePlayer -> render();

	hgeFont* fnt = SceneNow -> getFont();
	Dimensionality* DimenNow = SceneNow -> getDimenNow();
	char * s;
	s = get(x, y, DimenNow);
	fnt-> printf(10, 10, HGETEXT_LEFT, "self��%s", s);
	s = get(x - 23, y, DimenNow);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\nleft��%s", s);
	s = get(x + 23, y, DimenNow);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\n\nright��%s", s);
	s = get(x, y + 31, DimenNow);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\n\n\ndown��%s", s);

	//��ʾС�˵���ʵ�����꣺
	fnt -> printf(10, 10, HGETEXT_LEFT, "\n\n\n\n\n\noooo��%.3f, %.3f", thePlayer -> getX(), thePlayer -> getY());
	hge->Gfx_EndScene();

	return false;
}

Scene* Scene :: instance = NULL;
unsigned int Scene :: scene_id = 0;

Scene* Scene :: getScene(unsigned int _scene_id)
{
	if( (_scene_id != scene_id) || (instance == NULL))
	{
		scene_id = _scene_id;
		instance = new Scene(_scene_id);
	}

	return instance;
}

Scene :: Scene(unsigned int _scene_id)
	: DimenNow(NULL), DimenQuantity(0), state(NORMAL)
{
	for(int index = 0; index < 10; ++index)
		dimens[index] = NULL;
	initialize();
}

void Scene :: initialize()
{
	//��������
	fnt = ResourceManager :: getFont("fnt");

	//�˴���Ӧ����ӦͼƬ����ļ��أ���˵
	string dooh;
	string MapFileAddr;

	float dooh_x, dooh_y;//�˴������˻����ڵ�ͼ�е�λ��

	string FileName = "..\\Debug\\resources\\Scene&Map\\scene" + *(new string(1, scene_id + '0')) + ".txt";
	ifstream SceneFile(FileName.c_str(), ios :: in);

	//��ʼ����ͼ
	getline(SceneFile, MapFileAddr);
	aMapCal = new MapCal(MapFileAddr.c_str());

	//ȷ��������ά��ת����ʽ
	switch (scene_id)
	{
	case 1 :
	case 2 :
		background = new BackGround1(hge, scene_id);
		break; 
	case 3 :
		background = new BackGround3(hge, scene_id);
		break;
	case 4 :
		background = new BackGround4(hge, scene_id);
		break;
	default :
		break;
	}

	while(SceneFile >> DimenQuantity >> dooh >> dooh_x >> dooh_y)
	{
		if(!dimens[DimenQuantity])
		{
			dimens[DimenQuantity] = new Dimensionality;
			dimens[DimenQuantity] -> setMap(aMapCal -> getMap());
		}
		//����һϵ�еĻ��ر�����
		dimens[DimenQuantity] -> AddDooh(dooh, dooh_x, dooh_y);

	}
	DimenNow = dimens[1];
	SceneFile.close();
}

void Scene :: TransformJudge(Player* player)
{
	if(player -> getSuper())
	{
		background -> MouseJudge();

		if(!background -> GetCurrentState())
		{
			DimenNow = dimens[background -> GetPicNum()];
			player -> setState(TRANSFORMING);
			state = TRANSFORM;
		}
		else
		{
			state = NORMAL;
			if(player -> getState() != DRILL)
				player -> setState(WALKING);
		}
	}
	background -> RenderPic();
}

hgeFont* Scene :: getFont()
{
	return fnt;
}

int Scene :: getDimenNOWID()
{
	return (DimenNow - dimens[1]) / sizeof(DimenNow) + 1;
}