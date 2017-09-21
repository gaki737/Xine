#include "main.h"
#include <ctime>

int main(int argc, char **argv)
{

	//std::srand(std::time(0));
	Game game;
	if (!game.InitGame("Test", 400, 400, 800, 400))
		return -1;
	game.RunGame();
	SDL_Quit();
	return 0;
}

