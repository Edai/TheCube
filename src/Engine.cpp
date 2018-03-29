//
// Created by edai on 20/03/18.
//

#include "Engine.hpp"

Engine *Engine::instance = nullptr;


Engine::Engine()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = {1.0, 1.0, 0.0, 0.0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}


Engine::~Engine()
{
}


void Engine::Update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glRotatef(GraphicalCore::rotationX, 1.0, 0.0, 0.0);
    glRotatef(GraphicalCore::rotationY, 0.0, 1.0, 0.0);
    glScalef(0.5f, 0.5f, 0.5f);
    DrawCube();
 }

void Engine::DrawCube()
{
    glEnable (GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glTranslatef(2f, 4.0f, 5.0f);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f(1, -1, -1);
    glVertex3f(1,  1, -1);
    glVertex3f(-1,  1, -1);
    glVertex3f(-1, -1, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1, -1, 1);
    glVertex3f(1,  1, 1);
    glVertex3f(-1,  1, 1);
    glVertex3f(-1, -1, 1);
    glEnd();

    glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f(1, -1, -1);
    glVertex3f(1,  1, -1);
    glVertex3f(1,  1,  1);
    glVertex3f(1, -1,  1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-1, -1,  1);
    glVertex3f(-1,  1,  1);
    glVertex3f(-1,  1, -1);
    glVertex3f(-1, -1, -1);
    glEnd();

    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f(1,  1,  1);
    glVertex3f(1,  1, -1);
    glVertex3f(-1,  1, -1);
    glVertex3f(-1,  1,  1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1,  1);
    glVertex3f(-1, -1,  1);
    glVertex3f(-1, -1, -1);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
}