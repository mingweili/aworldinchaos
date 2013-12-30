#ifndef GLOBAL_H
#define GLOBAL_H
#include "hge.h"
#include "ResourceManager.h"
#include "BackGround1.h"

HGE* hge;
BackGround1 *background1;
//新建一个资源管理器
ResourceManager* ResourceManagerPtr;

HEFFECT snd;
float dt = 0;
enum KEYDIRECTION{KEY_LEFT, KEY_RIGHT};
KEYDIRECTION KeyDirection;
#endif