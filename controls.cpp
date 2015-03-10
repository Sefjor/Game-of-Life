#include "he.h"
float dx = 400;
float dy = 400;
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
        dx += 0.5;
        break;
    case '2':
        dx -= 0.5;
        break;
    case '3':
        dy += 0.5;
        break;
    case '4':
        dy -= 0.5;
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
    int x = (xM - dx) * sz * 2;
    int y = (yM - dy) * sz * 2;
    cout << button;
    if (!state)
        if (Arr.exist(x, y))
            Arr.setElement(x, Arr.maxY() - y, !(button / 2));
}
