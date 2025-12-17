#include "Player.h"
#include "graphics.h"
#include "config.h"
#include "Bullet.h"
#include "Util.h"
#include "Game.h" 
#include <iostream>

//get the collision area
Disk Player::getCollArea() {
	//maybe there should be a disk variable inside enemy and player
	Disk disk;
	disk.cx = posx; disk.cy = posy;
	disk.radius = sizex * (2/3.0f);
	return disk;
}

void Player::shot()
{
	game->addBullet(posx,posy,0.0f, -100.0f, false);
}


void Player::update()
{
	//User input and update position
	if (graphics::getKeyState(graphics::SCANCODE_RIGHT)) {
		posx += speedx * graphics::getDeltaTime() / 100.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_LEFT)) {
		posx -= speedx * graphics::getDeltaTime() / 100.f;

	}
	if (graphics::getKeyState(graphics::SCANCODE_UP)) {
		posy -= speedy * graphics::getDeltaTime() / 100.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_DOWN)) {
		posy += speedy * graphics::getDeltaTime() / 100.0f;
	}

	if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
		
		if (!pressed) {
			pressed = true;
			shot();
		}
		
	}
	else {
		pressed = false;
	}


	//check if out of bounds
	if (posx < 0) posx = 0;
	if (posx > CANVAS_WIDTH) posx = CANVAS_WIDTH;
	if (posy < 0) posy = 0;
	if (posy > CANVAS_HEIGHT) posy = CANVAS_HEIGHT;
}

void Player::draw()
{
	//maybe we should create one brush for player 
	//inside the contructor not one for every single draw
	graphics::Brush br;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	graphics::drawRect(posx, posy, sizex, sizey, br);

	//draw collision Area
	graphics::Brush br2;
	br2.fill_color[0] = 0.0f;
	br2.fill_color[1] = 0.5f;
	br2.fill_color[2] = 0.0f;
	br2.fill_opacity = 0.3f;
	br2.outline_width = 2;
	Disk collArea = getCollArea();
	graphics::drawDisk(collArea.cx, collArea.cy, collArea.radius, br2);
}

Player::Player( Game * mygame)
{
	game = mygame;
	posx = 100; posy = 500; sizex = 60; sizey = 60; speedx = 70; speedy = 80;
	collidable = true;
}
