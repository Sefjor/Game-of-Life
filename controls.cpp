#include "he.h"
float dx = 2;//magic num
float dy = 2;//for mouse coords, will be fixed with 2d
void key(unsigned char key, int x, int y)
{
    switch (key)
    {
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
        Arr = randArr(Arr);
        break;
    case 's':
      save1Arr = saveArr();
        break;
    case 'd':
        deleteArr();
        break;
    case 'p':
        pause = !pause;
        break;
    case 'l':
      loadArr(save1Arr);
        break;
    }
}
void mouse(int button, int state, int x, int y )
{
    int x1 = (x - dx) * size * 2 ;
    int y1 = (y - dy) * size * 2;
    cout << button;
    if (!state)
    if (x1 > -1 && y1 > -1 && x1 < arrX + 1 && y1 < arrY + 1)
            Arr[x1][arrY - y1] = !(button / 2);
}
