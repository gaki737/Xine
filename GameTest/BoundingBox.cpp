#include "BoundingBox.h"


//move the bounding box by the given vector
void BoundingBox::moveBB(const Vector3 & dist)
{
	this->Center += dist;

	this->LeftUpFront += dist;
	this->RightUpFront += dist;
	this->RightDownFront += dist;
	this->LeftDownFront += dist;

	this->LeftUpBack += dist;
	this->RightUpBack += dist;
	this->RightDownBack += dist;
	this->LeftDownBack += dist;
}

//constructor of the bounding box with position and dimensions
BoundingBox::BoundingBox(Vector3 pos, float width, float length, float height)
{
	this->Center = pos;
	this->height = height;
	this->length = length;
	this->width = width;

	this->LeftUpFront = Vector3(pos.x - (this->width / 2), pos.y + (this->height / 2), pos.z + (this->length / 2));
	this->RightUpFront = Vector3(pos.x + (this->width / 2), pos.y + (this->height / 2), pos.z + (this->length / 2));
	this->RightDownFront = Vector3(pos.x + (this->width / 2), pos.y - (this->height / 2), pos.z + (this->length / 2));
	this->LeftDownFront = Vector3(pos.x - (this->width / 2), pos.y - (this->height / 2), pos.z + (this->length / 2));

	this->LeftUpBack = Vector3(pos.x - (this->width / 2), pos.y + (this->height / 2), pos.z - (this->length / 2));
	this->RightUpBack = Vector3(pos.x + (this->width / 2), pos.y + (this->height / 2), pos.z - (this->length / 2));
	this->RightDownBack = Vector3(pos.x + (this->width / 2), pos.y - (this->height / 2), pos.z - (this->length / 2));
	this->LeftDownBack = Vector3(pos.x - (this->width / 2), pos.y - (this->height / 2), pos.z - (this->length / 2));
}
