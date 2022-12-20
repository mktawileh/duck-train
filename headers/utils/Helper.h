#pragma once

class Helper
{
    int prevX = 0, prevY = 0;
    bool isLeft = 0;
    float xrot = 0, yrot = 0, zrot = 0;
    float acc = 0.3;
    float posx = 1, posy = 1;
    int width = 400, height = 400;

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
        glRotatef(xrot, 1, 0, 0);
        glRotatef(yrot, 0, 1, 0);
    }
};