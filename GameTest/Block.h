#pragma once
#include "Vector3.h"
#include "SDL_opengl.h"
#include <vector>
#include "BoundingBox.h"
#include "Color.h"

class Block
{
public:
	Vector3 position;
	float size;
	Color color;
	Block(Vector3 pos = Vector3(0.f, 0.f, 0.f), float size = 1.f, Color color = Color(1.0f, 1.0f, 1.0f), Vector3 texCoord = Vector3(0.0f, 0.0f, 0.0f), bool textured = false);
	void Render();
	BoundingBox bb = BoundingBox(position, size, size, size);
private:
	bool textured;
	Vector3 texCoord;
};

