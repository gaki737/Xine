#pragma once
#include "Vector3.h"

class BoundingBox
{
public:
	
	//the coordinates of each corner of the bounding box
	Vector3
		Center,
		LeftUpFront,
		RightUpFront,
		RightDownFront,
		LeftDownFront,
		LeftUpBack,
		RightUpBack,
		RightDownBack,
		LeftDownBack;
	
	//the dimensions of the bounding box
	float
		width,
		length,
		height;

	//move method to change the bounding box position
	void moveBB(const Vector3 &dist);

	//standard constructor for a bounding box 
	//position, width, length and height
	BoundingBox(Vector3 pos, float width, float length, float height);
};

