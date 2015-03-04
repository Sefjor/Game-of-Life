#include <gl/glut.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#define arrX 49
#define arrY 29
using namespace std;
extern bool pause;
extern float delay;
extern int save1Arr[][arrY];
extern int Arr[][arrY];
void deleteArr(void);
void randArr(void);
void saveArr(int wheretosave[][arrY]);
void loadArr(int whattoload[][arrY]);
void changeSize(int w, int h);
void idle(void);
void key(unsigned char key, int x, int y);
void recalc_array(void);
void mouse(int button, int state, int x, int y );
