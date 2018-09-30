//----------------------------------------------------------------------------//
//    Learning OpenGL: Εισαγωγικά Μαθήματα OpenGL                             //
//                                                                            //
//    Πλατφόρμα ανάπτυξης παραδειγμάτων                                       //
//                                                                            //
//    Εργαστήριο 6ο                                                           //
//----------------------------------------------------------------------------//

#include <iostream>   // For string handling
#include <stdlib.h>   // Just for some standard functions
#include <stdio.h>    // Just for some ASCII messages
#include <glut.h>     // An interface and windows management library
#include "visuals.h"  // Header file for our OpenGL functions

#define KEY_ESC 27
#define MAX_BULLETS 1000
#define CIRCLE_SEGMENTS 36
#define OUTER_RADIUS 0.6
#define INNER_RADIUS 0.05
#define PI 3.1415927

using namespace std;

/*******************************************************************************
  State Variables
 ******************************************************************************/

int play = 0;

struct object
{
    bool 	exist;
    float	x,y;
}spaceship, enemyA, enemyB, enemyC, enemyD, bullet[MAX_BULLETS];

int lastBullet = 0;

const float spaceshipStep = 0.1;
const float enemyStep = -0.02;
const float bulletStep = 0.05;

static GLfloat locations[4][2] =
{
    {0.8f, 1.3f},
    {-0.7f, 1.1f},
    {0.3f, 1.5f},
    {-0.4f, 0.9f}
};

/*******************************************************************************
  Implementation of Auxiliary Functions
 ******************************************************************************/

void gameOver()
{
    // Draw angry face
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.4, 0.2);
    glVertex2f(-0.5, 0.3);
    glVertex2f(-0.3, 0.4);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.3, 0.3);
    glVertex2f(-0.1, 0.3);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.3, 0.3);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(0.4, 0.2);
    glVertex2f(0.3, 0.4);
    glVertex2f(0.5, 0.3);
    glEnd();
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<CIRCLE_SEGMENTS; i++)
        glVertex2f(OUTER_RADIUS*cos(2*PI/CIRCLE_SEGMENTS*i),
                   OUTER_RADIUS*sin(2*PI/CIRCLE_SEGMENTS*i));
    glEnd();
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<CIRCLE_SEGMENTS; i++)
        glVertex2f(INNER_RADIUS*cos(2*PI/CIRCLE_SEGMENTS*i),
                   INNER_RADIUS*sin(2*PI/CIRCLE_SEGMENTS*i));
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, -0.2);
    glVertex2f(0.1, -0.3);
    glVertex2f(-0.1, -0.3);
    glEnd();
  
    // Stop the game
    play = 0;
}

//------------------------------------------------------------------------------

void drawLine()
{
    //*
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);  
    glVertex2f(-1.0, -0.8);  
    glVertex2f(1.0, -0.8); 
    glEnd();
    //*/
    
    //-------------Task2b---------------
    // Create a line that is not parallel with axes
}

//------------------------------------------------------------------------------

void drawCircle(float radius, float x, float y) 
{
    //-------------Task1d---------------
    // Draw Circle
    //*
    glColor3f(1.0, 1.0, 0.0);
    double angleStep = 2 * PI / CIRCLE_SEGMENTS;
    double angle = 0;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i< CIRCLE_SEGMENTS; i++)
    {
        angle = i * angleStep;
        glVertex2f(radius*cos(angle) + x, radius*sin(angle) + y);
    }
    glEnd();
    //*/
}

//------------------------------------------------------------------------------

void drawSpaceship()
{
    if(spaceship.exist)
    {
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(spaceship.x, spaceship.y);
        glVertex2f(spaceship.x+0.1, spaceship.y-0.1);
        glVertex2f(spaceship.x-0.1, spaceship.y-0.1);
        glEnd();
    }
}

//------------------------------------------------------------------------------

void drawEnemyA()
{
    if(enemyA.exist)
    {
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(enemyA.x, enemyA.y);
        glVertex2f(enemyA.x-0.1, enemyA.y+0.1);
        glVertex2f(enemyA.x+0.1, enemyA.y+0.1);
        glEnd();
    }
}

//------------------------------------------------------------------------------

void drawEnemyB()
{
    if(enemyB.exist)
    {
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(enemyB.x, enemyB.y);
        glVertex2f(enemyB.x-0.1, enemyB.y+0.1);
        glVertex2f(enemyB.x+0.1, enemyB.y+0.1);
        glEnd();
    }
}

//------------------------------------------------------------------------------

void drawEnemyC()
{
    if(enemyC.exist)
    {
        glColor3f(0.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(enemyC.x, enemyC.y);
        glVertex2f(enemyC.x-0.1, enemyC.y+0.1);
        glVertex2f(enemyC.x+0.1, enemyC.y+0.1);
        glEnd();
    }
}

//------------------------------------------------------------------------------

void drawEnemyD()
{
    if(enemyD.exist)
    {
        glColor3f(1.0, 0.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(enemyD.x, enemyD.y);
        glVertex2f(enemyD.x-0.1, enemyD.y+0.1);
        glVertex2f(enemyD.x+0.1, enemyD.y+0.1);
        glEnd();
    }
}

//------------------------------------------------------------------------------

void drawBullets()
{
    float x, y;
    for(int i=0; i<MAX_BULLETS; i++)						
    {
        if(bullet[i].exist)
        {
            x = bullet[i].x;
            y = bullet[i].y;
            glColor3f(1.0, 1.0, 1.0);
            glBegin(GL_TRIANGLES);
            glVertex2f(x, y);
            glVertex2f(x+0.05, y-0.05);
            glVertex2f(x-0.05, y-0.05);
            glEnd();
        }
    }
}

//------------------------------------------------------------------------------

void init()
{
    // Bring all spaceships to life and set locations
    enemyA.exist = true;
    enemyA.x = locations[rand()%4][0];
    enemyA.y = locations[rand()%4][1];

    enemyB.exist = true;
    enemyB.x = locations[rand()%4][0];
    enemyB.y = locations[rand()%4][1];

    enemyC.exist = true;
    enemyC.x = locations[rand()%4][0];
    enemyC.y = locations[rand()%4][1];

    enemyD.exist = true;
    enemyD.x = locations[rand()%4][0];
    enemyD.y = locations[rand()%4][1];
  
    spaceship.exist = true;
    spaceship.x = 0.0;
    spaceship.y = -0.8;

    // Make peace hide all bullets in spaceship
    for(int i=0; i<MAX_BULLETS; i++)
    {
        bullet[i].exist = false;
        bullet[i].x = spaceship.x;
        bullet[i].y = spaceship.y;
    }

    // Start Timer
    play = 1;
}

/*******************************************************************************
  Implementation of Visual Functions
 ******************************************************************************/

void setup()
{
    // Parameter handling

    // Polygon rendering mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
  
    // Depth test
    glDisable(GL_DEPTH_TEST);

    // Cull Faces
    // Don't draw triangles that cannot be seen
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);

    // Initialize Game objects
    init();
}

//------------------------------------------------------------------------------

void render()
{
    // Clean up the colour of the window and the depth buffer
    glClear(GL_COLOR_BUFFER_BIT); // | GL_DEPTH_BUFFER_BIT
    
    //-------------Task2a---------------
    // Check Game Over conditions
    // Line-point/triangle intersection
	/*
	double m=(-0.8-0.8)/(1+1);
	
	if(enemyA.y<m*enemyA.x 
		|| enemyB.y<m*enemyB.x 
		|| enemyC.y<m*enemyC.x 
		|| enemyD.y<m*enemyD.x)
		*/
	if(enemyA.y<-0.8 ||enemyB.y<-0.8 ||enemyC.y<-0.8 ||enemyD.y<-0.8)
    {
        // Kill all objects
        enemyA.exist = false;
        enemyB.exist = false;
        enemyC.exist = false;
        enemyD.exist = false;
        spaceship.exist = false;
        bullet[lastBullet].exist = false;
        // Draw angry face
        gameOver();
    }
    else
    {
        // Draw objects
        drawLine();
        drawSpaceship();
        drawEnemyA();
        drawEnemyB();
        drawEnemyC();
        drawEnemyD();
        drawBullets();
    }

    // All drawing commands applied to the
    // hidden buffer, so now, bring forward
    // the hidden buffer and hide the visible one
    glutSwapBuffers();
}

//------------------------------------------------------------------------------

void resize(int w, int h)
{
}

//------------------------------------------------------------------------------

void idle()
{
}

//------------------------------------------------------------------------------

void timer(int value)
{
    if(value)
    {
        enemyA.y += enemyStep;
        enemyB.y += enemyStep;
        enemyC.y += enemyStep;
        enemyD.y += enemyStep;

        // For each bullet
        for(int i=0; i<lastBullet; i++)
        {
            // If bulet still exist
            if(bullet[i].exist)
            {
                // Go forward
                bullet[i].y += bulletStep;

                //-------------Task2b---------------
                // Check if enemyA hit with the bullet 
				double m1=(bullet[i].y-0.05-bullet[i].y)/(bullet[i].x+0.05-bullet[i].x);
				double m2=(bullet[i].y-0.05-bullet[i].y+0.05)/(bullet[i].x+0.05-bullet[i].x+0.05);
				double m3=(bullet[i].y-bullet[i].y+0.05)/(bullet[i].x-bullet[i].x-0.05);

	/*
				if(enemyA.y<m*enemyA.x 
				|| enemyB.y<m*enemyB.x 
				|| enemyC.y<m*enemyC.x 
				|| enemyD.y<m*enemyD.x)
				*/
				if(enemyA.y<m1*enemyA.x-m1*bullet[i].x+bullet[i].y
					&& enemyA.y>m2*enemyA.x-m2*(bullet[i].x+0.05)+bullet[i].y-0.05
					&& enemyA.y<m3*enemyA.x-m3*(bullet[i].x)+bullet[i].y ||

					enemyA.y+0.1<m1*(enemyA.x+0.1)-m1*bullet[i].x+bullet[i].y
					&& enemyA.y+0.1>m2*(enemyA.x+0.1)-m2*(bullet[i].x+0.05)+bullet[i].y-0.05
					&& enemyA.y+0.1<m3*(enemyA.x+0.1)-m3*(bullet[i].x)+bullet[i].y ||

					enemyA.y+0.1<m1*(enemyA.x-0.1)-m1*bullet[i].x+bullet[i].y
					&& enemyA.y+0.1>m2*(enemyA.x-0.1)-m2*(bullet[i].x+0.05)+bullet[i].y-0.05
					&& enemyA.y+0.1<m3*(enemyA.x-0.1)-m3*(bullet[i].x)+bullet[i].y)
                {
                    bullet[i].exist = false;
                    // Respwn enemy
                    enemyA.x = locations[rand()%4][0];
                    enemyA.y = locations[rand()%4][1];
                }
                // Check if enemyB hit
				if(enemyB.y<bullet[i].y && enemyB.x>bullet[i].x-0.1 && enemyB.x<bullet[i].x+0.1)
                {
                    bullet[i].exist = false;
                    // Respwn enemy
                    enemyB.x = locations[rand()%4][0];
                    enemyB.y = locations[rand()%4][1];
                }
                // Check if enemyC hit
				if(enemyC.y<bullet[i].y && enemyC.x>bullet[i].x-0.1 && enemyC.x<bullet[i].x+0.1)
                {
                    bullet[i].exist = false;
                    // Respwn enemy
                    enemyC.x = locations[rand()%4][0];
                    enemyC.y = locations[rand()%4][1];
                }
                // Check if enddemyD hit
				if(enemyD.y<bullet[i].y && enemyD.x>bullet[i].x-0.1 && enemyD.x<bullet[i].x+0.1)
                {
                    bullet[i].exist = false;
                    // Respwn enemy
                    enemyD.x = locations[rand()%4][0];
                    enemyD.y = locations[rand()%4][1];
                }
            }
        }
        // Recall after 200 ms
        glutTimerFunc(200, timer, play);
    }
    glutPostRedisplay();
}

//------------------------------------------------------------------------------

void menuSelect(int choice)
{
}

//------------------------------------------------------------------------------

void keyboardDown(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'W':
    case 'w':
        spaceship.y += spaceshipStep;
        break;
    case 'A':
    case 'a':
        spaceship.x -= spaceshipStep;
        break;
    case 'S':
    case 's':
        spaceship.y -= spaceshipStep;
        break;
    case 'D':
    case 'd':
        spaceship.x += spaceshipStep;
        break;
    case ' ':
        bullet[lastBullet].exist = true;
        bullet[lastBullet].x = spaceship.x;
        bullet[lastBullet].y = spaceship.y;
        lastBullet++;
        break;
    case 'R':
    case 'r':
        init();
        play = 1;
        glutTimerFunc(200, timer, play);
        glutPostRedisplay();
        break;
	case 'Z':
    case 'z':
       if(play)play = 0;
	   else{
			glutTimerFunc(200, timer, 1);
			play=1;
	   }
       
        break;
        
    //-------------Task1----------------
    case KEY_ESC:
        exit(0);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

//------------------------------------------------------------------------------

void keyboardUp(unsigned char key, int x, int y)
{
}

//------------------------------------------------------------------------------

void keyboardSpecialDown(int key, int x, int y)
{
}

//------------------------------------------------------------------------------

void keyboardSpecialUp(int key, int x, int y)
{
}

//------------------------------------------------------------------------------

void mouseClick(int button, int state, int x, int y)
{
}

//------------------------------------------------------------------------------

void mouseMotion(int x, int y)
{
}
