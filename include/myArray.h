#ifndef MYARRAY_H
#define MYARRAY_H
#include <array>
#include <iostream>
#include <cstring>
#include <time.h>
using namespace std;

class myArray {
private:
    static const int aX = 65;
    static const int aY = 65;
    template <class T, size_t ROW, size_t COL>
using Matrix = std::array<std::array<T, COL>, ROW>;
    typedef Matrix<int, aX, aY> Arr2d;
    Arr2d A;
    Arr2d Save1;

public:
    myArray();

    int getElement (int x, int y);
    int maxX();
    int maxY();
    void randA();
    void delA();
    void out();
    void saveA();
    void loadA();
    void recalcA();
    void setElement(int x, int y, int value);
    bool exist(int x, int y);//
};
#endif // MYARRAY_H

