#pragma once

class Skybox : Drawable
{
    int back, front, left, right, top, bottom;
    const float height = 30, width = 125, depth = 125;
    GLuint list;

public:
    void Init()
    {
        back = LoadTexture((char *)"skybox/back.bmp", 255);
        front = LoadTexture((char *)"skybox/front.bmp", 255);
        left = LoadTexture((char *)"skybox/left.bmp", 255);
        right = LoadTexture((char *)"skybox/right.bmp", 255);
        top = LoadTexture((char *)"skybox/top.bmp", 255);
        bottom = LoadTexture((char *)"skybox/bottom.bmp", 255);

        list = glGenLists(1);
        glNewList(list, GL_COMPILE);

        glDisable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
        glColor3d(1, 1, 1);

        glBindTexture(GL_TEXTURE_2D, front);
        glBegin(GL_QUADS);
        glTexCoord2d(0, 0);
        glVertex3d(-width / 2, -height / 2, -depth / 2);
        glTexCoord2d(1, 0);
        glVertex3d(width / 2, -height / 2, -depth / 2);
        glTexCoord2d(1, 1);
        glVertex3d(width / 2, height / 2, -depth / 2);
        glTexCoord2d(0, 1);
        glVertex3d(-width / 2, height / 2, -depth / 2);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, back);
        glBegin(GL_QUADS);
        glTexCoord2d(1, 0);
        glVertex3d(-width / 2, -height / 2, depth / 2);
        glTexCoord2d(0, 0);
        glVertex3d(width / 2, -height / 2, depth / 2);
        glTexCoord2d(0, 1);
        glVertex3d(width / 2, height / 2, depth / 2);
        glTexCoord2d(1, 1);
        glVertex3d(-width / 2, height / 2, depth / 2);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, left);
        glBegin(GL_QUADS);
        glTexCoord2d(0, 0);
        glVertex3d(-width / 2, -height / 2, depth / 2);
        glTexCoord2d(1, 0);
        glVertex3d(-width / 2, -height / 2, -depth / 2);
        glTexCoord2d(1, 1);
        glVertex3d(-width / 2, height / 2, -depth / 2);
        glTexCoord2d(0, 1);
        glVertex3d(-width / 2, height / 2, depth / 2);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, right);
        glBegin(GL_QUADS);
        glTexCoord2d(1, 0);
        glVertex3d(width / 2, -height / 2, depth / 2);
        glTexCoord2d(0, 0);
        glVertex3d(width / 2, -height / 2, -depth / 2);
        glTexCoord2d(0, 1);
        glVertex3d(width / 2, height / 2, -depth / 2);
        glTexCoord2d(1, 1);
        glVertex3d(width / 2, height / 2, depth / 2);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, top);
        glBegin(GL_QUADS);
        glTexCoord2d(0, 0);
        glVertex3d(-width / 2, height / 2, -depth / 2);
        glTexCoord2d(1, 0);
        glVertex3d(width / 2, height / 2, -depth / 2);
        glTexCoord2d(1, 1);
        glVertex3d(width / 2, height / 2, depth / 2);
        glTexCoord2d(0, 1);
        glVertex3d(-width / 2, height / 2, depth / 2);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, bottom);
        glBegin(GL_QUADS);
        glTexCoord2d(0, 0);
        glVertex3d(-width / 2, -height / 2, depth / 2);
        glTexCoord2d(1, 0);
        glVertex3d(width / 2, -height / 2, depth / 2);
        glTexCoord2d(1, 1);
        glVertex3d(width / 2, -height / 2, -depth / 2);
        glTexCoord2d(0, 1);
        glVertex3d(-width / 2, -height / 2, -depth / 2);
        glEnd();

        glDisable(GL_TEXTURE_2D);
        glEnable(GL_LIGHTING);

        glEndList();
    }

    void Draw()
    {
        glPushMatrix();
        glTranslatef(0, 12.0f, 0);
        glCallList(list);
        glPopMatrix();
    }
};
