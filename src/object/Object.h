#ifndef LABYRINTH_OPENGL_CPP_OBJECT_H
#define LABYRINTH_OPENGL_CPP_OBJECT_H


class Object {

private:

public:

    Object();

    virtual void draw(double x1, double x2, double y1, double y2, double z1, double z2) = 0; // draw object
};


#endif //LABYRINTH_OPENGL_CPP_OBJECT_H
