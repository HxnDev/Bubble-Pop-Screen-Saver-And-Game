//
// Created by hxn on 1/12/19.
//

#ifndef OOP_GAME_BLUECIRCLE_H
#define OOP_GAME_BLUECIRCLE_H

#include "Circle.h"
#include "util.h"
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

class BlueCircle:public Circle {

public:
    float getRadius1() const;

    void setRadius1(float radius);

public:
    virtual void Draw();

    BlueCircle();
};


#endif //OOP_GAME_BLUECIRCLE_H
