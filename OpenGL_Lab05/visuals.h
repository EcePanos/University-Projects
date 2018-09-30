// Enumeration for menu options
enum MENU_OPTIONS
{
    TYRA      = 1 << 0,
    PLANE     = 1 << 1,
    CYLINDER  = 1 << 2,
    SPHERE    = 1 << 3,
    CUBE      = 1 << 4,
    F16       = 1 << 5,
};

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

// Function for menu select events
void menuSelect(int choice);

// Function for handling keyboard events.
void keyboardDown(unsigned char key, int x, int y);

// Function for handling keyboard events.
void keyboardUp(unsigned char key, int x, int y);

// Function for handling keyboard events.
void keyboardSpecialDown(int key, int x, int y);

// Function for handling keyboard events.
void keyboardSpecialUp(int key, int x, int y);

// Function for handling mouse events
void mouseClick(int button, int state, int x, int y);

// Function for handling mouse events
void mouseMotion(int x, int y);