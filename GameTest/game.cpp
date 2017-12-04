#include <iostream>

#include "game.h"

Time timer;
Texture tex;
CollisonHandler colHandler;


const double pi180 = 0.017453292519943295769236907684886;
// pi/180
// replacement for gluPerspective
void setPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar) {
	GLdouble top, bottom, left, right;
	top = zNear * tan(pi180*fovy / 2);
	bottom = -top;
	right = aspect*top;
	left = -right;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(left, right, bottom, top, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);
}

void Game::ToggleFullscreen(SDL_Window* Window) {
	Uint32 FullscreenFlag = SDL_WINDOW_FULLSCREEN;
	bool IsFullscreen = SDL_GetWindowFlags(Window) & FullscreenFlag;

	if (IsFullscreen) 
	{
		SDL_SetWindowFullscreen(this->window, !FullscreenFlag);
		SDL_SetWindowSize(this->window, this->windowRect.w, this->windowRect.h);
		setPerspective(90.0f, (this->windowRect.w / this->windowRect.h), 0.1, 100.0);
		glViewport(0, 0, this->windowRect.w, this->windowRect.h);
	}
	else
	{
		SDL_SetWindowFullscreen(this->window, FullscreenFlag);
		SDL_SetWindowSize(this->window, 1920, 1080);
		setPerspective(90.0f, (1920 / 1080), 0.1, 100.0);
		glViewport(0, 0, 1920, 1080);

	}

	}

// Initialization ++
// ==================================================================
bool Game::InitGame(char* TITLE, int POSX, int POSY, int WIDTH, int HEIGHT, int mapLenght, int mapWidth, int mapHeightMin, int mapHeightMax)
{
	if (!this->InitSDL())
		return false;

	if (!this->InitWindow(TITLE, POSX, POSY, WIDTH, HEIGHT))
		return false;

	//if (!this->InitRenderer())
	//	return false;

	if (!this->InitGL())
		return false;

	this->InitializeObjects();
	this->InitializeMap(mapLenght, mapWidth, mapHeightMin, mapHeightMax);

	return true;
}

bool Game::InitSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}
	else
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);


	}

	return true;
}


bool Game::InitWindow(char* TITLE, int POSX, int POSY, int WIDTH, int HEIGHT)
{
	this->windowRect = { POSX, POSY, WIDTH, HEIGHT };
	this->quit = false;
	//window = SDL_CreateWindow( "Server", posX, posY, sizeX, sizeY, 0 );
	this->window = SDL_CreateWindow(TITLE, this->windowRect.x, this->windowRect.y, this->windowRect.w, this->windowRect.h, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);
	if (this->window == nullptr)
	{
		std::cout << "Failed to create window : " << SDL_GetError();
		return false;
	}

	this->context = SDL_GL_CreateContext(this->window);

	SDL_SetRelativeMouseMode(SDL_TRUE);

	return true;
}




bool Game::InitGL()
{
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	setPerspective(80.0f, (this->windowRect.w / this->windowRect.h), 0.1, 100.0);
	glViewport(0, 0, this->windowRect.w, this->windowRect.h);


	if (glGetError() != GL_NO_ERROR)
	{
		std::cout << "Failed to initialize OpenGL : " << glGetError();
		return false;
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (glGetError() != GL_NO_ERROR)
	{
		std::cout << "Failed to initialize OpenGL : " << glGetError();
		return false;
	}

	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);

	if (glGetError() != GL_NO_ERROR)
	{
		std::cout << "Failed to initialize OpenGL : " << glGetError();
		return false;
	}

	return true;
}

void Game::InitializeMap(int length, int width, int heightMin, int heightMax)
{
	this->map = Map(length, width, heightMin, heightMax);

}

void Game::InitializeObjects()
{
	this->player = Player(Vector3(5.0f, 20.0f, 5.0f), 1.8f);

	tex.initTexture("textures/blocks.bmp");

}

//Main Loop
void Game::RunGame()
{
	while (!this->quit)
	{
		timer.getDelta();
		this->inputHandler.HandleInput();
		this->UpdateObjects(timer.deltaTime);

		this->Render();
	}
	tex.delTexture();
}



//Updating stuff with delta time 
void Game::UpdateObjects(double delta)
{
	this->player.Move(timer.deltaTime, this->map.gravity);
	this->player.intersections = *colHandler.checkPlayerBlockCollisions(this->player, this->map.blocks);


	if(this->renderMode == Renderer::renderModes::Debug)
	{
		std::cout << "DEBUG: " << "FPS: " << (1 / delta) << " PLAYER-POS: " << this->player.position << " PLAYER-BB-POS: " << this->player.bb.Center << std::endl;
	}
}

//Actual rendering
void Game::Render()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_CULL_FACE);

	glLoadIdentity();

	this->player.cam.lookTrough();

	if (this->renderMode == Renderer::renderModes::Debug)
	{
		glBegin(GL_LINES);
		for (int i = -100; i <= 100; i++) {
			if (i == 0) { glColor3f(.6, .3, .3); }
			else { glColor3f(.25, .25, .25); };
			glVertex3f(i, 0, -100);
			glVertex3f(i, 0, 100);
			if (i == 0) { glColor3f(.3, .3, .6); }
			else { glColor3f(.25, .25, .25); };
			glVertex3f(-100, 0, i);
			glVertex3f(100, 0, i);
		}
		glEnd();


		//player col box indicators

		Block(this->player.bb.LeftDownBack, 0.05f, Color(0.0f, 0.0f, 1.0f), false).Render();
		Block(this->player.bb.RightUpFront, 0.05f, Color(0.0f, 1.0f, 0.0f), false).Render();
	}

	this->map.Render(this->renderMode);

	SDL_GL_SwapWindow(this->window);
}

Game::Game()
{
}
