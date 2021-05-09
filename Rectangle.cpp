//
// Created by hxn on 24/11/19.
//

#include "Rectangle.h"

float Rectangle::getX() const {
    return x;
}

void Rectangle::setX(float sx) {
    Rectangle::x = sx;
}

float Rectangle::getY() const {
    return y;
}

void Rectangle::setY(float sy) {
    Rectangle::y = sy;
}

float Rectangle::getHeight() const {
    return height;
}

void Rectangle::setHeight(float h) {
    Rectangle::height = h;
}

float Rectangle::getWidth() const {
    return width;
}

void Rectangle::setWidth(float w) {
    Rectangle::width = w;
}

void Rectangle::Draw() {

    DrawRectangle(getX(), getY(), getWidth(), getHeight(), colors[cl1]);
}

Rectangle::Rectangle() {
   cl1 = 20;
    if (cl1 > 30)
    {
        cl1 = 20;
    }
   }

/*void Rectangle::moveRectangle( int n) {
    x-=n;

}*/

void Rectangle::collisionDetection() {

    if (x+width >= 1300)
    {
        d =1;
        cl1=rand() % 40;
    }

    if (x <= 0)
    {
        d =2;
        cl1=rand() % 40;
    }

    if (y+height >= 840)
    {
        d=3;
        cl1=rand() % 40;
    }

    if (y <= 0)
    {
        d=4;
        cl1=rand() % 40;
    }
}

int Rectangle::getD() {
    return d;
}

Rectangle::Rectangle(float X, float Y, float W, float H) {
    x=X;
    y=Y;
    width=W;
    height=H;
}
