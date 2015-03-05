#include "he.h"
float delay = 55;
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
    case 'q':
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
    }
    glutPostRedisplay();
}
