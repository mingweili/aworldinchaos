#ifndef DOOR_H
#define DOOR_H


#include "Doohickey.h"

#define DOOR_HEIGHT 100
#define DOOR_WIDTH  60

class Door : public Doohickey
{
public :
	Door( float, float );

	void ToMapCal( DoohSpecies* );

	GameState logic( Player* , DoohSpecies* );

	void render();
};

#endif