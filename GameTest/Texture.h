#pragma once
#include <SDL.h>
#include <SDL_opengl.h>


class Texture
{
public:
	void initTexture(const char* name);
	void delTexture();
private:
	GLuint texture;
};

