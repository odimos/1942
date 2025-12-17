#include "Animation.h"
#include <iostream>
#include "config.h"

void Frame::draw(float x, float y)
{
	graphics::drawRect(x, y, sizex, sizey, br);
}

Frame::Frame(std::string image_path, float size_x, float size_y)
{
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + image_path;
	
	sizex = size_x;
	sizey = size_y;
}

Frame::Frame(std::string image_path, float size_x, float size_y, unsigned long duration_)
{
	br.outline_opacity = 0.0f;
	duration = duration_;
	br.texture = ASSET_PATH + image_path;
	sizex = size_x;
	sizey = size_y;
}




bool Animation::isEnd()
{
	return (it+1 == frames.end() && count+1 >= (*it).duration );
}

void Animation::draw(float x, float y)
{
	
	(*it).draw(x, y);//danger for ecception it null

}

void Animation::init()
{
	for (it = frames.begin(); it != frames.end(); ++it) {
		(*it).draw(0, 0);
	}
	it = frames.begin();
}

void Animation::update()
{
	//kati asproi satanades, but only the first time!
	count++;
	if (count >= (*it).duration ){
		it++;
		count = 1;
	}
	
	if (it ==frames.end()) it = frames.begin();

}

Animation::Animation(std::vector<Frame> frames_)
{
	count = 1;
	frames = frames_;
	it = frames.begin();

}

