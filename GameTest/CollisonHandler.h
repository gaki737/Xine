#pragma once
#include "Vector3.h"
#include "BoundingBox.h"
#include "Block.h"
#include "Player.h"

class CollisonHandler
{
public:

	std::vector<Block> intersections;

	std::vector<Block> * checkPlayerBlockCollisions(const Player &player, const std::vector<Block> &blocks);

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
	bool checkAABB(const BoundingBox &bb1, const BoundingBox &bb2);
};

