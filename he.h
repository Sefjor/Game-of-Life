#include <GL/freeglut.h>
#include <iostream>
#define arrX 29
#define arrY 29
#include <array>
#include <pthread.h>
#include <cstring>
#include <sstream>
#include "myArray.h"
using namespace std;
extern bool pause;
extern float delay;
typedef array <array <int, arrX>, arrY> Arr2d;
extern Arr2d save1Arr;
extern Arr2d Arr;
extern float size;
extern float dx;
extern float dy;
extern float rx;
extern float ry;
void deleteArr(void);
void printtext(string, float num, float posX, float posY);
Arr2d randArr(Arr2d what_to_rand);
Arr2d saveArr(void);
void loadArr(Arr2d whattoload);
void changeSize(int w, int h);
void idle(void);
void key(unsigned char key, int x, int y);
void recalc_array(void);
void mouse(int button, int state, int x, int y );
void renderScene(void);
