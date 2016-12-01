#ifndef LABYRINTH_OPENGL_CPP_FLOOR_H
#define LABYRINTH_OPENGL_CPP_FLOOR_H


#include <GL/glut.h>
#include "Object.h"
#include "Texture.h"

using namespace std;

class Floor : public Object {

private:

    Texture *texture; // get floor texture

public:

    Floor(Texture *texture);

    virtual ~Floor();

    Texture *getTexture() const; // get floor texture

    void setTexture(Texture *texture); // set floor texture

    void draw(double x1, double x2, double y1, double y2, double z1, double z2); // draw floor

};


#endif //LABYRINTH_OPENGL_CPP_FLOOR_H
