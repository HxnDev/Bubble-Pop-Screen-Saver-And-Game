//
// Created by hxn on 26/11/19.
//

#include "RoundRectangle.h"

RoundRectangle::RoundRectangle() {
    c5 = 6;

}

RoundRectangle::RoundRectangle(float x, float y, float width, float height, float radius)  {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->radius = radius;
}

float RoundRectangle::getX() const {
    return x;
}

void RoundRectangle::setX(float X) {
    RoundRectangle::x = X;
}

float RoundRectangle::getY() const {
    return y;
}

void RoundRectangle::setY(float Y) {
    RoundRectangle::y = Y;
}

float RoundRectangle::getWidth() const {
    return width;
}

void RoundRectangle::setWidth(float W) {
    RoundRectangle::width = W;
}

float RoundRectangle::getHeight() const {
    return height;
}

void RoundRectangle::setHeight(float H) {
    RoundRectangle::height = H;
}

float RoundRectangle::getRadius() const {
    return radius;
}

void RoundRectangle::setRadius(float R) {
    RoundRectangle::radius = R;
}

int RoundRectangle::getD() const {
    return d;
}

void RoundRectangle::setD(int D) {
    RoundRectangle::d = D;
}

void RoundRectangle::Draw() {

    DrawRoundRect(getX(), getY(), getWidth(), getHeight(), colors[c5], getRadius());
}

void RoundRectangle::collisionDetection() {

    if (x+radius >= 1300)
    {
        d =1;
        c5= rand() % 40;
    }

    if (x-radius <= 0)
    {
        d =2;
        c5=rand() % 40;
    }

    if (y+radius >= 780)
    {
        d=3;
        c5=rand() % 40;
    }

    if (y-radius <= 0)
    {
        d=4;
        c5=rand() % 40;
    }

}




