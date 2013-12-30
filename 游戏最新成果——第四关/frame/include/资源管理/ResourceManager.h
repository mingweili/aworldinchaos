#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "hge.h"
#include "hgefont.h"
#include "hgesprite.h"
#include "hgeresource.h"

class ResourceManager
{
public :

	static hgeResourceManager* ResourceManagerPtr;                      //��Դ��������ָ��

	static HEFFECT getEffect( const char* );                            //ȡ��������Ч�����

	static HTEXTURE getTexture( const char* );						    //ȡ��������

	static HMUSIC getMusic( const char* );							    //ȡ�����־��

	static HSTREAM getStream( const char* );                            //ȡ����Ƶ�����

	static hgeSprite* getSpritePtr( const char* );					    //ȡ�þ���ָ��

	static hgeFont* getFont( const char* );						        //ȡ������ָ��

	static hgeParticleSystem* getParticleSystemPtr( const char* ) ;     //ȡ������ϵͳָ��

	static hgeAnimation* getAnimation( const char* );                   //ȡ�ö�����ָ��
};


#endif