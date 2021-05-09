//
// Created by hxn on 24/11/19.
//

#ifndef OOP_PROJECT_SQUARE_H
#define OOP_PROJECT_SQUARE_H

#include "Shape.h"
#include "util.h"
#include <GL/glut.h>

class Square: public Shape {

protected:
    float x;
    float y;
    float height;
    float width;
    int d;
public:
    Square();
    Square(float x, float y, float width, float height);

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getHeight() const;

    void setHeight(float height);

    float getWidth() const;

    void setWidth(float width);

    int getD() const;

    void setD(int d);

protected:
    int cl2;

public:

    virtual void Draw();
    virtual void collisionDetection();
};


#endif //OOP_PROJECT_SQUARE_H
