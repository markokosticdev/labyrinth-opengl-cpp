#include "Labyrinth.h"

Labyrinth::Labyrinth() : Scene() {
    floorTexture = new Texture("res/img/floor.bmp", 600, 460);
    wallTexture = new Texture("res/img/wall.bmp", 900, 900);
    floorTexture->load();
    wallTexture->load();

    setStartPoint(1, 0);
    loadMap();
}

Labyrinth::~Labyrinth() {

    delete floorTexture;
    delete wallTexture;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            delete mapObjects[j][i];
        }
    }
}

void Labyrinth::display() {

    if (viewState == 1) changeView();

    glRotatef(angle1, 0.0, 1.0, 0.0);
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glTranslatef(axisX, axisY, axisZ);


        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (mapIndexes[j][i] == 1) {
                    if(!load) mapObjects[j][i] = new Wall(wallTexture);
                    mapObjects[j][i]->draw(0.4 * i, 0.4 * (i + 1), -0.2, 0.2, -0.4 * j, -0.4 * (j + 1));
                }
                else {
                    if(!load) mapObjects[j][i] = new Floor(floorTexture);
                    mapObjects[j][i]->draw(0.4 * i, 0.4 * (i + 1), -0.2, 0.2, -0.4 * j, -0.4 * (j + 1));

                }
            }
        }
        load = true;

    glutSwapBuffers();
    if (viewState == 1) {
        this_thread::sleep_for(chrono::seconds(sleep));
        changeView();
        viewState = 0;
        glutPostRedisplay();
    }
}

void Labyrinth::changeView() {
    if (birdView == 1) {
        angle1Tmp = angle1;
        angle1 = 0.0;
        birdView = 0;
        axisXTemp = axisX;
        axisZTemp = axisZ;
        axisZ = 0.4 * (2 * 10) / 2;
        axisX = -0.4 * (2 * 10) / 2;
        axisY = -9.6;
        angle2 = 90.0;
    }
    else if (birdView == 0) {
        angle1 = angle1Tmp;
        birdView = 1;
        axisZ = axisZTemp;
        axisX = axisXTemp;
        axisY = 0.0;
        angle2 = 0.0;
    }
}

void Labyrinth::keyboard(unsigned char key, int x, int y, int &sceneId) {

    if (key == 27) {
        sceneId = 1;
        glutPostRedisplay();
    }
    else if (key == 'a' && birdView) {
        angle1 -= 1.0;
        if (angle1 > 360.0) angle1 -= 360.0;
        if (angle1 < 0) angle1 += 360.0;
        glutPostRedisplay();
    }
    else if (key == 'd' && birdView) {
        angle1 += 1.0;
        if (angle1 < 0.0) angle1 += 360.0;
        if (angle1 > 360.0) angle1 -= 360.0;
        glutPostRedisplay();
    }
    else if (key == 's' && birdView) {
        int x = -1 * (int) ((axisX + (0.1 * sin(angle1 * (3.14 / 180)))) / 0.4);
        int z = (int) ((axisZ - (0.1 * cos(angle1 * (3.14 / 180)))) / 0.4);
        if (x >= 0 && x < width && z >= 0 && z < height) {
            if (mapIndexes[z][x] == 0)axisX += 0.1 * sin(angle1 * (3.14 / 180));
            if (mapIndexes[z][x] == 0)axisZ -= 0.1 * cos(angle1 * (3.14 / 180));
        }
        else {
            axisX += 0.1 * sin(angle1 * (3.14 / 180));
            axisZ -= 0.1 * cos(angle1 * (3.14 / 180));
        }
        glutPostRedisplay();
    }
    else if (key == 'w' && birdView) {
        int x = -1 * (int) ((axisX - (0.1 * sin(angle1 * (3.14 / 180)))) / 0.4);
        int z = (int) ((axisZ + (0.1 * cos(angle1 * (3.14 / 180)))) / 0.4);
        if (x >= 0 && x < width && z >= 0 && z < height) {
            if (mapIndexes[z][x] == 0)axisX -= 0.1 * sin(angle1 * (3.14 / 180));
            if (mapIndexes[z][x] == 0)axisZ += 0.1 * cos(angle1 * (3.14 / 180));
        }
        else {
            axisX -= 0.1 * sin(angle1 * (3.14 / 180));
            axisZ += 0.1 * cos(angle1 * (3.14 / 180));
        }
        glutPostRedisplay();
    }
    else if (key == 9) {
        changeView();
        glutPostRedisplay();
    }

}

void Labyrinth::setStartPoint(int x, int y) {
    axisX = -0.4 * (2 * x + 1) / 2;
    axisZ = 0.4 * (2 * y + 1) / 2;
}





void Labyrinth::loadMap() {

    int fx, fy;

    ifstream map("res/map/map.txt");
    if (map.is_open()) {
        for (fy = 0; fy < height; fy++)
            for (fx = 0; fx < width; fx++)
                map >> mapIndexes[fy][fx];
    }
    map.close();

}
