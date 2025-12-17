#pragma once
#include "Entity.h"
class Bullet :
    public Entity
{
    //already has posx,posy,sizex,sizey, collidable from entity | values are given at constructor

    float speedx, speedy; //values are given at constructor
    bool active = true; //check if out of boundaries or dead etc
    bool isEnemy=true;

public:
    bool is_Enemy() {return isEnemy;}
    class Disk getCollArea(); //get collision area
    bool isActive();
    void update() override;
    void draw() override;
    Bullet(float x, float y, float speed_x, float speed_y, bool is_enemy);
};

