#include "..\\..\\include\\资源管理\\ResourceManager.h"

hgeResourceManager* ResourceManager :: ResourceManagerPtr = new hgeResourceManager( "resources.res" );

HEFFECT ResourceManager :: getEffect( const char* EffectName )
{
	return ResourceManagerPtr -> GetEffect( EffectName );
}

HTEXTURE ResourceManager :: getTexture( const char* TextureName )
{
	return ResourceManagerPtr -> GetTexture( TextureName );
}

HMUSIC ResourceManager :: getMusic( const char* MusicName )
{
	return ResourceManagerPtr -> GetMusic( MusicName );
}

HSTREAM ResourceManager :: getStream( const char* StreamName )
{
	return ResourceManagerPtr -> GetStream( StreamName );
}

hgeSprite* ResourceManager :: getSpritePtr( const char* SpriteName )
{
	return ResourceManagerPtr -> GetSprite( SpriteName );
}

hgeFont* ResourceManager :: getFont( const char*FontName )
{
	return ResourceManagerPtr -> GetFont( FontName );
}

hgeParticleSystem* ResourceManager :: getParticleSystemPtr( const char* ParticleSystemName )
{
	return ResourceManagerPtr -> GetParticleSystem( ParticleSystemName );
}

hgeAnimation* ResourceManager :: getAnimation( const char* AnimationName )
{
	return ResourceManagerPtr -> GetAnimation( AnimationName );
}