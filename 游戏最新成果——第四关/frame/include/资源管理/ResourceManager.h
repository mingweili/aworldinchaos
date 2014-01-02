#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "hge.h"
#include "hgefont.h"
#include "hgesprite.h"
#include "hgeresource.h"

class ResourceManager
{
public :

	static hgeResourceManager* ResourceManagerPtr;                      //资源管理Æ÷µÄÖ¸Õë

	static HEFFECT getEffect( const char* );                            //È¡µÃÉùÒôµÄÐ§¹û¾ä±ú

	static HTEXTURE getTexture( const char* );						    //È¡µÃÎÆÀí¾ä±ú

	static HMUSIC getMusic( const char* );							    //È¡µÃÒôÀÖ¾ä±ú

	static HSTREAM getStream( const char* );                            //È¡µÃÒôÆµÁ÷¾ä±ú

	static hgeSprite* getSpritePtr( const char* );					    //È¡µÃ¾«ÁéÖ¸Õë

	static hgeFont* getFont( const char* );						        //È¡µÃ×ÖÌåÖ¸Õë

	static hgeParticleSystem* getParticleSystemPtr( const char* ) ;     //È¡µÃÁ£×ÓÏµÍ³Ö¸Õë

	static hgeAnimation* getAnimation( const char* );                   //È¡µÃ¶¯»­µÄÖ¸Õë
};


#endif