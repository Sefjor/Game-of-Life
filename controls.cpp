#include "he.h"
float dx = 0;
float dy = 0;
void key(unsigned char key, int x, int y)
{
    switch (key) {
    case 27 :
    case ' ':
        exit(0);
        break;
    case '-':
        delay *= 1.4;
        if (delay > 90)
            delay = 90;
        if (delay == 0)
            delay = 3;
        break;
    case '+':
    case '=':
        delay *= 0.7;
        if (delay < 2)
            delay = 0;
        break;
    case '1':
        rx += 0.5;
        break;
    case '2':
        rx -= 0.5;
        break;
    case '3':
        ry += 0.5;
        break;
    case '4':
        ry -= 0.5;
        break;
    case 'r':
    case 'R':
        Arr.randA();
        break;
    case 's':
        Arr.saveA();
        break;
    case 'd':
        Arr.delA();
        break;
    case 'p':
        pause = !pause;
        break;
    case 'l':
        Arr.loadA();
        break;
    }
}
void mouse(int button, int state, int xM, int yM )
{
    int x =  (2.0 * xM /  glutGet(GLUT_WINDOW_WIDTH) - 1 - rx ) / sz;
    int y =  (2 - 2.0 * yM / glutGet(GLUT_WINDOW_HEIGHT) - 1 - ry) / sz;
    if (!state)
        if (Arr.exist(x, y))
            Arr.setElement(x, y, !(button / 2));
}
