#ifndef KEY_H
#define KEY_H


#include "Doohickey.h"

#define KEY_HEIGHT 100
#define KEY_WIDTH  60

class Key : public Doohickey
{
public :
	Key( float, float );

	void ToMapCal( DoohSpecies* );

	GameState logic( Player* , DoohSpecies* );

	void render();
};

#endif