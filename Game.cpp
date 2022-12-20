#include "Game.h"

namespace Game
{
    int windowWidth, windowHeight;
    // Mouse mover
    Helper helper;

    // Trolley train[1];
    Model lamp;
    Truck t1;

    // Matrices
    Matrix4<float> cameraProjectionMatrix, cameraViewMatrix;

    // Camera & light positions
    Vec3<float> cameraPosition(9.0f, 3.0f, -9.0f);
    Vec3<float> lightPosition(0.0f, 1.0f, -5.5f);
    Vec4<float> lightPosition2(0.0f, 6.0f, 0.0f, 1.0f);

    void InitObjects()
    {
        t1.Init();
        lamp.Load("models/lamp.obj");
    }

    bool InitRendering()
    {
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT1);
        glEnable(GL_LIGHT2);

        // Depth states
        glClearDepth(1.0f);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_NORMALIZE);

        // Calculate & save matrices

        // Projection Matricx
        glViewport(0, 0, windowWidth, windowHeight);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0f, (float)windowWidth / windowHeight, 1.0f, 100.0f);

        // Model-view Matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glPushMatrix();
        gluLookAt(cameraPosition.x, cameraPosition.y, cameraPosition.z,
                  0.0f, 0.0f, 0.0f,
                  0.0f, 1.0f, 0.0f);
        glGetFloatv(GL_MODELVIEW_MATRIX, cameraViewMatrix);
        glPopMatrix();

        InitObjects();

        return true;
    }

    void RedrawScene()
    {
        glPushMatrix();
        helper.LoadModelViewMatrix();

        glTranslated(0, -3, 0);
        lamp.Draw();
        glPopMatrix();
    }

    void Display()
    {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glLoadMatrixf(cameraViewMatrix);

        glLightfv(GL_LIGHT1, GL_POSITION, Vec4<float>(lightPosition));
        // glLightfv(GL_LIGHT1, GL_AMBIENT, Vec3<float>(0.2));
        glLightfv(GL_LIGHT1, GL_DIFFUSE, Vec3<float>(1));
        glLightfv(GL_LIGHT1, GL_SPECULAR, Vec3<float>(0.8));

        // GLfloat light1_ambient[] = { 1.0, 0.85, 0.09, 0.2 };
        GLfloat light1_diffuse[] = {1.0, 0.85, 0.09, 1.0};
        GLfloat light1_specular[] = {1.0, 0.95, 0.39, 1.0};
        GLfloat spot_direction[] = {0.0, -1.0, 0.0};

        // glLightfv(GL_LIGHT2, GL_AMBIENT, light1_ambient);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, light1_diffuse);
        glLightfv(GL_LIGHT2, GL_SPECULAR, light1_specular);
        glLightfv(GL_LIGHT2, GL_POSITION, lightPosition2);
        glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.1);
        glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.05);
        glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.01);

        glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 70.0f);
        glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
        // glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 2.0);

        RedrawScene();

        glutSwapBuffers();

        glutPostRedisplay();
    }

    void MouseClick(int button, int state, int x, int y)
    {
        helper.UpdateMouseClick(button, state, x, y);
    }

    void MouseDrag(int x, int y)
    {
        helper.UpdateMouseDrag(x, y);
    }

    void ResizeWindow(int w, int h)
    {
        windowWidth = w, windowHeight = h;
        helper.UpdateWindowSize(w, h);
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, (double)w / (double)h, 1.0f, 100.0f);
    }

    void Keypressed(unsigned char key, int x, int y)
    {
        switch (key)
        {
        case 27:
            exit(0);
            break;
        }
    }

};