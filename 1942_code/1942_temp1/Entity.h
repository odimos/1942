#pragma once
enum Entity_state {
	ALIVE, DYING, DEAD
};

class Entity
{
protected :
	float posx=0, posy=0;
	float sizex=0, sizey=0;
	bool collidable=false; //true if the entity should collide with other entities

public:
	virtual void draw() = 0;
	virtual void update() = 0;

};

