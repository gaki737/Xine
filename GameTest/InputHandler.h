#pragma once
#include <SDL.h>
#include <SDL_mouse.h>
#include "game.h"

class InputHandler
{
public:
	Game* game;
	InputHandler(Game* game);
	~InputHandler();
	void HandleInput();
};

