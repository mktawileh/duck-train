#pragma once

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include "glut.h"
#include "utils/Helper.h"
#include "utils/MathAux.h"
#include "Model.h"

class Truck
{

public:
    GLuint list = 0;
    void Init()
    {
        list = glGenLists(1);
        glNewList(list, GL_COMPILE);
        glColor3ub(0, 145, 200);

        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 12.5, -15);
        glVertex3d(-40, 12.5, -10);
        glVertex3d(40, 12.5, -10);
        glVertex3d(40, 12.5, -15);
        glEnd();
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 12.4, -15);
        glVertex3d(40, 12.4, -10);
        glVertex3d(-40, 12.4, -10);
        glVertex3d(-40, 12.4, -15);
        glEnd();

        // sub: the side two:
        //(230, 25, 69);

        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 12.5, 15);
        glVertex3d(40, 12.5, 10);
        glVertex3d(-40, 12.5, 10);
        glVertex3d(-40, 12.5, 15);
        glEnd();
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 12.4, 15);
        glVertex3d(-40, 12.4, 10);
        glVertex3d(40, 12.4, 10);
        glVertex3d(40, 12.4, 15);
        glEnd();

        // the vertical rooves:
        // sub: the v one:

        glNormal3d(0, 1, 0);

        glBegin(GL_POLYGON);
        glVertex3d(40, 12.5, 10);
        glVertex3d(40, 15, 10);
        glVertex3d(-40, 15, 10);
        glVertex3d(-40, 12.5, 10);
        glEnd();
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 12.5, 9.9);
        glVertex3d(-40, 15, 9.9);
        glVertex3d(40, 15, 9.9);
        glVertex3d(40, 12.5, 9.9);
        glEnd();

        //(125, 225, 169);
        // sub: the v two:

        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 12.5, -10);
        glVertex3d(-40, 15, -10);
        glVertex3d(40, 15, -10);
        glVertex3d(40, 12.5, -10);
        glEnd();
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(40, 12.5, -9.9);
        glVertex3d(40, 15, -9.9);
        glVertex3d(-40, 15, -9.9);
        glVertex3d(-40, 12.5, -9.9);
        glEnd();

        // the flat roof:
        //(36, 251, 57);

        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 15, 10);
        glVertex3d(40, 15, -10);
        glVertex3d(-40, 15, -10);
        glVertex3d(-40, 15, 10);
        glEnd();
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 14.9, 10);
        glVertex3d(-40, 14.9, -10);
        glVertex3d(40, 14.9, -10);
        glVertex3d(40, 14.9, 10);
        glEnd();

        // the front side

        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, 15);
        glVertex3d(-40, 7.5, 15);
        glVertex3d(-40, 7.5, 5);
        glVertex3d(-40, -12.5, 5);
        glEnd();
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-39.9, -12.5, 5);
        glVertex3d(-39.9, 7.5, 5);
        glVertex3d(-39.9, 7.5, 15);
        glVertex3d(-39.9, -12.5, 15);
        glEnd();

        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, -5);
        glVertex3d(-40, 7.5, -5);
        glVertex3d(-40, 7.5, -15);
        glVertex3d(-40, -12.5, -15);
        glEnd();
        glNormal3d(1, 0, 0);

        glBegin(GL_POLYGON);
        glVertex3d(-39.9, -12.5, -15);
        glVertex3d(-39.9, 7.5, -15);
        glVertex3d(-39.9, 7.5, -5);
        glVertex3d(-39.9, -12.5, -5);
        glEnd();

        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 7.5, 15);
        glVertex3d(-40, 12.5, 15);
        glVertex3d(-40, 12.5, -15);
        glVertex3d(-40, 7.5, -15);
        glEnd();
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-39.9, 7.5, -15);
        glVertex3d(-39.9, 12.5, -15);
        glVertex3d(-39.9, 12.5, 15);
        glVertex3d(-39.9, 7.5, 15);
        glEnd();

        // sub:
        //(136, 36, 57)

        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 15, 10);
        glVertex3d(-40, 15, -10);
        glVertex3d(-40, 12.5, -10);
        glVertex3d(-40, 12.5, 10);
        glEnd();
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-39.9, 12.5, 10);
        glVertex3d(-39.9, 12.5, -10);
        glVertex3d(-39.9, 15, -10);
        glVertex3d(-39.9, 15, 10);
        glEnd();

        // the back side

        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, 5);
        glVertex3d(40, 7.5, 5);
        glVertex3d(40, 7.5, 15);
        glVertex3d(40, -12.5, 15);
        glEnd();
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(39.9, -12.5, 15);
        glVertex3d(39.9, 7.5, 15);
        glVertex3d(39.9, 7.5, 5);
        glVertex3d(39.9, -12.5, 5);
        glEnd();

        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, -15);
        glVertex3d(40, 7.5, -15);
        glVertex3d(40, 7.5, -5);
        glVertex3d(40, -12.5, -5);
        glEnd();
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(39.9, -12.5, -5);
        glVertex3d(39.9, 7.5, -5);
        glVertex3d(39.9, 7.5, -15);
        glVertex3d(39.9, -12.5, -15);
        glEnd();

        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 7.5, -15);
        glVertex3d(40, 12.5, -15);
        glVertex3d(40, 12.5, 15);
        glVertex3d(40, 7.5, 15);
        glEnd();
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(39.9, 7.5, 15);
        glVertex3d(39.9, 12.5, 15);
        glVertex3d(39.9, 12.5, -15);
        glVertex3d(39.9, 7.5, -15);
        glEnd();

        // sub:
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 12.5, 10);
        glVertex3d(40, 12.5, -10);
        glVertex3d(40, 15, -10);
        glVertex3d(40, 15, 10);
        glEnd();
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(39.9, 15, 10);
        glVertex3d(39.9, 15, -10);
        glVertex3d(39.9, 12.5, -10);
        glVertex3d(39.9, 12.5, 10);
        glEnd();

        // the first side
        //(36, 57, 230);

        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, -15);
        glVertex3d(-40, -2.5, -15);
        glVertex3d(40, -2.5, -15);
        glVertex3d(40, -12.5, -15);
        glEnd();
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, -14.9);
        glVertex3d(40, -2.5, -14.9);
        glVertex3d(-40, -2.5, -14.9);
        glVertex3d(-40, -12.5, -14.9);
        glEnd();

        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 7.5, -15);
        glVertex3d(-40, 12.5, -15);
        glVertex3d(40, 12.5, -15);
        glVertex3d(40, 7.5, -15);
        glEnd();
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, 7.5, -14.9);
        glVertex3d(40, 12.5, -14.9);
        glVertex3d(-40, 12.5, -14.9);
        glVertex3d(-40, 7.5, -14.9);
        glEnd();

        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(37.5, -2.5, -15);
        glVertex3d(37.5, 7.5, -15);
        glVertex3d(40, 7.5, -15);
        glVertex3d(40, -2.5, -15);
        glEnd();
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -2.5, -14.9);
        glVertex3d(40, 7.5, -14.9);
        glVertex3d(37.5, 7.5, -14.9);
        glVertex3d(37.5, -2.5, -14.9);
        glEnd();

        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 7.5, -15);
        glVertex3d(-37.5, 7.5, -15);
        glVertex3d(-37.5, -2.5, -15);
        glVertex3d(-40, -2.5, -15);
        glEnd();
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -2.5, -14.9);
        glVertex3d(-37.5, -2.5, -14.9);
        glVertex3d(-37.5, 7.5, -14.9);
        glVertex3d(-40, 7.5, -14.9);
        glEnd();

        // the second side
        //(36, 230, 57);

        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, 15);
        glVertex3d(40, -2.5, 15);
        glVertex3d(-40, -2.5, 15);
        glVertex3d(-40, -12.5, 15);
        glEnd();
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, 14.9);
        glVertex3d(-40, -2.5, 14.9);
        glVertex3d(40, -2.5, 14.9);
        glVertex3d(40, -12.5, 14.9);
        glEnd();

        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, 7.5, 15);
        glVertex3d(40, 12.5, 15);
        glVertex3d(-40, 12.5, 15);
        glVertex3d(-40, 7.5, 15);
        glEnd();
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 7.5, 14.9);
        glVertex3d(-40, 12.5, 14.9);
        glVertex3d(40, 12.5, 14.9);
        glVertex3d(40, 7.5, 14.9);
        glEnd();

        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -2.5, 15);
        glVertex3d(40, 7.5, 15);
        glVertex3d(37.5, 7.5, 15);
        glVertex3d(37.5, -2.5, 15);
        glEnd();
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(37.5, -2.5, 14.9);
        glVertex3d(37.5, 7.5, 14.9);
        glVertex3d(40, 7.5, 14.9);
        glVertex3d(40, -2.5, 14.9);
        glEnd();

        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -2.5, 15);
        glVertex3d(-37.5, -2.5, 15);
        glVertex3d(-37.5, 7.5, 15);
        glVertex3d(-40, 7.5, 15);
        glEnd();
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 7.5, 14.9);
        glVertex3d(-37.5, 7.5, 14.9);
        glVertex3d(-37.5, -2.5, 14.9);
        glVertex3d(-40, -2.5, 14.9);
        glEnd();

        /*
            Bottom truck box
        */
        //(250, 25, 57);
        glNormal3d(0, 1, 0);
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, 15);
        glVertex3d(40, -12.5, -15);
        glVertex3d(-40, -12.5, -15);
        glVertex3d(-40, -12.5, 15);
        glEnd();
        glNormal3d(0, 1, 0);
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, -15, 15);
        glVertex3d(40, -15, -15);
        glVertex3d(-40, -15, -15);
        glVertex3d(-40, -15, 15);
        glEnd();

        //(145, 130, 230);
        glNormal3d(0, 0, 1);
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, -15);
        glVertex3d(40, -15, -15);
        glVertex3d(-40, -15, -15);
        glVertex3d(-40, -12.5, -15);
        glEnd();
        glNormal3d(0, 0, 1);
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, 15);
        glVertex3d(40, -15, 15);
        glVertex3d(-40, -15, 15);
        glVertex3d(-40, -12.5, 15);
        glEnd();
        //(255, 255, 230);

        // right box دعاسة
        glNormal3d(0, 1, 0);
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(45, -12.5, 17.5);
        glVertex3d(45, -12.5, -17.5);
        glVertex3d(40, -12.5, -17.5);
        glVertex3d(40, -12.5, 17.5);
        glEnd();
        glNormal3d(0, 1, 0);
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(45, -15, 17.5);
        glVertex3d(45, -15, -17.5);
        glVertex3d(40, -15, -17.5);
        glVertex3d(40, -15, 17.5);
        glEnd();
        glNormal3d(1, 0, 0);
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(45, -12.5, 17.5);
        glVertex3d(45, -15, 17.5);
        glVertex3d(45, -15, -17.5);
        glVertex3d(45, -12.5, -17.5);
        glEnd();
        glNormal3d(1, 0, 0);
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, 17.5);
        glVertex3d(40, -15, 17.5);
        glVertex3d(40, -15, -17.5);
        glVertex3d(40, -12.5, -17.5);
        glEnd();
        //(250, 134, 123);
        glNormal3d(0, 0, 1);
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -15, 17.5);
        glVertex3d(40, -12.5, 17.5);
        glVertex3d(45, -12.5, 17.5);
        glVertex3d(45, -15, 17.5);
        glEnd();
        glNormal3d(0, 0, 1);
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -15, -17.5);
        glVertex3d(40, -12.5, -17.5);
        glVertex3d(45, -12.5, -17.5);
        glVertex3d(45, -15, -17.5);
        glEnd();

        // left
        glNormal3d(0, 1, 0);
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-45, -12.5, 17.5);
        glVertex3d(-45, -12.5, -17.5);
        glVertex3d(-40, -12.5, -17.5);
        glVertex3d(-40, -12.5, 17.5);
        glEnd();
        glNormal3d(0, 1, 0);
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-45, -15, 17.5);
        glVertex3d(-45, -15, -17.5);
        glVertex3d(-40, -15, -17.5);
        glVertex3d(-40, -15, 17.5);
        glEnd();
        glNormal3d(1, 0, 0);
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-45, -12.5, 17.5);
        glVertex3d(-45, -15, 17.5);
        glVertex3d(-45, -15, -17.5);
        glVertex3d(-45, -12.5, -17.5);
        glEnd();
        glNormal3d(1, 0, 0);
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, 17.5);
        glVertex3d(-40, -15, 17.5);
        glVertex3d(-40, -15, -17.5);
        glVertex3d(-40, -12.5, -17.5);
        glEnd();
        //(250, 134, 123);
        glNormal3d(0, 0, 1);
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -15, 17.5);
        glVertex3d(-40, -12.5, 17.5);
        glVertex3d(-45, -12.5, 17.5);
        glVertex3d(-45, -15, 17.5);
        glEnd();
        glNormal3d(0, 0, 1);
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -15, -17.5);
        glVertex3d(-40, -12.5, -17.5);
        glVertex3d(-45, -12.5, -17.5);
        glVertex3d(-45, -15, -17.5);
        glEnd();

        // Bottom box of the truck تبع الدوليب
        //(100, 100, 100);
        glNormal3d(1, 0, 0);
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(35, -15, -13);
        glVertex3d(35, -18, -13);
        glVertex3d(35, -18, 13);
        glVertex3d(35, -15, 13);
        glEnd();
        glNormal3d(1, 0, 0);
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-35, -15, -13);
        glVertex3d(-35, -18, -13);
        glVertex3d(-35, -18, 13);
        glVertex3d(-35, -15, 13);
        glEnd();
        glNormal3d(0, 0, 1);
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(35, -15, -13);
        glVertex3d(35, -18, -13);
        glVertex3d(-35, -18, -13);
        glVertex3d(-35, -15, -13);
        glEnd();
        glNormal3d(0, 0, 1);
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(35, -15, 13);
        glVertex3d(35, -18, 13);
        glVertex3d(-35, -18, 13);
        glVertex3d(-35, -15, 13);
        glEnd();

        // the wheel number 1:
        glBegin(GL_POLYGON);
        for (double a = 0; a <= 2 * (3.15); a += 0.1)
        {
            double x = 4 * cos(a) + 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, 12.9);
        }
        glEnd();
        // the wheel number 2:
        glBegin(GL_POLYGON);
        for (double a = 0; a <= 2 * (3.15); a += 0.1)
        {
            double x = 4 * cos(a) - 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, 12.9);
        }
        glEnd();
        // the wheel number 3:
        glBegin(GL_POLYGON);
        for (double a = 0; a <= 2 * (3.15); a += 0.1)
        {
            double x = 4 * cos(a) + 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, -12.9);
        }
        glEnd();
        // the wheel number 4:
        glBegin(GL_POLYGON);
        for (double a = 0; a <= 2 * (3.15); a += 0.1)
        {
            double x = 4 * cos(a) - 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, -12.9);
        }
        glEnd();
        glEndList();
    }
    void Draw()
    {
        glCallList(list);
    }
};

namespace Game
{
    extern int windowWidth, windowHeight;
    // Mouse mover
    extern Helper helper;

    // Trolley train[1];
    extern Model lamp;
    extern Truck t1;

    // Matrices
    extern Matrix4<float> cameraProjectionMatrix, cameraViewMatrix;

    // Camera & light positions
    extern Vec3<float> cameraPosition;
    extern Vec3<float> lightPosition;
    extern Vec4<float> lightPosition2;

    extern void InitObjects();

    extern bool InitRendering();

    extern void RedrawScene();

    extern void Display();

    extern void MouseClick(int button, int state, int x, int y);

    extern void MouseDrag(int x, int y);

    extern void ResizeWindow(int w, int h);

    extern void Keypressed(unsigned char key, int x, int y);
};
