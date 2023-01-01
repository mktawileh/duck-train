#pragma once

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include "GL/freeglut.h"
#include "utils/Helper.h"
#include "utils/MathAux.h"
#include "utils/Primitives.h"
#include <Texture.h>
#include "Model.h"
#include "Skybox.h"
#include "solids/Trolley.h"
#include "solids/Door.h"
#include "solids/Window.h"

namespace Game
{
    extern int windowWidth, windowHeight;
    // Mouse mover
    extern Helper helper;

    // Trolley train[1];
    extern Model lamp;
    extern Trolley t1;

    // Matrices
    extern Matrix4<float> cameraProjectionMatrix, cameraViewMatrix;
    extern Matrix4<float> lightProjectionMatrix, lightViewMatrix;

    // Camera & light positions
    extern Vec3<float> cameraPosition;
    extern Vec3<float> lookingAt;
    extern Vec3<float> lightPosition;
    extern Vec4<float> lightPosition2;

    extern void InitObjects();

    // extern bool InitRendering();

    extern void RedrawScene();

    // extern void Display();

    extern void Mouse(int button, int state, int x, int y);

    extern void MouseScroll(int button, int state, int x, int y);

    extern void MouseDrag(int x, int y);

    extern void ResizeWindow(int w, int h);

    extern void Keypressed(unsigned char key, int x, int y);
};
