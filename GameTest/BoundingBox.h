#pragma once
#include "Vector3.h"

class BoundingBox
{
public:
	
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
	
	float
		width,
		length,
		height;

	void moveBB(const Vector3 &dist);

	BoundingBox(Vector3 pos, float width, float length, float height);
};

