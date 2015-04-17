#include "he.h"
float delay = 5; //render scene
bool pause = 0;
float rx = -0.99;// position of matrix on screen
float ry = -0.99;//0 is center  f(x=0)=0
float sz = 0.03; //size of square

void changeSize(int w, int h)
{
    const float ar = (float) w / (float) h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D( -ar, ar, -1, 1);
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
        Arr.recalcA();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        glBegin(GL_QUADS);
        for (int i = 0; i < Arr.maxX(); i++)
            for (int j = 0; j < Arr.maxY(); j++) {
                float xmod = (i * sz + rx);
                float ymod = (j * sz + ry) ;
                if (Arr.getElement(i,j)) {
                  if (Arr.getElement(i,j) == 1)
                   glColor3f(0.6f, 0.7f, 0.5f);
                if (Arr.getElement(i,j) == 2)
                      glColor3f(0.4f, 0.5f, 0.5f);
                    glVertex2f(xmod, ymod);
                    glVertex2f(xmod, sz + ymod);
                    glVertex2f(sz + xmod, sz + ymod);
                    glVertex2f(sz + xmod, ymod);
                }
            }
        glEnd(); //
        glLineWidth(0.5);
        glColor3f(0.3, 0.5, 0.6);
        glBegin(GL_LINES);
        for (int i = 0; i < Arr.maxX() + 1; i++)
            for (int j = 0; j < Arr.maxY() + 1; j++) {
                glVertex2f(rx + i * sz , ry);
                glVertex2f(rx + i * sz, ry + Arr.maxY() * sz);
                glVertex2f(rx, ry + j * sz );
                glVertex2f(rx + Arr.maxX() * sz, ry + j * sz); //2.85 1.75
            }
        glEnd();
        glColor3f(0.3f,0.5f,0.5f);
        printtext("delay=", delay, rx ,ry + Arr.maxY() * sz );
        printtext("dx=", dx, rx + Arr.maxY() * sz / 2 - 4 * sz, ry + Arr.maxY() * sz);
        printtext("dy=", dy, rx + Arr.maxY() * sz - sz * 4 , ry + Arr.maxY() * sz);
        glutSwapBuffers();
}
void printtext(string txt, float num, float posX, float posY)
{
    stringstream s;
    s << txt << num;
    glRasterPos2f(posX, posY);
    glutBitmapString (GLUT_BITMAP_HELVETICA_12, reinterpret_cast<const unsigned char*>(s.str().c_str()));
}


