//
// Created by edai on 20/03/18.
//

#include <Engine.hpp>

GraphicalCore* GraphicalCore::instance = nullptr;
float GraphicalCore::rotationX = 0.0f;
GLfloat GraphicalCore::light0_position[4] = {0.0f, 0.0f, 0.0f, 1.0f};

void GraphicalCore::Init()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
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
    glutReshapeFunc(Engine::_Reshape);
    glutSpecialFunc(GraphicalCore::_SpecialKeyHandle);
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
        case '2':
            if (glIsEnabled(GL_LIGHT1))
            {
                std::cout << "Light 2 disabled." << std::endl;
                glDisable(GL_LIGHT1);
            }
            else
            {
                std::cout << "Light 2 enabled." << std::endl;
                glEnable(GL_LIGHT1);
            }
            break;

        default:
            return;
    }
}

void GraphicalCore::SpecialKeyHandle(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_UP:
            std::cout << "UP" << std::endl;
            GraphicalCore::light0_position[1] += 0.1f;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            std::cout << "GLUT_KEY_DOWN" << std::endl;
            GraphicalCore::light0_position[1] -= 0.1f;
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            std::cout << "GLUT_KEY_LEFT" << std::endl;
            GraphicalCore::light0_position[0] -= 0.1f;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            std::cout << "GLUT_KEY_RIGHT" << std::endl;
            GraphicalCore::light0_position[0] += 0.1f;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}


GraphicalCore::GraphicalCore() = default;

GraphicalCore::~GraphicalCore() = default;