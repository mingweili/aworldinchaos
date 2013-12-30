#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream MapFile("D:\\MapFile1.txt", ios :: out);
    for(int x = 0; x < 1000; ++x)
    {
        for(int y = 0; y < 800; ++y)
        {
            MapFile << x << " " << y << " ";
            if( x <= 5 || y <= 5 || x >= 995 || y >= 795 ||
                (x >= 0 && x <= 499 && y >= 200 && y <= 240) ||
                (x >= 740 && x <= 999 && y >= 200 && y <= 240)
              )
                MapFile << "ROCK" << endl;
            else
                MapFile << "AIR" << endl;
        }
    }
    MapFile.close();
    return 0;
}
