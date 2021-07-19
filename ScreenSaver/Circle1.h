//
// Created by hxn on 25/11/19.
//

#ifndef OOP_PROJECT_CIRCLE1_H
#define OOP_PROJECT_CIRCLE1_H

#include "Shape.h"
#include "util.h"
#include <GL/glut.h>

class Circle1: public Shape {

protected:
    float x;
    float y;
    float radius;
    int d2;
public:

    Circle1();
    virtual void Draw();
    virtual void moveCircle();
    virtual void collisionDetection();

    float getX() const;

    void setX(float x);

    float getY() const;

    int getD2() const;

    void setY(float y);

    float getRadius() const;

    void setRadius(float radius);

};


#endif //OOP_PROJECT_CIRCLE1_H
