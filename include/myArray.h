#include <array>
#include <iostream>
#include <cstring>
#include <time.h>
using namespace std;

class myArray
{
   static const int aX = 29;
static const int aY = 29;
typedef array <array <int, arrX>, arrY> Arr2d;
   Arr2d A, save1;
    public:
            int Element (int x, int y)
    {
        return A[x][y];
    }
    int maxX() {
    return aX;
    }
      int maxY() {
    return aY;
    }
    void randomize (void)
    {
        srand(time(0));
    for (auto& i: A)
        for (auto& j: i)
            j = rand()%2;
    }
     void out (void)
    {
    for (auto i: A)
        for (auto j: i)
        cout << j;
    }
   void save()
{
     int i = 0;
    int j = 0;
    for (auto& x: A)
    {
        for (auto& y: x)
        {
            save1[i][j] = y;
            j++;
        }
        j = 0;
        i++;
        }
}
 void load()
{
     int i = 0;
    int j = 0; //counters
    for (auto& x: save1)
    {
        for (auto& y: x)
        {
            A[i][j] = y;
            j++;
        }
        j = 0;
        i++;}
}
};


