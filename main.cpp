#include <GL/glut.h>

const float g_worldLimit = 100.0f;

float g_posX = 0.0f;
float g_posY = 0.0f;
float g_squareSize = 20.0f;

float g_velocityX = 0.2f;
float g_velocityY = 0.15f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float halfSize = g_squareSize / 2.0f;
    float x1 = g_posX - halfSize;
    float x2 = g_posX + halfSize;
    float y1 = g_posY - halfSize;
    float y2 = g_posY + halfSize;


    glColor3f(0.0f, 0.0f, 0.8f);


    glBegin(GL_QUADS);
        glVertex2f(x1, y2); // top-left
        glVertex2f(x2, y2); // top-right
        glVertex2f(x2, y1); // bottom-right
        glVertex2f(x1, y1); // bottom-left
    glEnd();


    glutSwapBuffers();
}

void initialize()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0f, 100.0f, -100.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void resize(int width, int height)
{
    if (height == 0) height = 1;

    glViewport(0, 0, width, height);

    float aspect = (float) width / (float) height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (width >= height)
    {
        gluOrtho2D((-g_worldLimit * aspect), (g_worldLimit * aspect), -g_worldLimit, g_worldLimit);
    }
    else
    {
        gluOrtho2D(-g_worldLimit, g_worldLimit, (-g_worldLimit / aspect), (g_worldLimit / aspect));
    }

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);


    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DVD Screensaver");


    glutDisplayFunc(display);
    glutReshapeFunc(resize);

    initialize();

    glutMainLoop();

    return 0;
}
