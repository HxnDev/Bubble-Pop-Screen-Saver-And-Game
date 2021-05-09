//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Brick Slayer...
//============================================================================

#ifndef Bomberman_CPP_
#define Bomberman_CPP_
#include "Board.h"
#include "util.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "RoundRectangle.h"
#include <iostream>
#include<string>
#include<cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Declarations

int direct = 1;
int direct1 = 1;
int direct2 = 1;
int direct3 = 1;
int direct4 = 1;
int direct5 = 1;
/*________________________________________________________________________________________________________________________________________________________________________________*/


/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*________________________________________________________________________________________________________________________________________________________________________________*/
Circle c (400, 400, 50);

void circleDirection() {
    switch (direct) {

        case 1:
            c.setY(c.getY() +5);
            break;

        case 2:
            c.setY(c.getY() -5);

    }
}

void CdirectionChange()
{
    if (c.getD1()==3)
    {
        direct = 2;
    }

    if (c.getD1()==4)
    {
        direct = 1;
    }

}





/*________________________________________________________________________________________________________________________________________________________________________________*/

//Circle1

 Circle c1(300, 0, 60);

void circle1Direction() {
    switch (direct2) {

        case 1:
            c1.setY(c1.getY() +3); c1.setX(c1.getX() +3);
            break;

        case 2:
            c1.setY(c1.getY() +3); c1.setX(c1.getX() -3);
            break;

        case 3:
            c1.setY(c1.getY() -3); c1.setX(c1.getX() -3);
            break;

        case 4:
            c1.setY(c1.getY() -3); c1.setX(c1.getX() +3);
            break;
    }
}


void C1directionChange()
{
    if (c1.getD1()== 1)
    {
        if (direct2 == 1)
        {
            direct2 = 2;
        }
        else if (direct2 == 4)
        {
            direct2 = 3;
        }
    }

    if (c1.getD1()==3)
    {
        if (direct2 == 2)
        {
            direct2 = 3;
        }
        else if (direct2 == 1)
        {
            direct2 = 4;
        }
    }

    if (c1.getD1()==2)
    {
        if (direct2 == 3)
        {
            direct2 = 4;
        }
        else if (direct2 == 2)
        {
            direct2 = 1;
        }
    }

    if (c1.getD1()==4)
    {
        if (direct2 == 4)
        {
            direct2 = 1;
        }
        else if( direct2 == 3)
        {
            direct2 = 2;
        }
    }

}



/*________________________________________________________________________________________________________________________________________________________________________________*/
Rectangle r(400,400,100,150);

void rectangleDirection()
{
    switch (direct1)
    {
        case 1:
            r.setX(r.getX()+3);
            break;

        case 2:
            r.setX(r.getX() -3);
            break;


    }
}

void RdirectionChange()
{
    if (r.getD()==1)
    {
        direct1 = 2;
    }

    if (r.getD()==2)
    {
        direct1 = 1;
    }

}

/*________________________________________________________________________________________________________________________________________________________________________________*/

Rectangle r1(600,0,70,100);

void rectangle1Direction()
{
    switch (direct3)
    {
        case 1:
            r1.setY(r1.getY()+5);
            break;

        case 2:
            r1.setY(r1.getY() -5);
            break;


    }
}

void R1directionChange()
{
    if (r1.getD()==3)
    {
        direct3 = 2;
    }

    if (r1.getD()==4)
    {
        direct3 = 1;
    }

}
/*________________________________________________________________________________________________________________________________________________________________________________*/

// Square

Square sq(50,790,100,100);

void SquareDirection()
{
    switch (direct4)
    {
        case 1:
             sq.setX(sq.getX() +3); sq.setY(sq.getY() -3);
             break;

        case 2:
            sq.setX(sq.getX() +3); sq.setY(sq.getY() +3);
            break;

        case 3:
            sq.setX(sq.getX() -3); sq.setY(sq.getY() +3);
            break;

        case 4:
            sq.setX(sq.getX() -3); sq.setY(sq.getY() -3);
            break;
    }
}

void SqdirectionChange()
{
    if (sq.getD()==1)
    {
        if (direct4 == 1)
        {
            direct4 = 4;
        }
        else if (direct4 == 2)
        {
            direct4 = 3;
        }
    }

    if (sq.getD()==4)
    {
        if (direct4 == 1)
        {
            direct4 = 2;
        }
        else if (direct4 == 4)
        {
            direct4 = 3;
        }

    }
    if (sq.getD()==2)

    {
        if (direct4 == 4)
        {
            direct4 = 3;
        }
        else if (direct4 == 3)
        {
            direct4 = 2;
        }

    }

    if (sq.getD()==3)
    {
        if (direct4 == 2)
        {
            direct4 = 1;
        }
        else if (direct4 == 3)
        {
            direct4 = 4;
        }

    }
}
/*________________________________________________________________________________________________________________________________________________________________________________*/
// Rounded Rectangle

RoundRectangle rr (1220, 20, 100, 80, 20 );

void RRDirection()
{
    switch (direct5)
    {
        case 1:
            rr.setX(rr.getX() -1); rr.setY(rr.getY() +1);
            break;

        case 2:
            rr.setX(rr.getX() +1); rr.setY(rr.getY() +1);
            break;

        case 3:
            rr.setX(rr.getX() +1); rr.setY(rr.getY() -1);
            break;

        case 4:
            rr.setX(rr.getX() -1); rr.setY(rr.getY() -1);
            break;

    }
}

void RRdirectionChange() {
    if (rr.getD() == 1) {
        direct5 = 1;
    }

    if (rr.getD() == 2) {
        direct5 = 3;
    }

    if (rr.getD() == 3) {
        direct5 = 4;
    }

    if (rr.getD() == 4) {
        direct5 = 2;
    }

}



void CollisionCheckC1()
{
//Circle1

int x;
int y;
    if (c.getX()+c.getRadius() + c1.getRadius() > c1.getX() and c.getX() < c1.getX()+c1.getRadius() + c.getRadius() and c.getY()+c.getRadius()+c1.getRadius() > c1.getY() and c.getY() < c1.getY()+c1.getRadius() + c.getRadius())
    {
        direct2 = 1;
    }

//Circle with Rectangle
   /* if (c.getX() < r.getX())
    {
        x = r.getX();
    }
    else if (c.getX() > r.getX() + r.getWidth())
    {
        x = r.getX() + r.getWidth();
    }

    if (c.getY() < r.getY())
    {
        y = r.getY();
    }

    else if (c.getY() > r.getY() +r.getHeight())
    {
        y = r.getY() + r.getHeight();
    }

    if ((c.getX()-x)*(r.getX() - x) + (c.getY() - y)*(r.getY() - y) <= c.getRadius())
    {
        direct2 = 1;
    }*/


//Square
   /* else if ((c.getX()+c.getRadius() == sq.getX()+sq.getWidth()) and (c.getY()+c.getRadius() == sq.getY()+sq.getWidth()))
    {
        direct = direct % 4;
        direct4 = direct4 % 4;
    }
//Rectangle 1
    else if ((c.getX()+c.getRadius() == r.getX()+r.getWidth()) and (c.getY()+c.getRadius() == r.getY()+r.getHeight()))
    {
        direct = direct % 4;
        direct1 = direct1 % 4;
    }
//Rectangle 2
    else if ((c.getX()+c.getRadius() == r1.getX()+r1.getWidth()) and (c.getY()+c.getRadius() == r1.getY()+r1.getHeight()))
    {
        direct = direct % 4;
        direct3 = direct3 % 4;
    }
//Rounded Rectangle

    else if ((c.getX()+c.getRadius() == rr.getX()+rr.getRadius()) and (c.getY()+c.getRadius() == rr.getY()+rr.getRadius()))
    {
        direct = direct % 4;
        direct5 = direct5 % 4;
    }*/

//Rectangle with Rectangle1

    if (r1.getX() >=r.getX() and r1.getX() <= r.getX()+r.getWidth()) {

    if (r1.getY() == r.getY() + r.getHeight()) {
        direct3 = 1;
    } else if (r1.getY() + r1.getHeight() == r.getY()) {
        direct3 = 2;
    }
}


    if (r.getX()+ r.getWidth() == r1.getX())
    {
        direct1 = 2;
    }
    else if (r.getX() ==r1.getX() +r1.getWidth())
    {
        direct1 = 1;
    }
}

/*________________________________________________________________________________________________________________________________________________________________________________*/
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	//Circle 1
    c.Draw();
    circleDirection();
    c.collisionDetection();
    CdirectionChange();
    CollisionCheckC1();

    //Circle 2
    c1.Draw();
    circle1Direction() ;
    c1.collisionDetection();
    C1directionChange();

    //Rectangle 1
    r.Draw();
    rectangleDirection();
    r.collisionDetection();
    RdirectionChange();

    //Rectangle 2
    r1.Draw();
    rectangle1Direction();
    r1.collisionDetection();
    R1directionChange();

    //Square
    sq.Draw();
    SquareDirection();
    sq.collisionDetection();
    SqdirectionChange();

    //Round Rectangle
    rr.Draw();
    RRDirection();
    rr.collisionDetection();
    RRdirectionChange();

    glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

/*________________________________________________________________________________________________________________________________________________________________________________*/

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {


	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	 glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
//			{
//		bombStatus = true;

//	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*
 * our gateway main function
 * */


/*________________________________________________________________________________________________________________________________________________________________________________*/


int main(int argc, char*argv[]) {


	int width = 1300, height = 840; // i have set my window size to be 800 x 600
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("CP's Bomber Bomberman"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
#ifdef WITH_TEXTURES
	RegisterTextures();
#endif
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* Bomberman_CPP_ */
