//----------------------------------------------------------------------------//
//    Learning OpenGL: Εισαγωγικά Μαθήματα OpenGL                             //
//                                                                            //
//    Πλατφόρμα ανάπτυξης παραδειγμάτων                                       //
//                                                                            //
//    Εργαστήριο 4ο                                                           //
//----------------------------------------------------------------------------//

#include <stdlib.h>	  // Just for some standard functions
#include <stdio.h>    // - Just for some ASCII messages
#include <glut.h>     // - An interface and windows management library
#include "visuals.h"  // Header file for our OpenGL functions

/*******************************************************************************
  Main Program code
 ******************************************************************************/

int main(int argc, char* argv[])
{
    // initialize GLUT library state
    glutInit(&argc, argv);

    // Set up the display using the GLUT functions to
    // get rid of the window setup details:
    // - Use true RGB colour mode ( and transparency )
    // - Enable double buffering for faster window update
    // - Allocate a Depth-Buffer in the system memory or
    //   in the video memory if 3D acceleration available
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    // Define the main window size and initial position
    // ( upper left corner, boundaries included )
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(50, 50);

    // Create and label the main window
    glutCreateWindow("OpenGL Lab04");

    // Configure various properties of the OpenGL rendering context
    setup();

    // Callbacks for the GL and GLUT events:
    // Set the rendering function
    glutDisplayFunc(render);
    // Set the resize function
    glutReshapeFunc(resize);
    // Set the idle function
    glutIdleFunc(idle);
  
    //-------------Task2------------------
    // Set function for menu
    glutCreateMenu(menuSelect);
    glutAddMenuEntry("Light0", LIGHT0);
    glutAddMenuEntry("Light1", LIGHT1);
    glutAddMenuEntry("Both", BOTH);
    glutAddMenuEntry("None", NONE);
    // attach the menu to the right button
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    //-------------Task3------------------
    // Set functions for keyboard
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(keyboardSpecialDown);
    glutSpecialUpFunc(keyboardSpecialUp);

    //-------------Task4------------------
    // Set functions for mouse
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMotion);

    //Enter main event handling loop
    glutMainLoop();
    return 0;
}

