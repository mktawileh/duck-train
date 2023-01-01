#pragma once
#include "Game.h" // how NOT to call this header and still work?!
class Door : Drawable
{


public:
    void Init()
    {
        //DECLARATION:
        //NO need for display lists here for this class is going to be a component of another class!!!




        // list = glGenLists(1);
        // glNewList(list, GL_COMPILE);



        // Front Door out
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.499, 4.99);
        glVertex3d(-40, 7.499, 4.99);
        glVertex3d(-40, 7.499, -4.99);
        glVertex3d(-40, -12.499, -4.99);
        glEnd();
        // Front Door in
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-39.999, -12.499, 4.99);
        glVertex3d(-39.999, -12.499, -4.99);
        glVertex3d(-39.999, 7.499, -4.99);
        glVertex3d(-39.999, 7.499, 4.99);
        glEnd();


        // Back Door out
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-39.999, -12.499, 4.99);
        glVertex3d(-39.999, -12.499, -4.99);
        glVertex3d(-39.999, 7.499, -4.99);
        glVertex3d(-39.999, 7.499, 4.99);
        glEnd();
        // Back Door in
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.499, 4.99);
        glVertex3d(40, 7.499, 4.99);
        glVertex3d(40, 7.499, -4.99);
        glVertex3d(40, -12.499, -4.99);
        glEnd();

        // glEndList();
    }
    void Draw()
    {
        // glCallList(list);
    }
};