//
// Created by hxn on 1/12/19.
//

#include "RedCircle.h"

void RedCircle::Draw() {

    DrawCircle(x,  y, radius, colors[RED]);
}


float RedCircle::getRadius1() const {
    return radius;
}

void RedCircle::setRadius1(float R) {
    radius = R;
}

RedCircle::RedCircle() : Circle() {
    cl = RED;
    radius = 30;
}