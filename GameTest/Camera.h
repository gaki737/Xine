#pragma once

#include "Vector3.h"
#include <SDL_opengl.h>

class Camera {
	friend class Game;
public:
	Camera();
	Camera(Vector3 pos, float yaw = 0.0f, float pitch = 0.0f);
	void move(Vector3 direction);
	void rotate(float yaw, float pitch);
	void lookTrough();

private:
	Vector3 position;
	float yaw;
	float pitch;
};