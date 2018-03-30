//
// Created by edai on 20/03/18.
//

#include <Engine.hpp>

GraphicalCore* GraphicalCore::instance = nullptr;
float GraphicalCore::rotationX = 0.0f;
float GraphicalCore::rotationY = 0.0f;

void GraphicalCore::Init()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
}

bool GraphicalCore::Run(int ac, char **av, Options *options)
{
    glutInit(&ac, av);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH) ;
    glutInitWindowPosition(0,0);
    glutInitWindowSize(options->width, options->height);
    glutCreateWindow(options->window_name.c_str());
    Init();
    glutIdleFunc(Engine::_Update);
    glutKeyboardFunc(GraphicalCore::_KeyboardHandle);
    glutMainLoop();
    return (true);
}

void GraphicalCore::UpdateGl()
{
    glutSwapBuffers();
    glutPostRedisplay();
}

void GraphicalCore::KeyboardHandle(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
            glutLeaveMainLoop();
            break;
        case '1':
            if (glIsEnabled(GL_LIGHT0))
            {
                std::cout << "Light 1 disabled." << std::endl;
                glDisable(GL_LIGHT0);
            }
            else
            {
                std::cout << "Light 1 enabled." << std::endl;
                glEnable(GL_LIGHT0);
            }
            break;
        default:
            return;
    }
}


GraphicalCore::GraphicalCore() = default;

GraphicalCore::~GraphicalCore() = default;