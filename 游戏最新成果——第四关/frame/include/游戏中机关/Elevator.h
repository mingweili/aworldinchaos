#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Doohickey.h"

class Elevator : public Doohickey
{
public :
	Elevator( float , float );					

	void ToMapCal( DoohSpecies* );
	
	GameState logic(Player*, DoohSpecies* );

	void render();

private :
	float dy;
};

#endif