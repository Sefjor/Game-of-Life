#include "he.h"
float delay = 55;
void changeSize(int w, int h)
{
    // ����������� ������� �� ����
    if(h == 0)
        h = 1;
    float ratio = 1.0* w / h;
    // ���������� ������� ��������
    glMatrixMode(GL_PROJECTION);
    // Reset �������
    glLoadIdentity();
    // ���������� ���� ���������
    glViewport(0, 0, w, h);
    // ���������� ���������� �����������.
    gluPerspective(45,ratio,1,1000);
    // ��������� � ������
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
