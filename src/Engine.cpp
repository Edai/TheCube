//
// Created by edai on 20/03/18.
//

#include "Engine.hpp"

Engine *Engine::instance = nullptr;

Engine::Engine()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glEnable(GL_LIGHTING);
}


Engine::~Engine()
{
}


void Engine::Update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    gluLookAt(0.95f, 2.0f, 2.5f,
              0.0f, 1.0f, 0.0f,
              0.0f, 1.0f,  0.0f);
    glScalef(0.5f, 0.5f, 0.5f);
    glTranslatef(2.0f, 4.0f, 5.0f);
    GraphicalCore::rotationX += 0.5f;
    glRotatef(GraphicalCore::rotationX, 1.0f, 0.0f, 0.0f);
    DrawCube();
    glPopMatrix();
 }

void Engine::DrawCube()
{
    glEnable (GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
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