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

	
	HEFFECT getEffect( const char* ) const;                            //ȡ��������Ч�����

	HTEXTURE getTexture( const char* ) const;						   //ȡ��������

	HMUSIC getMusic( const char* ) const;							   //ȡ�����־��

	HSTREAM getStream( const char* ) const;                            //ȡ����Ƶ�����

	hgeSprite* getSpritePtr( const char* ) const;					   //ȡ�þ���ָ��

	hgeFont* getFont( const char* ) const;						       //ȡ������ָ��

	hgeParticleSystem* getParticleSystemPtr( const char* ) const ;     //ȡ������ϵͳָ��

	hgeAnimation* getAnimation( const char* ) const;                   //ȡ�ö�����ָ��
};

#endif