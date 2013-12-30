#ifndef MAPCAL_H
#define MAPCAL_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//��Ļ���ж��ٸ���ͼ��
#define MAPPOINTQUANTITY_X 1000
#define MAPPOINTQUANTITY_Y 800

//����һϵ�е�ͼ�������,�Ժ󽫻��и��ֻ���
enum DoohSpecies{AIR, ROCK, SOFTLAND, LADDER, BOOKESTRADE};

class MapCal 
{
public :
	MapCal(const char* MapFile)
	{
		string species;
		int x, y = 0;

		ifstream file(MapFile, ios :: in);
		while(file >> x >> y >> species)
		{
			if(species == "ROCK")
				map[y * MAPPOINTQUANTITY_X + x] = ROCK;
			if(species == "LADDER")
				map[y * MAPPOINTQUANTITY_X + x] = LADDER;
			if(species == "AIR")
				map[y * MAPPOINTQUANTITY_X + x] = AIR;
		}

		file.close();
	};

	DoohSpecies* getMap()
	{
		return map;
	};

private :
	DoohSpecies map[MAPPOINTQUANTITY_X * MAPPOINTQUANTITY_Y];
};

#endif