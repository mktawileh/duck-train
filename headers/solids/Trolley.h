#pragma once

class Trolley : Drawable
{

    GLuint list;

public:
    void Init()
    {
        list = glGenLists(1);
        glNewList(list, GL_COMPILE);

        // glDisable(GL_LIGHTING);

        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // Ceiling right up
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 12.5, -15);
        glVertex3d(-40, 12.5, -10);
        glVertex3d(40, 12.5, -10);
        glVertex3d(40, 12.5, -15);
        glEnd();

        // Celing right down
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 12.499, -15);
        glVertex3d(40, 12.499, -10);
        glVertex3d(-40, 12.499, -10);
        glVertex3d(-40, 12.499, -15);
        glEnd();

        // Ceiling left up
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 12.5, 15);
        glVertex3d(40, 12.5, 10);
        glVertex3d(-40, 12.5, 10);
        glVertex3d(-40, 12.5, 15);
        glEnd();
        // Ceiling left down
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 12.499, 15);
        glVertex3d(-40, 12.499, 10);
        glVertex3d(40, 12.499, 10);
        glVertex3d(40, 12.499, 15);
        glEnd();

        // Ceiling side left out
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 12.5, 10);
        glVertex3d(40, 15, 10);
        glVertex3d(-40, 15, 10);
        glVertex3d(-40, 12.5, 10);
        glEnd();

        // Ceiling side left in
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 12.5, 9.999);
        glVertex3d(-40, 15, 9.999);
        glVertex3d(40, 15, 9.999);
        glVertex3d(40, 12.5, 9.999);
        glEnd();

        // Ceiling side right out
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 12.5, -10);
        glVertex3d(-40, 15, -10);
        glVertex3d(40, 15, -10);
        glVertex3d(40, 12.5, -10);
        glEnd();

        // Ceiling side right in
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, 12.5, -9.999);
        glVertex3d(40, 15, -9.999);
        glVertex3d(-40, 15, -9.999);
        glVertex3d(-40, 12.5, -9.999);
        glEnd();

        // Celing center out
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 15, 10);
        glVertex3d(40, 15, -10);
        glVertex3d(-40, 15, -10);
        glVertex3d(-40, 15, 10);
        glEnd();

        // Celing center in
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 14.999, 10);
        glVertex3d(-40, 14.999, -10);
        glVertex3d(40, 14.999, -10);
        glVertex3d(40, 14.999, 10);
        glEnd();

        // Front side door left out
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, 15);
        glVertex3d(-40, 7.5, 15);
        glVertex3d(-40, 7.5, 5);
        glVertex3d(-40, -12.5, 5);
        glEnd();

        // Front side door left in
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-39.999, -12.5, 5);
        glVertex3d(-39.999, 7.5, 5);
        glVertex3d(-39.999, 7.5, 15);
        glVertex3d(-39.999, -12.5, 15);
        glEnd();

        // Front side door right out
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, -5);
        glVertex3d(-40, 7.5, -5);
        glVertex3d(-40, 7.5, -15);
        glVertex3d(-40, -12.5, -15);
        glEnd();

        // Front side door right in
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-39.999, -12.5, -15);
        glVertex3d(-39.999, 7.5, -15);
        glVertex3d(-39.999, 7.5, -5);
        glVertex3d(-39.999, -12.5, -5);
        glEnd();

        // Front up door out
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 7.5, 15);
        glVertex3d(-40, 12.5, 15);
        glVertex3d(-40, 12.5, -15);
        glVertex3d(-40, 7.5, -15);
        glEnd();

        // Front up door in
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-39.999, 7.5, -15);
        glVertex3d(-39.999, 12.5, -15);
        glVertex3d(-39.999, 12.5, 15);
        glVertex3d(-39.999, 7.5, 15);
        glEnd();

        // Celing front side out
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 15, 10);
        glVertex3d(-40, 15, -10);
        glVertex3d(-40, 12.5, -10);
        glVertex3d(-40, 12.5, 10);
        glEnd();

        // Celing front side in
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-39.999, 12.5, 10);
        glVertex3d(-39.999, 12.5, -10);
        glVertex3d(-39.999, 15, -10);
        glVertex3d(-39.999, 15, 10);
        glEnd();

        // Back door side left out
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, 5);
        glVertex3d(40, 7.5, 5);
        glVertex3d(40, 7.5, 15);
        glVertex3d(40, -12.5, 15);
        glEnd();

        // Back door side left in
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(39.999, -12.5, 15);
        glVertex3d(39.999, 7.5, 15);
        glVertex3d(39.999, 7.5, 5);
        glVertex3d(39.999, -12.5, 5);
        glEnd();

        // Back door side right out

        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, -15);
        glVertex3d(40, 7.5, -15);
        glVertex3d(40, 7.5, -5);
        glVertex3d(40, -12.5, -5);
        glEnd();

        // Back door side right in
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(39.999, -12.5, -5);
        glVertex3d(39.999, 7.5, -5);
        glVertex3d(39.999, 7.5, -15);
        glVertex3d(39.999, -12.5, -15);
        glEnd();

        // Back up door out

        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 7.5, -15);
        glVertex3d(40, 12.5, -15);
        glVertex3d(40, 12.5, 15);
        glVertex3d(40, 7.5, 15);
        glEnd();

        // Back up door in
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(39.999, 7.5, 15);
        glVertex3d(39.999, 12.5, 15);
        glVertex3d(39.999, 12.5, -15);
        glVertex3d(39.999, 7.5, -15);
        glEnd();

        // Celing back side out
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 12.5, 10);
        glVertex3d(40, 12.5, -10);
        glVertex3d(40, 15, -10);
        glVertex3d(40, 15, 10);
        glEnd();

        // Celing back side in
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(39.999, 15, 10);
        glVertex3d(39.999, 15, -10);
        glVertex3d(39.999, 12.5, -10);
        glVertex3d(39.999, 12.5, 10);
        glEnd();

        // Right window side bottom out
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, -15);
        glVertex3d(-40, -2.5, -15);
        glVertex3d(40, -2.5, -15);
        glVertex3d(40, -12.5, -15);
        glEnd();

        // Right window side bottom in
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, -14.999);
        glVertex3d(40, -2.5, -14.999);
        glVertex3d(-40, -2.5, -14.999);
        glVertex3d(-40, -12.5, -14.999);
        glEnd();

        // Right window side up out
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 7.5, -15);
        glVertex3d(-40, 12.5, -15);
        glVertex3d(40, 12.5, -15);
        glVertex3d(40, 7.5, -15);
        glEnd();

        // Right window side up in
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, 7.5, -14.999);
        glVertex3d(40, 12.5, -14.999);
        glVertex3d(-40, 12.5, -14.999);
        glVertex3d(-40, 7.5, -14.999);
        glEnd();

        // Right window side back up
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(37.5, -2.5, -15);
        glVertex3d(37.5, 7.5, -15);
        glVertex3d(40, 7.5, -15);
        glVertex3d(40, -2.5, -15);
        glEnd();

        // Right window side back in
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -2.5, -14.999);
        glVertex3d(40, 7.5, -14.999);
        glVertex3d(37.5, 7.5, -14.999);
        glVertex3d(37.5, -2.5, -14.999);
        glEnd();

        // Right window side front out
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 7.5, -15);
        glVertex3d(-37.5, 7.5, -15);
        glVertex3d(-37.5, -2.5, -15);
        glVertex3d(-40, -2.5, -15);
        glEnd();
        // Right window side font in
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -2.5, -14.999);
        glVertex3d(-37.5, -2.5, -14.999);
        glVertex3d(-37.5, 7.5, -14.999);
        glVertex3d(-40, 7.5, -14.999);
        glEnd();

        // Left window side bottom out
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, 15);
        glVertex3d(40, -2.5, 15);
        glVertex3d(-40, -2.5, 15);
        glVertex3d(-40, -12.5, 15);
        glEnd();
        // Left window side bottom in
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, 14.999);
        glVertex3d(-40, -2.5, 14.999);
        glVertex3d(40, -2.5, 14.999);
        glVertex3d(40, -12.5, 14.999);
        glEnd();

        // Left window side up out
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, 7.5, 15);
        glVertex3d(40, 12.5, 15);
        glVertex3d(-40, 12.5, 15);
        glVertex3d(-40, 7.5, 15);
        glEnd();
        // Left window side up in
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 7.5, 14.999);
        glVertex3d(-40, 12.5, 14.999);
        glVertex3d(40, 12.5, 14.999);
        glVertex3d(40, 7.5, 14.999);
        glEnd();

        // Left window side back out
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -2.5, 15);
        glVertex3d(40, 7.5, 15);
        glVertex3d(37.5, 7.5, 15);
        glVertex3d(37.5, -2.5, 15);
        glEnd();
        // Left widnow side back in
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(37.5, -2.5, 14.999);
        glVertex3d(37.5, 7.5, 14.999);
        glVertex3d(40, 7.5, 14.999);
        glVertex3d(40, -2.5, 14.999);
        glEnd();

        // Left window side front out
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -2.5, 15);
        glVertex3d(-37.5, -2.5, 15);
        glVertex3d(-37.5, 7.5, 15);
        glVertex3d(-40, 7.5, 15);
        glEnd();

        // Left window side front in
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 7.5, 14.999);
        glVertex3d(-37.5, 7.5, 14.999);
        glVertex3d(-37.5, -2.5, 14.999);
        glVertex3d(-40, -2.5, 14.999);
        glEnd();

        // Floor up
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -15, 15);
        glVertex3d(-40, -15, -15);
        glVertex3d(40, -15, -15);
        glVertex3d(40, -15, 15);
        glEnd();

        // Floor bottom
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, 15);
        glVertex3d(40, -12.5, -15);
        glVertex3d(-40, -12.5, -15);
        glVertex3d(-40, -12.5, 15);
        glEnd();

        // Floor right side
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, -15);
        glVertex3d(40, -15, -15);
        glVertex3d(-40, -15, -15);
        glVertex3d(-40, -12.5, -15);
        glEnd();
        // Floor left side
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, 15);
        glVertex3d(-40, -15, 15);
        glVertex3d(40, -15, 15);
        glVertex3d(40, -12.5, 15);
        glEnd();

        // Back step up
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(45, -12.5, 17.5);
        glVertex3d(45, -12.5, -17.5);
        glVertex3d(40, -12.5, -17.5);
        glVertex3d(40, -12.5, 17.5);
        glEnd();
        // Back step down
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, -15, 17.5);
        glVertex3d(40, -15, -17.5);
        glVertex3d(45, -15, -17.5);
        glVertex3d(45, -15, 17.5);
        glEnd();

        // Step back front side
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(45, -12.5, 17.5);
        glVertex3d(45, -15, 17.5);
        glVertex3d(45, -15, -17.5);
        glVertex3d(45, -12.5, -17.5);
        glEnd();

        // Step back back side
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, -17.5);
        glVertex3d(40, -15, -17.5);
        glVertex3d(40, -15, 17.5);
        glVertex3d(40, -12.5, 17.5);
        glEnd();

        // Step back left side
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(45, -15, 17.5);
        glVertex3d(45, -12.5, 17.5);
        glVertex3d(40, -12.5, 17.5);
        glVertex3d(40, -15, 17.5);
        glEnd();

        // Step back right side
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -15, -17.5);
        glVertex3d(40, -12.5, -17.5);
        glVertex3d(45, -12.5, -17.5);
        glVertex3d(45, -15, -17.5);
        glEnd();

        // Step front up
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, 17.5);
        glVertex3d(-40, -12.5, -17.5);
        glVertex3d(-45, -12.5, -17.5);
        glVertex3d(-45, -12.5, 17.5);
        glEnd();

        // Step front down
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-45, -15, 17.5);
        glVertex3d(-45, -15, -17.5);
        glVertex3d(-40, -15, -17.5);
        glVertex3d(-40, -15, 17.5);
        glEnd();

        // Step front front side
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-45, -12.5, -17.5);
        glVertex3d(-45, -15, -17.5);
        glVertex3d(-45, -15, 17.5);
        glVertex3d(-45, -12.5, 17.5);
        glEnd();
        // Step front back side
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, 17.5);
        glVertex3d(-40, -15, 17.5);
        glVertex3d(-40, -15, -17.5);
        glVertex3d(-40, -12.5, -17.5);
        glEnd();

        // Step front right side
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -15, 17.5);
        glVertex3d(-40, -12.5, 17.5);
        glVertex3d(-45, -12.5, 17.5);
        glVertex3d(-45, -15, 17.5);
        glEnd();
        // Step front left side
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-45, -15, -17.5);
        glVertex3d(-45, -12.5, -17.5);
        glVertex3d(-40, -12.5, -17.5);
        glVertex3d(-40, -15, -17.5);
        glEnd();

        // Bottom box back
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(35, -15, 13);
        glVertex3d(35, -18, 13);
        glVertex3d(35, -18, -13);
        glVertex3d(35, -15, -13);
        glEnd();
        // Bottom box front
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-35, -15, -13);
        glVertex3d(-35, -18, -13);
        glVertex3d(-35, -18, 13);
        glVertex3d(-35, -15, 13);
        glEnd();

        // Bottom box right
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(35, -15, -13);
        glVertex3d(35, -18, -13);
        glVertex3d(-35, -18, -13);
        glVertex3d(-35, -15, -13);
        glEnd();
        // Bottom box left
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-35, -15, 13);
        glVertex3d(-35, -18, 13);
        glVertex3d(35, -18, 13);
        glVertex3d(35, -15, 13);
        glEnd();

        // Back left wheel out
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        for (double a = 0; a <= 2 * (3.15); a += 0.5)
        {
            double x = 4 * cos(a) + 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, 12.9);
        }
        glEnd();
        // Back left wheel in
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        for (double a = 2 * (3.15); a >= 0; a -= 0.5)
        {
            double x = 4 * cos(a) + 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, 12.899);
        }
        glEnd();

        // Front left wheel out
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        for (double a = 0; a <= 2 * (3.15); a += 0.5)
        {
            double x = 4 * cos(a) - 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, 12.9);
        }
        glEnd();

        // Front left wheel in
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        for (double a = 2 * (3.15); a >= 0; a -= 0.5)
        {
            double x = 4 * cos(a) - 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, 12.899);
        }
        glEnd();

        // Back right wheel out
        glNormal3f(0, 0, -1);
        glBegin(GL_POLYGON);
        for (double a = 2 * (3.15); a >= 0; a -= 0.5)
        {
            double x = 4 * cos(a) + 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, -12.9);
        }
        glEnd();

        // Back right wheel in
        glNormal3f(0, 0, 1);
        glBegin(GL_POLYGON);
        for (double a = 0; a <= 2 * (3.15); a += 0.5)
        {
            double x = 4 * cos(a) + 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, -12.899);
        }
        glEnd();

        // Front right wheel out
        glNormal3f(0, 0, -1);
        glBegin(GL_POLYGON);

        for (double a = 2 * (3.15); a >= 0; a -= 0.5)
        {
            double x = 4 * cos(a) - 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, -12.9);
        }
        glEnd();

        // Front right wheel in
        glNormal3f(0, 0, 1);
        glBegin(GL_POLYGON);
        for (double a = 0; a <= 2 * (3.15); a += 0.5)
        {
            double x = 4 * cos(a) - 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, -12.899);
        }
        glEnd();

        // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        glEndList();
    }
    void Draw()
    {
        glCallList(list);
    }
};