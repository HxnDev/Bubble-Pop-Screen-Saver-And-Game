//
// Created by hxn on 1/12/19.
//

#ifndef OOP_GAME_YELLOWCIRCLE_H
#define OOP_GAME_YELLOWCIRCLE_H

#include "Circle.h"
#include "util.h"
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

class YellowCircle:public Circle {

protected:
public:
    float getRadius1() const;

    void setRadius1(float radius);

public:
    YellowCircle();

public:
    virtual void Draw();
};


#endif //OOP_GAME_YELLOWCIRCLE_H
