#include "Game.h"

namespace Game
{
    int windowWidth, windowHeight;

    // Mouse mover
    Helper helper;

    // Objects
    // Model lamp;
    Trolley trolley;

    // Skybox
    Skybox world;

    // Matrices
    Matrix4<float> cameraProjectionMatrix, cameraViewMatrix;
    Matrix4<float> lightProjectionMatrix, lightViewMatrix;

    // Camera & light positions
    Vec3<float> cameraPosition(0.0f, 0.0f, 0.0f);
    Vec3<float> lookingAt(0.0f, 0.0f, -1.0f);

    Vec3<float> lightPosition(2.0f, 3.0f, -2.0f);
    Vec4<float> lightPosition2(0.0f, 6.0f, 0.0f, 1.0f);

    void InitObjects()
    {
        trolley.Init();
        world.Init();
    }

    void RedrawScene()
    {
        glPushMatrix();
        helper.LoadRotateMatrix();
        world.Draw();
        glPopMatrix();
        
        glPushMatrix();
        helper.LoadModelViewMatrix();
        glScalef(0.1, 0.1, 0.1);
        trolley.Draw();
        glPopMatrix();
    }

    void Mouse(int button, int state, int x, int y)
    {
        helper.UpdateMouseClick(button, state, x, y);
        
    }

    void MouseScroll(int button, int dir, int x, int y)
    {
        if (dir > 0)
            helper.UpdateMouseScrollUp();
        else

            helper.UpdateMouseScrollDown();

        return;
    }

    void MouseDrag(int x, int y)
    {
        helper.UpdateMouseDrag(x, y);
    }

    void ResizeWindow(int w, int h)
    {
        windowWidth = w, windowHeight = h;
        helper.UpdateWindowSize(w, h);
        // Update the camera's projection matrix
        // glPushMatrix();
        // glLoadIdentity();
        // gluPerspective(45.0f, (float)windowWidth / windowHeight, 1.0f, 500.0f);
        // glGetFloatv(GL_MODELVIEW_MATRIX, cameraProjectionMatrix);
        // glPopMatrix();
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
