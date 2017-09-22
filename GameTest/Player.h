#pragma once

#include "Camera.h"
#include "Vector3.h"
#include "BoundingBox.h"
#include "Block.h"
#include "Map.h"

class Player
{
	friend class Game;
public:
	Player(const Vector3 pos = Vector3(0.0f, 0.0f, 0.0f), float height = 1.8f);
	Vector3 position;
	BoundingBox bb = BoundingBox(position, 0.5f, 0.5f, 1.8f);
private:
	Camera cam;
	float yaw = 0.0f;
	float pitch = 0.0f;
	float mouseSensitivity = 0.2f;
	float movementSpeed = 5.0f;
	float jumpHeight = 1.5f;
	void MoveRight();
	void MoveLeft();
	void MoveForward();
	void MoveBackwards();
	void Jump();
	void rotate(float yaw, float pitch);
	std::vector<Block> intersections;
	void Move(double delta, float gravity = 0.0f);
	Vector3 movementVector = Vector3(0.0f,0.0f,0.0f);
	bool inAir = false;
};
