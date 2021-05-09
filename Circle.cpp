//
// Created by hxn on 24/11/19.
//

#include "Circle.h"

float Circle::getX() {
    return x;
}

void Circle::setX(float sx) {
    Circle::x = sx;
}

float Circle::getY() const {
    return y;
}

void Circle::setY(float sy) {
    Circle::y = sy;
}

float Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(float r) {
    Circle::radius = r;
}

void Circle::Draw() {


   DrawCircle(getX(),  getY(), getRadius(), colors[cl]);

}

Circle::Circle(float X, float Y, float R) {

    x = X;
    y = Y;
    radius = R;
}

/*void Circle:: moveCircle(int n) {

   x+=n;
   y+=n;


}*/

void Circle::collisionDetection() {
    if (x+radius >= 1300)
    {
        d1 =1;
        cl=rand() % 40;
    }

    if (x-radius <= 0)
    {
        d1 =2;
        cl=rand() % 40;
    }

    if (y+radius >= 840)
    {
        d1 =3;
        cl=rand() % 40;
    }

    if (y-radius <= 0)
    {
        d1 =4;
        cl=rand() % 40;
    }

}

int Circle::getD1() const {
    return d1;
}

Circle::Circle() {

    cl =rand() % 40;

}


