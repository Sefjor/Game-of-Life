#include "he.h"
myArray Arr;

int main(int argc, char **argv)
{
#if (WINDOWS == false)  //temp solution for bug with <string>, will be fixed in ubuntu 15
    {
        glEnable(GL_LIGHT0);
        int NastyBug = pthread_getconcurrency();// https://bugs.launchpad.net/ubuntu/+source/nvidia-graphics-drivers-319/+bug/1248642
        NastyBug++;
    }
#endif
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,800);
    glutCreateWindow("LIFE");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(key);
    // glutMouseFunc(mouse);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutMainLoop();

}

