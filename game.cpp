//============================================================================
//	Hassan Shahzad
//	18i-0441
//	FAST-NUCES
//	Bubble Pop Game Project
//	Contact at : chhxnshah@gmail.com
//============================================================================


//#include "Board.h"
#include "util.h"
#include "Circle.h"
#include "RedCircle.h"
#include "BlueCircle.h"
#include "YellowCircle.h"
#include "GreenCircle.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include<string>
#include<cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Declarations

int sg;
int scount=0;
int screen = 1;
float R = 40;
int score = 0;
int fscore;
bool flag = true;
int initialTime;
int currentTime;
int count1 =0;
int count2 =0;
int count3 =0;
int count4 =0;

/*________________________________________________________________________________________________________________________________________________________________________________*/

int rx[5] = {30, 70, 850, 750, 1100};
int ry[5] = {30, 720, 600, 270, 490};

int yx[5] = {1010, 40, 550, 240, 760};
int yy[5] = {30, 360, 240, 640, 710};

int gx[5] = {1250, 440, 670, 920, 700};
int gy[5] = {490, 270, 480, 140, 640};

int bx[5] = {670, 230, 560, 1030, 30};
int by[5] = {180, 700, 90, 580, 500};

/*________________________________________________________________________________________________________________________________________________________________________________*/


RedCircle* rptr;
YellowCircle* yptr;
GreenCircle* gptr;
BlueCircle* bptr;
Circle *ptr;




/*________________________________________________________________________________________________________________________________________________________________________________*/


/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */

/*________________________________________________________________________________________________________________________________________________________________________________*/

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void GameWon()
{
    if (scount == 5)
    {
        screen =9;
    }
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

float Distance(int x1, int x2, int y1, int y2)
{
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2) * 1.0);
}

/*________________________________________________________________________________________________________________________________________________________________________________*/
string convertToString(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

/*________________________________________________________________________________________________________________________________________________________________________________*/
string getStringScore()
{
    fstream scoreFile("scores.txt", ios::in);

    string str1;
    getline(scoreFile, str1);

    scoreFile.close();
    stringstream ss(str1);
    ss >> fscore;

    return str1;
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

int getIntScore()
{
    fstream scoreFile("scores.txt", ios::in);

    string str1;
    getline(scoreFile, str1);

    scoreFile.close();
    stringstream ss(str1);
    ss >> fscore;

    return fscore;
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void checkAndUpdateScore() {
    if (score > fscore) {
        ofstream outFile("scores.txt");
        outFile << convertToString(score);
    }
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void DisplayScore() {
    DrawString(1000, 820, "Score = " + convertToString(score), colors[GOLD]);
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void DisplayBackButton()
{
    DrawRectangle(520,20,130,50,colors[BLACK]);
    DrawString(530, 35 , "GO BACK", colors[LAVENDER_BLUSH]);
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void SetCircles() {
    rptr = new RedCircle[5];

    for (int i = 0; i < 5; i++) {
        rptr[i].setX(rx[i]);
        rptr[i].setY(ry[i]);
        //rptr[i].setRadius(30);
    }

    yptr = new YellowCircle[5];

    for (int i = 0; i < 5; i++) {
        yptr[i].setX(yx[i]);
        yptr[i].setY(yy[i]);
    }

    gptr = new GreenCircle[5];

    for (int i = 0; i < 5; i++) {
        gptr[i].setX(gx[i]);
        gptr[i].setY(gy[i]);
    }

    bptr = new BlueCircle[5];

    for (int i = 0; i < 5; i++) {
        bptr[i].setX(bx[i]);
        bptr[i].setY(by[i]);
    }
}
/*
    circles[0] = new RedCircle[5];
    circles[1] = new BlueCircle[5];
    circles[2] = new YellowCircle[5];
    circles[3] = new GreenCircle[5];

    int j=0;
    for (int i=0; i<5; i++)
    {
        circles[0][i].setX(x[i]);
        circles[0][i].setY(y[i]);
        j++;
    }

    for (int i=0; i<5 ; i++)
    {
        circles[1][i].setX(x[j]);
        circles[1][i].setY(y[j]);
        j++;
    }

    for (int i=0; i<5 ; i++)
    {
        circles[2][i].setX(x[j]);
        circles[2][i].setY(y[j]);
        j++;
    }

    for (int i=0; i<5 ; i++)
    {
        circles[3][i].setX(x[j]);
        circles[3][i].setY(y[j]);
        j++;
    }

}
*/

/*________________________________________________________________________________________________________________________________________________________________________________*/

void DrawCircle()
{
        for (int j=0; j<5; j++)
        {
            rptr[j].Draw();
        }

        for (int j=0; j<5; j++)
        {
            yptr[j].Draw();
        }

        for (int j=0; j<5; j++)
        {
            gptr[j].Draw();
        }

        for (int j=0; j<5; j++)
        {
            bptr[j].Draw();
        }

}
    float radius=30;

/*________________________________________________________________________________________________________________________________________________________________________________*/

void CollisionCheckRed(int i)
{

    float DisX = ptr->getX() - rptr[i].getX();
    float DisY = ptr->getY() - rptr[i].getY();

    float distance = sqrt((DisX*DisX)+(DisY*DisY));

    distance = distance - (ptr->radius + rptr[i].getRadius1());

    if (distance <=  0)
    {
        score +=10;
        rptr[i].setX(-900);
        rptr[i].setY(-900);
        R+=5;
        scount++;
    }

}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void CollisionCheckBlue(int i)
{
    float DisX = ptr->getX() - bptr[i].getX();
    float DisY = ptr->getY() - bptr[i].getY();

    float distance = sqrt((DisX*DisX)+(DisY*DisY));

    distance = distance - (ptr->radius + bptr[i].getRadius1());

    if (distance <=  0)
    {
        score +=10;
        bptr[i].setX(-900);
        bptr[i].setY(-900);
        R+=5;
        scount++;
    }

}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void CollisionCheckGreen(int i)
{
    float DisX = ptr->getX() - gptr[i].getX();
    float DisY = ptr->getY() - gptr[i].getY();

    float distance = sqrt((DisX*DisX)+(DisY*DisY));

    distance = distance - (ptr->radius + gptr[i].getRadius1());

    if (distance <=  0)
    {
        score +=10;
        gptr[i].setX(-900);
        gptr[i].setY(-900);
        R+=5;
        scount++;
    }

}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void CollisionCheckYellow(int i)
{
    float DisX = ptr->getX() - yptr[i].getX();
    float DisY = ptr->getY() - yptr[i].getY();

    float distance = sqrt((DisX*DisX)+(DisY*DisY));

    distance = distance - (ptr->radius + yptr[i].getRadius1());

    if (distance <=  0)
    {
        score +=10;
        yptr[i].setX(-900);
        yptr[i].setY(-900);
        R+=5;
        scount++;
    }
}


/*________________________________________________________________________________________________________________________________________________________________________________*/

void CollisionWithRed(int i)
{
    float DisX = ptr->getX() - rptr[i].getX();
    float DisY = ptr->getY() - rptr[i].getY();

    float distance = sqrt((DisX*DisX)+(DisY*DisY));

    distance = distance - (ptr->radius + rptr[i].getRadius1());

    if (distance <=  0)
    {
        score -=10;
        rptr[i].setX(-900);
        rptr[i].setY(-900);
        R-=5;
        count4++;
    }
    if (count4 ==3)
    {
        screen = 9;
    }

}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void CollisionWithBlue(int i)
{
    float DisX = ptr->getX() - bptr[i].getX();
    float DisY = ptr->getY() - bptr[i].getY();

    float distance = sqrt((DisX*DisX)+(DisY*DisY));

    distance = distance - (ptr->radius + bptr[i].getRadius1());

    if (distance <=  0)
    {
        score -=10;
        bptr[i].setX(-900);
        bptr[i].setY(-900);
        R-=5;
        count1++;
    }
    if (count1 ==3)
    {
        screen = 9;
    }



}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void CollisionWithGreen(int i)
{

    float DisX = ptr->getX() - gptr[i].getX();
    float DisY = ptr->getY() - gptr[i].getY();

    float distance = sqrt((DisX*DisX)+(DisY*DisY));

    distance = distance - (ptr->radius + gptr[i].getRadius1());

    if (distance <=  0)
    {
        score -=10;
        gptr[i].setX(-900);
        gptr[i].setY(-900);
        R-=5;
        count2++;
    }
    if (count2 ==3)
    {
        screen = 9;
    }

}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void CollisionWithYellow(int i)
{

    float DisX = ptr->getX() - yptr[i].getX();
    float DisY = ptr->getY() - yptr[i].getY();

    float distance = sqrt((DisX*DisX)+(DisY*DisY));

    distance = distance - (ptr->radius + yptr[i].getRadius1());

    if (distance <=  0)
    {
        score -=10;
        yptr[i].setX(-900);
        yptr[i].setY(-900);
        R-=5;
        count3++;
    }
    if (count3 ==3)
    {
        screen = 9;
    }


}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void displayTimer() {

    if (screen ==3 or screen  == 4 or screen  ==5 or screen ==6)
    {
    currentTime = time(NULL);
    int diff = (currentTime - initialTime);

    DrawRoundRect(10, 800, 1200 - (diff*10), 5, colors[MAGENTA], 5);
    DrawString(100, 820 , "Time = " + convertToString(120-diff), colors[GOLD]);

    if ( diff == 120)
    {
        screen =9;
    }
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

/*________________________________________________________________________________________________________________________________________________________________________________*/

//MENU
if (screen==1) //Menu
{
//Title
    DrawRectangle(0,0,1300,840,colors[BLACK]);
    DrawString(520, 810 , "Bubble Pop by HXN", colors[10]);

//Design
    DrawCircle(10,10,100,colors[YELLOW]);
    DrawCircle(1300,840,100,colors[GREEN]);
    DrawCircle(1300,10,100,colors[BLUE]);
    DrawCircle(10,840,100,colors[RED]);

//Option 1(Start Game)
    DrawRectangle(400,600,400,50,colors[GOLD]);
    DrawString(530, 617 , "PLAY GAME", colors[BLACK]);
//Option 2(Rules)
    DrawRectangle(400,500,400,50,colors[GOLD]);
    DrawString(530, 517 , "RULES", colors[BLACK]);
//Option 3(Instructions)
    DrawRectangle(400,400,400,50,colors[GOLD]);
    DrawString(530, 417 , "INSTRUCTIONS", colors[BLACK]);

//Option 4 (Highscore)
    DrawRectangle(400,300,400,50,colors[GOLD]);
    DrawString(530, 317 , "HIGH SCORE", colors[BLACK]);

//Option 5 (Exit)
    DrawRectangle(400,200,400,50,colors[GOLD]);
    DrawString(530, 217 , "EXIT GAME", colors[BLACK]);

}

/*________________________________________________________________________________________________________________________________________________________________________________*/

else if (screen==2) //Color Choice
{
//Title
    DrawRectangle(0, 0, 1300, 840, colors[WHITE]);
    DrawString(400,780,"Please Select Your Color To Start With: ",colors[BLACK]);

//Colors Choice
    DrawCircle(300,600,100,colors[YELLOW]);
    DrawCircle(900,600,100,colors[GREEN]);
    DrawCircle(300,300,100,colors[BLUE]);
    DrawCircle(900,300,100,colors[RED]);
//Design
    DrawCircle(10,10,100,colors[YELLOW]);
    DrawCircle(1300,840,100,colors[GREEN]);
    DrawCircle(1300,10,100,colors[BLUE]);
    DrawCircle(10,840,100,colors[RED]);
//Back Button
    DisplayBackButton();
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

else if (screen ==3)        //Red Game Interface
{
    DrawRectangle(0,0,1300,850,colors[BLACK]);
    DrawCircle();

    ptr->radius = R;
    ptr->Draw();

    for (int i=0; i<5; i++)
    {
        CollisionCheckRed(i);
        CollisionWithBlue(i);
        CollisionWithGreen(i);
        CollisionWithYellow(i);

    }
    GameWon();

    displayTimer();
    DisplayScore();

    glutPostRedisplay();
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

else if (screen ==4)        //Blue Game Interface
{
    DrawRectangle(0,0,1300,850,colors[BLACK]);
    DrawCircle();
    ptr->radius = R;
    ptr->Draw();

    for (int i=0; i<5; i++)
    {
        CollisionCheckBlue(i);

        CollisionWithRed(i);
        CollisionWithGreen(i);
        CollisionWithYellow(i);
    }

    GameWon();
    displayTimer();
    DisplayScore();

    glutPostRedisplay();
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

else if (screen ==5)        //Green Game Interface
{
    DrawRectangle(0,0,1300,850,colors[BLACK]);
    DrawCircle();
    ptr->radius = R;
    ptr->Draw();

    for (int i=0; i<5; i++)
    {
        CollisionCheckGreen(i);


        CollisionWithBlue(i);
        CollisionWithRed(i);
        CollisionWithYellow(i);
    }
    GameWon();
    displayTimer();
    DisplayScore();

    glutPostRedisplay();
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

else if (screen ==6)        //Yellow Game Interface
{
    DrawRectangle(0,0,1300,850,colors[BLACK]);
    DrawCircle();
    ptr->radius = R;
    ptr->Draw();


    for (int i=0; i<5; i++)
    {
        CollisionCheckYellow(i);


        CollisionWithBlue(i);
        CollisionWithGreen(i);
        CollisionWithRed(i);
    }
    GameWon();
    displayTimer();
    DisplayScore();

    glutPostRedisplay();
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

else if (screen==7) //Rules Screen
{
//Heading
    DrawRectangle(0,0,1300,850,colors[GOLDEN_ROD]);
    DrawRectangle(190,650,80,40,colors[GOLD]);
    DrawString(200,660,"Rules:  ",colors[BLACK]);
//Rules
    DrawString(300,600,"Rule #1: You Can Select Only 1 Color At the Start of The Game.   ",colors[BLACK]);
    DrawString(300,500,"Rule #2: You Can Collide It With The Balloons Of Same Color Only.   ",colors[BLACK]);
    DrawString(300,400,"Rule #3: Collision With The Balloons Of Different Colors Will Result In Loss Of Points.   ",colors[BLACK]);
    DrawString(300,300,"Rule #4: If You Collide With 3 Or More Balloons Of Different Colors, Your Will Lose.  ",colors[BLACK]);

//Design
    DrawCircle(10,10,100,colors[YELLOW]);
    DrawCircle(1300,840,100,colors[GREEN]);
    DrawCircle(1300,10,100,colors[BLUE]);
    DrawCircle(10,840,100,colors[RED]);
//Back Button
    DisplayBackButton();
    glutPostRedisplay();
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

else if (screen==8)     //Instructions Screen
{
//Heading
    DrawRectangle(0,0,1300,850,colors[GOLDEN_ROD]);
    DrawRectangle(190,750,140,40,colors[GOLD]);
    DrawString(200,760,"Instructions: ",colors[BLACK]);

//Instructions
    DrawString(300,700,"1: Click on Start Game for Game to Start.",colors[BLACK]);
    DrawString(300,600,"2: You can choose from 4 different colors.",colors[BLACK]);
    DrawString(300,500,"3: Drag the balloon to collide with same color.",colors[BLACK]);
    DrawString(300,400,"4: Each collision with the same color will earn you 10 points.",colors[BLACK]);
    DrawString(300,300,"5: Each collision with the different color will lose you 10 points.",colors[BLACK]);
    DrawString(300,200,"6: You will have 2 minutes to play the game and score as much as you can.",colors[BLACK]);
    DrawString(300,100,"7: After 2 minutes the game will be over.",colors[BLACK]);

//Design
    DrawCircle(10,10,100,colors[YELLOW]);
    DrawCircle(1300,840,100,colors[GREEN]);
    DrawCircle(1300,10,100,colors[BLUE]);
    DrawCircle(10,840,100,colors[RED]);

//Back Button
    DisplayBackButton();
    glutPostRedisplay();
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

else if (screen==9)     //Exit Screen
{
//Heading
    DrawRectangle(0,0,1300,850,colors[GOLDEN_ROD]);
    DrawString(400,780,"You Lost! ",colors[BLACK]);

    DrawString(400,580,"High Score = " + getStringScore(),colors[BLACK]);
    DrawString(400,380,"Your score = " + convertToString(score),colors[BLACK]);

    if (score > getIntScore())
        DrawString(400,180,"Congratulations! You have beaten the high score! :))",colors[BLACK]);

    checkAndUpdateScore();

//Design
    DrawCircle(10,10,100,colors[YELLOW]);
    DrawCircle(1300,840,100,colors[GREEN]);
    DrawCircle(1300,10,100,colors[BLUE]);
    DrawCircle(10,840,100,colors[RED]);

    glutPostRedisplay();
}

else if (screen == 10)      //HighScore
{
//Heading
        DrawRectangle(0,0,1300,850,colors[GOLDEN_ROD]);
        DrawRectangle(190,750,140,40,colors[GOLD]);
        DrawString(200,760,"High Score: ",colors[BLACK]);
        DrawString(250, 560 , getStringScore(), colors[BLACK]);
//Design
        DrawCircle(10,10,100,colors[YELLOW]);
        DrawCircle(1300,840,100,colors[GREEN]);
        DrawCircle(1300,10,100,colors[BLUE]);
        DrawCircle(10,840,100,colors[RED]);
//Back Button
        DisplayBackButton();
        glutPostRedisplay();
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

    glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..

}
/*________________________________________________________________________________________________________________________________________________________________________________*/
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

	else if (key == GLUT_LEFT) {


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

/*________________________________________________________________________________________________________________________________________________________________________________*/

void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */

/*________________________________________________________________________________________________________________________________________________________________________________*/

void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*
 * our gateway main function
 * */

/*________________________________________________________________________________________________________________________________________________________________________________*/

void MousePressedAndMoved(int x, int y){

    if ((x <= ptr->getX() + R and x>= ptr->getX() - R) and (840-y<= ptr->getY() + R) and (840-y>= ptr->getY() - R)) {
        ptr->setX(x);
        ptr->setY(840 - y);
        ptr->setRadius(100);
    }


       /* if (screen == 3)    //RedScreen
        {
            for (int i=0; i<5; i++)
            {
            if ((x <= rptr[i].getX() + 30 and x>= rptr[i].getX() - 30) and (840-y<= rptr[i].getY() + 30) and (840-y>= rptr[i].getY() - 30))
            {
                  rptr[i].setX(x);
                  rptr[i].setY(840-y);
                CollisionCheck();
            }

            //CollisionCheck();
            }
        }

        else if (screen == 4)    //BlueScreen
        {
*/
            //cout<< screen<<endl;
            //for (int i=0; i<5; i++)
            //{
                //cout<<i<<endl;
            //if ((x <= bptr[i].getX() + 30 and x>= bptr[i].getX() - 30) and (840-y<= bptr[i].getY() + 30) and (840-y>= bptr[i].getY() - 30))
            //{
              //  bptr[i].setX(x);
                //bptr[i].setY(840-y);

            //}


                /*if (bptr[i].getX() <= bptr[i+1].getX() + bptr[i+1].getRadius() and  bptr[i].getX() >= bptr[i+1].getX() - bptr[i+1].getRadius() and bptr[i].getY() <= bptr[i+1].getY() + bptr[i+1].getRadius() and bptr[i].getY() >= bptr[i+1].getY() - bptr[i+1].getRadius())
                {
                    bptr[i].setRadius(bptr[i].getRadius() +10);
                    //cout<<"This conditon works  "<< i<< " "<< i+1<<endl;
                }*/
                /*for (int j=0;j<5; j++) {
                    if (bptr[i].getX() <= rptr[j].getX() + rptr[j].getRadius() and
                        bptr[i].getX() >= rptr[j].getX() - rptr[j].getRadius() and
                        bptr[i].getY() <= rptr[j].getY() + rptr[j].getRadius() and
                        bptr[i].getY() >= rptr[j].getY() - rptr[j].getRadius()) {
                        cout << "END GAME" << endl;
                    }
                }*/


        /*    }
        }

        else if (screen == 5)    //GreenScreen
        {
            for (int i=0; i<5; i++)
            {
            if ((x <= gptr[i].getX() + 30 and x>= gptr[i].getX() - 30) and (840-y<= gptr[i].getY() + 30) and (840-y>= gptr[i].getY() - 30))
            {
                gptr[i].setX(x);
                gptr[i].setY(840-y);

            }

            }
        }

        else if (screen == 6)    //YellowScreen
        {
            for (int i=0; i<5; i++)
            {
            if ((x <= yptr[i].getX() + 30 and x>= yptr[i].getX() - 30) and (840-y<= yptr[i].getY() + 30) and (840-y>= yptr[i].getY() - 30))
            {
                yptr[i].setX(x);
                yptr[i].setY(840-y);
            }

            }
        }
*/

    glutPostRedisplay();
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void MouseMoved (int x, int y)
{
    glutPostRedisplay();
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

void MouseClicked(int button, int state, int x, int y)
{
        if (button == GLUT_LEFT_BUTTON) //  dealing only with left button
        {
            if (x >= 400 and x <= 800 and 840 - y >= 600 and 840 - y <= 650 and screen ==1) {      //Start Game


                screen = 2;
            }


            else if (x >= 520 and x <= 650 and 840 - y >= 20 and 840 - y <= 70 and screen ==2) {      //BackButton


                screen = 1;
            }

            else if (x >= 520 and x <= 650 and 840 - y >= 20 and 840 - y <= 70 and screen ==7) {      //BackButton


                screen = 1;
            }

            else if (x >= 520 and x <= 650 and 840 - y >= 20 and 840 - y <= 70 and screen ==8) {      //BackButton


                screen = 1;
            }

            else if (x >= 520 and x <= 650 and 840 - y >= 20 and 840 - y <= 70 and screen ==10) {      //BackButton


                screen = 1;
            }

            else if ((x <= 900 + 100 and x>= 900 - 100) and (840-y<= 300+100) and (840-y>= 300-100) and screen ==2)    //Red
            {

                screen = 3;

            }


            else if ((x <= 300 + 100 and x>= 300 - 100) and (840-y<= 300+100) and (840-y>= 300-100) and screen ==2) {  //Blue

                screen = 4;
            }

            else if ((x <= 900 + 100 and x>= 900 - 100) and (840-y<= 600+100) and (840-y>= 600-100) and screen ==2) {  //Green

                screen = 5;
            }

            else if ((x <= 300 + 100 and x>= 300 - 100) and (840-y<= 600+100) and (840-y>= 600-100) and screen ==2) {  //Yellow

                screen = 6;
            }

            else if (x >= 400 and x <= 800 and 840 - y >= 500 and 840 - y <= 550 and screen ==1) {      //Rules


                screen = 7;
            }

            else if (x >= 400 and x <= 800 and 840 - y >= 400 and 840 - y <= 450 and screen ==1) {      //Instructions


                screen = 8;
            }

            else if (x >= 400 and x <= 800 and 840 - y >= 300 and 840 - y <= 350 and screen ==1) {      //High Scores


                screen = 10;
            }

            else if (x >= 400 and x <= 800 and 840 - y >= 200 and 840 - y <= 300 and screen ==1) {      //Exit

                exit(1);
            }
        }

    if (button == GLUT_LEFT_BUTTON and screen ==3 && flag)
    {
        ptr = new RedCircle;
        ptr->setX(x);
        ptr->setY(840-y);
        ptr->setRadius(R);
        //ptr->Draw();

        if (flag)
            flag = false;
    }

    if (button == GLUT_LEFT_BUTTON and screen ==4 && flag)
    {
        ptr = new BlueCircle;
        ptr->setX(x);
        ptr->setY(840-y);
        //ptr->setX(40);
        //ptr->setY(840-40);
        //ptr->setRadius(R);
        //ptr->Draw();

        if (flag)
            flag = false;
    }

    if (button == GLUT_LEFT_BUTTON and screen ==5 && flag)
    {
        ptr = new GreenCircle;
        ptr->setX(x);
        ptr->setY(840-y);
        //ptr->setX(40);
        //ptr->setY(840-40);
        //ptr->setRadius(R);
        //ptr->Draw();

        if (flag)
            flag = false;
    }

    if (button == GLUT_LEFT_BUTTON and screen ==6 && flag)
    {
        ptr = new YellowCircle;
        ptr->setX(x);
        ptr->setY(840-y);
        //ptr->setX(40);
        //ptr->setY(840-40);
        //ptr->setRadius(R);
        //ptr->Draw();

        if (flag)
            flag = false;
    }

        else if (button == GLUT_RIGHT_BUTTON)   //  dealing with right button
        {

        }
        glutPostRedisplay();


}

/*________________________________________________________________________________________________________________________________________________________________________________*/


int main(int argc, char*argv[]) {

    initialTime = time(NULL);
    //cout<<Distance(3,4,4,3)<<endl;
    SetCircles();
    DrawCircle();
	int width = 1300, height = 840; // i have set my window size to be 800 x 600
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("HXN's Bubble Pop"); // set the title of our game window
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

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved);
	glutMotionFunc(MousePressedAndMoved);

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* Bomberman_CPP_ */
