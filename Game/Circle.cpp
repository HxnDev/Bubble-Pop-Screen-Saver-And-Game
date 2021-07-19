//
// Created by hxn on 1/12/19.
//

#include "Circle.h"

Circle::Circle() {

    x=50;
    y=50;
}

Circle::Circle(float X, float Y, float R, int C) {

    x = X;
    y = Y;
    radius = R;
    cl = C;

}



float Circle::getX() const {
    return x;
}

void Circle::setX(float X) {
    Circle::x = X;
}

float Circle::getY() const {
    return y;
}

void Circle::setY(float Y) {
    Circle::y = Y;
}

float Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(float R) {
    Circle::radius = R;
}

int Circle::getCl() const {
    return cl;
}

void Circle::setCl(int C) {
    Circle::cl = C;
}
