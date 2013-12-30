#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream MapFile("D:\\MapFile3.txt", ios :: out);
    for(int x = 0; x < 1000; ++x)
    {
        for(int y = 0; y < 800; ++y)
        {
            if(
                (x >= 106 && x <= 116 && y >= 660 && y <= 720)   ||
                (x >= 884 && x <= 894 && y >= 660 && y <= 720) ||

                (x >= 272 && x <= 282 && y >= 380 && y <= 440) ||
                (x >= 718 && x <= 728 && y >= 380 && y <= 440) ||

                (x >= 400 && x <= 410 && y >= 160 && y <= 260) ||
                (x >= 590 && x <= 600 && y >= 160 && y <= 260) ||

                (y >= 724 && y <= 800 && (x <= 460 || x >= 540)) ||
                (y >= 785 && y <= 800) ||
                (y >= 440 && y <= 480 && (x <= 500 || x >= 570)) ||
                (y >= 240 && y <= 280)
              )
              MapFile << x << " " << y << " " << "ROCK" << endl;
        }
    }

    MapFile.close();
}
