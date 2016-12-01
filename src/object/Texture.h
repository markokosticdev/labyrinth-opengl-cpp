#ifndef LABYRINTH_OPENGL_CPP_TEXTURE_H
#define LABYRINTH_OPENGL_CPP_TEXTURE_H


#include <GL/glut.h>
#include <fstream>
#include <string>

using namespace std;

class Texture {

private:

    GLuint id; // texture id
    string filename; // texture file name
    int width; // texture width
    int height; // texture height

public:

    Texture(const string &filename, int width, int height);

    virtual ~Texture();

    GLuint getId() const; // get texture id

    void setId(GLuint id); // set texture id

    const string &getFilename() const; // get texture file name

    void setFilename(const string &filename); // set texture file name

    int getWidth() const; // get texture width

    void setWidth(int width); // set texture width

    int getHeight() const; // get texture height

    void setHeight(int height); // set texture height

    bool load(); // load texture resource

    void free(); // free texture resource

};


#endif //LABYRINTH_OPENGL_CPP_TEXTURE_H
