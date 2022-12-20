#include "Main.h"
#include "Game.h"

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Holy Moly it work!");

    // Game::InitMembers();
    if (!Game::InitRendering())
    {
        return 0;
    }

    glutDisplayFunc(Game::Display);
    glutReshapeFunc(Game::ResizeWindow);
    glutKeyboardFunc(Game::Keypressed);
    glutMotionFunc(Game::MouseDrag);
    glutMouseFunc(Game::MouseClick);

    glutMainLoop();

    return 0;
}