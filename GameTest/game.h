#pragma once
#include <chrono>
#include <SDL.h>
#include <SDL_mouse.h>
#include <SDL_opengl.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include "Player.h"
#include "Block.h"
#include "Time.h"
#include "Map.h"
#include "Texture.h"
#include "CollisonHandler.h"
#include "Renderer.h"

class Game
{
private:
	char* TITLE;
	SDL_Rect windowRect;
	SDL_Window* window;
	SDL_GLContext context;
	bool quit;
	void HandleInput();
	void UpdateObjects(double delta);
	void InitializeObjects();
	void Render();
	bool InitSDL();
	bool InitWindow(char* TITLE, int POSX, int POSY, int WIDTH, int HEIGHT);
	bool InitGL();
	Player player;
	Map map;

	int renderMode = Renderer::renderModes::Normal;


public:
	Game();
	bool InitGame(char* TITLE, int POSX, int POSY, int WIDTH, int HEIGHT);
	void RunGame();


};
