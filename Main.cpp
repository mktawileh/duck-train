#include "Renderer.h"

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Holy Moly it work!");

    if (!Renderer::Init())
    {
        return 0;
    }

    // glutFullScreen();

    // Main loop
    glutDisplayFunc(Renderer::Render);

    // Events
    glutReshapeFunc(Game::ResizeWindow);
    glutKeyboardFunc(Game::Keypressed);
    glutMotionFunc(Game::MouseDrag);
    glutMouseFunc(Game::Mouse);
    glutMouseWheelFunc(Game::MouseScroll);
   

    glutMainLoop();

    return 0;
}