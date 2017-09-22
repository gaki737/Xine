#pragma once
#include "Block.h"
#include "Vector3.h"
#include "Color.h"
#include "Renderer.h"

class Map
{
public:
	Map();
	Map(int width, int length);
	void Render(int rendermode);
	void findBlock(Vector3 pos);
	std::vector<Block> blocks;
	std::vector<Block> blockCols;
	float gravity = 10.0f;

private:
};

