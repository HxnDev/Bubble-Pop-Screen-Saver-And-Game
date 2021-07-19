//
// Created by hxn on 1/12/19.
//

#include "YellowCircle.h"

void YellowCircle::Draw() {

    DrawCircle(x,  y, radius, colors[YELLOW]);
}

float YellowCircle::getRadius1() const {
    return radius;
}

void YellowCircle::setRadius1(float R) {
    YellowCircle::radius = R;
}

YellowCircle::YellowCircle() {
    cl = YELLOW;
    radius = 30;
}
