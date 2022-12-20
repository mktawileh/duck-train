#include "glut.h"
#include "src/Trolley.h"

namespace Scene
{
    Trolley train[1];
    void InitRendering()
    {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_COLOR_MATERIAL);
        // glEnable(GL_LIGHTING);  // Enable lighting
        // glEnable(GL_LIGHT0);    // Enable light #0
        // glEnable(GL_LIGHT1);    // Enable light #1
        glEnable(GL_NORMALIZE);
        glShadeModel(GL_SMOOTH);
    }
    void InitObjects()
    {
       train[0].init();
    }
    void Redraw()
    {
       train[0].draw();
    }
}
