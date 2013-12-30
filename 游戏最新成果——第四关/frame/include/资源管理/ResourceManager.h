#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "hge.h"
#include "hgefont.h"
#include "hgesprite.h"
#include "hgeresource.h"

class ResourceManager
{
public :

	static hgeResourceManager* ResourceManagerPtr;                      //资源管理器的指针

	static HEFFECT getEffect( const char* );                            //取得声音的效果句柄

	static HTEXTURE getTexture( const char* );						    //取得纹理句柄

	static HMUSIC getMusic( const char* );							    //取得音乐句柄

	static HSTREAM getStream( const char* );                            //取得音频流句柄

	static hgeSprite* getSpritePtr( const char* );					    //取得精灵指针

	static hgeFont* getFont( const char* );						        //取得字体指针

	static hgeParticleSystem* getParticleSystemPtr( const char* ) ;     //取得粒子系统指针

	static hgeAnimation* getAnimation( const char* );                   //取得动画的指针
};


#endif