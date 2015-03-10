#include "he.h"
float delay = 5; //render scene
bool pause = 0;
float rx = 0;// position of matrix on screen
float ry = 0;//0 is center  f(x=0)=0
float sz = 0.015; //1/2 size of square

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
                float xmod = (i * sz * 2 + rx);
                float ymod = (j * sz * 2 + ry) ;
                glColor3f(0.6f,0.7f,0.5f);
                if (Arr.getElement(i,j)) {
                    glVertex2f(-sz + xmod, -sz + ymod);
                    glVertex2f(-sz + xmod, sz + ymod);
                    glVertex2f(sz + xmod, sz + ymod);
                    glVertex2f(sz + xmod, -sz + ymod);
                }
            }
        glEnd(); //
        glLineWidth(0.5);
        glColor3f(0.3, 0.5, 0.6);
        glBegin(GL_LINES);
        for (int i = 0; i < Arr.maxX() + 1; i++)
            for (int j = 0; j < Arr.maxY() + 1; j++) {
                glVertex2f(rx - sz + i * sz * 2, ry-sz);
                glVertex2f(rx - sz + i * sz * 2, ry-sz + Arr.maxY() * sz * 2);
                glVertex2f(rx - sz, ry-sz + j * sz * 2);
                glVertex2f(rx - sz + Arr.maxX() * sz * 2, ry-sz + j * sz * 2); //2.85 1.75
            }
        glEnd();
        glColor3f(0.3f,0.5f,0.5f);
        printtext("delay=", delay, rx ,ry + Arr.maxY() * sz * 2 );
        printtext("dx=", dx, rx + Arr.maxY() * sz - 4 * sz, ry + Arr.maxY() * sz * 2);
        printtext("dy=", dy, rx + Arr.maxY() * sz * 2 - sz * 8 , ry + Arr.maxY() * sz * 2);
        glutSwapBuffers();
}
void printtext(string txt, float num, float posX, float posY)
{
    stringstream s;
    s << txt << num;
    glRasterPos2f(posX, posY);
    glutBitmapString (GLUT_BITMAP_HELVETICA_12, reinterpret_cast<const unsigned char*>(s.str().c_str()));
}


