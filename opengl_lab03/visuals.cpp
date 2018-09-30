#include <iostream>	  // For string handling
#include <stdlib.h>	  // Just for some standard functions
#include <stdio.h>    // Just for some ASCII messages

#define GLEW_STATIC
#include <GLFW/GL/glew.h>

#include <GL/freeglut.h>     // An interface and windows management library
#include "visuals.h"  // Header file for our OpenGL functions

#define KEY_ESC 27
#define SENSITIVITY 2.0
#define PI 3.1415927

using namespace std;

/*******************************************************************************
  State Variables
 ******************************************************************************/
static unsigned int chess_tex;

// Model variables
float translateY = 0.0f;
float vel = 40.0;

// Camera variables
float azim = 0.0f, elev = 0.0f;

// Event handle variables
bool mouseClickDown = false;
int mx0;
int my0;


/*******************************************************************************
  Implementation of Visual Functions
 ******************************************************************************/

void setup()
{ 
    // Parameter handling
	glewInit();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_NORMALIZE);

	glClearColor(0.1, 0.1, 0.1, 1);

	chess_tex = genChessTexture(0.9, 0.3, 0.1, 0.3, 0.1, 0.35);

    // Black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

//------------------------------------------------------------------------------

void render()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Rotate to view
	glRotatef(elev, 1, 0, 0);
	glRotatef(azim, 0, 1, 0);

	// Translate back enough
	glTranslatef(0, -5, -10);

	// Draw the scene
	drawScene();

	glutSwapBuffers();
}

void drawScene()
{
	int i;
	float grey[] = { 0.8, 0.8, 0.8, 1 };
	float col[] = { 0, 0, 0, 1 };
	float lpos[][4] = {
		{ -8, 2, 10, 1 },
		{ 0, 15, 0, 1 }
	};
	float lcol[][4] = {
		{ 0.8, 0.8, 0.8, 1 },
		{ 0.4, 0.3, 0.3, 1 }
	};

	for (i = 0; i < 2; i++) {
		glLightfv(GL_LIGHT0 + i, GL_POSITION, lpos[i]);
		glLightfv(GL_LIGHT0 + i, GL_DIFFUSE, lcol[i]);
	}

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glTranslatef(0, 10, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, grey);
	glBindTexture(GL_TEXTURE_2D, chess_tex);
	glEnable(GL_TEXTURE_2D);
	drawBox(30, 20, 30, -1.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	for (i = 0; i < 4; i++) {
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, grey);
		glPushMatrix();
		glTranslatef(i & 1 ? 5 : -5, 1, i & 2 ? -5 : 5);
		drawBox(0.5, 2, 0.5, 1.0);
		glPopMatrix();

		col[0] = i & 1 ? 1.0 : 0.3;
		col[1] = i == 0 ? 1.0 : 0.3;
		col[2] = i & 2 ? 1.0 : 0.3;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, col);

		glPushMatrix();
		if (i & 1) {
			glTranslatef(0, 0.25, i & 2 ? 2 : -2);
		}
		else {
			glTranslatef(i & 2 ? 2 : -2, 0.25, 0);
		}
		drawBox(0.5, 0.5, 0.5, 1.0);
		glPopMatrix();
	}

	col[0] = 1;
	col[1] = 1;
	col[2] = 0.4;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, col);
	drawBox(0.05, 1.2, 6, 1.0);
	drawBox(6, 1.2, 0.05, 1.0);
}
//------------------------------------------------------------------------------

void resize(int w, int h)
{ 
    // define the visible area of the window ( in pixels )
    if (h==0) h=1;
    glViewport(0, 0, w, h); 

    // Setup viewing volume

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
 
    gluPerspective(90.0, (float)w / (float)h, 1.0, 100.0);
}

//------------------------------------------------------------------------------

void keyboardDown(unsigned char key, int x, int y)
{

    switch(key)
    {
        case 'W':
        case 'w':
            cout << "w pressed" << endl;
            break;
        case 'A':
        case 'a':
            cout << "a pressed" << endl;
            break;
        case 'S':
        case 's':
            cout << "s pressed" << endl;
            break;
        case 'D':
        case 'd':
            cout << "d pressed" << endl;
            break;
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
    switch(key)
    {
        case 'W':
        case 'w':
            cout << "w released" << endl;
            break;
        case 'A':
        case 'a':
            cout << "a released" << endl;
            break;
        case 'S':
        case 's':
            cout << "s released" << endl;
            break;
        case 'D':
        case 'd':
            cout << "d released" << endl;
            break;
        case KEY_ESC:
            exit(0);
            break;
        default:
            break;
    }
    glutPostRedisplay();

}

//------------------------------------------------------------------------------

void mouseClick(int button, int state, int x, int y)
{

    if(button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            cout << "mouse click down" << endl;
            // Set click down state flag true  
            mouseClickDown = true;
            // Save initial mouse position
            mx0 = x;
            my0 = y;
        }
        else
        {
            cout << "mouse click up" << endl;
            // Set click down state flag false
            mouseClickDown = false;
        }
    }

}

//------------------------------------------------------------------------------

void mouseMotion(int x, int y)
{
    if (mouseClickDown)
    {
        // Simple FPS Camera
		azim += (x - mx0)*SENSITIVITY/10.0f;
		elev += (y - my0)*SENSITIVITY/10.0f;

        // Save current mouse position
        mx0 = x;
        my0 = y;

        cout << "mouse moving" << endl;
        glutPostRedisplay();
    }
}

void drawBox(float xsz, float ysz, float zsz, float norm_sign)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glScalef(xsz * 0.5, ysz * 0.5, zsz * 0.5);

	if (norm_sign < 0.0) {
		glFrontFace(GL_CW);
	}

	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1 * norm_sign);
	glTexCoord2f(0, 0); glVertex3f(-1, -1, 1);
	glTexCoord2f(1, 0); glVertex3f(1, -1, 1);
	glTexCoord2f(1, 1); glVertex3f(1, 1, 1);
	glTexCoord2f(0, 1); glVertex3f(-1, 1, 1);
	glNormal3f(1 * norm_sign, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(1, -1, 1);
	glTexCoord2f(1, 0); glVertex3f(1, -1, -1);
	glTexCoord2f(1, 1); glVertex3f(1, 1, -1);
	glTexCoord2f(0, 1); glVertex3f(1, 1, 1);
	glNormal3f(0, 0, -1 * norm_sign);
	glTexCoord2f(0, 0); glVertex3f(1, -1, -1);
	glTexCoord2f(1, 0); glVertex3f(-1, -1, -1);
	glTexCoord2f(1, 1); glVertex3f(-1, 1, -1);
	glTexCoord2f(0, 1); glVertex3f(1, 1, -1);
	glNormal3f(-1 * norm_sign, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
	glTexCoord2f(1, 0); glVertex3f(-1, -1, 1);
	glTexCoord2f(1, 1); glVertex3f(-1, 1, 1);
	glTexCoord2f(0, 1); glVertex3f(-1, 1, -1);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glNormal3f(0, 1 * norm_sign, 0);
	glTexCoord2f(0.5, 0.5); glVertex3f(0, 1, 0);
	glTexCoord2f(0, 0); glVertex3f(-1, 1, 1);
	glTexCoord2f(1, 0); glVertex3f(1, 1, 1);
	glTexCoord2f(1, 1); glVertex3f(1, 1, -1);
	glTexCoord2f(0, 1); glVertex3f(-1, 1, -1);
	glTexCoord2f(0, 0); glVertex3f(-1, 1, 1);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glNormal3f(0, -1 * norm_sign, 0);
	glTexCoord2f(0.5, 0.5); glVertex3f(0, -1, 0);
	glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
	glTexCoord2f(1, 0); glVertex3f(1, -1, -1);
	glTexCoord2f(1, 1); glVertex3f(1, -1, 1);
	glTexCoord2f(0, 1); glVertex3f(-1, -1, 1);
	glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
	glEnd();

	glFrontFace(GL_CCW);
	glPopMatrix();
}


/* generate a chessboard texture with tiles colored (r0, g0, b0) and (r1, g1, b1) */
unsigned int genChessTexture(float r0, float g0, float b0, float r1, float g1, float b1)
{
	int i, j;
	unsigned int tex;
	unsigned char img[8 * 8 * 3];
	unsigned char *pix = img;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			int black = (i & 1) == (j & 1);
			pix[0] = (black ? r0 : r1) * 255;
			pix[1] = (black ? g0 : g1) * 255;
			pix[2] = (black ? b0 : b1) * 255;
			pix += 3;
		}
	}

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 8, 8, 0, GL_RGB, GL_UNSIGNED_BYTE, img);

	return tex;
}