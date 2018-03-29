//
// Created by edai on 20/03/18.
//

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "GraphicalCore.hpp"
#include <glm/glm.hpp>
#include <list>
#include <array>

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

private:
    void Update();
    void DrawCube();

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
