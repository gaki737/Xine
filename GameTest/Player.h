#pragma once

#include "Camera.h"
#include "Vector3.h"
#include "BoundingBox.h"
#include "Block.h"
#include "Map.h"
#include "InputHandler.h"

class Player
{
	//make game a friend
	friend class Game;
	friend class InputHandler;
public:
	//constructor with position and height
	Player(const Vector3 pos = Vector3(0.0f, 0.0f, 0.0f), float height = 1.8f);
	//the position of the player
	Vector3 position;
	//the bounding box of the player
	BoundingBox bb = BoundingBox(position, 0.5f, 0.5f, 1.8f);
private:
	//the camera component
	Camera cam;
	//the players yaw
	float yaw = 0.0f;
	//the players pitch
	float pitch = 0.0f;
	//the mouse sensitivity
	float mouseSensitivity = 0.2f;
	//the players movementspeed
	float movementSpeed = 6.0f;
	//the players jump height
	float jumpHeight = 1.5f;
	//move right method
	void MoveRight();
	//move left method
	void MoveLeft();
	//move forward method
	void MoveForward();
	//move backwards method
	void MoveBackwards();
	//jump method
	void Jump();
	//rotate the player by yaw and pitch
	void rotate(float yaw, float pitch);
	//the players intersections with blocks
	std::vector<Block> intersections;
	//move method with delta and gravity
	void Move(double delta, float gravity = 0.0f);
	//the players movement vector
	Vector3 movementVector = Vector3(0.0f,0.0f,0.0f);
	//is the player in air
	bool inAir = false;
};
