#ifndef SOFTLAND_H
#define SOFTLAND_H

#include "Doohickey.h"

class SoftLand : public Doohickey
{
public :
	SoftLand( float, float );

	void ToMapCal( DoohSpecies* );

	GameState logic(Player* player, DoohSpecies* map);

	void render();

private :
	unsigned int times_passed;
};

#endif 