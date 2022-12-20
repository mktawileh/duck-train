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
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {50.0};
    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
    glClearColor(0.1, 0.1, 0.1, 0.0);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    // glEnable(GL_COLOR_MATERIAL);
    // glEnable(GL_LIGHTING);   // Enable lighting
    // glEnable(GL_LIGHT0);     // Enable light #0
    // glEnable(GL_LIGHT1);     // Enable light #1
    // glEnable(GL_NORMALIZE);  // Automatically normalize normals
    test.Load("models/duck-body.obj");
    // test.PrintFaces();
}

void handleResize(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)w / (double)h, 1.0, 200.0);
    // glRotated(45, 0, 0, 1);
    // glTranslatef(0, 0, -4.0f);
}

float _angle = 1.0f;

int prevX = 0, prevY = 0;
bool isLeft = 0;
float xrot = 0, yrot = 0, zrot = 0;
float acc = 0.3;
void domagic(int x, int y)
{
    int dx = x - prevX;
    int dy = y - prevY;
    if (isLeft)
    {
        xrot = xrot + acc * dy;
        yrot = yrot + acc * dx;
    }
    else
    {
        // xrot = xrot + acc * dy;
        // zrot = zrot + acc * dx;
    }
    glutPostRedisplay();
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix

    glLoadIdentity(); // Reset The Modelview Matrix

    gluLookAt(0.0f, 0.0f, 8.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    // glRotatef(zrot, 0.0f, 0.0f, 1.0f);
    // glRotatef(_angle, 0.0f, 1.0f, 0.0f);
    // glEnable(GL_LINE_STIPPLE);
    // glEnable(GL_LINE_SMOOTH);
    // glLineStipple(1, 0xF0F0);
    // glLineWidth(2);

    // GLubyte red[] = {255, 0, 0};
    // GLubyte blue[] = {0, 0, 255};
    // GLubyte green[] = {0, 255, 0};
    glShadeModel(GL_SMOOTH);

    test.Draw();
    // glColor3ubv(blue);
    // glBegin(GL_LINES);
    // glVertex3d(0 ,-100, 0);
    // glVertex3d(0, 100, 0);
    // glEnd();

    // glColor3ubv(red);
    // glBegin(GL_LINES);
    // glVertex3d(0, 0, -100);
    // glVertex3d(0, 0, 100);
    // glEnd();

    // glColor3ubv(green);
    // glBegin(GL_LINES);
    // glVertex3d(-100, 0, 0);
    // glVertex3d(100, 0, 0);
    // glEnd();

    // glTranslatef(0.0f, 0.0f, -6.0f);
    // glPushMatrix();
    // glRotatef(_angle, 0.0f, 1.0f, 0.0f);

    // glShadeModel(GL_FLAT);
    // test.Draw();
    // glPopMatrix();
    // // Add ambient light
    // GLfloat ambientColor[] = { 0.2f, 0.2f, 0.2f, 1.0f };  // Color (0.2, 0.2, 0.2)
    // glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    // // Add positioned light
    // GLfloat lightColor0[] = { 0.5f, 0.5f, 0.5f, 1.0f };  // Color (0.5, 0.5, 0.5)
    // GLfloat lightPos0[] = { 2.0f, 0.0f, 4.0f, 1.0f };  // Positioned at (4, 0, 8)
    // glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    // glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    // // Add directed light
    // GLfloat lightColor1[] = { 0.5f, 0.2f, 0.2f, 1.0f };  // Color (0.5, 0.2, 0.2)
    // 													 // Coming from the direction (-1, 0.5, 0.5)
    // GLfloat lightPos1[] = { -1.0f, 0.5f, 0.5f, 0.0f };
    // glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    // glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

    glutSwapBuffers();
}

void drag(int x, int y)
{
    std::cout << "x = " << x << " y = " << y << '\n';
    domagic(x, y);
    prevX = x, prevY = y;
}
void click(int button, int state, int x, int y)
{
    if (!state)
    {
        prevX = x, prevY = y;
    }
    isLeft = button == 0;
    std::cout << "button: " << button << ", state: " << state << '\n';
    std::cout << "x = " << x << " y = " << y << '\n';
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
    glutMotionFunc(drag);
    glutMouseFunc(click);

    glutTimerFunc(25, update, 0); // Add a timer

    glutMainLoop();
    return 0;
}
