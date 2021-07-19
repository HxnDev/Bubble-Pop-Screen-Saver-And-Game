//
// Created by hxn on 25/11/19.
//

#include "Circle1.h"

Circle1::Circle1() {
    x = 20;
    y = 20;
    radius = 20;
}


float Circle1::getX() const {
    return x;
}

void Circle1::setX(float X) {
    Circle1::x = X;
}

float Circle1::getY() const {
    return y;
}

void Circle1::setY(float Y) {
    Circle1::y = Y;
}

float Circle1::getRadius() const {
    return radius;
}

void Circle1::setRadius(float r) {
    Circle1::radius = r;
}

int Circle1::getD2() const {
    return d2;
}


void Circle1::moveCircle() {

    x+=3;
    y+=3;
}

void Circle1::collisionDetection() {
    if (x+10 >= 1020)
    {
        d2 =1;
    }

    if (x-10 <= 0)
    {
        d2 =2;
    }

    if (y+10 >= 840)
    {
        d2 =3;
    }

    if (y-10 <= 0)
    {
        d2 =4;
    }
}

void Circle1::Draw() {
    DrawCircle(getX(),  getY(), getRadius(), colors[30]);
}



