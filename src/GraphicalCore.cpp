//
// Created by edai on 20/03/18.
//

#include <Engine.hpp>

GraphicalCore* GraphicalCore::instance = nullptr;
float GraphicalCore::rotationX = 0;
float GraphicalCore::rotationY = 0;

void GraphicalCore::Init()
{
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
}

bool GraphicalCore::Run(int ac, char **av, Options *options)
{
    glutInit(&ac, av);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH) ;
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
        case 'q' :
        case 27:
            glutLeaveMainLoop();
            break;
        case 'd':
            rotationY += 5;
            break;
        case 'a':
            rotationY -= 5;
            break;
        case 'w':
            rotationX += 5;
            break;
        case 's':
            rotationX -= 5;
            break;
        default:
            return;
    }
}


GraphicalCore::GraphicalCore() = default;

GraphicalCore::~GraphicalCore() = default;