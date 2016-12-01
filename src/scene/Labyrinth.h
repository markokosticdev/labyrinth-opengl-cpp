#ifndef LABYRINTH_OPENGL_CPP_LABYRINTH_H
#define LABYRINTH_OPENGL_CPP_LABYRINTH_H


#include <GL/glut.h>
#include <fstream>
#include <cmath>
#include <chrono>
#include <thread>
#include "Scene.h"
#include "../object/Texture.h"
#include "../object/Object.h"
#include "../object/Floor.h"
#include "../object/Wall.h"

using namespace std;

class Labyrinth : public Scene {

private:

    Texture *floorTexture; // floor texture
    Texture *wallTexture; // wall texture
    double angle1 = 0.0; // angle 1
    double angle1Tmp = 0.0; //temporarily angle 1
    double angle2 = 0.0; // angle 2
    double axisX = 0.0; // x axis
    double axisXTemp = 0.0; // temporarily x axis
    double axisY = 0.0; //
    double axisZ = -5.0; // z axis
    double axisZTemp = 0.0; // temporarily z axis
    int sleep = 3; // sleep view change
    int viewState = 1; // view state
    int birdView = 1; // bird view state
    int width = 20; // labyrinth width
    int height = 20; // labyrinth width
    bool load = false; // labyrinth first load
    Object *mapObjects[20][20]; // map of objects
    int mapIndexes[20][20] = { // map of indexes
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},

        {1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},

        {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},

        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
    };

public:

    Labyrinth();

    virtual ~Labyrinth();

    void display(); // display labyrinth

    void keyboard(unsigned char key, int x, int y, int &sceneId); // keyboard labyrinth functions

    void setStartPoint(int x, int y); // set start pont in labyrinth

    void changeView(); // change view

    void loadMap(); // load map from file

};


#endif //LABYRINTH_OPENGL_CPP_LABYRINTH_H
