//
// Created by hxn on 24/11/19.
//

#ifndef OOP_PROJECT_SHAPE_H
#define OOP_PROJECT_SHAPE_H
#include <iostream>
#include "util.h"
#include <GL/glut.h>

using namespace std;

class Shape {

public:
    virtual void Draw()=0;
};


#endif //OOP_PROJECT_SHAPE_H
