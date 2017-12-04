#include "InputHandler.h"



InputHandler::InputHandler(Game* game)
{
	this->game = game;
}


InputHandler::~InputHandler()
{
}

//Handles Input
void InputHandler::HandleInput()
{



	const Uint8 *keyState = SDL_GetKeyboardState(NULL);
	SDL_Event event;



	if (keyState[SDL_SCANCODE_ESCAPE])
	{
		this->game->quit = true;
	}
	if (keyState[SDL_SCANCODE_W] || keyState[SDL_SCANCODE_UP])
	{
		this->game->player.MoveForward();
	}
	if (keyState[SDL_SCANCODE_S] || keyState[SDL_SCANCODE_DOWN])
	{
		this->game->player.MoveBackwards();
	}
	if (keyState[SDL_SCANCODE_A] || keyState[SDL_SCANCODE_LEFT])
	{
		this->game->player.MoveLeft();
	}
	if (keyState[SDL_SCANCODE_D] || keyState[SDL_SCANCODE_RIGHT])
	{
		this->game->player.MoveRight();
	}
	if (keyState[SDL_SCANCODE_SPACE])
	{
		this->game->player.Jump();
		//this->player.MoveUp();
	}
	if (keyState[SDL_SCANCODE_LCTRL])
	{
		//this->player.MoveDown();
	}
	if (keyState[SDL_SCANCODE_F11])
	{
		//SDL_SetWindowBordered(this->window, SDL_FALSE);
		this->game->ToggleFullscreen(this->game->window);
		//SDL_SetWindowSize(this->window, 1920, 1080);

		//setPerspective(45.0f, (1920 / 1080), 0.1, 100.0);

		//SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN);
	}
	if (keyState[SDL_SCANCODE_F1])
	{
		this->game->renderMode = Renderer::renderModes::Normal;
	}
	if (keyState[SDL_SCANCODE_F2])
	{
		this->game->renderMode = Renderer::renderModes::Debug;
	}


	while (SDL_PollEvent(&event))
	{

		if (event.type == SDL_QUIT)
			this->game->quit = true;

		if (event.type == SDL_MOUSEMOTION)
		{
			//this->game->player.rotate(event.motion.xrel, event.motion.yrel);
		}
	}
}