//
// Created by edai on 20/03/18.
//

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "GraphicalCore.hpp"
#include <glm/glm.hpp>
#include <list>
#include <array>

struct Material
{
    GLfloat mat_ambient[4];
    GLfloat mat_diffuse[4];
    GLfloat mat_specular[4];
    GLfloat shine;
};

class Engine
{
public:
    Engine();
    ~Engine();

    static void _Update()
    {
        Instance()->Update();
        GraphicalCore::UpdateGl();
    }
    static void _Reshape(int w, int h)
    {
        Instance()->Reshape(w, h);
    }
private:
    void Update();
    void Reshape(int w, int h);
    void DrawCube();
    void SetMaterial(Material *);
    void SetLight(GLenum nb, GLfloat *pos);

#pragma SINGLETON
private:
    static Engine* instance;

public:
    static Engine* Instance()
    {
        if (instance == nullptr)
        {
            instance = new Engine();
        }
        return instance;
    }

#pragma END SINGLETON
};


#endif //ENGINE_HPP
