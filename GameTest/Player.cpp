#include "Player.h"

//a constant value of pi
const double pi180 = 0.017453292519943295769236907684886;

//the player constructor with passed values for position and player height
Player::Player(Vector3 pos, float height)
{
	this->position = pos;
	//adding a camera component to the player to make the player the actual player (you see through "his" eyes)
	this->cam = Camera(pos + Vector3(0, height * 0.9f / 2, 0));
	//adding a bouding box component to the player for collision detection/handling
	bb = BoundingBox(pos, 0.5f,0.5f, height);
}

//calculate the movement vector for a movement to the right
void Player::MoveRight()
{
	this->movementVector.x += -sin((this->yaw - 90)*pi180);
	this->movementVector.z += cos((this->yaw - 90)*pi180);

}

//calculate the movement vector for a movement to the left
void Player::MoveLeft()
{
	this->movementVector.x += -sin((this->yaw + 90)*pi180);
	this->movementVector.z += cos((this->yaw + 90)*pi180);

}

//calculate the movement vector for a foreward movement
void Player::MoveForward()
{
	this->movementVector.x += sin((this->yaw)*pi180);
	this->movementVector.z += -cos((this->yaw)*pi180);
	
}

//calculate the movement vector for a backwards movement
void Player::MoveBackwards()
{
	this->movementVector.x += -sin((this->yaw)*pi180);
	this->movementVector.z += cos((this->yaw)*pi180);

}

//check if the player is already in the air
//if not change the y-value of the movement-vector to the jump height
void Player::Jump()
{
	if (!this->inAir)
	{
		this->movementVector.y = this->jumpHeight;
	}
}

//calculate the totation based on mouse input and sensitivity
//rotate the camera based on the input 
void Player::rotate(float _yaw, float _pitch)
{
	float yaw = _yaw*this->mouseSensitivity;
	float pitch = _pitch*this->mouseSensitivity;
	this->cam.rotate(yaw, pitch);
	

	this->yaw += yaw;

	//resetting the rotation if rotated more than 360 degrees
	if (this->yaw >= 360 || this->yaw <= -360)
		this->yaw = 0;

	//not allowing the player to have a pitch greater than 90 
	if ((this->pitch + pitch) <= 90 && (this->pitch + pitch) >= -90)
	{
		this->pitch += pitch;
	}
}


//move the player and it's components according to the movement vector 
void Player::Move(double delta, float gravity)
{
	//setting the inAir value to true to avoid jumping errors
	this->inAir = true;
	//check if the player is not collided
	if (!this->intersections.empty())
	{
		//iterate through the collisions
		for (Block intersection : this->intersections) 
		{
			//check if the player is standing on or moving into a block from the top to set the inAir value to false (player is standing on something)
			if (intersection.position.y <= this->position.absoluteCoordinate().y)
			{
				this->inAir = false;
			}

			//check if the player is colliding with a block on it's negative x axis 
			//avoid any movement in that direction to stop clipping
			//y-coordinate is checked to avoid sideway collision while standing on top of a block
			if (intersection.position.x < this->position.absoluteCoordinate().x && intersection.position.y >= this->position.absoluteCoordinate().y && this->movementVector.x < 0)
			{
				this->movementVector.x = 0;
			}

			//check if the player is colliding with a block on it's x axis 
			//avoid any movement in that direction to stop clipping
			//y-coordinate is checked to avoid sideway collision while standing on top of a block
			if (intersection.position.x > this->position.absoluteCoordinate().x && intersection.position.y >= this->position.absoluteCoordinate().y && this->movementVector.x > 0)
			{
				this->movementVector.x = 0;
			}

			//check if the player is colliding with a block on it's negative z axis 
			//avoid any movement in that direction to stop clipping
			//y-coordinate is checked to avoid sideway collision while standing on top of a block
			if (intersection.position.z < this->position.absoluteCoordinate().z && intersection.position.y >= this->position.absoluteCoordinate().y && this->movementVector.z < 0)
			{
				this->movementVector.z = 0;
			}


			//check if the player is colliding with a block on it's z axis 
			//avoid any movement in that direction to stop clipping
			//y-coordinate is checked to avoid sideway collision while standing on top of a block
			if (intersection.position.z > this->position.absoluteCoordinate().z && intersection.position.y >= this->position.absoluteCoordinate().y && this->movementVector.z > 0)
			{
				this->movementVector.z = 0;
			}
		}
	}

	//change the players position vector3 by the movementvector multiplied with the movementspeed and the delta time
	this->position += (this->movementVector*this->movementSpeed*delta);
	//change the players bounding box position vector3 by the movementvector multiplied with the movementspeed and the delta time
	this->bb.moveBB(this->movementVector*this->movementSpeed*delta);
	//change the players camera position vector3 by the movementvector multiplied with the movementspeed and the delta time
	this->cam.move(this->movementVector*this->movementSpeed*delta);


	if(this->inAir)
	{
		//apply gravity force to the movement vector if the player is in air
		//multiplied width the delta time to make the simulation smooth and steady
		this->movementVector.y += -gravity*delta;
	}
	else
	{
		//resetting the y value of the movement vector if the player in on top of something
		this->movementVector.y = 0.0f;
	}

	//resetting the movement vector to finish the movement 
	//the y value is not changed to simulate acceleration while falling and making falling itself possible 
	this->movementVector = this->movementVector * Vector3(0, 1, 0);

}