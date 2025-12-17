#include "Bullet.h"
#include "graphics.h"
#include "Util.h"
#include "config.h"

Disk Bullet::getCollArea()
{
	//maybe there should be a disk variable inside enemy and player
	Disk disk;
	disk.cx = posx; disk.cy = posy;
	disk.radius = sizex * (2 / 3.0f);
	return disk;

}

void Bullet::draw() {
	//maybe we should create one brush for player 
	//inside the contructor not one for every single draw
	graphics::Brush br;
	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.1f;
	br.fill_color[2] = 0.0f;
	graphics::drawRect(posx, posy, sizex, sizey, br);

	//draw collision Area
	/*graphics::Brush br2;
	br2.fill_color[0] = 0.0f;
	br2.fill_color[1] = 0.5f;
	br2.fill_color[2] = 0.0f;
	br2.fill_opacity = 0.3f;
	br2.outline_width = 2;
	Disk collArea = getCollArea();
	graphics::drawDisk(collArea.cx, collArea.cy, collArea.radius, br2);*/
}
Bullet::Bullet(float x, float y, float speed_x, float speed_y, bool is_enemy)
{
	//posx = (rand() * 1.0f / RAND_MAX) * CANVAS_WIDTH;
	//posy = (rand() * 1.0f / RAND_MAX) * CANVAS_HEIGHT;
	posx = x; posy = y;
	sizex = 20;
	sizey = sizex;
	speedx = speed_x; speedy = speed_y;
	isEnemy = is_enemy;
	collidable = true;
};

void Bullet::update() {
	//update position
	posx += speedx * graphics::getDeltaTime() / 100.0f;
	posy += speedy * graphics::getDeltaTime() / 100.0f;

	//check if out of boundaries
	if (posx < 0 - sizex || posx > CANVAS_WIDTH + sizex / 2) {
		active = false;
	}
	if (posy < 0 - sizey || posy > CANVAS_HEIGHT + sizey / 2) {
		active = false;
	}
}

bool Bullet::isActive() {
	return active;
}