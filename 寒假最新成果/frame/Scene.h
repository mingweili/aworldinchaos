#ifndef SCENE_H
#define SCENE_H

#include "ResourceManager.h"
#include "Account.h"

#include "Dimensionality.h"
#include "BackGround1.h"
#include "BackGround3.h"

enum SceneState{NORMAL, TRANSFORM, PASS};

bool FrameFunc_scene();
bool RenderFunc_scene();

class Scene
{	
public :
	static Scene* getScene(unsigned int = 0);							//单例模式，得到场景对象

	inline Dimensionality* getDimenNow() const { return DimenNow; };    //取得当前维度

	inline SceneState getState() const { return state; };				//取得场景的状态

	inline void setState( SceneState _state ) { state = _state; };		//设置场景的状态

	void TransformJudge( Player* );										//判断鼠标手势

	BackGround* background;												//维度转化的类句柄

	hgeFont* getFont();

private :
	static Scene* instance;
	Scene(unsigned int = 0);                                      //构造函数，初始化场景及维度、机关
	void initialize();                                                  //具体的初始化函数

	static unsigned int scene_id;														//用来记录该场景的转换方式

	int DimenQuantity;													//维度的数量
	Dimensionality* dimens[10];											//存放维度指针的数组
	Dimensionality* DimenNow;											//存放当前的维度

	MapCal* aMapCal;													//场景对应的虚拟地图类
	
	SceneState state;													//场景的状态

	hgeFont* fnt;
};

#endif