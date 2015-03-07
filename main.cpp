#include "he.h"
 Arr2d Arr;
 Arr2d save1Arr;

int main(int argc, char **argv)
{
   Arr = randArr(Arr);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,800);
    glutCreateWindow("LIFE");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    glutReshapeFunc(changeSize);
    glutIdleFunc(idle);
    glutMainLoop();

}

