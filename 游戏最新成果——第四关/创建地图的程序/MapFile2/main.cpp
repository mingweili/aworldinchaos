#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream MapFile("D:\\MapFile2.txt", ios :: out);
    for(int x = 0; x < 1000; ++x)
    {
        for(int y = 0; y < 800; ++y)
        {
            if(x <= 5 || y <= 5 || x >= 995 || y >= 795
               || (y >= 450 && y <= 490))
               MapFile << x << " " << y << " " << "ROCK" << endl;
        }
    }
    MapFile.close();
    return 0;
}
