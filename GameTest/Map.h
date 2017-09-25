#pragma once
#include "Block.h"
#include "Vector3.h"
#include "Color.h"
#include "Renderer.h"

class Map
{
public:
	//default constructor
	Map();
	//constructor with length, width and height parameters
	Map(int length, int width, int heightMin, int heightMax);
	//the map render method
	void Render(int rendermode);
	//find a block by coordinates
	void findBlock(Vector3 pos);
	//the block vector
	std::vector<Block> blocks;
	//the blockcollision vector
	std::vector<Block> blockCols;
	//the maps gravity
	float gravity = 3.0f;

private:
};

