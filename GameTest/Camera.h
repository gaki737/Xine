#pragma once

#include "Vector3.h"
#include <SDL_opengl.h>

class Camera {
	//make the game class a friend
	friend class Game;
public:
	//standard empty constructor
	Camera();
	//constructor with passed position and rotation
	Camera(Vector3 pos, float yaw = 0.0f, float pitch = 0.0f);
	//move method to move camera around
	void move(Vector3 direction);
	//rotate to rotate the camera around it's axes
	void rotate(float yaw, float pitch);
	//"look through the camera"
	void lookTrough();

private:
	//the cameras position
	Vector3 position;
	//the cameras yaw
	float yaw;
	//the cameras pitch
	float pitch;
};