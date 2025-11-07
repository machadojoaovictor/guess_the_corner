/****************************************************
 *  GuessTheCorner (OpenGL / GLUT)
 *  Author: João Victor Machado (github.com/machadojoaovictor)
 *  Description: Simulates the classic DVD logo bouncing
 *               around the screen edges with color and size changes.
 ****************************************************/

#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>

// =====================================================
// ===============  GLOBAL VARIABLES  ==================
// =====================================================

const float g_worldLimit = 100.0f;

float g_worldLimitX = g_worldLimit;
float g_worldLimitY = g_worldLimit;

float g_posX = 0.0f;
float g_posY = 0.0f;

const float g_originalSize = 20.0f;
float g_currentSize = g_originalSize;

float g_velocityX = 0.08f;
float g_velocityY = 0.05f;

float g_colorR = 0.0f;
float g_colorG = 0.0f;
float g_colorB = 0.8f;

// =====================================================
// ==================  UTIL FUNCTIONS  =================
// =====================================================
inline const float getHalfSize() {
    return g_currentSize / 2.0f;
}

inline const float getIncrementAmount() {
    return g_originalSize * 0.01f;
}

inline const float getMaxSize() {
    return g_originalSize * 1.20f;
}

// =====================================================
// ===============  PHYSICS & LOGIC  ===================
// =====================================================

int checkCollision(float* pos, float* velocity, float limit, float halfSize) {
    if (*pos + halfSize > limit) {
        *velocity = -*velocity;
        *pos = limit - halfSize;
        return 1;
    } else if (*pos - halfSize < -limit) {
        *velocity = -*velocity;
        *pos = -limit + halfSize;
        return 1;
    }

    return 0;
}

void changeColor() {
    g_colorR = 0.2f + ((float)rand() / RAND_MAX) * 0.8f;
    g_colorG = 0.2f + ((float)rand() / RAND_MAX) * 0.8f;
    g_colorB = 0.2f + ((float)rand() / RAND_MAX) * 0.8f;
}

// =====================================================
// ===============  MAIN GAME LOOP  ====================
// =====================================================

void update() {
    g_posX += g_velocityX;
    g_posY += g_velocityY;


    float halfSize = getHalfSize();
    float maxSize = getMaxSize();
    float incrementAmount = getIncrementAmount();

    int collided = 0;

    collided |= checkCollision(&g_posX, &g_velocityX, g_worldLimitX, halfSize);
    collided |= checkCollision(&g_posY, &g_velocityY, g_worldLimitY, halfSize);

    if (collided) {
        changeColor();

        if (g_currentSize < maxSize) {
            g_currentSize += incrementAmount;

            if (g_currentSize > maxSize) {
                g_currentSize = maxSize;
            }
        }
    }

    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float halfSize = getHalfSize();
    float x1 = g_posX - halfSize;
    float x2 = g_posX + halfSize;
    float y1 = g_posY - halfSize;
    float y2 = g_posY + halfSize;


    glColor3f(g_colorR, g_colorG, g_colorB);


    glBegin(GL_QUADS);
        glVertex2f(x1, y2); // top-left
        glVertex2f(x2, y2); // top-right
        glVertex2f(x2, y1); // bottom-right
        glVertex2f(x1, y1); // bottom-left
    glEnd();


    glutSwapBuffers();
}

// =====================================================
// ===============  WINDOW HANDLING  ===================
// =====================================================

void resize(int width, int height) {
    if (height == 0) height = 1;

    glViewport(0, 0, width, height);

    float aspect = (float) width / (float) height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (width >= height)
    {
        gluOrtho2D((-g_worldLimit * aspect), (g_worldLimit * aspect), -g_worldLimit, g_worldLimit);
        g_worldLimitX = g_worldLimit * aspect;
        g_worldLimitY = g_worldLimit;
    }
    else
    {
        gluOrtho2D(-g_worldLimit, g_worldLimit, (-g_worldLimit / aspect), (g_worldLimit / aspect));
        g_worldLimitX = g_worldLimit;
        g_worldLimitY = g_worldLimit / aspect;
    }

    glMatrixMode(GL_MODELVIEW);
}

void initialize() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    if (width <= 0) width = 1024;
    if (height <= 0) height = 768;

    resize(width, height);
}

// =====================================================
// =====================  MAIN  ========================
// =====================================================

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    srand(time(NULL));

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GuessTheCorner - OpenGL Screensaver");


    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutIdleFunc(update);

    initialize();

    glutMainLoop();


    return 0;
}
