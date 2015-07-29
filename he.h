#include <GL/freeglut.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include "myArray.h"
using namespace std;
#ifdef _WIN32
#define WINDOWS true
#else
#define WINDOWS false
#include <pthread.h>
#endif
extern bool pause;
extern float delay;
extern float dx;
extern float dy;
extern const float rx;
extern const float ry;
extern const float sz;
extern myArray Arr;
void printtext(string txt, float num, float posX, float posY);
void changeSize(int w, int h);
void idle(void);
void key(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y );
void renderScene(void);
