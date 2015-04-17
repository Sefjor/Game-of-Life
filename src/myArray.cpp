#include "myArray.h"

myArray::myArray()
{
    randA();
}
int myArray::getElement (int x, int y)
{
    return A[x][y];
}
void myArray::setElement(int x, int y, int value)
{
    A[x][y] = value;
}
bool myArray::exist(int x, int y)
{
    return (x >= 0 && y >= 0 && x < aX && y < aY);
}
int myArray::maxX()
{
    return aX;
}
int myArray::maxY()
{
    return aY;
}

void myArray::randA (void)
{
    srand(time(0));
    for (auto& i: A)
        for (auto& j: i)
            j = rand()%2;
}
void myArray::delA()
{
    for (auto& i: A)
        for (auto& j: i)
            j = 0;
}
void myArray::out (void)
{
    for (auto i: A)
        for (auto j: i)
            cout << j;
}
void myArray::saveA()
{
    for ( auto iA = begin(A), iS = begin(Save1); iA != end(A); iA++ ,iS++)
        for ( auto jA = begin(*iA), jS = begin(*iS); jA != end(*iA); jA++, jS++)
            *jS = *jA;
}
void myArray::loadA()
{

    for ( auto iA = begin(A), iS = begin(Save1); iA != end(A); iA++ ,iS++)
        for ( auto jA = begin(*iA), jS = begin(*iS); jA != end(*iA); jA++, jS++)
            *jA = *jS;
}

void myArray::recalcA()
{
    Arr2d ArrT;
    for (int i = 0; i < aX; i++)
        for (int j = 0; j < aY; j++) {
            int cter = 0; //counting neighbors
            for (int i1 = -1; i1 <= 1; i1++)
                for (int j1 = -1; j1 <= 1; j1++) {
                    if (!(i1 == 0 && j1 == 0) && exist(i+i1, j+j1)) //not center & elenent exist
                        if (A[i+i1][j+j1])
                                cter++;
                }
            switch (cter) {
            case 3 :  // creating cell
                ArrT[i][j] = 2;
                break;
            case 2 : // state remains
                ArrT[i][j] = A[i][j];
                break;
            default : // cell dies
                ArrT[i][j] = 0;
            }
        }
    for (int i = 0; i < aX; i++)
        for (int j = 0; j < aY; j++)
            A[i][j] = ArrT[i][j];
}
