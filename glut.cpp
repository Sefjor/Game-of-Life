#include "he.h"
float delay = 5; //render scene
bool pause = 0;
float rx = 0;//0 is center  f(x=0)=0
float ry = 0;//0 is center  f(x=0)=0
float size = 0.03; //1/2 size of square

void changeSize(int w, int h)
{
    const float ar = (float) w / (float) h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho( -2 * ar, 2 * ar, -2, 2, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void renderScene(void)
{
    static double timenext = 0;
    double timecurrent =  glutGet(GLUT_ELAPSED_TIME) / 30.0;
    if (timenext > timecurrent)
        return;
    else timenext += delay;

    if (!pause)
    {
        recalc_array();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        glBegin(GL_QUADS);
        for (int i = 0; i < arrX; i++)
            for (int j = 0; j < arrY; j++)
            {
                float xmod = (i * size * 2 + rx);
                float ymod = (j * size * 2 + ry) ;
                if (Arr[i][j]) glColor3f(0.6f,0.7f,0.5f);
                else glColor3f(0.0f,0.0f,0.0f);
                glVertex2f(-size + xmod, -size + ymod);
                glVertex2f(-size + xmod, size + ymod);
                glVertex2f(size + xmod, size + ymod);
                glVertex2f(size + xmod, -size + ymod);
            }
        glEnd();
        glLineWidth(0.5);
        glColor3f(0.3, 0.5, 0.6);
        glBegin(GL_LINES);
        for (int i = 0; i < arrX + 1; i++)
            for (int j = 0; j < arrY + 1; j++)
            {
                glVertex2f(rx - size + i * size * 2, ry-size);
                glVertex2f(rx - size + i * size * 2, ry-size + arrY * size * 2);
                glVertex2f(rx - size, ry-size + j * size * 2);
                glVertex2f(rx - size + arrX * size * 2, ry-size + j * size * 2); //2.85 1.75
            }
        glEnd();
        printtext(delay, rx - size ,ry + arrY * size * 2 - 0.02);
       printtext(dx, rx + arrY * size - size, ry + arrY * size * 2 - 0.02);
       printtext(dy, rx + arrY * size * 2 - size * 2 , ry + arrY * size * 2 - 0.02);
        glutSwapBuffers();
    }
}
void printtext(float num, float posX, float posY)
{
    std::string s;
    s = to_string(num);
     glRasterPos2f(posX, posY);
   glutBitmapString (GLUT_BITMAP_HELVETICA_12, reinterpret_cast<const unsigned char*>(s.c_str()));
}


