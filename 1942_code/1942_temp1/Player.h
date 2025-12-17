#pragma once
#include "Entity.h"

class Player :
    public Entity
{
    //already has posx,posy,sizex,sizey,collidable from entity | values are given at constructor

    float speedx, speedy; //values are given at constructor
    class Game* game = nullptr;

    bool pressed = false;

public:
    void shot();
    class Disk getCollArea(); //get collision area
    void update() override;
    void draw() override;
    Player(class Game *mygame);
};

