#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream MapFile("D:\\MapFile1.txt", ios :: out);
    for(int x = 0; x < 1000; ++x)
    {
        for(int y = 0; y < 800; y++)
        {
            if(x <= 5 || y <= 5 || x >= 995 || y >= 795
               ||(y >= 200 && y <= 240 && x <= 500)
               || (y >= 200 && y <= 240 && x >= 740))
               MapFile << x << " " << y << " " << "ROCK" << endl;
        }
    }
    MapFile.close();
    return 0;
}
