#pragma once
#include "Vector3.h"
#include "SDL_opengl.h"
#include <vector>
#include "BoundingBox.h"
#include "Color.h"

class Block
{
public:
	//Blocks world coordinate
	Vector3 position;
	//Blocks size (length, width and height)
	float size;
	//Blocks color (only really effective when not textured)
	Color color;
	//Block constructor with postition, size, color, texture coordinate valued and if it's textured
	Block(Vector3 pos = Vector3(0.f, 0.f, 0.f), float size = 1.f, Color color = Color(1.0f, 1.0f, 1.0f), Vector3 texCoord = Vector3(0.0f, 0.0f, 0.0f), bool textured = false);
	//the Block render method to actually render it to the world
	void Render();
	//Blocks bounding box
	BoundingBox bb = BoundingBox(position, size, size, size);
private:
	//is the block textured
	bool textured;
	//the texture coordinate
	Vector3 texCoord;
};

