#include "Camera.h"

//default empty constructor
Camera::Camera() 
{
}
//constructor with position and rotation
Camera::Camera(Vector3 pos, float yaw, float pitch)
{
	this->position = pos;
	this->yaw = yaw;
	this->pitch = pitch;
}

//rotate the camera based on the passed values
void Camera::rotate(float yaw, float pitch)
{
	this->yaw += yaw;

	//reset rotation if greater than 360 degrees or smaller than -360 degrees
	if (this->yaw >= 360 || this->yaw <= -360)
		this->yaw = 0;

	//prevent from having a greater pitch than 90 degrees
	if ((this->pitch + pitch) <= 90 && (this->pitch + pitch) >= -90)
	{
		this->pitch += pitch;
	}
}

//move than camera by the given vector
void Camera::move(Vector3 direction)
{
	this->position += direction;
}

//"look through the camera"
void Camera::lookTrough()
{
	glLoadIdentity();
	glRotatef(this->pitch, 1.0f, 0.0f, 0.0f);
	glRotatef(this->yaw, 0.0f, 1.0f, 0.0f);
	glTranslatef(-this->position.x, -this->position.y, -this->position.z);
}
