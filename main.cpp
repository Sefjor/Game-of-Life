#include "he.h"
using namespace std;
int Arr[arrX][arrY];
int save1Arr[arrX][arrY];
void renderScene(void)
{
    static double timenext = 0;
    double timecurrent =  glutGet(GLUT_ELAPSED_TIME) / 30.0;
    if (timenext > timecurrent)
    {
        return;
    }
    else timenext += delay;

    if (!pause) recalc_array();
    float dimZ = -5.0;
    float size = 0.05;
    for (int i = 0; i < arrX; i++)
        for (int j = 0; j < arrY; j++)
        {
            float xmod = (i * size * 2 - 2);
            float ymod = (j * size * 2 - 1) ;
            //float tpass;
            if (Arr[i][j]) glColor3f(0.4f,0.6f,0.5f);
            else glColor3f(0.0f,0.0f,0.0f);
            glBegin(GL_QUADS);
            glVertex3f(-size + xmod, -size + ymod, dimZ);
            glVertex3f(-size + xmod, size + ymod, dimZ);
            glVertex3f(size + xmod, size + ymod, dimZ);
            glVertex3f(size + xmod, -size + ymod, dimZ);
            glEnd();

        }
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    //filling array
    randArr();


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,400);
    glutCreateWindow("Life");
    // регистрация
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    // Новая функция изменения размеров окна
    glutReshapeFunc(changeSize);
    glutIdleFunc(idle);
    // основной цикл
    glutMainLoop();

}

