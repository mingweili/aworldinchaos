#include "Scene.h"

bool FrameFunc_scene()
{
	float dt = hge -> Timer_GetDelta();

	////�˴��ݶ�Ϊ����E�����л�������scene��
	int level_id = Account :: getLevelId();
	if(hge -> Input_GetKeyState(HGEK_E))
		Account :: setLevelId(++level_id);

	//��ʱ������Ϊ�������ߵķ���
	if(hge -> Input_GetKeyState(HGEK_K))
		Account :: getAccount()->getProperty(_KEY) -> setUsing(true);
	
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
			Scene :: getScene(level_id);//��ʱ����һ����䣬��ɾ
			break;
		case DEAD :
			//������ˣ���������
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
		SceneNow -> getDimenNow() -> DoohRender();

	//С�˵���Ⱦ����
	thePlayer -> render();

	/*s = get(x, y);
	fnt -> printf(10, 10, HGETEXT_LEFT, "self��%s", s);
	s = get(x - 30, y);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\nleft��%s", s);
	s = get(x + 30, y);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\n\nright��%s", s);
	s = get(x, y + 43);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\n\n\ndown��%s", s);*/

	//��ʾС�˵���ʵ�����꣺
	SceneNow -> getFont() -> printf(10, 10, HGETEXT_LEFT, "\n\n\n\n\n\noooo��%.3f, %.3f", thePlayer -> getX(), thePlayer -> getY());
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
			state = NORMAL;
	}
	background -> RenderPic();
}

hgeFont* Scene :: getFont()
{
	return fnt;
}