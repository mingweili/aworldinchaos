#include "MapCal.h"

MapCal :: MapCal(const char* MapFile)
{
	MakeNull();
	string species;
	int x, y = 0;

	ifstream file(MapFile, ios :: in);
	while(file >> x >> y >> species)
		map[y * MAPPOINTQUANTITY_X + x] = ROCK;

	file.close();
}

void MapCal :: MakeNull()
{
	for(int index = 0; index < MAPPOINTQUANTITY_X * MAPPOINTQUANTITY_Y; ++index)
		map[index] = AIR;
}

