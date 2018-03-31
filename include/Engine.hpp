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
    float mat_ambient[4];
    float mat_diffuse[4];
    float mat_specular[4];
    float shine;
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
