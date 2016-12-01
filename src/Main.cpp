#define _CRT_SECURE_NO_WARNINGS
#include "window/Window.h"
using namespace std;

int main(int argc, char** argv)
{
    Window::setWidth(800); // window width
    Window::setHeight(600); // window height
    Window::setMode(0); // window mode (NORMAL = 0, FULLSCREEN = 1)

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    Window::getMode(0);
    glutCreateWindow("Labyrinth");
    Window::getMode(1);
    glutReshapeFunc(Window::reshape);
	glutKeyboardFunc(Window::keyboard);
	glutDisplayFunc(Window::display);
    Window::init();
	glutMainLoop();
    delete Window::getScene();

    return 0;
}


