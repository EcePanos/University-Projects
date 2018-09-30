//----------------------------------------------------------------------------//
//    Learning OpenGL: Εισαγωγικά Μαθήματα OpenGL                             //
//                                                                            //
//    Πλατφόρμα ανάπτυξης παραδειγμάτων                                       //
//                                                                            //
//    Εργαστήριο 4ο                                                           //
//----------------------------------------------------------------------------//

#include <iostream>   // For string handling
#include <stdlib.h>	  // Just for some standard functions
#include <stdio.h>    // Just for some ASCII messages
#include <glut.h>     // An interface and windows management library
#include "visuals.h"  // Header file for our OpenGL functions
#include "windows.h"
#include "tiny_obj_loader.h"

#define KEY_ESC 27
#define PI 3.1415927

using namespace std;
using namespace tinyobj;

/*******************************************************************************
  State Variables
 ******************************************************************************/

// Model variables
mesh_t tyra;
mesh_t tyra_norm;
static float dx = 0.0;
static float dy = 0.0;
static float dz = 0.0;
static float ry = 0.0;
// Camera variables
static float rotFactor = 0.001;
static float zoomStep  = 10;
static float cdist = 250.0;
static float cx = 0.0;
static float cy = 0.0;
static float cz = cdist;
static float azimuthAngle  = 0.0;
static float altitudeAngle = PI/2.;
// Event handle variables
static bool mouseClickDown = false;
static int mx0;
static int my0;
float lightpos=-100.0;
float lightcol=1.0;
bool flagf=true;
int propflag=0;
float prop1=0;
float prop2=0;
float prop3=0;
float prop4=0;
float prop5=0;
float prop6=0;
float prop7=0;
float prop8=0;

/*******************************************************************************
  Implementation of Auxiliary Functions
 ******************************************************************************/

void field(float sizeOfTile, int numOfTiles)
{
    // All traingles have tha same normal
    glNormal3f(0.0, 1.0, 0.0);

    glPushMatrix();
    glTranslatef(-numOfTiles*sizeOfTile/2., 0, -numOfTiles*sizeOfTile/2.);
    for (int i=0; i<numOfTiles; i++)
    {
        glPushMatrix();
        glTranslatef(0, 0, i*sizeOfTile);
        for (int j=0; j<numOfTiles; j++)
        {
            glPushMatrix();
            glTranslatef(j*sizeOfTile, 0, 0);
            glBegin(GL_TRIANGLE_FAN);
            glVertex3f(         0.0f, 0.0f,          0.0f);
            glVertex3f( sizeOfTile/2, 0.0f,  sizeOfTile/2);
            glVertex3f(-sizeOfTile/2, 0.0f,  sizeOfTile/2);
            glVertex3f(-sizeOfTile/2, 0.0f, -sizeOfTile/2);
            glVertex3f( sizeOfTile/2, 0.0f, -sizeOfTile/2);
            glVertex3f( sizeOfTile/2, 0.0f,  sizeOfTile/2);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    glPopMatrix();
}

//------------------------------------------------------------------------------

void calculateNormals(mesh_t &mesh)
{
    cout << endl << "Calculating Normals..." << endl;
    // Take the points, normals and faces of the obj
    vector<float> &positions = mesh.positions;
    vector<float> &normals = mesh.normals;
    vector<unsigned> &indices = mesh.indices;

    cout << "Before Calculations" << endl;
    cout << "Number of Positions: " << positions.size() << endl;
    cout << "Number of Normals: " << normals.size() << endl;
    cout << "Number of Indicies: " << indices.size() << endl << endl;
    
    // Set all normals (0.0 0.0 1.0)
    //*
    for (int i = 0; i < positions.size(); i+=3)
    {
        normals.push_back(0.0);
        normals.push_back(0.0);
        normals.push_back(1.0);
    }
    //*/

    //-------------Task4b---------------
    // Apply new normal every tree vertices
    /*
    // Allocate memory for normals
    normals.resize(positions.size());
    
    float normal[3];
    for (int i = 0; i < indices.size(); i+=3)
    {
        // Get points of each triangle
        GLfloat *pt1 = (GLfloat*) &positions[3*indices[i]];
        GLfloat *pt2 = (GLfloat*) &positions[3*indices[i+1]];
        GLfloat *pt3 = (GLfloat*) &positions[3*indices[i+2]];

        // Compute cross product pt12 x pt13

        // Normalize

        // Write the calculated normal to right normals vector position
        // Normal of the first point of current triangle (x, y, z)
        normals[3*indices[i]]     = normal[0];
        normals[3*indices[i]+1]   = normal[1];
        normals[3*indices[i]+2]   = normal[2];
        
        // Normal of the second point of current triangle (x, y, z)
        normals[3*indices[i+1]]   = normal[0];
        normals[3*indices[i+1]+1] = normal[1];
        normals[3*indices[i+1]+2] = normal[2];
        
        // Normal of the third point of current triangle (x, y, z)
        normals[3*indices[i+2]]   = normal[0];
        normals[3*indices[i+2]+1] = normal[1];
        normals[3*indices[i+2]+2] = normal[2];
    }
    //*/

    cout << "After Calculations" << endl;
    cout << "Number of Positions: " << positions.size() << endl;
    cout << "Number of Normals: " << normals.size() << endl;
    cout << "Number of Indicies: " << indices.size() << endl;
}

//------------------------------------------------------------------------------

void readObj(string filename, mesh_t &mesh)
{
    //-------------Task4a---------------
    vector<shape_t> shapes;
    string err = LoadObj(shapes, filename.c_str());

    if (!err.empty())
    {
        // Print the error
        cerr << err << endl;
        exit(1);
    }
    else
    {
        // The .obj file might contain more than one shapes(meshes)
        // we are intrested only for the first one
        mesh = shapes[0].mesh;
        if (mesh.normals.empty())
        {
            cout << "Normals does not exist!" << endl;
            calculateNormals(mesh);
        }
    }
}

//------------------------------------------------------------------------------

void drawObj(mesh_t &mesh)
{
    //-------------Task4a---------------
    // Take the points, normals and faces of the obj
    vector<float> &positions = mesh.positions;
    vector<float> &normals = mesh.normals;
    vector<unsigned> &indices = mesh.indices;

    if (normals.size() != positions.size())
    {
        cout << "The number of normals is not the same with number of points" << endl;
        return;
    }

    float *point;
    float *normal;
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < indices.size(); i++)
    {
        // Set the normal
        normal = &normals[3*indices[i]];
        glNormal3fv((GLfloat*) normal);
        // Set the point
        point = &positions[3*indices[i]];
        glVertex3fv((GLfloat*) point);
    }
    glEnd();
}

//------------------------------------------------------------------------------

string getExeDir()
{
    HMODULE hModule = GetModuleHandleW(NULL);
    WCHAR wPath[MAX_PATH];
    GetModuleFileNameW(hModule, wPath, MAX_PATH);
    char cPath[MAX_PATH];
    char DefChar = ' ';
    WideCharToMultiByte(CP_ACP, 0, wPath, -1, cPath, 260, &DefChar, NULL);
    string sPath(cPath);
    return sPath.substr(0, sPath.find_last_of("\\/")).append("\\");
}

/*******************************************************************************
  Implementation of Visual Functions
 ******************************************************************************/

void setup()
{ 
    // Parameter handling

    //-------------Task1a---------------
    // polygon rendering mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    //-------------Task1b---------------
    // Make models with smoothed edges
    glShadeModel(GL_SMOOTH);
    //glShadeModel(GL_FLAT);

    // Blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Depth test
    glEnable(GL_DEPTH_TEST);
    // Renders a fragment if its z value is less or equal of the stored value
    glDepthFunc(GL_LEQUAL);
    glClearDepth(1);
  
    // Cull Faces
    // Don't draw triangles that cannot be seen
    //glEnable(GL_CULL_FACE);
    //glFrontFace(GL_CW);
  
    // Automatically normalize normals of the model
    //glEnable(GL_NORMALIZE);
    //*
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set the camera
    gluLookAt(0, 40, 250, 0, 40, 0, 0, 1, 0);
    //*/

    //-------------Task2a---------------
    // Enable the Lighting
    glEnable(GL_LIGHTING);

    // Set up light source
    // Light 0
    GLfloat light0Ambient[]   = {0.2, 0.2, 0.2, 1.0};
    GLfloat light0Diffuse[]   = {0.9, 0.9, 0.9, 1.0};
    GLfloat light0Specular[]  = {0.9, 0.9, 0.9, 1.0};
    // If w=0 light is directional with (x,y,z) describe its direction
    GLfloat light0Position[]  = {50, 70, 100, 1};
    GLfloat light0Direction[] = {-1.0, -1.0, -1.0, 0.0};
  
    // Set Ambient Light
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light0Ambient);
    // Set Difuse Light
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light0Diffuse);
    // Set Specular Light
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
    // Set Position of the Light
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    
    // Set Attenuation of the light a*x^2 + b*x + c
    //glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 2);
    //glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0001);
    //glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.00001);
    // Make Light a spot light setting the cutoff angle and direction
    //glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0Direction);
    //glLightf (GL_LIGHT0, GL_SPOT_EXPONENT, 16.0); // [0,128]

    // Enable Light 0
    //glEnable(GL_LIGHT0);
    
    //-------------Task2b---------------
    // Light 1
    
    GLfloat light1Ambient[]   = {0.3, 0.3, 0.3, 1.0};
    GLfloat light1Diffuse[]   = {0.8, 0.9, 0.9, 1.0};
    GLfloat light1Specular[]  = {0.9, 0.9, 0.9, 1.0};
    // If w=0 light is directional with (x,y,z) describe its direction
    GLfloat light1Position[]  = {-50.0, 70.0, 100.0, 1.0};
    GLfloat light1Direction[] = {  1.0, -1.0,  -1.0, 0.0};
  
    // Set Ambient Light
    glLightfv(GL_LIGHT1, GL_AMBIENT,  light1Ambient);
    // Set Difuse Light
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light1Diffuse);
    // Set Specular Light
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1Specular);
    // Set Position of the Light
    glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
	//glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
  
    // Enable Light 1
    //glEnable(GL_LIGHT1);
    //*/






	// Light 2
    
    GLfloat light2Ambient[]   = {0.3, 0.3, 0.3, 1.0};
    GLfloat light2Diffuse[]   = {0.9, 0.0, 0.0, 1.0};
    GLfloat light2Specular[]  = {0.9, 0.9, 0.9, 1.0};
    // If w=0 light is directional with (x,y,z) describe its direction
    GLfloat light2Position[]  = {-20.0, 70.0, 30.0, 1.0};
    GLfloat light2Direction[] = {  0, -1.0,  0, 0.0};
  
    // Set Ambient Light
    glLightfv(GL_LIGHT2, GL_AMBIENT,  light2Ambient);
    // Set Difuse Light
    glLightfv(GL_LIGHT2, GL_DIFFUSE,  light2Diffuse);
    // Set Specular Light
    glLightfv(GL_LIGHT2, GL_SPECULAR, light2Specular);
    // Set Position of the Light
    glLightfv(GL_LIGHT2, GL_POSITION, light2Position);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 10.0);
  
    // Enable Light 1
    glEnable(GL_LIGHT2);




	GLfloat light3Ambient[]   = {0.3, 0.3, 0.3, 1.0};
    GLfloat light3Diffuse[]   = {0, 0.9, 0.0, 1.0};
    GLfloat light3Specular[]  = {0, 0.9, 0.0, 1.0};
    // If w=0 light is directional with (x,y,z) describe its direction
    GLfloat light3Position[]  = {-30.0, 100.0, 30.0, 1.0};
    GLfloat light3Direction[] = {  0, -1.0,  0, 0.0};
  
    // Set Ambient Light
    glLightfv(GL_LIGHT3, GL_AMBIENT,  light3Ambient);
    // Set Difuse Light
    glLightfv(GL_LIGHT3, GL_DIFFUSE,  light3Diffuse);
    // Set Specular Light
    glLightfv(GL_LIGHT3, GL_SPECULAR, light3Specular);
    // Set Position of the Light
    glLightfv(GL_LIGHT3, GL_POSITION, light3Position);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 10.0);
  
    // Enable Light 1
    glEnable(GL_LIGHT3);




	GLfloat light4Ambient[]   = {0.3, 0.3, 0.3, 1.0};
    GLfloat light4Diffuse[]   = {0, 0.0, 0.9, 1.0};
    GLfloat light4Specular[]  = {0, 0.0, 0.9, 1.0};
    // If w=0 light is directional with (x,y,z) describe its direction
    GLfloat light4Position[]  = {-10.0, 100.0, 30.0, 1.0};
    GLfloat light4Direction[] = {  0, -1.0,  0, 0.0};
  
    // Set Ambient Light
    glLightfv(GL_LIGHT4, GL_AMBIENT,  light4Ambient);
    // Set Difuse Light
    glLightfv(GL_LIGHT4, GL_DIFFUSE,  light4Diffuse);
    // Set Specular Light
    glLightfv(GL_LIGHT4, GL_SPECULAR, light4Specular);
    // Set Position of the Light
    glLightfv(GL_LIGHT4, GL_POSITION, light4Position);
	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 10.0);
  
    // Enable Light 1
    glEnable(GL_LIGHT4);



	GLfloat light5Ambient[]   = {0.3, 0.3, 0.3, 1.0};
    GLfloat light5Diffuse[]   = {1, 0.9, 0.9, 1.0};
    GLfloat light5Specular[]  = {1, 0.9, 0.9, 1.0};
    // If w=0 light is directional with (x,y,z) describe its direction
    GLfloat light5Position[]  = {10.0, 100.0, 30.0, 1.0};
    GLfloat light5Direction[] = {  0, -1.0,  0, 0.0};
  
    // Set Ambient Light
    glLightfv(GL_LIGHT5, GL_AMBIENT,  light5Ambient);
    // Set Difuse Light
    glLightfv(GL_LIGHT5, GL_DIFFUSE,  light5Diffuse);
    // Set Specular Light
    glLightfv(GL_LIGHT5, GL_SPECULAR, light5Specular);
    // Set Position of the Light
    glLightfv(GL_LIGHT5, GL_POSITION, light5Position);
	glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 10.0);
  
    // Enable Light 1
    glEnable(GL_LIGHT5);




	 GLfloat light6Ambient[]   = {0.3, 0.3, 0.3, 1.0};
    GLfloat light6Diffuse[]   = {0.9, 0.9, 0.0, 1.0};
    GLfloat light6Specular[]  = {0.9, 0.9, 0.0, 1.0};
    // If w=0 light is directional with (x,y,z) describe its direction
    GLfloat light6Position[]  = {0.0, 70.0, 30.0, 1.0};
    GLfloat light6Direction[] = {  0, -1.0,  0, 0.0};
  
    // Set Ambient Light
    glLightfv(GL_LIGHT6, GL_AMBIENT,  light6Ambient);
    // Set Difuse Light
    glLightfv(GL_LIGHT6, GL_DIFFUSE,  light6Diffuse);
    // Set Specular Light
    glLightfv(GL_LIGHT6, GL_SPECULAR, light6Specular);
    // Set Position of the Light
    glLightfv(GL_LIGHT6, GL_POSITION, light6Position);
	glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, 10.0);
  
    // Enable Light 1
   glEnable(GL_LIGHT6);


   // Light 7
    
    GLfloat light7Ambient[]   = {0.3, 0.3, 0.3, 1.0};
    GLfloat light7Diffuse[]   = {0.9, 0.0, 0.0, 1.0};
    GLfloat light7Specular[]  = {0.9, 0.0, 0.0, 1.0};
    // If w=0 light is directional with (x,y,z) describe its direction
    GLfloat light7Position[]  = {-20.0, 70.0, 30.0, 1.0};
    GLfloat light7Direction[] = {  0, -1.0,  0, 0.0};
  
    // Set Ambient Light
    glLightfv(GL_LIGHT7, GL_AMBIENT,  light7Ambient);
    // Set Difuse Light
    glLightfv(GL_LIGHT7, GL_DIFFUSE,  light7Diffuse);
    // Set Specular Light
    glLightfv(GL_LIGHT7, GL_SPECULAR, light7Specular);
    // Set Position of the Light
    glLightfv(GL_LIGHT7, GL_POSITION, light7Position);
	glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, 10.0);
  
    // Enable Light 1
    glEnable(GL_LIGHT7);
    //*/
    
    //-------------Task3a---------------
    /*
    // Polygon rendering mode enable Material
    glEnable(GL_COLOR_MATERIAL);
    // We use Ambient and Diffuse color of each object as given in color3f
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    //*/
    
    //-------------Task3b---------------
    /*
    // Set Material parameters (experimental)
    GLfloat ambref[]  = {0.1, 0.1, 0.1, 1.0};
    GLfloat difref[]  = {0.4, 0.4, 0.4, 1.0};
    GLfloat specref[] = {0.8, 0.8, 0.8, 1.0};
    GLint shininess   = 128.0;
    //*/
    
    //-------------Task3c---------------
    // Different Materials

    // Material Parameters for Gold
    /*
    GLfloat ambref[]  = {0.247, 0.225, 0.065, 1.0};
    GLfloat difref[]  = {0.346, 0.314, 0.090, 1.0};
    GLfloat specref[] = {0.797, 0.724, 0.208, 1.0};
    GLint shininess   = 83.2;
    //*/
    // Material Parameters for Silver
    /*
    GLfloat ambref[]  = {0.231, 0.231, 0.231, 1.0};
    GLfloat difref[]  = {0.278, 0.278, 0.278, 1.0};
    GLfloat specref[] = {0.774, 0.774, 0.774, 1.0};
    GLint shininess   = 89.6;
    //*/
    // Material Parameters for Cooper
    /*
    GLfloat ambref[]  = {0.230, 0.089, 0.028, 1.0};
    GLfloat difref[]  = {0.551, 0.212, 0.066, 1.0};
    GLfloat specref[] = {0.581, 0.223, 0.070, 1.0};
    GLint shininess   = 51.2;
    //*/
    // Material Parameters for Ruby
    /*
    GLfloat ambref[]  = {0.175, 0.012, 0.012, 0.55};
    GLfloat difref[]  = {0.614, 0.041, 0.041, 0.55};
    GLfloat specref[] = {0.728, 0.308, 0.308, 0.55};
    GLint shininess   = 76.8;
    //*/
    // Material Parameters for Black Plastic
    /*
    GLfloat ambref[]  = {0.0,  0.0,  0.0,  1.0};
    GLfloat difref[]  = {0.01, 0.01, 0.01, 1.0};
    GLfloat specref[] = {0.5,  0.5,  0.5,  1.0};
    GLint shininess   = 32;
    //*/
    // Material Parameters for Black Rubber
    /*
    GLfloat ambref[]  = {0.02, 0.02, 0.02, 1.0};
    GLfloat difref[]  = {0.01, 0.01, 0.01, 1.0};
    GLfloat specref[] = {0.4,  0.4,  0.4,  1.0};
    GLint shininess   = 10;
    //*/
  
    // Set Material parameters
	/*
    glMaterialfv(GL_FRONT, GL_AMBIENT,   ambref);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   difref);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specref);
    glMaterialf (GL_FRONT, GL_SHININESS, shininess);
    
    //-------------Task4a---------------
    /*
    // Read OBJ models
    // The mesh consists of positions, normals and indicies
    // we can access them using the following code:
    // tyra.positions[3*ith] returns the ith point
    // tyra.normals[3*ith] returns the ith normal
    // tyra.indices[ith] returns the index of the ith point
    // we have a new triangle every 3 indicies    
    readObj(getExeDir() + "..\\Models\\tyra.obj", tyra);
    //*/
    
    //-------------Task4c---------------
    /*
    readObj(getExeDir() + "..\\Models\\tyra_norm.obj", tyra_norm);
    //*/

    // Black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

//------------------------------------------------------------------------------

void render()
{
    // Clean up the colour of the window and the depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set the camera
    gluLookAt(cx, 40+cy, cz,  // camera position
               0,    40,  0,  // target position
               0,     1,  0); // up vector
    
    //-------------Task2c---------------
    // Update lights position and direction when mvMatrix change
    
    glPushMatrix();
    GLfloat light0Position[]  = {50, 70, 100, 1};
    GLfloat light0Direction[] = {0, -1.0, 0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0Direction);
    glPopMatrix();
	
	glPushMatrix();
    GLfloat light2Position[]  = {lightpos, 70, 30, 1};
    GLfloat light2Direction[] = {0, -1.0, 0, 0.0};
    glLightfv(GL_LIGHT2, GL_POSITION, light2Position);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light2Direction);
	GLfloat lightDiffuse[]   = {lightcol, 0.0, 1-lightcol, 1.0};
	glLightfv(GL_LIGHT2, GL_DIFFUSE,  lightDiffuse);
    glPopMatrix();
	
	glPushMatrix();
    GLfloat light3Position[]  = {-10, 70, 40, 1};
    GLfloat light3Direction[] = {0, -1.0, 0, 0.0};
    glLightfv(GL_LIGHT3, GL_POSITION, light3Position);
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light3Direction);
    glPopMatrix();
	glPushMatrix();
    GLfloat light4Position[]  = {-20, 70, 50, 1};
    GLfloat light4Direction[] = {0, -1.0, 0, 0.0};
    glLightfv(GL_LIGHT4, GL_POSITION, light4Position);
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light4Direction);
    glPopMatrix();
	glPushMatrix();
    GLfloat light5Position[]  = {-10, 70, 60, 1};
    GLfloat light5Direction[] = {0, -1.0, 0, 0.0};
    glLightfv(GL_LIGHT5, GL_POSITION, light5Position);
    glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, light5Direction);
    glPopMatrix();
	glPushMatrix();
    GLfloat light6Position[]  = {-20, 70, 70, 1};
    GLfloat light6Direction[] = {0, -1.0, 0, 0.0};
    glLightfv(GL_LIGHT6, GL_POSITION, light6Position);
    glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, light6Direction);
    glPopMatrix();

	glPushMatrix();
    GLfloat light7Position[]  = {-20, 70, 30, 1};
    GLfloat light7Direction[] = {0, -1.0, 0, 0.0};
    glLightfv(GL_LIGHT7, GL_POSITION, light7Position);
    glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, light7Direction);
    glPopMatrix();
    //*/
    
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glColor3f(0.3, 0.7, 0.3);
    field(2, 100);
	glDisable(GL_COLOR_MATERIAL);
    
    //-------------Task3a---------------
    //*
    glPushMatrix();
    glTranslatef(0, 15, 0);
    GLfloat ambref3[]  = {prop1,0, 0, 1.0};
    GLfloat difref3[]  = {0, 0, prop2, 1.0};
    GLfloat specref3[] = {prop3, prop3, prop3, 1.0};
    GLint shininess3   = 23;
	glMaterialfv(GL_FRONT, GL_AMBIENT,   ambref3);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   difref3);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specref3);
    glMaterialf (GL_FRONT, GL_SHININESS, shininess3);
    glutSolidTeapot(20.0);

    glPushMatrix();
    glTranslatef(25, 0, 30);
    GLfloat ambref2[]  = {0,0,prop5, 1.0};
    GLfloat difref2[]  = {0, prop6, 0, 1.0};
    GLfloat specref2[] = {prop7, 0, prop7, 1.0};
    GLint shininess2   = 23;
	glMaterialfv(GL_FRONT, GL_AMBIENT,   ambref2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   difref2);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specref2);
    glMaterialf (GL_FRONT, GL_SHININESS, shininess2);
    glutSolidTeapot(20.0);
    glPopMatrix();

    glPopMatrix();
    //*/
    
    //-------------Task4a---------------
    
    // Disable color material
   // glDisable(GL_COLOR_MATERIAL);
	/*
    GLfloat ambref0[]  = {0.1,  0.1,  0.1,  1.0};
    GLfloat difref0[]  = {0.45, 0.45, 0.45, 1.0};
    GLfloat specref0[] = {0.50, 0.50, 0.50, 1.0};
    GLint shininess0   = 32;
    glMaterialfv(GL_FRONT, GL_AMBIENT,   ambref0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   difref0);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specref0);
    glMaterialf (GL_FRONT, GL_SHININESS, shininess0);

    //*
    glPushMatrix();
    glTranslatef(dx-40, 31+dy, dz);
    glRotatef(ry, 0, 1, 0);
    drawObj(tyra);
    glPopMatrix();
    //*/
    
    //-------------Task4c---------------
    //*

	// Polygon rendering mode enable Material
    //glEnable(GL_COLOR_MATERIAL);
    // We use Ambient and Diffuse color of each object as given in color3f
   // glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	//glColor3f(0,1,1);
	/*
    GLfloat ambref1[]  = {0.175, 0.012, 0.012, 0.55};
    GLfloat difref1[]  = {0.614, 0.041, 0.041, 0.55};
    GLfloat specref1[] = {0.728, 0.308, 0.308, 0.55};
    GLint shininess1   = 76.8;
	glMaterialfv(GL_FRONT, GL_AMBIENT,   ambref1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   difref1);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specref1);
    glMaterialf (GL_FRONT, GL_SHININESS, shininess1);
	*/
	/*
    glPushMatrix();
    glTranslatef(dx+40, 31+dy, dz);
    glRotatef(ry, 0, 1, 0);
    drawObj(tyra_norm);
    glPopMatrix();

    /*
    GLfloat ambref1[]  = {0.247, 0.225, 0.065, 1.0};
    GLfloat difref1[]  = {0.346, 0.314, 0.090, 1.0};
    GLfloat specref1[] = {0.797, 0.724, 0.208, 1.0};
    GLint shininess1   = 83.2;
    glMaterialfv(GL_FRONT, GL_AMBIENT,   ambref1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   difref1);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specref1);
    glMaterialf (GL_FRONT, GL_SHININESS, shininess1);

    glPushMatrix();
    glTranslatef(25, 15, 30);
    glutSolidTeapot(20.0);
    glPopMatrix();
    //*/    

    // All drawing commands applied to the
    // hidden buffer, so now, bring forward
    // the hidden buffer and hide the visible one
    glutSwapBuffers();
}

//------------------------------------------------------------------------------

void resize(int w, int h)
{
    glMatrixMode(GL_PROJECTION); 
    // define the visible area of the window ( in pixels )
    if (h==0) h=1;
    glViewport(0, 0, w, h); 

    // Setup viewing volume
    glLoadIdentity();
    gluPerspective(60.0, (float)w/(float)h, 1.0, 500.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//------------------------------------------------------------------------------

void idle()
{
    //glMatrixMode(GL_MODELVIEW);
    // Make your changes here
    
    //-------------Task2c---------------
    // Light movement
	if(flagf==true){
		if(lightpos<100){
			lightpos+=5;
			lightcol-=0.025;
		}
		else{flagf=false;}
		}
		else{
			if(lightpos>-100){
			lightpos-=5;
			lightcol+=0.025;
			}
			else{flagf=true;}
		}
		if(propflag==0){
			if(prop1<1){
				prop1+=0.01;
			}
			else{propflag++;}
		}
		if(propflag==1){
			if(prop2<1){
				prop2+=0.01;
			}
			else{propflag++;}
		}
		if(propflag==2){
			if(prop3<1){
				prop3+=0.01;
			}
			else{propflag+=2;}
		}
		
		if(propflag==4){
			if(prop5<1){
				prop5+=0.01;
			}
			else{propflag++;}
		}
		if(propflag==5){
			if(prop6<1){
				prop6+=0.01;
			}
			else{propflag++;}
		}
		if(propflag==6){
			if(prop7<1){
				prop7+=0.01;
			}
			else{propflag++;}
		}
		if(propflag==7){
			if(prop8<1){
				prop8+=0.01;
			}
			else{
				prop1=0;
				prop2=0;
				prop3=0;
				prop4=0;
				prop5=0;
				prop6=0;
				prop7=0;
				prop8=0;
				propflag=0;
			}
		}
	

    // After your changes rerender
    glutPostRedisplay();
}

//------------------------------------------------------------------------------

void menuSelect(int choice)
{
    //-------------Task2b---------------
    
    switch (choice)
    {
    case LIGHT0:
		glEnable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
        break;
    case LIGHT1:
		glEnable(GL_LIGHT1);
		glDisable(GL_LIGHT0);
        break;
    case BOTH:
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
        break;
    case NONE:
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
        break;
    }
    glutPostRedisplay();
    //*/
}

//------------------------------------------------------------------------------

void keyboardDown(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'W':
    case 'w':
        dz -= 1;
        break;
    case 'A':
    case 'a':
        dx -= 1;
        break;
    case 'S':
    case 's':
        dz += 1;
        break;
    case 'D':
    case 'd':
        dx += 1;
        break;
    case '+':
        cdist -= zoomStep;
        cx = cdist*sin(altitudeAngle)*sin(azimuthAngle);
        cy = cdist*cos(altitudeAngle);
        cz = cdist*sin(altitudeAngle)*cos(azimuthAngle);
        break;
    case '-':
        cdist += zoomStep;
        cx = cdist*sin(altitudeAngle)*sin(azimuthAngle);
        cy = cdist*cos(altitudeAngle);
        cz = cdist*sin(altitudeAngle)*cos(azimuthAngle);
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
        break;
    case 'A':
    case 'a':
        break;
    case 'S':
    case 's':
        break;
    case 'D':
    case 'd':
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

void keyboardSpecialDown(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        dy += 1;
        break;
    case GLUT_KEY_DOWN:
        dy -= 1;
        break;
    case GLUT_KEY_RIGHT:
        ry -= 1;
        break;
    case GLUT_KEY_LEFT:
        ry += 1;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

//------------------------------------------------------------------------------

void keyboardSpecialUp(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        break;
    case GLUT_KEY_DOWN:
        break;
    case GLUT_KEY_RIGHT:
        break;
    case GLUT_KEY_LEFT:
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

//------------------------------------------------------------------------------

void mouseClick(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
    {
        mouseClickDown = true;
        mx0 = x;
        my0 = y;
    }
    else 
    {
        mouseClickDown = false;
    }
}

//------------------------------------------------------------------------------

void mouseMotion(int x, int y)
{
    if (mouseClickDown)
    {
        // Calculate angles
        azimuthAngle  -= (x-mx0)*rotFactor;
        altitudeAngle -= (y-my0)*rotFactor;
        // Set new camrea position
        cx = cdist*sin(altitudeAngle)*sin(azimuthAngle);
        cy = cdist*cos(altitudeAngle);
        cz = cdist*sin(altitudeAngle)*cos(azimuthAngle);
        // Keep mouse x,y for next call
        mx0 = x;
        my0 = y;

        glutPostRedisplay();
    }
    //*/
}

