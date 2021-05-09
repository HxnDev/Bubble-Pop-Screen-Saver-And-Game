//
// Created by hxn on 1/12/19.
//

#include "GreenCircle.h"

void GreenCircle::Draw() {

    DrawCircle(x,  y, radius, colors[GREEN]);
}

float GreenCircle::getRadius1() const {
    return radius;
}

void GreenCircle::setRadius1(float R) {
    GreenCircle::radius = R;
}

GreenCircle::GreenCircle() {
    cl = GREEN;
    radius = 30;
}


