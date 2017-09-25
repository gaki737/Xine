#pragma once
#include "Vector3.h"
#include "BoundingBox.h"
#include "Block.h"
#include "Player.h"

class CollisonHandler
{
public:

	//a vector to store all intersections
	std::vector<Block> intersections;

	//check if a player is colliding with a vector of blocks
	std::vector<Block> * checkPlayerBlockCollisions(const Player &player, const std::vector<Block> &blocks);

	//enumeration to determine on which side it is colliding
	enum CollisionType
	{
		CollidedTop,
		CollidedBottom,
		CollidedFront,
		CollidedBack,
		CollidedLeft,
		CollidedRight
	};
private:
	//compare two bounding boxes
	//are they overlapping
	bool checkAABB(const BoundingBox &bb1, const BoundingBox &bb2);
};

