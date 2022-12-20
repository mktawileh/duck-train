#pragma once

class Trolley : Drawable {

    private: 
        GLuint list;
     

    public:   
        void Init() override {
            list = glGenLists(2);
            glNewList(list, GL_COMPILE);
            glBegin(GL_POLYGON);
            
            glEnd();
            glEndList();
        }

        void Draw() override {
          
            glCallList(list);
          
        }
    
};