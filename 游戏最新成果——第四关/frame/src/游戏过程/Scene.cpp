#include "..\\..\\include\\游戏过程\\Scene.h"

bool FrameFunc_scene()
{
	float dt = hge -> Timer_GetDelta();

	////´Ë´¦ÔÝ¶¨Îª°´¡°E¡±¼üÇÐ»»³¡¾°¡°scene¡±
	int level_id = Account :: getLevelId();
	if(hge -> Input_GetKeyState(HGEK_E))
		Account :: setLevelId(++level_id);

	//ÔÝÊ±½«´Ë×÷Îª¿ªÆôµÀ¾ßµÄ·½·¨
	//¿ªÆôÉý½µÌÝµÄÔ¿³×£º
	if(hge -> Input_GetKeyState(HGEK_K))
		Account :: getAccount()->getProperty(_KEY) -> setUsing(true);
	//Ê¹ÓÃÄ¾Í°
	if(hge -> Input_GetKeyState(HGEK_C))
		Account :: getAccount()->getProperty(_CASK) -> setUsing(true);
	//Ê¹ÓÃ¿ÉÒÆ¶¯µÄÌÝ×Ó
	if(hge -> Input_GetKeyState(HGEK_M))
		Account :: getAccount()->getProperty(_MOBILE_LADDER) -> setUsing(true);
	//Ê¹ÓÃÉ±³æ¼Á
	if(hge -> Input_GetKeyState(HGEK_P))
		Account :: getAccount()->getProperty(_PESTICIDE) -> setUsing(true);
	
	//Í¨¹ýµ¥¼þÄ£Ê½È¡µÃ³¡¾°¡¢Ð¡ÈËµÄÊµÀý
	Scene* SceneNow = Scene :: getScene(level_id);
	Player* thePlayer = Player :: getPlayer(level_id);

	//Êó±êÊÖÊÆµÄ¼ì²â£¬ÒÀÍÐÓÚµ±Ç°³¡¾°µÄµ÷ÓÃ
	SceneNow -> TransformJudge(thePlayer);

	//È¡µÃµ±Ç°µÄÎ¬¶È
	Dimensionality* DimenNow = SceneNow -> getDimenNow();

	//Ð¡ÈËµÄÊäÈë¼ì²â
	thePlayer -> KeyboardInput();

	//Ð¡ÈË×²Ç½¼ì²â
	HitMap(thePlayer, DimenNow -> getMap());

	//Èç¹ûµ±Ç°Ã»ÓÐ½øÐÐ维度转换£¬ÔòÕý³£½øÐÐÂß¼­´¦Àí
	if (SceneNow -> getState() == NORMAL)
	{
		//´Ë´¦ÊÇµ±Ç°Î¬¶ÈµÄËùÓÐ¿ÉÓÃ»ú¹ØµÄÂß¼­µ÷ÓÃ
		GameState gs = DimenNow -> DoohLogic(thePlayer);
		switch(gs)
		{
		case SUCCESS :
			//Èç¹û¹ý¹ØÁË£¬¾Í½«¹Ø¿¨Êý¼Ó1
			Account :: setLevelId(++level_id);
			break;
		case DEAD :
			//Èç¹ûËÀÁË£¬ÁíÐÐÌÖÂÛ
			MessageBox(NULL, "¹þ¹þ", "ÄãËÀÁË£¬ÎÒ³É¹¦ÁË£¡£¡", MB_OK | MB_ICONERROR | MB_APPLMODAL);
			exit(0);
		case GOON :
		default :
			break;
		}

		//µÀ¾ßµÄÂß¼­ÅÐ¶Ï
		Account :: getAccount() -> PropertyLogic(thePlayer, DimenNow->getMap());
	}
 
	//¸ù¾Ý×´Ì¬µÄ²»Í¬£¬¸üÐÂÐ¡ÈËµÄÎ»ÖÃ
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

	//³¡¾°µØÍ¼µÄäÖÈ¾
	SceneNow->background->BackGroundRender();

	//Î¬¶ÈµÄäÖÈ¾
	if(SceneNow -> getState() == NORMAL)
	{
		SceneNow -> getDimenNow() -> DoohRender();

	//Ò»Ð©ÌØÊâµÀ¾ßµÄäÖÈ¾
		Account ::getAccount() -> PropertyRender();
	}


	//Ð¡ÈËµÄäÖÈ¾º¯Êý
	thePlayer -> render();

	hgeFont* fnt = SceneNow -> getFont();
	Dimensionality* DimenNow = SceneNow -> getDimenNow();
	char * s;
	s = get(x, y, DimenNow);
	fnt-> printf(10, 10, HGETEXT_LEFT, "self£º%s", s);
	s = get(x - 23, y, DimenNow);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\nleft£º%s", s);
	s = get(x + 23, y, DimenNow);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\n\nright£º%s", s);
	s = get(x, y + 31, DimenNow);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\n\n\ndown£º%s", s);

	//ÏÔÊ¾Ð¡ÈËµÄÕæÊµµÄ×ø±ê£º
	fnt -> printf(10, 10, HGETEXT_LEFT, "\n\n\n\n\n\noooo£º%.3f, %.3f", thePlayer -> getX(), thePlayer -> getY());
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
	//¼ÓÔØ×ÖÌå
	fnt = ResourceManager :: getFont("fnt");

	//´Ë´¦»¹Ó¦ÓÐÏàÓ¦Í¼Æ¬¾«ÁéµÄ¼ÓÔØ£¬ÔÙËµ
	string dooh;
	string MapFileAddr;

	float dooh_x, dooh_y;//´Ë´¦´ú±íÁË»ú¹ØÔÚµØÍ¼ÖÐµÄÎ»ÖÃ

	string FileName = "..\\Debug\\resources\\Scene&Map\\scene" + *(new string(1, scene_id + '0')) + ".txt";
	ifstream SceneFile(FileName.c_str(), ios :: in);

	//³õÊ¼»¯µØÍ¼
	getline(SceneFile, MapFileAddr);
	aMapCal = new MapCal(MapFileAddr.c_str());

	//È·¶¨³¡¾°µÄÎ¬¶È×ª»¯·½Ê½
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
		//ºóÃæÒ»ÏµÁÐµÄ»ú¹Ø±»¼ÓÔØ
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