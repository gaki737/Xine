#include "CollisonHandler.h"


std::vector<Block> * CollisonHandler::checkPlayerBlockCollisions(const Player &player, const std::vector<Block> &blocks)
{
	//clear the intersections vector
	intersections.clear();
	//interate through the blocks
	for (Block block : blocks)
	{
		//check if the bbs are overlapping
		if (checkAABB(player.bb, block.bb))
		{
			//add the intersection to the vector
			intersections.push_back(block);
		}
	}
	//return the intersections
	return &intersections;
}

//check if two bounding boxes are overlapping/colliding
bool CollisonHandler::checkAABB(const BoundingBox &bb1, const BoundingBox &bb2)
{
	if (bb1.LeftDownBack <= bb2.RightUpFront && bb1.RightUpFront >= bb2.LeftDownBack)
	{
		return true;
	}
	else
		return false;
}
