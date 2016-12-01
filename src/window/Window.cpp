#include "Window.h"

int Window::sceneId = 1;
Scene *Window::scene = nullptr;
int Window::width = 800;
int Window::height = 600;
int Window::mode = 0;

Scene *Window::getScene() {
    return scene;
}

void Window::setScene(Scene *scene) {
    Window::scene = scene;
}

int Window::getSceneId() {
    return sceneId;
}

void Window::setSceneId(int sceneId) {
    Window::sceneId = sceneId;
}

int Window::getWidth() {
    return width;
}

void Window::setWidth(int width) {
    Window::width = width;
}

int Window::getHeight() {
    return height;
}

void Window::setHeight(int height) {
    Window::height = height;
}

void Window::getMode(int m) {

    if(mode == 0 && m ==0){
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-Window::getWidth())/2,(glutGet(GLUT_SCREEN_HEIGHT)-Window::getHeight())/2);
        glutInitWindowSize(Window::getWidth(),Window::getHeight());
    }
    else if(mode == 1 && m == 1 ){
        glutInitWindowSize(Window::getWidth(),Window::getHeight());
        glutFullScreen();
    }
}

void Window::setMode(int mode) {
    Window::mode = mode;
}

void Window::changeMode() {

    if(mode == 0){
        glutInitWindowSize(Window::getWidth(),Window::getHeight());
        glutFullScreen();
        Window::mode = 1;
    }
    else if(mode == 1 ){
        glutPositionWindow((glutGet(GLUT_SCREEN_WIDTH)-Window::getWidth())/2,(glutGet(GLUT_SCREEN_HEIGHT)-Window::getHeight())/2);
        glutReshapeWindow(Window::getWidth(),Window::getHeight());
        Window::mode = 0;
    }
}

void Window::display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);

    if (sceneId == 1) {

        if (scene != nullptr) {

            if (Home *h = dynamic_cast<Home *>(scene)) {}
            else {
                delete scene;
                scene = new Home();
            }
        }
        else scene = new Home();

        scene->display();
    }
    else if (sceneId == 2) {

        if (scene != nullptr) {

            if (Labyrinth *l = dynamic_cast<Labyrinth *>(scene)) {}
            else {
                delete scene;
                scene = new Labyrinth();
            }
        }
        else scene = new Labyrinth();

        scene->display();
    }
}

void Window::keyboard(unsigned char key, int x, int y) {

    if(key == 'f'){
        changeMode();
    }
    else if (sceneId == 1) {
        Home *home = dynamic_cast<Home *>(scene);
        home->keyboard(key, x, y, sceneId);
    }
    else if (sceneId == 2) {
        Labyrinth *labyrinth = dynamic_cast<Labyrinth *>(scene);
        labyrinth->keyboard(key, x, y, sceneId);
    }
}

void Window::reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, w / (double) h, 0.1, 200.0);
}

void Window::init() {
    glClearColor(220 / 255.0, 220 / 255.0, 220 / 255.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
