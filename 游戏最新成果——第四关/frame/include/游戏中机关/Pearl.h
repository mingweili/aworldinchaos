#ifndef PEARL_H
#define PEARL_H


#include "Doohickey.h"

#define PEARL_HEIGHT 80
#define PEARL_WIDTH  100

class Pearl : public Doohickey
{
public :
	Pearl( float, float );

	void ToMapCal( DoohSpecies* );

	GameState logic( Player* , DoohSpecies* );

	void render();
};

#endif