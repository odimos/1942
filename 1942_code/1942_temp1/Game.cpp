#include "Game.h"
#include "Enemy.h"
#include "Util.h"
#include "config.h"
#include "Player.h"
#include "Bullet.h"
#include "graphics.h"
#include <iostream>

bool Game::checkCollisionA(class Bullet& bullet, class Enemy& enemy) {
	if (enemy.state == DEAD || !bullet.isActive()) {
		return false;
	}

	if (bullet.is_Enemy()) {
		return false;
	}

	Disk d1 = bullet.getCollArea();
	Disk d2 = enemy.getCollArea();

	return sqrt((d1.cx - d2.cx) * (d1.cx - d2.cx) +
		(d1.cy - d2.cy) * (d1.cy - d2.cy)) < d1.radius + d2.radius;
}



bool Game::checkCollisionWithPlayer(Enemy &enemy)
{
	if (!enemy.state == DEAD)return false;

	//check if not collidable when more objects

	Disk d1 = player->getCollArea();
	Disk d2 = enemy.getCollArea();

	return sqrt((d1.cx - d2.cx)* (d1.cx - d2.cx) + 
			(d1.cy - d2.cy)* (d1.cy - d2.cy)) < d1.radius + d2.radius;

}

void Game::addBullet(float x, float y, float speed_x, float speed_y, bool is_enemy)
{
	bullets.push_back(*(new Bullet(x,y,speed_x, speed_y,is_enemy)));
}

//sks diumo ksana vol.2
void Game::update()
{	

	if(player) player->update();
	if (enemies.size() == 0) {

		enemies.push_back(*(new Enemy(this)));
		enemies.push_back(*(new Enemy(this)));
	}


	//collisions checker - handler

	//Enemies collision With player and boundaries
	for (std::vector<Enemy>::iterator it = enemies.begin(); it != enemies.end();) {
		(*it).update();
		if ((*it).state == DEAD) {
			//delete is there need for deleting?
			it = enemies.erase(it);
		}else {
			if (checkCollisionWithPlayer(*it)) {
				(*it).state =DYING;
			}

			++it;
		}
		
	}

	//bullets boundaries
	for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end();) {
		(*it).update();

		if (!(*it).isActive()) {
			//delete is there need for deleting?
			it = bullets.erase(it);

		}
		else {
			++it;
		}
	}

	
	bool plus = true;
	//bullets collision with enemies, every bullet with every enemy
	for (std::vector<Bullet>::iterator it_b = bullets.begin(); it_b != bullets.end();) {

		for (std::vector<Enemy>::iterator it_e = enemies.begin(); it_e != enemies.end();) {
			if (checkCollisionA((*it_b), (*it_e) ) ) {
				(*it_e).state = DYING; //it_e = enemies.erase(it_e); 
				++it_e; //probably there is a much beter implementation
				it_b = bullets.erase(it_b);
				plus = false;
				break; //else bug if enemies one on other
			}else {
				++it_e;
			}
		}

		if (plus) {
			++it_b;
		}
		plus = true;

	}
	

}

void Game::draw()
{

	for (std::vector<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
		(*it).draw(); 
	}
	//if (enemy)enemy->draw();
	if (player)player->draw();

	for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
		(*it).draw();
	}
}

void Game::init()
{
	
}

Game::Game()
{
	player = new Player(this);
	//enemy = new Enemy;
	enemies.push_back(*(new Enemy(this)));
	//enemies.push_back(*(new Enemy));

}

Game::~Game()
{
	if (player) delete player;
}
