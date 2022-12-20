#pragma once

#include "glut.h"

namespace Event
{
    void Mouse(int button, int state, int x, int y)
    {
    }
    void ResizeWindow(int w, int h)
    {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, (double)w / (double)h, 1.0, 200.0);
    }
}