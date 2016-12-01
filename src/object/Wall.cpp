#include "Wall.h"

Wall::Wall(Texture *texture) : Object(), texture(texture) {}

Wall::~Wall() {

}

Texture *Wall::getTexture() const {
    return texture;
}

void Wall::setTexture(Texture *texture) {
    Wall::texture = texture;
}

void Wall::draw(double x1, double x2, double y1, double y2, double z1, double z2) {

    glBindTexture(GL_TEXTURE_2D, texture->getId());
    glBegin(GL_QUADS);

    //front side
    glColor4f(1.0, 1.0, 1.0, 0.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(x1, y1, z1);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(x2, y1, z1);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(x2, y2, z1);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(x1, y2, z1);

    //back side
    glTexCoord2d(0.0, 0.0);
    glVertex3f(x1, y1, z2);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(x2, y1, z2);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(x2, y2, z2);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(x1, y2, z2);

    //left side
    glTexCoord2d(1.0, 0.0);
    glVertex3f(x1, y1, z1);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(x1, y2, z1);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(x1, y2, z2);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(x1, y1, z2);

    //right side
    glTexCoord2d(0.0, 0.0);
    glVertex3f(x2, y1, z1);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(x2, y2, z1);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(x2, y2, z2);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(x2, y1, z2);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
    glBegin(GL_QUADS);

    //top side
    glColor3f(240 / 255.0, 240 / 255.0, 240 / 255.0);
    glVertex3f(x1, y2, z1);
    glVertex3f(x2, y2, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x1, y2, z2);
    glEnd();
}
