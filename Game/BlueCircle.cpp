//
// Created by hxn on 1/12/19.
//

#include "BlueCircle.h"

void BlueCircle::Draw() {

    DrawCircle(x,  y, radius, colors[BLUE]);

}

float BlueCircle::getRadius1() const {
    return radius;
}

void BlueCircle::setRadius1(float R) {
    BlueCircle::radius = R;
}

BlueCircle::BlueCircle() {
    cl = BLUE;
    radius = 30;
}

