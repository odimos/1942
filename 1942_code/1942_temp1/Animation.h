#pragma once
#include "config.h"
#include <string>
#include "graphics.h"
#include <vector>

class Frame {

	float sizex, sizey;
	graphics::Brush br;
	

public:
	unsigned long duration = -1; //to use inside animatin
	void draw(float x,float  y);
	Frame(std::string imagePath, float size_x, float size_y);
	Frame(std::string imagePath, float size_x, float size_y, unsigned long duration_);

};

class Animation {

	std::vector<Frame> frames;
	Frame* now=nullptr;
	std::vector<Frame>::iterator it ;

	int count; //should count time not frames



public:
	bool isEnd();
	void draw(float x, float y);
	void update();
	void init();//for asprous satanades to go
	Animation(std::vector<Frame> frame);
	

};