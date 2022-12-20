#pragma once

#include <vector>
#include "glut.h"

#include "Primitives.h"

class Trolley {

    private: 
        GLuint list;
        std::vector<Vec3<GLfloat>> vertices = {
            {-1.0, 1.0, 1.0},
            {-1.0, -1.0, 1.0},
            {1.0, -1.0, 1.0},
            {1.0, 1.0, 1.0}
        };

    public: 
        Trolley() {
            std::cout << "Inited";
        }
        ~Trolley() {
            std::cout << "Deconstructed\n";
        }

    
        void init() {
            list = glGenLists(2);
            glNewList(list, GL_COMPILE);
            glBegin(GL_POLYGON);
            for (Vec3<GLfloat> &point: vertices) {
                glVertex3fv((GLfloat*)&point);
            }
            glEnd();
            glEndList();
        }

        void draw() {
            glCallList(list);
        }
};