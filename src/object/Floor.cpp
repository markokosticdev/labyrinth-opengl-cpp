#include "Floor.h"

Floor::Floor(Texture *texture) : Object(), texture(texture) {}

Floor::~Floor() {

}

Texture *Floor::getTexture() const {
    return texture;
}

void Floor::setTexture(Texture *texture) {
    Floor::texture = texture;
}

void Floor::draw(double x1, double x2, double y1, double y2, double z1, double z2) {

    glBindTexture(GL_TEXTURE_2D, texture->getId());
    glBegin(GL_QUADS);

    glColor3f(1.0, 1.0, 1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(x2, y1, z1);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(x1, y1, z1);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(x1, y1, z2);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(x2, y1, z2);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}
