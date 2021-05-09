//
// Created by hxn on 1/12/19.
//

#ifndef OOP_GAME_GREENCIRCLE_H
#define OOP_GAME_GREENCIRCLE_H

#include "Circle.h"
#include "util.h"
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

class GreenCircle:public Circle {

protected:
public:
    GreenCircle();

    float getRadius1() const;

    void setRadius1(float radius);

public:
    virtual void Draw();
};


#endif //OOP_GAME_GREENCIRCLE_H
