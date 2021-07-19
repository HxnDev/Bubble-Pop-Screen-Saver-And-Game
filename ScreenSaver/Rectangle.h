//
// Created by hxn on 24/11/19.
//

#ifndef OOP_PROJECT_RECTANGLE_H
#define OOP_PROJECT_RECTANGLE_H

#include "Shape.h"
#include "util.h"
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

class Rectangle: public Shape {

protected:
    float x;
    float y;
    float height;
    float width;
    int d;
    int cl1;
public:
    int getD();

public:
    Rectangle();

    Rectangle(float x, float y, float width, float height);

    float getX() const;

    void setX(float sx);

    float getY() const;

    void setY(float sy);

    float getHeight() const;

    void setHeight(float h);

    float getWidth() const;

    void setWidth(float w);

    virtual void Draw();

//    virtual void moveRectangle(int n);

    virtual void collisionDetection();
};


#endif //OOP_PROJECT_RECTANGLE_H
