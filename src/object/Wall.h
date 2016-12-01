#ifndef LABYRINTH_OPENGL_CPP_WALL_H
#define LABYRINTH_OPENGL_CPP_WALL_H


#include <GL/glut.h>
#include "Object.h"
#include "Texture.h"

using namespace std;

class Wall : public Object {

private:

    Texture *texture; // wall texture

public:

    Wall(Texture *texture);

    virtual ~Wall();

    Texture *getTexture() const; // get wall texture

    void setTexture(Texture *texture); // set wall texture

    void draw(double x1, double x2, double y1, double y2, double z1, double z2);  // draw wall

};


#endif //LABYRINTH_OPENGL_CPP_WALL_H
