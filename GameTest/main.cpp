#include "main.h"
#include <ctime>

int main(int argc, char **argv)
{

	//declare the game component
	Game game;
	//initialize the game
	if (!game.InitGame("Test", 400, 400, 800, 400, 100, 100, 0 , 1))
		return -1;
	//rin the game
	game.RunGame();
	//quit the sdl framework
	SDL_Quit();
	//end the program
	return 0;
}

