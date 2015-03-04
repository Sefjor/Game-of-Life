#include "he.h"
float delay = 0.5;
bool pause = 0;
void changeSize(int w, int h)
{
    // предупредим деление на ноль
    if(h == 0)
        h = 1;
    float ratio = 1.0* w / h;
    // используем матрицу проекции
    glMatrixMode(GL_PROJECTION);
    // Reset матрицы
    glLoadIdentity();
    // определяем окно просмотра
    glViewport(0, 0, w, h);
    // установить корректную перспективу.
    gluPerspective(45,ratio,1,1000);
    // вернуться к модели
    glMatrixMode(GL_MODELVIEW);
}
void idle(void)
{
    glutPostRedisplay();
}
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
        break;
    case '+':
        delay *= 0.7;
        break;
    case 'r':
    case 'R':
        randArr();
        break;
    case 's':
        saveArr(save1Arr);
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
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y )
{
    int x1 = (x - 95)/10;
    int y1 = (y - 3)/10;
    cout << button;
    if (!state)
        if (x1 > -1 && y1 > -1 && x1 < arrX + 1 && y1 < arrY + 1)
            Arr[x1][arrY - y1] = !(button / 2);
}


