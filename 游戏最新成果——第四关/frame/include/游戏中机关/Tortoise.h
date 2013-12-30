#ifndef TORTOISE_H
#define TORTOISE_H


#include "Doohickey.h"

#define TORTOISE_HEIGHT 60
#define TORTOISE_WIDTH  60

class Tortoise : public Doohickey
{
public :
	Tortoise( float, float );

	void ToMapCal( DoohSpecies* );

	GameState logic( Player* , DoohSpecies* );

	void render();
private :
	int DimenId;
	float dx;
	float dy;
};

#endif