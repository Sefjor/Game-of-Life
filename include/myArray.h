#include <array>
#include <iostream>
#include <cstring>
using namespace std;

class myArray
{
   static const int X = 29;
static const int Y = 29;
    array <array <int, X>, Y> A;
    public:
            int getElement (int x, int y)
    {
        //cout << A.begin() << " ";
        return A[x][y];
    }
    int boundX() {
    return X;
    }
      int boundY() {
    return Y;
    }
    void randomize (void)
    {
        srand(time(0));
    for (auto& i: A)
        for (auto& j: i)
            j = rand()%2;
    }

};


