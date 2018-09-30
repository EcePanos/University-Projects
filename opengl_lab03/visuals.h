/*******************************************************************************
  Visual Functions
 ******************************************************************************/

// Set up the OpenGL state machine and create a light source
void setup();

// The function responsible for drawing everything in the
// OpenGL context associated to a window.
void render();

// Handle the window size changes and define the world coordinate
// system and projection type
void resize(int w, int h);

// Idle function
void idle();

// Function for handling keyboard events.
void keyboardDown(unsigned char key, int x, int y);

// Function for handling keyboard events.
void keyboardUp(unsigned char key, int x, int y);

// Function for handling keyboard events.
void keyboardSpecialDown(int key, int x, int y);

// Function for handling keyboard events.
void keyboardSpecialUp(int key, int x, int y);\

// Function for handling mouse events
void mouseClick(int button, int state, int x, int y);

// Function for handling mouse events
void mouseMotion(int x, int y);

unsigned int genChessTexture(float r0, float g0, float b0, float r1, float g1, float b1);

void drawScene(void);

void drawBox(float xsz, float ysz, float zsz, float norm_sign);
