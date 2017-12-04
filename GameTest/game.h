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
#include "InputHandler.h"

class Game
{

	//makes the InputHandler friend
	friend class InputHandler;
private:
	void ToggleFullscreen(SDL_Window* Window);
	//the windows title
	char* TITLE;
	//the coordinate and dimension of the window
	SDL_Rect windowRect;
	//the sdl window
	SDL_Window* window;
	//the sdl context
	SDL_GLContext context;
	//is the game quitting
	bool quit;
	//the method to update the objects
	void UpdateObjects(double delta);
	//initialize the objects
	void InitializeObjects();
	//the map initialization method
	void Game::InitializeMap(int length, int width, int heightMin, int heightMax);
	//the render method
	void Render();
	//initialization of sdl
	bool InitSDL();
	//initialization of the window
	bool InitWindow(char* TITLE, int POSX, int POSY, int WIDTH, int HEIGHT);
	//initialization of opengl
	bool InitGL();
	//the player reference
	Player player;
	//the map reference
	Map map; 

	//the currently set renderMode 
	int renderMode = Renderer::renderModes::Normal;

	//the InputHandler
	InputHandler inputHandler = InputHandler(this);


public:
	//standard constructor
	Game();
	//initialization of the game 
	//window title, position, dimension and map generation parameter
	bool InitGame(char* TITLE, int POSX, int POSY, int WIDTH, int HEIGHT, int mapLenght, int mapWidth, int mapHeightMin, int mapHeightMax);
	//run the game
	void RunGame();


};
