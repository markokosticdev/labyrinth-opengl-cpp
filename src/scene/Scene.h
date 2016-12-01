#ifndef LABYRINTH_OPENGL_CPP_SCANE_H
#define LABYRINTH_OPENGL_CPP_SCANE_H


#include <GL/glut.h>
#include <string>

using namespace std;

class Scene {

private:

public:

    Scene();

    virtual void display() = 0; // display scene

    void drawText(GLfloat x, GLfloat y, GLfloat z, GLfloat scale, string text, char font); // draw text (HEADER = h, BODY = b)

    void drawText(GLfloat x, GLfloat y, GLfloat z, GLfloat scale, string text); // draw body text

};


#endif //LABYRINTH_OPENGL_CPP_SCANE_H
