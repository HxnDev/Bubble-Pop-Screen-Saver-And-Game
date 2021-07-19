//
// Created by hxn on 24/11/19.
//

#include "Square.h"


float Square::getX() const {
    return x;
}

void Square::setX(float X) {
    Square::x = X;
}

float Square::getY() const {
    return y;
}

void Square::setY(float Y) {
    Square::y = Y;
}

float Square::getHeight() const {
    return height;
}

void Square::setHeight(float H) {
    Square::height = H;
}

float Square::getWidth() const {
    return width;
}

void Square::setWidth(float W) {
    Square::width = W;
}

int Square::getD() const {
    return d;
}

void Square::setD(int D) {
    Square::d = D;
}


void Square::Draw() {

    DrawRectangle(getX(), getY(), getWidth(), getHeight(), colors[cl2]);
}

Square::Square() {

    cl2 = 30;
    if (cl2 > 45)
    {
        cl2 = 30;
    }
}

void Square::collisionDetection() {
    if (x+width >= 1300)
    {
        d =1;
        cl2=rand() % 40;
    }

    if (x <= 0)
    {
        d =2;
        cl2=rand() % 40;
    }

    if (y+width >= 840)
    {
        d=3;
        cl2=rand() % 40;
    }

    if (y <= 0)
    {
        d=4;
        cl2=rand() % 40;
    }
}

Square::Square(float X, float Y, float W, float H) {

    x= X;
    y= Y;
    width = W;
    height = H;
}