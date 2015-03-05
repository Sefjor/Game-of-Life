#include "he.h"
float dx = 0;//magic num
float dy = 0;//for mouse coords will be fixed with 2d
float delay = 5; //render scene
bool pause = 0;
float dimZ = -2; // magic num for 3d
float rx = -0.5;//0 is center  f(x=0)=0
float ry = -0.5;//0 is center  f(x=0)=0
float size = 0.03; //1/2 size of square

void changeSize(int w, int h) //unused atm, migrating 2d
{
    const float ar = (float) w / (float) h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho( -2 * ar, 2 * ar, -2, 2, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
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
        if (delay > 90)
            delay = 90;
        if (delay == 0)
            delay = 3;
        break;
    case '+':
        delay *= 0.7;
        if (delay < 2)
            delay = 0;
        break;
    case '1':
        dx += 1;
        break;
    case '2':
        dx -= 1;
        break;
    case '3':
        dy += 1;
        break;
    case '4':
        dy -= 1;
        break;
    case 'r':
    case 'R':
        randArr();
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
    glutPostRedisplay();
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
void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    static double timenext = 0;
    double timecurrent =  glutGet(GLUT_ELAPSED_TIME) / 30.0;
    if (timenext > timecurrent)
        return;
    else timenext += delay;

    if (!pause) recalc_array();
    for (int i = 0; i < arrX; i++)
        for (int j = 0; j < arrY; j++)
        {
            float xmod = (i * size * 2 + rx);
            float ymod = (j * size * 2 + ry) ;
            //float tpass;
            if (Arr[i][j]) glColor3f(0.6f,0.7f,0.5f);
            else glColor3f(0.0f,0.0f,0.0f);
            glBegin(GL_QUADS);
            glVertex2f(-size + xmod, -size + ymod);
            glVertex2f(-size + xmod, size + ymod);
            glVertex2f(size + xmod, size + ymod);
            glVertex2f(size + xmod, -size + ymod);
            glEnd();
            glLineWidth(0.5);
            glColor3f(0.3, 0.5, 0.6);
            glBegin(GL_LINES);
            glVertex2f(rx - size + i * size * 2, ry-size);
            glVertex2f(rx - size + i * size * 2, ry-size + arrY * size * 2);
            glVertex2f(rx - size, ry-size + j * size * 2);
            glVertex2f(rx - size + arrX * size * 2, ry-size + j * size * 2); //2.85 1.75
            glEnd();
        }
    //  glColor3f(0.3, 0.5, 0.6);
    glBegin(GL_LINES);
    glVertex2f(rx - size + arrX * size * 2, ry - size);
    glVertex2f(rx - size + arrX * size * 2, ry - size+ arrY * size * 2);
    glVertex2f(rx - size, ry - size + arrY * size * 2);
    glVertex2f(rx - size + arrX * size * 2, ry - size + arrY * size * 2); //2.85 1.75
    glEnd();
    printtext(delay, rx +6, ry+arrY*size*2 + 0.1);
    printtext(dx, rx, ry+arrY*size*2 + 0.1);
    printtext(dy, rx + 0.5, ry+arrY*size*2 + 0.1);

    glutSwapBuffers();
}
void printtext(float num, float posX, float posY)
{
    char ss[5];
    sprintf(ss,"%.0f", num);
    glRasterPos3f(posX, posY, dimZ);
    glutBitmapString (GLUT_BITMAP_HELVETICA_12, reinterpret_cast<const unsigned char*>(ss));
}


