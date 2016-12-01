#ifndef LABYRINTH_OPENGL_CPP_WINDOW_H
#define LABYRINTH_OPENGL_CPP_WINDOW_H


#include <GL/glut.h>
#include "../scene/Scene.h"
#include "../scene/Home.h"
#include "../scene/Labyrinth.h"

using namespace std;

class Window {

private:

    static Scene *scene; // current scene
    static int sceneId; // current scene id
    static int width; // window width
    static int height; // window height
    static int mode; // window mode

    Window(){}

public:

    static Scene *getScene(); // get scene

    static void setScene(Scene *scene); // set scene

    static int getSceneId(); // get sceneId

    static void setSceneId(int sceneId); // set sceneId

    static int getWidth(); // get window width

    static void setWidth(int width); // set window width

    static int getHeight(); // get window height

    static void setHeight(int height); // set window height

    static void getMode(int mode); // get window mode

    static void setMode(int mode); // set window mode

    static void changeMode(); // change window mode

    static void display(); // display window

    static void keyboard(unsigned char key, int x, int y); // keyboard window functions

    static void reshape(int w, int h); // reshape window

    static void init(); // window init setup

};

#endif //LABYRINTH_OPENGL_CPP_WINDOW_H
