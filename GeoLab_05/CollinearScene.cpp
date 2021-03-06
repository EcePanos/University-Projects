#include "CollinearScene.h"
#include <utils.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>

#define NUMPOINTS   60

/* Task Function prototypes */
void Task_CollinearPoints (const C2DPointSet&, C2DPointSet&);

/* Construct - Load  - Setup */

CollinearScene::CollinearScene()
{
    m_bg_col = Colour(0x44, 0x44, 0x44);
    reset();
}

void CollinearScene::reset()
{
    Scene::reset();
    
    
    // Divide window to Tasks
    boundary1.Set(C2DPoint(4000, 400), C2DPoint(-4000, 400));
    boundary2.Set(C2DPoint(-800, -3000), C2DPoint(-800, 400));
    canvas0.add(boundary1, Colour::black);
    canvas0.add(boundary2, Colour::black);

    SetupTask();

    // Execute Tasks
    C2DPointSet colPts;
    Task_CollinearPoints(points, colPts);

    double dist1, dist2, dist3;
    for (unsigned j=0; j<colPts.size(); j+=3) {
        dist1 = colPts[j].Distance(colPts[j+1]);
        dist2 = colPts[j+1].Distance(colPts[j+2]);
        dist3 = colPts[j+2].Distance(colPts[j]);

        if (dist1>dist2 && dist1>dist3) {
            canvas1.add(C2DLine(colPts[j],colPts[j+1]), Colour::darkRed);
        }
        else if (dist2 > dist3) {
            canvas1.add(C2DLine(colPts[j+1],colPts[j+2]), Colour::darkRed);
        }
        else {
            canvas1.add(C2DLine(colPts[j+2],colPts[j]), Colour::darkRed);
        }
    }
    for (unsigned i=0; i<colPts.size(); i++) {
        canvas1.add(colPts[i], Colour::red);
    }

}

void CollinearScene::SetupTask()
{
    points.AddCopy(C2DPoint(125, -55));
    points.AddCopy(C2DPoint( 75, -55));
    points.AddCopy(C2DPoint( 25, -55));
    points.AddCopy(C2DPoint(125,-105));
    points.AddCopy(C2DPoint( 25,-105));
    points.AddCopy(C2DPoint(125,-155));
    points.AddCopy(C2DPoint( 75,-155));
    points.AddCopy(C2DPoint( 25,-155));

    points.AddCopy(C2DPoint(175, -40));
    points.AddCopy(C2DPoint(175, -90));
    points.AddCopy(C2DPoint(175,-140));
    points.AddCopy(C2DPoint(205, -40));
    points.AddCopy(C2DPoint(205, -90));
    points.AddCopy(C2DPoint(205,-140));
    points.AddCopy(C2DPoint(235, -40));
    points.AddCopy(C2DPoint(235,-140));

    canvas1.add(C2DPoint(125, -55), Colour::green);
    canvas1.add(C2DPoint( 75, -55), Colour::green);
    canvas1.add(C2DPoint( 25, -55), Colour::green);
    canvas1.add(C2DPoint(125,-105), Colour::green);
    canvas1.add(C2DPoint( 25,-105), Colour::green);
    canvas1.add(C2DPoint(125,-155), Colour::green);
    canvas1.add(C2DPoint( 75,-155), Colour::green);
    canvas1.add(C2DPoint( 25,-155), Colour::green);

    canvas1.add(C2DPoint(175, -40), Colour::green);
    canvas1.add(C2DPoint(175, -90), Colour::green);
    canvas1.add(C2DPoint(175,-140), Colour::green);
    canvas1.add(C2DPoint(205, -40), Colour::green);
    canvas1.add(C2DPoint(205, -90), Colour::green);
    canvas1.add(C2DPoint(205,-140), Colour::green);
    canvas1.add(C2DPoint(235, -40), Colour::green);
    canvas1.add(C2DPoint(235,-140), Colour::green);

    C2DPoint pt;
    CRandomNumber rnX(  5, 500);
    CRandomNumber rnY(-350, -10);

    for (int i=0; i<NUMPOINTS; i++) {
        pt.Set(rnX.Get(), rnY.Get());
        points.AddCopy(pt);
        canvas1.add(pt, Colour::green);
    }

    canvas1.newFrame(true);

    C2DPoint mousePt = C2DPoint(37, -10);
    points.AddCopy(mousePt);
    canvas1.add(mousePt, Colour::yellow);
}

/* UI Handling */

void CollinearScene::mousePressed(int x, int y, int modif)
{
    Scene::mousePressed(x, y, modif);
    HandlePoint(C2DPoint(x,y));
}

void CollinearScene::mouseMoved(int x, int y, int modif)
{
    Scene::mouseMoved(x, y, modif);
    mousePressed(x,y,modif);
}

void CollinearScene::HandlePoint(const C2DPoint &p)
{
    if (boundary1.IsOnRight(p)) {
        
    }
    else if (boundary2.IsOnRight(p)) {
        HandleTask(p);
    }
    else {

    }
}

void CollinearScene::HandleTask(const C2DPoint &p)
{
    canvas1.resize(1);
    canvas1.newFrame(true);

    points[points.size()-1].Set(p.x, p.y);
    canvas1.add(p, Colour::yellow);

    C2DPointSet colPts;
    Task_CollinearPoints(points, colPts);

    double dist1, dist2, dist3;
    for (unsigned j=0; j<colPts.size(); j+=3) {
        dist1 = colPts[j].Distance(colPts[j+1]);
        dist2 = colPts[j+1].Distance(colPts[j+2]);
        dist3 = colPts[j+2].Distance(colPts[j]);

        if (dist1>dist2 && dist1>dist3) {
            canvas1.add(C2DLine(colPts[j],colPts[j+1]), Colour::darkRed);
        }
        else if (dist2 > dist3) {
            canvas1.add(C2DLine(colPts[j+1],colPts[j+2]), Colour::darkRed);
        }
        else {
            canvas1.add(C2DLine(colPts[j+2],colPts[j]), Colour::darkRed);
        }
    }

    for (unsigned i=0; i<colPts.size(); i++) {
        canvas1.add(colPts[i], Colour::red);
    }

}

/* Drawing */

void CollinearScene::draw()
{
    enterPixelMode();
    
    canvas0.draw();
    canvas1.draw();

    returnFromPixelMode();
}

/* Application Entry Point */

int main_2(int argc, char* argv[])
{
    return vvr::mainLoop(argc, argv, new CollinearScene);
}

/*! Dosmenwn triwn shmeiwn epistrefei an auta einai syneftheiaka
 * @param[in]  p1 To prwto shmeio
 * @param[in]  p2 To deutero shmeio
 * @param[in]  p3 To trito shmeio
 * @return Epistrefei an ta tria auta shmeia einai shneftheiaka me akribeia klishs
 *  4 dekadikwn psifiwn
 */
bool isCollinear(const C2DPoint &p1, const C2DPoint &p2, const C2DPoint &p3)
{


    return true;
}

/*! Dosmenou enos nefous shmeiwn ypologizei poia apo afta einai suneftheiaka
 * @param[in]  cloudPts C2DPointSet apo shmeia
 * @param[out] collinearPts C2DPointSet ta shmeia pou einai shneftheiaka ana triades
 *  ena shmeio mporei na einai panw apo mia fora sto Set.
 */
void Task_CollinearPoints(const C2DPointSet &cloudPts, C2DPointSet &collinearPts) 
{


}
