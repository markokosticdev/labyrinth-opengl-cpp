#include "Home.h"

Home::Home() : Scene() {}

Home::~Home() {

}

void Home::display() {
    if (glutGet(GLUT_WINDOW_WIDTH) < 1280) glTranslatef(0.0, -1.3, -8.0);
    else glTranslatef(0.0, -1.3, -6.0);

    glLoadName(3);

    glColor3f(0.2, 0.2, 0.2);
    drawText(-3.1, 2.7, 0.0, 0.0065, "LABYRINTH", 'h');
    drawText(-1.0, 2.3, 0.0, 0.0017, "by Marko Kostic");

    glColor3f(0.5, 0.5, 0.5);
    drawText(-1.7, 0.1, 0.0, 0.0020, "Use: W, S, A, D, TAB, F");

    glColor3f(0.4, 0.4, 0.4);
    drawText(-3.1, -0.8, 0.0, 0.0030, "Press ENTER key to continue...");

    glutSwapBuffers();
}

void Home::keyboard(unsigned char key, int x, int y, int &sceneId) {

    if (key == 27) exit(0);
    else if(key == 13) {
        sceneId = 2;
        glutPostRedisplay();
    }

}
