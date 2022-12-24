#pragma once

class Helper
{
    int prevX = 0, prevY = 0;
    int width = 400, height = 400;

    bool isLeft = 0;
    float xrot = 0, yrot = 0, zrot = 0;
    float acc = 0.3f;
    float zoom_sense = 1.0f;

    float posx = 1, posy = 1, zoom = 0;

public:
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
        std::cout << xrot << " " << yrot << '\n';
    }

    void UpdateMouseDrag(int x, int y)
    {
        posx = 2 * (2 * (float)x / width - 1);
        posy = -2 * (2 * (float)y / height - 1);

        domagic(x, y);
        prevX = x, prevY = y;
    }

    void UpdateMouseClick(int button, int state, int x, int y)
    {
        if (!state)
        {
            prevX = x, prevY = y;
        }
        isLeft = button == 0;
    }

    void UpdateWindowSize(int w, int h) {
        width = w, height = h;
    }

    void UpdateMouseScrollUp() {
        zoom += zoom_sense;
    }

    void UpdateMouseScrollDown() {
        zoom -= zoom_sense;
    }

    float getXRotation()
    {
        return xrot;
    }
    float getYRotation()
    {
        return yrot;
    }

    void LoadModelViewMatrix()
    {
        glTranslatef(0, 0, zoom);
        glRotatef(xrot, 1, 0, 0);
        glRotatef(yrot, 0, 1, 0);
    }


};