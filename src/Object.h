#pragma once

#include <vector>
#include "glut.h"

#include "Primitives.h"

class Object {

    private: 
        GLuint list;
        std::vector<Vec3<float>> vertices;
        std::vector<Vec3<float>> normals;
        std::vector<unsigned int> faces;

    public: 
        Trolley() {
            init();
        }

        void createTrolleyList() {
            
        }
        void init() {
            list = glGenLists(1);
            glNewList(list, GL_COMPILE);
            
            glEndList();
        }
};