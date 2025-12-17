#include "Enemy.h"
#include "graphics.h"
#include "config.h"
#include "Util.h"
#include <random>
#include "Game.h" 
#include <iostream>

#include <vector>

void Enemy::shot()
{
	game->addBullet(posx, posy, 0.0f, 50.0f, true);
}


//get the collision area
Disk Enemy::getCollArea()
{
	//maybe there should be a disk variable inside enemy and player
	Disk disk;
	disk.cx = posx; disk.cy = posy;
	disk.radius = sizex * (2 / 3.0f);
	return disk;

}

void Enemy::update()
{

	posx += speedx * graphics::getDeltaTime() / 100.0f;
	posy += speedy * graphics::getDeltaTime() / 100.0f;

	if (state == ALIVE) {
		if ((rand() * 1.0f / RAND_MAX) > 0.99f) {

			shot();
		}
		//update position

		//check if out of boundaries
		if (posx < 0 - sizex || posx > CANVAS_WIDTH + sizex / 2) {
			state = DEAD;
		}
		if (posy < 0 - sizey || posy > CANVAS_HEIGHT + sizey / 2) {
			state = DEAD;
		}
	}
	else if (state == DYING) {
		destr_animation->update();
		if (destr_animation->isEnd()) {
			state = DEAD;
		}
	}
}

void Enemy::draw()
{

	if (state == ALIVE) {
		//maybe we should create one brush for player 
		//inside the contructor not one for every single draw
		graphics::Brush br;
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 1.0f;
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
	else if (state == DYING) {
		destr_animation->draw(posx, posy); // to tsirtsirisma feugei mono afou exoun emfanistei mia fora sinolika, 
											// opote isws prp sthn arxh na ta emfanizoume kapou
	}	
}

Enemy::Enemy(Game* mygame){
	game = mygame;
	posx = (rand() * 1.0f / RAND_MAX)* CANVAS_WIDTH;
	posy = 0;// (rand() * 1.0f / RAND_MAX)* CANVAS_HEIGHT;
	sizex = 60; 
	sizey = sizex; 
	speedx = 10; speedy = 5;
	collidable = true;

	//enemies dying animation
	int duration = 50;
	std::vector<Frame> animation;
	animation.push_back(*new Frame("destr1.png", 50, 50, duration));
	animation.push_back(*new Frame("destr2.png", 50, 50, duration));
	animation.push_back(*new Frame("destr3.png", 50, 50, duration));
	animation.push_back(*new Frame("destr4.png", 50, 50, duration));
	animation.push_back(*new Frame("destr5.png", 50, 50, duration));
	animation.push_back(*new Frame("destr6.png", 50, 50, duration));
	destr_animation = new Animation(animation);
	
}
