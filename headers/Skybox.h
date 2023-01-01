class Skybox : Drawable
{
    const static int size = 2;
    int back, front, left, right, top, bottom;
    const int height = 30 * size, width = 125 * size, depth = 125 * size;
    GLuint list;

    //stars and moon variables:
    const static int nStars = 500 * size;
    Vec3<double> stars[nStars];
    const static int total = 30 * size;
    double r = 4 * size;
    Vec3<double> sphere[total + 1][total + 1];

    double mapping(double x, double oldMin, double oldMax, double newMin, double newMax)
    {
        double temp = (x - oldMin) / (oldMax - oldMin);
        return newMin + temp * (newMax - newMin);
    }
    void drawingStarsAndMoon(){
                // drawing_stars
        glColor3ub(255, 255, 255);
        glPointSize(1);
        glBegin(GL_POINTS);
        for (int i = 0; i < nStars; i++)
        {
            glVertex3d(stars[i].x, stars[i].y, stars[i].z);
        }
        glEnd();
        // drawing moon:
        glBegin(GL_TRIANGLE_STRIP);
        for (int i = 0; i < total; i++)
            for (int j = 0; j < total + 1; j++)
            {
                Vec3<double> p1 = sphere[i][j];
                Vec3<double> p2 = sphere[i + 1][j];
                glVertex3d(p1.x * r + (-width / 2 + 0.1) + (r+1), p1.y * r + (height / 2 - 0.1) - (r+1), p1.z * r + (-depth / 2 + 0.1) + (r+1));
                glVertex3d(p2.x * r + (-width / 2 + 0.1) + (r+1), p2.y * r + (height / 2 - 0.1) - (r+1), p2.z * r + (-depth / 2 + 0.1) + (r+1));
            }
        glEnd();
    }

public:
    void Init()
    {
        // moon settings:
        // Sphere settings

        for (int i = 0; i < total + 1; i++)
        {
            double lat = mapping(i, 0, total, 0, M_PI);
            for (int j = 0; j < total + 1; j++)
            {
                double lon = mapping(j, 0, total, 0, 2 * M_PI);
                sphere[i][j].x = sin(lat) * cos(lon);
                sphere[i][j].y = sin(lat) * sin(lon);
                sphere[i][j].z = cos(lat);
            }
        }

        //***********************
                // Stars settings
        for (int i = 0; i < nStars; i++)
        {
            stars[i].x = (-width / 2 + 0.1) + (((int)rand() % width) - 0.2);
            stars[i].y = height / 2 - 0.1;
            stars[i].z = (-depth / 2 + 0.1) + (((int)rand() % depth) - 0.2);
        }
        //==============================


        back = LoadTexture((char *)"skybox/back.bmp", 255);
        front = LoadTexture((char *)"skybox/front.bmp", 255);
        left = LoadTexture((char *)"skybox/left.bmp", 255);
        right = LoadTexture((char *)"skybox/right.bmp", 255);
        top = LoadTexture((char *)"skybox/top.bmp", 255);
        bottom = LoadTexture((char *)"skybox/bottom.bmp", 255);

        list = glGenLists(1);
        glNewList(list, GL_COMPILE);
        // glDisable(GL_LIGHTING);
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
        // glEnable(GL_LIGHTING);

        glEndList();
    }

    void Draw()
    {
        drawingStarsAndMoon();
        glPushMatrix();
        glCallList(list);
        glPopMatrix();
    }
};
