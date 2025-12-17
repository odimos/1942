#pragma once
#include "Entity.h"
#include "Animation.h"

class Enemy :
    public Entity
{
   
    //already has posx,posy,sizex,sizey, collidable from entity | values are given at constructor

    float speedx, speedy; //values are given at constructor
    
   
    class Game* game = nullptr;

    Animation * destr_animation = nullptr;

public:
    
    Entity_state state = ALIVE;
    void shot();
    class Disk getCollArea(); //get collision area
    void update() override;
    void draw() override;
    Enemy(class Game* mygame);
};

