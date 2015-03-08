#include "he.h"
Arr2d Arr;
Arr2d save1Arr;

int main(int argc, char **argv)
{
    {
        //temp solution for bug with <string>, will be fixed in ubuntu 15
        glEnable(GL_LIGHT0);
        int NastyBug=pthread_getconcurrency();// https://bugs.launchpad.net/ubuntu/+source/nvidia-graphics-drivers-319/+bug/1248642
    }
    Arr = randArr(Arr);
    int i = 0;
    int j = 0; //counters
    for (auto& x: Arr)
    {
        for (auto& y: x)
        {
            y = rand()%2;
           // cout << i << "," << j << " ";
            j++;
        }
        j = 0;
        i++;
    }
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

