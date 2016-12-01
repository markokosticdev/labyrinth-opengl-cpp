#include "Scene.h"

Scene::Scene() {}

void Scene::drawText(GLfloat x, GLfloat y, GLfloat z, GLfloat scale, string text, char font) {
    unsigned int i;
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(scale, scale, scale);
    for (i = 0; i < text.size(); i++)
        if (font == 'b') glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
        else glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text[i]);
    glPopMatrix();
}

void Scene::drawText(GLfloat x, GLfloat y, GLfloat z, GLfloat scale, string text) {

    drawText(x, y, z, scale, text, 'b');
}
