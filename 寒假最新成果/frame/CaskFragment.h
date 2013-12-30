#ifndef CASK_FRAGMENT_H
#define CASK_FRAGMENT_H

#include "Doohickey.h"

#define CASK_FRAGMENT_HEIGHT 50
#define CASK_FRAGMENT_WIDTH  30

class CaskFragment : public Doohickey
{
public :
	CaskFragment( float, float );

	void ToMapCal( DoohSpecies* );

	GameState logic( Player* , DoohSpecies* );

	void render();

private :
	static int quantity;
};

#endif