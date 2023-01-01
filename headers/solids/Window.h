#pragma once
#include "Game.h"
class Window : Drawable
{

public:
    void Init()
    {

        //left Window out
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(37.499, -2.499, 15);
        glVertex3d(37.499, 7.499, 15);
        glVertex3d(-37.499, 7.499, 15);
        glVertex3d(-37.499, -2.499, 15);
        glEnd();
        //left Window in
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(37.499, 7.499, 14.999);
        glVertex3d(37.499, -2.499, 14.999);
        glVertex3d(-37.499, -2.499, 14.999);
        glVertex3d(-37.499, 7.499, 14.999);
        glEnd();
        //right Window in
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(37.499, -2.499, -14.999);
        glVertex3d(37.499, 7.499, -14.999);
        glVertex3d(-37.499, 7.499, -14.999);
        glVertex3d(-37.499, -2.499, -14.999);
        glEnd();
        
        //right Window out
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(37.499, 7.499, -15);
        glVertex3d(37.499, -2.499, -15);
        glVertex3d(-37.499, -2.499, -15);
        glVertex3d(-37.499, 7.499, -15);
        glEnd();


    }
    void Draw()
    {

    }
};