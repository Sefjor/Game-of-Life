#include "he.h"
Arr2d Arr;
Arr2d save1Arr;

int main(int argc, char **argv)
{
    #if (WINDOWS == false)  //temp solution for bug with <string>, will be fixed in ubuntu 15
    {
        glEnable(GL_LIGHT0);
        int NastyBug = pthread_getconcurrency();// https://bugs.launchpad.net/ubuntu/+source/nvidia-graphics-drivers-319/+bug/1248642
        NastyBug++;
    }
    #endif

    Arr = randArr(Arr);
    /*for (auto& x: Arr)
    {
        for (auto& y: x)
        {
            y = rand()%2;
            j++;
        }
        j = 0;
        i++;} */
      myArray B;
B.randomize();
B.out();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,800);
    glutCreateWindow("LIFE");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutMainLoop();

}

