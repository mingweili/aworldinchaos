#include "ResourceManager.h"

ResourceManager :: ResourceManager( HGE* HGEPtr )
{
	HGEPtr -> Resource_Load( "resources.res" );
	ResourceManagerPtr = new hgeResourceManager( "resources.res" );//新建一个资源管理器
}

HEFFECT ResourceManager :: getEffect( const char* EffectName ) const
{
	return ResourceManagerPtr -> GetEffect( EffectName );
}

HTEXTURE ResourceManager :: getTexture( const char* TextureName ) const
{
	return ResourceManagerPtr -> GetTexture( TextureName );
}

HMUSIC ResourceManager :: getMusic( const char* MusicName ) const
{
	return ResourceManagerPtr -> GetMusic( MusicName );
}

HSTREAM ResourceManager :: getStream( const char* StreamName ) const
{
	return ResourceManagerPtr -> GetStream( StreamName );
}

hgeSprite* ResourceManager :: getSpritePtr( const char*SpriteName ) const
{
	return ResourceManagerPtr -> GetSprite( SpriteName );
}

hgeFont* ResourceManager :: getFont( const char*FontName ) const
{
	return ResourceManagerPtr -> GetFont( FontName );
}

hgeParticleSystem* ResourceManager :: getParticleSystemPtr( const char* ParticleSystemName ) const
{
	return ResourceManagerPtr -> GetParticleSystem( ParticleSystemName );
}

hgeAnimation* ResourceManager :: getAnimation( const char* AnimationName ) const
{
	return ResourceManagerPtr -> GetAnimation( AnimationName );
}



