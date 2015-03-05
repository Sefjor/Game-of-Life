#include <gl/freeglut.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#define arrX 39
#define arrY 39
#include <stdio.h>
#include <deque>
#include <array>
using namespace std;
extern bool pause;
extern float delay;
typedef array <array <int, arrX>, arrY> Arr2d;
extern Arr2d save1Arr;
extern Arr2d Arr;
void deleteArr(void);
void printtext(float num, float posX, float posY);
void randArr(void);
Arr2d saveArr(void);
void loadArr(Arr2d whattoload);
void changeSize(int w, int h);
void idle(void);
void key(unsigned char key, int x, int y);
void recalc_array(void);
void mouse(int button, int state, int x, int y );
void renderScene(void);
