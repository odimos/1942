#include "graphics.h"
#include "Game.h"
#include "config.h"
#include <iostream>

//the mother of all ipdate functions, update function
void update(float ms) {
	/*short for: Game* game = (Game*) graphics::getUserData(); //einterpret_cast< Game *>(graphics::getUserData());
	(game)->update();*/
	((Game*)graphics::getUserData())->update();


}

// The mother of all draw functions, update function 
// The window content drawing function.
void draw() {
	((Game*)graphics::getUserData())->draw();
}

//This is first function. It starts the programm
int main() {
	srand(time(NULL)); //randomize the rand for every different call

	Game * game = new Game() ;
	
	//size is in pixels
	//must be the first function of graphics group
	graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "1942");

	graphics::setUserData(game);//

	//could be changes however with mouse
	graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	//create a background
	graphics::Brush br;
	br.fill_color[0] = 0.7f;
	br.fill_color[1] = 0.8f;
	br.fill_color[2] = 0.95f;
	graphics::setWindowBackground(br);

	game->init();
	graphics::startMessageLoop();


	return 0;

}

