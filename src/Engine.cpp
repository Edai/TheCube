//
// Created by edai on 20/03/18.
//

#include "Engine.hpp"

Engine *Engine::instance = nullptr;

static float no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};
static float mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
static float mat_ambient_color[] = {0.8f, 0.8f, 0.2f, 1.0f};
static float mat_diffuse[] = {0.1f, 0.5f, 0.8f, 1.0f};
static float mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
static float no_shininess = 0.0f;
static float low_shininess = 5.0f;
static float high_shininess = 100.0f;
static float mat_emission[] = {0.3f, 0.2f, 0.2f, 0.0f};

Engine::Engine()
{
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glClearColor (0.0, 0.0, 0.0, 0.0);
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glShadeModel (GL_SMOOTH);
}

Engine::~Engine()
{
}

void Engine::Update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);glLoadIdentity();
    glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);
    glRotatef( GraphicalCore::rotationX, 1.0, 0.0, 0.0 );
    glRotatef( GraphicalCore::rotationY, 0.0, 1.0, 0.0 );
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_ambient_color);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_ambient_color);
    glBegin(GL_POLYGON);
    glVertex3f(  0.5, -0.5, 0.5 );
    glVertex3f(  0.5,  0.5, 0.5 );
    glVertex3f( -0.5,  0.5, 0.5 );
    glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5,  0.5, -0.5 );
    glVertex3f( 0.5,  0.5,  0.5 );
    glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(  0.5,  0.5,  0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
 }