/*
  Author: "A duck on the truck" Team
*/
#include "include/glut.h"
#include <stdlib.h>

#include <cmath>
#include <iostream>
#include "src/Model.h"

using namespace std;

Model test;

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    test.Load("models/shape.obj");
    test.PrintFaces();
}

void handleResize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 1.0f;

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
    glLoadIdentity();           // Reset The Modelview Matrix

    glTranslatef(0.0f, 0.0f, -8.0f);
    glTranslatef(0.0f, 0.0f, 0.5f);
    glRotatef(_angle, 0.0f, 1.0f, 0.0f);

    glPolygonMode(GL_FRONT, GL_LINE);
    glPolygonMode(GL_BACK, GL_LINE);
    glShadeModel(GL_FLAT);
    test.Draw();

    glutSwapBuffers();
}

void update(int value)
{
    _angle += 1.5f;
    if (_angle > 360)
    {
        _angle -= 360;
    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char **argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);

    // Create the window
    glutCreateWindow("Holy Moly, It work :D");
    initRendering();

    // Set handler functions
    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);

    glutTimerFunc(25, update, 0); // Add a timer

    glutMainLoop();
    return 0;
}
