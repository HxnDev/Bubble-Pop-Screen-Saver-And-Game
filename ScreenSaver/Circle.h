//
// Created by hxn on 24/11/19.
//

#ifndef OOP_PROJECT_CIRCLE_H
#define OOP_PROJECT_CIRCLE_H

#include "Shape.h"
#include "util.h"
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

class Circle:public Shape {

protected:
    float x;
    float y;
    float radius;
    int d1;
    int cl;
public:
    int getD1() const;

public:
    Circle();
    Circle(float X, float Y, float R);
    float getX();
    void setX(float x);
    float getY() const;
    void setY(float y);
    float getRadius() const;
    void setRadius(float radius);
    virtual void Draw();
//    virtual void moveCircle(int n);
    virtual void collisionDetection();

};


#endif //OOP_PROJECT_CIRCLE_H
