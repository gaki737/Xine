#pragma once
#include "Block.h"
#include "Vector3.h"
#include "Color.h"
#include "Renderer.h"

class Map
{
public:
	Map();
	Map(int length, int width, int heightMin, int heightMax);
	void Render(int rendermode);
	void findBlock(Vector3 pos);
	std::vector<Block> blocks;
	std::vector<Block> blockCols;
	float gravity = 3.0f;

private:
};

