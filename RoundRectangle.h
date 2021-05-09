//
// Created by hxn on 26/11/19.
//

#ifndef OOP_PROJECT_ROUNDRECTANGLE_H
#define OOP_PROJECT_ROUNDRECTANGLE_H

#include "Shape.h"
#include "util.h"
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

class RoundRectangle: public Shape {

protected:
    float x;
    float y;
    float width;
public:
    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getWidth() const;

    void setWidth(float width);

    float getHeight() const;

    void setHeight(float height);

    float getRadius() const;

    void setRadius(float radius);

    int getD() const;

    void setD(int d);

protected:
    float height;
    float radius;
    int c5=6;
    int d;

public:
    RoundRectangle();

    RoundRectangle(float x, float y, float width, float height, float radius);

    virtual void Draw();

    virtual void collisionDetection();
};


#endif //OOP_PROJECT_ROUNDRECTANGLE_H
