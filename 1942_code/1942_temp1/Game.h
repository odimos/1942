#pragma once

#include <vector> 

//test for branch

class Game
{
	//with "class .. " dont need to import player.h
	class Player* player = nullptr;
	std::vector<class Enemy> enemies;
	std::vector<class Bullet> bullets;
	

	bool checkCollisionWithPlayer(class Enemy & e);
	bool checkCollisionA(class Bullet& b, class Enemy& e);

public: 
	void addBullet(float x, float y, float speed_x, float speed_y, bool is_enemy);
	void update();
	void draw();
	void init();

	Game();
	~Game();
	
};

