#ifndef LABYRINTH_OPENGL_CPP_HOME_H
#define LABYRINTH_OPENGL_CPP_HOME_H


#include <GL/glut.h>
#include <string>
#include "Scene.h"

using namespace std;

class Home : public Scene {

private:

public:

    Home();

    virtual ~Home();

    void display(); // display home

    void keyboard(unsigned char key, int x, int y, int &scane); // keyboard home functions

};


#endif //LABYRINTH_OPENGL_CPP_HOME_H
