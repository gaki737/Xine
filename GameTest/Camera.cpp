#include "Camera.h"

Camera::Camera() 
{
}
Camera::Camera(Vector3 pos, float yaw, float pitch)
{
	this->position = pos;
	this->yaw = yaw;
	this->pitch = pitch;
}

void Camera::rotate(float yaw, float pitch)
{
	this->yaw += yaw;

	if (this->yaw >= 360 || this->yaw <= -360)
		this->yaw = 0;

	if ((this->pitch + pitch) <= 90 && (this->pitch + pitch) >= -90)
	{
		this->pitch += pitch;
	}
}

void Camera::move(Vector3 direction)
{
	this->position += direction;
}

void Camera::lookTrough()
{
	glLoadIdentity();
	glRotatef(this->pitch, 1.0f, 0.0f, 0.0f);
	glRotatef(this->yaw, 0.0f, 1.0f, 0.0f);
	glTranslatef(-this->position.x, -this->position.y, -this->position.z);
}
