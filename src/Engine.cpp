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
    glEnable(GL_LIGHT0);
}


Engine::~Engine()
{
}


void Engine::Update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 5.0, 7.0, 5.0, 1.0 };
    GLfloat light_specular[] = { 5.0, 7.0, 5.0, 1.0 };
    GLfloat light_position[] = { 5.0, 7.0, 5.0, 0.0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    gluLookAt(0.95f, 2.0f, 2.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,  0.0f);
    glScalef(0.5f, 0.5f, 0.5f);
    glTranslatef(2.0f, 4.0f, 5.0f);
    GraphicalCore::rotationX += 0.5f;
    glRotatef(GraphicalCore::rotationX, 1.0f, 0.0f, 0.0f);
    DrawCube();
    glPopMatrix();
 }

void Engine::DrawCube()
{
    GLfloat color_up[] = {0.0, 1.0, 0.0, 1.0};
    GLfloat color_front[] = {1.0, 0.0, 0.0, 1.0};
    GLfloat color_side[] = {0.0, 0.0, 1.0, 1.0};

    glEnable (GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color_side);
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

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color_up);
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

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color_front);
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
}