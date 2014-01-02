#ifndef SCENE_H
#define SCENE_H

#include "..\\资源管理\\ResourceManager.h"
#include "..\\账户\\Account.h"

#include "Dimensionality.h"
#include "..\\维度转换\\BackGround1.h"
#include "..\\维度转换\\BackGround3.h"
#include "..\\维度转换\\BackGround4.h"

enum SceneState{NORMAL, TRANSFORM, PASS};

bool FrameFunc_scene();
bool RenderFunc_scene();

class Scene
{	
public :
	static Scene* getScene(unsigned int = 0);							//µ¥ÀýÄ£Ê½£¬µÃµ½³¡¾°¶ÔÏó

	inline Dimensionality* getDimenNow() const { return DimenNow; };    //È¡µÃµ±Ç°Î¬¶È

	inline SceneState getState() const { return state; };				//È¡µÃ³¡¾°µÄ×´Ì¬

	inline void setState( SceneState _state ) { state = _state; };		//ÉèÖÃ³¡¾°µÄ×´Ì¬

	void TransformJudge( Player* );										//ÅÐ¶ÏÊó±êÊÖÊÆ

	BackGround* background;												//Î¬¶È×ª»¯µÄÀà¾ä±ú

	hgeFont* getFont();

	int getDimenNOWID();												//È¡µÃµ±Ç°Î¬¶ÈµÄ±àºÅ

private :
	static Scene* instance;
	Scene(unsigned int = 0);                                      //¹¹Ôìº¯Êý£¬³õÊ¼»¯³¡¾°¼°Î¬¶È¡¢»ú¹Ø
	void initialize();                                                  //¾ßÌåµÄ³õÊ¼»¯º¯Êý

	static unsigned int scene_id;										//ÓÃÀ´¼ÇÂ¼¸Ã³¡¾°µÄ×ª»»·½Ê½

	int DimenQuantity;													//Î¬¶ÈµÄÊýÁ¿
	Dimensionality* dimens[10];											//´æ·ÅÎ¬¶ÈÖ¸ÕëµÄÊý×é
	Dimensionality* DimenNow;											//´æ·Åµ±Ç°µÄÎ¬¶È

	MapCal* aMapCal;													//³¡¾°¶ÔÓ¦µÄÐéÄâµØÍ¼Àà
	
	SceneState state;													//³¡¾°µÄ×´Ì¬

	hgeFont* fnt;
};

#endif