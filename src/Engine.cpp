//
// Created by edai on 20/03/18.
//

#include "Engine.hpp"

Engine *Engine::instance = nullptr;

Material Ruby = {
       {0.1745f, 0.01175f, 0.01175f, 0.55f},
       {0.61424f, 0.04136f, 0.04136f, 0.55f},
       {0.727811f, 0.626959f, 0.626959f, 0.55f},
       32.0f
};

Material Emerald = {
        {0.0215f, 0.1745f, 0.0215f, 0.55f},
        {0.07568f, 0.61424f, 0.07568f, 0.55f},
        {0.633f, 0.727811f, 0.633f, 0.55f},
        76.8f
};

Material Turquoise = {
        {0.1f, 0.18725f, 0.1745f, 0.8f},
        {0.396f, 0.74151f, 0.69102f, 0.8f},
        {0.297254f, 0.30829f, 0.306678f, 0.8f},
        76.8f
};

void Engine::SetLight(GLenum nb, GLfloat* pos)
{
    GLfloat light_ambient[] = {0.1, 0.1, 0.1, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(nb, GL_AMBIENT, light_ambient);
    glLightfv(nb, GL_DIFFUSE, light_diffuse);
    glLightfv(nb, GL_SPECULAR, light_specular);
    glLightfv(nb, GL_POSITION, pos);
    glEnable(nb);
}
Engine::Engine()
{
    GLfloat light1_position[] = {3.0f, 6.0f, 6.0f, 1.0f};

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    SetLight(GL_LIGHT0, GraphicalCore::light0_position);
    SetLight(GL_LIGHT1, light1_position);
    glEnable(GL_LIGHTING);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
}

Engine::~Engine() = default;

void Engine::Update()
{
    GLfloat light1_position[] = {3.0f, 6.0f, 6.0f, 1.0f};

    glLoadIdentity();
    if (glIsEnabled(GL_LIGHT0))
        SetLight(GL_LIGHT0, GraphicalCore::light0_position);
    if (glIsEnabled(GL_LIGHT1))
        SetLight(GL_LIGHT1, light1_position);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);

    glLoadIdentity();
    gluLookAt(1.0f, 2.0f, 2.5f,
              2.0f, 4.0f, 5.0f,
              0.0f, 1.0f, 0.0f);
    glTranslatef(2.0f, 4.0f, 5.0f);
    glScalef(0.8f, 0.8f, 0.8f);
    glRotatef(GraphicalCore::rotationX, 1.0f, 0.0f, 0.0f);
    GraphicalCore::rotationX += 0.05f;
    DrawCube();
    glDisable(GL_LIGHTING);
 }

void Engine::SetMaterial(Material *m)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, m->mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, m->mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, m->mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, m->shine);
}

void Engine::DrawCube()
{
    glBegin(GL_QUADS);
    SetMaterial(&Ruby);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f,-1.0f, 1.0f);
    glVertex3f(1.0f,-1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    SetMaterial(&Turquoise);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 1.0f,-1.0f);
    glVertex3f(1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);

    SetMaterial(&Ruby);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    SetMaterial(&Turquoise);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);

    SetMaterial(&Emerald);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f,-1.0f);

    glNormal3f(1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glEnd();
}

void Engine::Reshape(int w, int h)
{
    auto wf = (GLfloat)w;
    auto hf = (GLfloat)h;

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-1.5f, 1.5f, -1.5f * hf / wf,
                 1.5f * hf / wf, -10.0, 10.0);
    else
        glOrtho (-1.5f * wf / hf,
                 1.5f * wf / hf, -1.5f, 1.5f, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

