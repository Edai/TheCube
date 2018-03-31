//
// Created by edai on 20/03/18.
//

#include "Engine.hpp"

Engine *Engine::instance = nullptr;

Material Ruby = {
       {0.1745f, 0.01175f, 0.01175f, 0.55f},
       {0.61424f, 0.04136f, 0.04136f, 0.55f},
       {0.727811f, 0.626959f, 0.626959f, 0.55f},
       76.8f
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
        12.8f
};

float light_position[] = {0.50f, 1.0f, 1.0f, 1.0f};
float light1_position[] = {-1.0f, -.5f, 2.0f, 1.0f};

GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};
GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};

Engine::Engine()
{
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glEnable(GL_LIGHT1);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
}

Engine::~Engine()
{
}

void Engine::Update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    //gluLookAt(0.95f, 2.0f, 2.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,  0.0f);

    glLoadIdentity();
    glScalef(0.3f, 0.3f, 0.3f);
    glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
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
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glVertex3f( 1.0f,-1.0f, -1.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);

    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f( 1.0f, 1.0f,-1.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);

    SetMaterial(&Turquoise);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    SetMaterial(&Ruby);
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
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
                 1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    else
        glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
                 1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

