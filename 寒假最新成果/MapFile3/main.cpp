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
                (x >= 111 && x <= 131 && y >= 600 && y <= 680) ||
                (x >= 869 && x <= 889 && y >= 600 && y <= 680) ||
                (x >= 296 && x <= 316 && y >= 320 && y <= 400) ||
                (x >= 684 && x <= 704 && y >= 320 && y <= 400) ||
                (x >= 412 && x <= 432 && y >= 120 && y <= 200) ||
                (x >= 568 && x <= 588 && y >= 120 && y <= 200) ||

                (y >= 680 && y <= 800 && (x <= 460 || x >= 540)) ||
                (y >= 795 && y <= 800) ||
                (y >= 400 && y <= 440 && (x <= 400 || x >= 480)) ||
                (y >= 200 && y <= 240)
              )
              MapFile << x << " " << y << " " << "ROCK" << endl;
        }
    }

    MapFile.close();
}
