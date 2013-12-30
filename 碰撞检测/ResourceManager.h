#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "hge.h"
#include "hgefont.h"
#include "hgesprite.h"
#include "hgeresource.h"

class ResourceManager
{
private :
	hgeResourceManager* ResourceManagerPtr;

public :
	ResourceManager(HGE*);

	~ResourceManager();	

	
	HEFFECT getEffect( const char* ) const;                            //取得声音的效果句柄

	HTEXTURE getTexture( const char* ) const;						   //取得纹理句柄

	HMUSIC getMusic( const char* ) const;							   //取得音乐句柄

	HSTREAM getStream( const char* ) const;                            //取得音频流句柄

	hgeSprite* getSpritePtr( const char* ) const;					   //取得精灵指针

	hgeFont* getFont( const char* ) const;						       //取得字体指针

	hgeParticleSystem* getParticleSystemPtr( const char* ) const ;     //取得粒子系统指针

	hgeAnimation* getAnimation( const char* ) const;                   //取得动画的指针
};

#endif