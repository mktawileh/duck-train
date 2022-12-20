/*
  Author: "A duck on the truck" Team
*/
#include "glut.h"
#include <stdlib.h>

#include <iostream>
#include "src/Model.h"
#include "src/Trolley.h"
#include "src/Scene.h"
#include "src/Event.h"

using namespace std;

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
    glLoadIdentity(); // Reset The Modelview Matrix
    gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    Scene::Redraw();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    // Create the window
    glutCreateWindow("Holy Moly, It work :D");
    Scene::InitRendering(); 
    Scene::InitObjects();

    glutDisplayFunc(drawScene);
    // Set handler functions
    glutReshapeFunc(Event::ResizeWindow);
    glutMouseFunc(Event::Mouse);

    glutMainLoop();
    return 0;
}
