#include "Scene01.h"
#include "utils.h"
#include "canvas.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace vvr;
using namespace std;

Scene01::Scene01() 
{
    m_bg_col = Colour::grey;
    m_rad = 30;
    m_x = 300;
    m_y = 0;
}

void Scene01::draw()
{
    enterPixelMode();  // Instruct OpenGL to render in pixel coordinates.

    Colour col_circ = Colour::black;
    Colour col_tri  = Colour::black;

    // Compute areas.
    // Triangle area: http://en.wikipedia.org/wiki/Triangle#Using_coordinates
    double area_circ = 3.14159 * m_rad * m_rad;
    double area_tri = 0.5 * abs((-200.0 - m_x) * (200.0 - (-200.0)) - 
        (-200.0 - (-200.0)) * (m_y - (-200.0)));
    
    echo(area_circ);
    echo(area_tri);

    if (area_circ > area_tri) {
        col_circ = Colour::green;
    }
    else {
        col_tri = Colour::green;
    }

    // Draw a circle centered at: (m_x , m_y).
    Circle2D circle = Circle2D( m_x, m_y, m_rad, col_circ);
    circle.draw();

    // Draw a triangle.
    Triangle2D tri(-200, -200, -200, 200, m_x, m_y, col_tri); 
    tri.setSolidRender(false);
    tri.draw();

    // Draw a line segment.
    LineSeg2D line(300, -200, m_x, m_y, Colour::white);
    line.draw();
}

void Scene01::mousePressed(int x, int y, int modif)
{
    m_x = x;
    m_y = y;
}

void Scene01::mouseMoved(int x, int y, int modif)
{
    m_x = x;
    m_y = y;
}

void Scene01::mouseWheel(int dir, int modif)
{
    if (dir>0) 
    {
        m_rad += 9;
    }
    else 
    {
        m_rad -= 9;
        if (m_rad<0) m_rad = 0;
    }
}
