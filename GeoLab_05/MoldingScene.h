#include "settings.h"
#include "scene.h"
#include "mesh.h"
#include "canvas.h"
#include "GeoLib.h"

class MoldingScene : public vvr::Scene
{
public: 
    MoldingScene();
    const char* getName() const override;

protected:
    void draw() override;
    void reset() override;
    bool idle() override;
    void mousePressed(int x, int y, int modif) override;
    void mouseReleased(int x, int y, int modif) override;
    void mouseMoved(int x, int y, int modif) override;
    void keyEvent(unsigned char key, bool up, int modif) override;
    void arrowEvent(vvr::ArrowDir dir, int modif) override;

private:
    bool isFreeToMove(C2DVector &dx);

private:
    C2DPoint               *m_curr_p;
    vvr::Canvas2D           m_canvas;
    std::vector<C2DPoint>   m_pts;
    C2DVector               m_displacement;
    C2DVector               m_dv;
    C2DPoint                m_click_anchor;
    float                   m_last_update_time;
    bool                    m_anim_on;
};
