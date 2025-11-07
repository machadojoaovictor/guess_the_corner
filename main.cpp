#include <GL/glut.h>

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void initialize()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);


    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DVD Screensaver MVP");


    glutDisplayFunc(draw);
    initialize();

    glutMainLoop();

    return 0;
}
