#include "Scene.h"

bool FrameFunc_scene()
{
	float dt = hge -> Timer_GetDelta();

	////此处暂定为按“E”键切换场景“scene”
	int level_id = Account :: getLevelId();
	if(hge -> Input_GetKeyState(HGEK_E))
		Account :: setLevelId(++level_id);

	//暂时将此作为开启道具的方法
	if(hge -> Input_GetKeyState(HGEK_K))
		Account :: getAccount()->getProperty(_KEY) -> setUsing(true);
	
	//通过单件模式取得场景、小人的实例
	Scene* SceneNow = Scene :: getScene(level_id);
	Player* thePlayer = Player :: getPlayer(level_id);

	//鼠标手势的检测，依托于当前场景的调用
	SceneNow -> TransformJudge(thePlayer);

	//取得当前的维度
	Dimensionality* DimenNow = SceneNow -> getDimenNow();

	//小人的输入检测
	thePlayer -> KeyboardInput();

	//小人撞墙检测
	HitMap(thePlayer, DimenNow -> getMap());

	//如果当前没有进行维度转换，则正常进行逻辑处理
	if (SceneNow -> getState() == NORMAL)
	{
		//此处是当前维度的所有可用机关的逻辑调用
		GameState gs = DimenNow -> DoohLogic(thePlayer);
		switch(gs)
		{
		case SUCCESS :
			//如果过关了，就将关卡数加1
			Account :: setLevelId(++level_id);
			Scene :: getScene(level_id);//临时增加一个语句，可删
			break;
		case DEAD :
			//如果死了，另行讨论
			exit(0);
		case GOON :
		default :
			break;
		}

		//道具的逻辑判断
		Account :: getAccount() -> PropertyLogic(thePlayer, DimenNow->getMap());
	}
 
	//根据状态的不同，更新小人的位置
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

	//场景地图的渲染
	SceneNow->background->BackGroundRender();
	//维度的渲染
	if(SceneNow -> getState() == NORMAL)
		SceneNow -> getDimenNow() -> DoohRender();

	//小人的渲染函数
	thePlayer -> render();

	/*s = get(x, y);
	fnt -> printf(10, 10, HGETEXT_LEFT, "self：%s", s);
	s = get(x - 30, y);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\nleft：%s", s);
	s = get(x + 30, y);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\n\nright：%s", s);
	s = get(x, y + 43);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\n\n\ndown：%s", s);*/

	//显示小人的真实的坐标：
	SceneNow -> getFont() -> printf(10, 10, HGETEXT_LEFT, "\n\n\n\n\n\noooo：%.3f, %.3f", thePlayer -> getX(), thePlayer -> getY());
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
	//加载字体
	fnt = ResourceManager :: getFont("fnt");

	//此处还应有相应图片精灵的加载，再说
	string dooh;
	string MapFileAddr;

	float dooh_x, dooh_y;//此处代表了机关在地图中的位置

	string FileName = "..\\Debug\\resources\\Scene&Map\\scene" + *(new string(1, scene_id + '0')) + ".txt";
	ifstream SceneFile(FileName.c_str(), ios :: in);

	//初始化地图
	getline(SceneFile, MapFileAddr);
	aMapCal = new MapCal(MapFileAddr.c_str());

	//确定场景的维度转化方式
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
		//后面一系列的机关被加载
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