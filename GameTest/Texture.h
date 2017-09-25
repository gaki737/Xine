#pragma once
#include <SDL.h>
#include <SDL_opengl.h>


class Texture
{
public:
	//initializing a texture
	void initTexture(const char* name);
	//delete the texture from memory
	void delTexture();
private:
	//the texture reference id
	GLuint texture;
};

