//
// Created by hxn on 1/12/19.
//

#ifndef OOP_GAME_CIRCLE_H
#define OOP_GAME_CIRCLE_H

#include "util.h"
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

class Circle {
protected:
    float x;
public:
    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getRadius() const;

    void  setRadius(float radius);

protected:
    float y;
    //int d1;
    int cl;
public:

    float radius;

    int getCl() const;

    void setCl(int cl);

public:

    //int getD1() const;
    Circle();
    Circle(float X, float Y, float R, int cl);
    virtual void Draw()=0;
    //virtual void collisionDetection();
};


#endif //OOP_GAME_CIRCLE_H
