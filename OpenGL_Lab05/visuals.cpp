//----------------------------------------------------------------------------//
//    Learning OpenGL: Εισαγωγικά Μαθήματα OpenGL                             //
//                                                                            //
//    Πλατφόρμα ανάπτυξης παραδειγμάτων                                       //
//                                                                            //
//    Εργαστήριο 5ο                                                           //
//----------------------------------------------------------------------------//

#include <iostream>	  // For string handling
#include <stdlib.h>   // Just for some standard functions
#include <stdio.h>    // Just for some ASCII messages
#include <glut.h>     // An interface and windows management library
#include "visuals.h"  // Header file for our OpenGL functions
#include "windows.h"
#include "tiny_obj_loader.h"
#include "soil.h"

#define KEY_ESC 27
#define PI 3.1415927

using namespace std;
using namespace tinyobj;

/*******************************************************************************
  State Variables
 ******************************************************************************/

// Menu mode variable
static int mode = TYRA;
// Texture IDs
static GLuint wallTexID;
static GLuint windmillTexID;
static GLuint floorTexID;
static GLuint skinTexID;
static GLuint cubeTexID;
static GLuint f16sTexID;
static GLuint f16tTexID;
static GLuint currentTexID;
static int tx;
static int ty;
// Model variables
mesh_t tyra;
mesh_t tyra_norm;
mesh_t plane;
mesh_t cylinder;
mesh_t sphere;
mesh_t cube;
mesh_t f16;
static float dx = 0.0;
static float dy = 0.0;
static float dz = 0.0;
static float ry = 0.0;
double midx=0;
double midy=0;
double midz=0;
double weight=0;
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
static int  mx0;
static int  my0;
int selector=0;
int method=0;
int deform=0;

/*******************************************************************************
  Implementation of Auxiliary Functions
 ******************************************************************************/

void planarMapping(GLfloat &u, GLfloat &v, float *point)
{
    //-------------Task2b---------------
    // The coordinates of the represented object range between [-50, 50]
    // When u, v texture coordinates between [0, 1]
    u = 0;
    v = 0;
}

//------------------------------------------------------------------------------

void cylindricalMapping(GLfloat &u, GLfloat &v, float *point)
{
    //-------------Task2b---------------
    // Map y and theta angle to u, v coordinates
    float theta;
    float x = point[0];
    float y = point[1];
    float z = point[2];

    theta = atan2(x, z);
    u = (GLfloat) ((theta + PI) / (2*PI));
    v = (GLfloat) ((y + 50.) / 100.);
}

//------------------------------------------------------------------------------

void sphericalMapping(GLfloat &u, GLfloat &v, float *point)
{
    //-------------Task2b---------------
    //*
    // Map theta and (90-)phi angles to u, v coordinates
    float theta, phi;
    float x = point[0];
    float y = point[1];
    float z = point[2];

    //theta = ...;
    //phi   = ...;

    u = 0;
    v = 0;
    //*/
}

//------------------------------------------------------------------------------

void cubicalMapping(GLfloat &u, GLfloat &v, float *point)
{
    //-------------Task2b---------------
    u = (GLfloat) (point[0] + 50.) / 100.;
    v = (GLfloat) (point[1] + 50.) / 100.;
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
	/*
    for (int i = 0; i < positions.size(); i+=3)
    {
        normals.push_back(0.0);
        normals.push_back(0.0);
        normals.push_back(1.0);
    }

    //*/
    
    //-------------Task1b---------------
    // Apply new normal every tree vertices
    
    // Allocate memory for normals
    normals.resize(positions.size());
    
    float normal[3];
	cout<<"Press 0 for average, 1 for area weighted average, 2 for angle weighted average";
	cin>>method;
	cout<<endl;
    for (int i = 0; i < indices.size(); i+=3)
    {
        // Get points of each triangle
        GLfloat *pt1 = (GLfloat*) &positions[3*indices[i]];
        GLfloat *pt2 = (GLfloat*) &positions[3*indices[i+1]];
        GLfloat *pt3 = (GLfloat*) &positions[3*indices[i+2]];

        // Compute cross product pt12 x pt13
		GLfloat pt12[]={pt2[0]-pt1[0],pt2[1]-pt1[1],pt2[2]-pt1[2]};
		GLfloat pt13[]={pt3[0]-pt1[0],pt3[1]-pt1[1],pt3[2]-pt1[2]};
		//double weight=0.5*sqrt(pow((pt12[1]*pt13[2])-(pt12[2]*pt13[1]),2)+pow(-((pt12[0]*pt13[2])-(pt12[2]*pt13[0])),2)+pow((pt12[0]*pt13[1])-(pt12[1]*pt13[0]),2));
		
		if(method==0){
			weight=1;
		}
		if(method==2){
			weight=acos((pt12[0]*pt13[0]+pt12[1]*pt13[1]+pt12[2]*pt13[2])/sqrt((pt12[0]*pt12[0]+pt12[1]*pt12[1]+pt12[2]*pt12[2])*(pt13[0]*pt13[0]+pt13[1]*pt13[1]+pt13[2]*pt13[2])));
		}
		normal[0]=((pt12[1]*pt13[2])-(pt12[2]*pt13[1]));
		normal[1]=(-((pt12[0]*pt13[2])-(pt12[2]*pt13[0])));
		normal[2]=((pt12[0]*pt13[1])-(pt12[1]*pt13[0]));
		if(method==1){
			weight = sqrt(pow(normal[0], 2) + pow(normal[1], 2) + pow(normal[2], 2)) / 2.0;
		}
		//normal[0]*=weight;
		//normal[1]*=weight;
		//normal[2]*=weight;
		
		normals[3*indices[i]]+=normal[0]*weight;
		normals[3*indices[i]+1]+=normal[1]*weight;
		normals[3*indices[i]+2]+=normal[2]*weight;
		normals[3*indices[i+1]]+=normal[0]*weight;
		normals[3*indices[i+1]+1]+=normal[1]*weight;
		normals[3*indices[i+1]+2]+=normal[2]*weight;
		normals[3*indices[i+2]]+=normal[0]*weight;
		normals[3*indices[i+2]+1]+=normal[1]*weight;
		normals[3*indices[i+2]+2]+=normal[2]*weight;
		/*
		normals[3*indices[i]]*=weight;
		normals[3*indices[i]+1]*=weight;
		normals[3*indices[i]+2]*=weight;
		normals[3*indices[i+1]]*=weight;
		normals[3*indices[i+1]+1]*=weight;
		normals[3*indices[i+1]+2]*=weight;
		normals[3*indices[i+2]]*=weight;
		normals[3*indices[i+2]+1]*=weight;
		normals[3*indices[i+2]+2]*=weight;
		*/

        // Normalize the per triangle normal

        // Add the calculated normal to the corresponding normal per vertex
        // Normal of the first point of current triangle (x, y, z)
        
        // Normal of the second point of current triangle (x, y, z)
        
        // Normal of the third point of current triangle (x, y, z)
    }

    // Normalize per vertex normals
    for (int i = 0; i < normals.size(); i+=3)
    {
		float d=sqrt(pow(normals[i],2)+pow(normals[i+1],2)+pow(normals[i+2],2));
		normals[i]/=d;
		normals[i+1]/=d;
		normals[i+2]/=d;
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
    //-------------Task1a---------------
    vector<shape_t> shapes;
    string err = LoadObj(shapes, filename.c_str(), (getExeDir() + "..\\Models\\").c_str());

    if (!err.empty())
    {
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
        //-----------Task1c-------------
        // Modify points here.
		if(selector==1){
		int num=mesh.positions.size()/3;
		for(int i=0;i<mesh.positions.size();i+=3){
			midx+=mesh.positions[i];
			midy+=mesh.positions[i+1];
			midz+=mesh.positions[i+2];
		}
		midx/=num;
		midy/=num;
		midz/=num;
		
		for(int i=0;i<mesh.positions.size();i+=3){
			mesh.positions[i]-=midx;
			mesh.positions[i+1]-=midy;
			mesh.positions[i+2]-=midz;
		}
		for(int i=0;i<mesh.positions.size();i+=3){
			mesh.positions[i]*=10;
			mesh.positions[i+1]*=10;
			mesh.positions[i+2]*=10;
		}
		cout<<"Press 0 to show the model or 1 to show deformed model";
		cin>>deform;
		cout<<endl;
		if(deform==1){
			for(int i=0;i<mesh.positions.size();i+=3){
				if(mesh.positions[i]>0){
					mesh.positions[i]+=100;
				}
			
			}
		}
		}
    }
}

//------------------------------------------------------------------------------

void drawObj(mesh_t &mesh)
{
    //-------------Task1a---------------
    // Take the points and faces of the first shape of obj
    vector<unsigned> &indices = mesh.indices;
    vector<float>  &positions = mesh.positions;
    vector<float>    &normals = mesh.normals;

    float* point;
    float* normal;
    glBegin(GL_TRIANGLES);
    for(int i = 0; i < indices.size(); i++)
    {
        normal = &normals[3*indices[i]];
        point = &positions[3*indices[i]];

        glNormal3fv((GLfloat*) normal);
        glVertex3fv((GLfloat*) point);
    }
    glEnd();
}

//------------------------------------------------------------------------------

void drawObjWithTexture(mesh_t &mesh,
             void(*Map)(GLfloat &u, GLfloat &v, float *point),
             int textureID)
{
    //-------------Task2a---------------
    // Take the points and faces of the first shape of obj
    vector<unsigned> &indices = mesh.indices;
    vector<float>  &positions = mesh.positions;
    vector<float>    &normals = mesh.normals;
    vector<float>  &texcoords = mesh.texcoords;

    float* point;
    if(Map && textureID)
    {
        // Load texture using the texture ID and Transform given
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
        GLfloat coord1;
        GLfloat coord2;
        
        float* normal;
        glBegin(GL_TRIANGLES);
        for(int i = 0; i < indices.size(); i++)
        {
            normal = &normals[3*indices[i]];
            point = &positions[3*indices[i]];

            // Calculate texture coordinates
            Map(coord1, coord2, point);

            glTexCoord2f(coord1, coord2);
            glNormal3fv((GLfloat*) normal);
            glVertex3fv((GLfloat*) point);
        }
        glEnd();

        glDisable(GL_TEXTURE_2D);
    }
    else if(!texcoords.empty() && textureID)
    {
        // Load texture with the texture ID and .objs' u, v coordinates
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
        float* texcoord;

        // With normals
        float* normal;
        glBegin(GL_TRIANGLES);
        for(int i = 0; i < indices.size(); i++)
        {
            normal = &normals[3*indices[i]];
            point = &positions[3*indices[i]];
            texcoord = &texcoords[2*indices[i]];

            glTexCoord2f((GLfloat) texcoord[0], (GLfloat) texcoord[1]);
            glNormal3fv((GLfloat*) normal);
            glVertex3fv((GLfloat*) point);
        }
        glEnd();

        glDisable(GL_TEXTURE_2D);
    }
    else
    {
        // No texture at all
        glDisable(GL_TEXTURE_2D);
        //cout << "No texture loaded " << "Or texture ID " << textureID << " not valid" << endl;
        
        float* normal;
        glBegin(GL_TRIANGLES);
        for(int i = 0; i < indices.size(); i++)
        {
            normal = &normals[3*indices[i]];
            point = &positions[3*indices[i]];

            glNormal3fv((GLfloat*) normal);
            glVertex3fv((GLfloat*) point);
        }
        glEnd();
    }
}

//------------------------------------------------------------------------------

GLuint loadTexture(const char *filename)
{
    // load an image file directly as a new OpenGL texture
    GLuint texID;
    texID = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                  SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS |
                                  SOIL_FLAG_TEXTURE_REPEATS);
  
    // check for an error during the load process
    if(!texID) cout << "texture: "  << *filename << " .SOIL loading error: "
                    << SOIL_last_result() << endl;
    return texID;
}

//------------------------------------------------------------------------------

GLuint loadRGBTexture(const char * filename, int width, int height,
                      bool linear, bool wrap)
{
    GLuint texID;
    GLbyte* data;
    FILE* file;

    // open texture data
    file = fopen(filename, "rb");
    if (!file)
    {
    printf("Image could not be opened\n");
    return 0;
    }

    // allocate buffer
    data = (GLbyte*) malloc(width*height*3);

    // read texture
    fread(data, width*height*3, sizeof(GLbyte), file);
    fclose(file);

    // allocate and bind texture
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
  
    // Give the image to OpenGL preprocess mipmaps
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

    // linear inter- and extrapolation
    // When MAGnifying the image (no bigger mipmap available), use LINEAR filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, linear? GL_LINEAR:GL_NEAREST);
    // When MINifying the image, use a LINEAR blend of two mipmaps, each filtered LINEARLY too
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, linear? GL_LINEAR:GL_NEAREST);

    // if wrap is true, the texture wraps over at the edges (repeat)
    //       ... false, the texture ends at the edges (clamp)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap? GL_REPEAT:GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap? GL_REPEAT:GL_CLAMP);
  
    // free buffer
    free(data);

    return texID;
}

//------------------------------------------------------------------------------

GLuint loadBMPTexture(const char * imagepath, bool linear, bool wrap)
{
    // Data read from the header of the BMP file
    // Each BMP file begins by a 54-bytes header
    unsigned char header[54];
    // Position in the file where the actual data begins
    unsigned int  dataPos;
    unsigned int  width, height;
    unsigned int  imageSize;
    // Actual RGB data
    unsigned char*data;

    // Open the file
    FILE * file = fopen(imagepath,"rb");
    if (!file)
    {
    printf("Image could not be opened\n");
    return 0;
    }
    if ( fread(header, 1, 54, file) != 54 )
    { 
    // If not 54 bytes read : problem
        printf("Not a correct BMP file\n");
        return 0;
    }
    if ( header[0]!='B' || header[1]!='M' )
    {
    printf("Not a correct BMP file\n");
    return 0;
    }

    // Read ints from the byte array
    dataPos    = *(int*)&(header[0x0A]);
    imageSize  = *(int*)&(header[0x22]);
    width      = *(int*)&(header[0x12]);
    height     = *(int*)&(header[0x16]);

    // Some BMP files are misformatted, guess missing information
    // 3 : one byte for each Red, Green and Blue component
    if (imageSize==0) imageSize = width*height*3;
    // The BMP header is done that way
    if (dataPos==0)   dataPos = 54;
  
    // Create a buffer
    data = new unsigned char [imageSize];
 
    // Read the actual data from the file into the buffer
    fread(data, 1, imageSize, file);
 
    //Everything is in memory now, the file can be closed
    fclose(file);
    
    //-------------Task2a---------------
    // Create one OpenGL texture
    GLuint texID;
    glGenTextures(1, &texID);
    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, texID);
 
    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
 
    // linear inter- and extrapolation
    // When MAGnifying the image (no bigger mipmap available), use LINEAR filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, linear? GL_LINEAR:GL_NEAREST);
    // When MINifying the image, use a LINEAR blend of two mipmaps, each filtered LINEARLY too
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, linear? GL_LINEAR:GL_NEAREST);

    // if wrap is true, the texture wraps over at the edges (repeat)
    //       ... false, the texture ends at the edges (clamp)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap ? GL_REPEAT : GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap ? GL_REPEAT : GL_CLAMP);
  
    // free buffer
    free(data);

    return texID;
}

/*******************************************************************************
  Implementation of Visual Functions
 ******************************************************************************/

void setup()
{
    // Parameter handling

    // polygon rendering mode and material properties
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  
    // Make models with smooth edges
    glShadeModel(GL_SMOOTH);

    // Points represented as circles
    glEnable(GL_POINT_SMOOTH);
  
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
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);

    // Polygon rendering mode enable Material
    glEnable(GL_COLOR_MATERIAL);
    // We use Ambient and Diffuse color of each object as given in color3f
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Enable the Lighting
    glEnable(GL_LIGHTING);

    // Set up light source
    // Light
    GLfloat lightAmbient[]   = {0.2,   0.2,   0.2, 1.0};
    GLfloat lightDiffuse[]   = {0.6,   0.6,   0.6, 1.0};
    GLfloat lightSpecular[]  = {0.9,   0.9,   0.9, 1.0};
    GLfloat lightPosition[]  = {0.0,   0.0,   0.0, 1.0};
    GLfloat lightDirection[] = {0.0,   0.0,  -1.0, 0.0};
  
    // Set Ambient Light
    glLightfv(GL_LIGHT0, GL_AMBIENT,  lightAmbient);
    // Set Difuse Light
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  lightDiffuse);
    // Set Specular Light
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    // Set Position of the Light
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
  
    // Enable Light
    glEnable(GL_LIGHT0);
    
    //-------------Task2a---------------
    // Enable Texture
    glEnable(GL_TEXTURE_2D);
    // Set mode for multiple textures
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    // C = Cf(1-At) + CtAt, A = Af
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    // Keep IDs of every texture
    wallTexID = loadRGBTexture((getExeDir() + "..\\Textures\\wall.rgb").c_str(), 512, 512, false, false);
    windmillTexID = loadBMPTexture((getExeDir() + "..\\Textures\\windmill.bmp").c_str(), false, true);
    // soil for the rescue
    floorTexID = loadTexture((getExeDir() + "..\\Textures\\floor.png").c_str());
    skinTexID  = loadTexture((getExeDir() + "..\\Textures\\skin.jpg").c_str());
    cubeTexID  = loadTexture((getExeDir() + "..\\Textures\\cube.png").c_str());
    f16sTexID  = loadTexture((getExeDir() + "..\\Textures\\F16s.bmp").c_str());
    f16tTexID  = loadTexture((getExeDir() + "..\\Textures\\F16t.bmp").c_str());
    // Set the current texture ID
    currentTexID = wallTexID;

    //-------------Task1a---------------
    /*
    // Read OBJ models
    // The mesh consists of positions, normals and indicies
    // we can access them using the following code:
    // tyra.positions[3*ith] returns the ith point
    // tyra.normals[3*ith] returns the ith normal
    // tyra.indices[ith] returns the index of the ith point
    // we have a new triangle every 3 indicies
    //*/
	cout<<"Press 0 for tyra secene or 1 for tyra_m";
	cin>>selector;
	cout<<endl;
	if(selector==0){
	 readObj(getExeDir() + "..\\Models\\tyra.obj", tyra);

    //-------------Task1b---------------
	 readObj(getExeDir() + "..\\Models\\tyra_norm.obj", tyra_norm);
	}

    //-------------Task1c---------------
   if(selector==1){
	readObj(getExeDir() + "..\\Models\\tyra_m.obj", tyra);
   }
    
    //-------------Task2a---------------
    /*
    readObj(getExeDir() + "..\\Models\\plane.obj", plane);
    readObj(getExeDir() + "..\\Models\\uvsphere.obj", sphere);
    readObj(getExeDir() + "..\\Models\\cylinder.obj", cylinder);
    readObj(getExeDir() + "..\\Models\\cube.obj", cube);
    readObj(getExeDir() + "..\\Models\\f16.obj", f16);
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
    gluLookAt(cx, cy, cz,  // camera position
               0,  0,  0,  // target position
               0,  1,  0); // up vector

    glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
    glTranslatef(dx, dy, dz);
    glRotatef(ry, 0, 1, 0);
    if(mode & TYRA)
    {
        glPushMatrix();
		if(selector==0){
			glTranslatef(-45, 0, 0);
		}
		//glScalef(100,100,100);
        drawObj(tyra);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(45, 0, 0);
        drawObj(tyra_norm);
        glPopMatrix();
    }
    if(mode & PLANE)
        drawObjWithTexture(plane, planarMapping, currentTexID);
    if(mode & CYLINDER)
        drawObjWithTexture(cylinder, cylindricalMapping, currentTexID);
    if(mode & SPHERE)
        drawObjWithTexture(sphere, sphericalMapping, currentTexID);
    if(mode & CUBE)
        drawObjWithTexture(cube, cubicalMapping, currentTexID);
    if(mode & F16)
        drawObjWithTexture(f16, NULL, f16sTexID);
    glPopMatrix();
  
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
}

//------------------------------------------------------------------------------

void idle()
{
    //glMatrixMode(GL_MODELVIEW);
    // Make your changes here
  
    // After your changes rerender
    //glutPostRedisplay();
}

//------------------------------------------------------------------------------

void menuSelect(int choice)
{
    switch (choice)
    {
    case TYRA:
        mode ^= TYRA;
        break;
    case PLANE:
        mode ^= PLANE;
        break;
    case CYLINDER:
        mode ^= CYLINDER;
        break;
    case SPHERE:
        mode ^= SPHERE;
        break;
    case CUBE:
        mode ^= CUBE;
        break;
    case F16:
        mode ^= F16;
        break;
    default:
        break;
    }
    glutPostRedisplay();
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
    case 'I':
    case 'i':
        ty -= 1;
        break;
    case 'K':
    case 'k':
        ty += 1;
        break;
    case 'J':
    case 'j':
        tx += 1;
        break;
    case 'L':
    case 'l':
        tx -= 1;
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
    case GLUT_KEY_F1:
        currentTexID = wallTexID;
        break;
    case GLUT_KEY_F2:
        currentTexID = windmillTexID;
        break;
    case GLUT_KEY_F3:
        currentTexID = floorTexID;
        break;
    case GLUT_KEY_F4:
        currentTexID = skinTexID;
        break;
    case GLUT_KEY_F5:
        currentTexID = cubeTexID;
        break;
    case GLUT_KEY_F6:
        currentTexID = f16sTexID;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

//------------------------------------------------------------------------------

void keyboardSpecialUp(int key, int x, int y)
{
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
    mouseClickDown = false;
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
}
