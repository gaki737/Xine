#include "Player.h"

const double pi180 = 0.017453292519943295769236907684886;


Player::Player(Vector3 pos, float height)
{
	this->position = pos;
	this->cam = Camera(pos + Vector3(0, height * 0.9f / 2, 0));
	bb = BoundingBox(pos, 0.5f,0.5f, height);
}

void Player::MoveRight()
{
	this->movementVector.x += -sin((this->yaw - 90)*pi180);
	this->movementVector.z += cos((this->yaw - 90)*pi180);

}

void Player::MoveLeft()
{
	this->movementVector.x += -sin((this->yaw + 90)*pi180);
	this->movementVector.z += cos((this->yaw + 90)*pi180);

}

void Player::MoveForward()
{
	this->movementVector.x += sin((this->yaw)*pi180);
	this->movementVector.z += -cos((this->yaw)*pi180);
	
}

void Player::MoveBackwards()
{
	this->movementVector.x += -sin((this->yaw)*pi180);
	this->movementVector.z += cos((this->yaw)*pi180);

}

void Player::Jump()
{
	if (!this->inAir)
	{
		this->movementVector.y = this->jumpHeight;
	}
}

void Player::rotate(float _yaw, float _pitch)
{
	float yaw = _yaw*this->mouseSensitivity;
	float pitch = _pitch*this->mouseSensitivity;
	this->cam.rotate(yaw, pitch);
	

	this->yaw += yaw;

	if (this->yaw >= 360 || this->yaw <= -360)
		this->yaw = 0;

	if ((this->pitch + pitch) <= 90 && (this->pitch + pitch) >= -90)
	{
		this->pitch += pitch;
	}
}

void Player::Move(double delta, float gravity)
{
	this->inAir = true;
	if (!this->intersections.empty())
	{
		for (Block intersection : this->intersections) 
		{
			if (intersection.position.y <= this->position.absoluteCoordinate().y)
			{
				this->inAir = false;
			}

			if (intersection.position.x < this->position.absoluteCoordinate().x && intersection.position.y >= this->position.absoluteCoordinate().y && this->movementVector.x < 0)
			{
				this->movementVector.x = 0;
			}
			if (intersection.position.x > this->position.absoluteCoordinate().x && intersection.position.y >= this->position.absoluteCoordinate().y && this->movementVector.x > 0)
			{
				this->movementVector.x = 0;
			}
			if (intersection.position.z < this->position.absoluteCoordinate().z && intersection.position.y >= this->position.absoluteCoordinate().y && this->movementVector.z < 0)
			{
				this->movementVector.z = 0;
			}
			if (intersection.position.z > this->position.absoluteCoordinate().z && intersection.position.y >= this->position.absoluteCoordinate().y && this->movementVector.z > 0)
			{
				this->movementVector.z = 0;
			}
		}
	}

	this->position += (this->movementVector*this->movementSpeed*delta);
	this->bb.moveBB(this->movementVector*this->movementSpeed*delta);
	this->cam.move(this->movementVector*this->movementSpeed*delta);

	if(this->inAir)
	{
		this->movementVector.y += -gravity*delta;
	}
	else
	{
		this->movementVector.y = 0.0f;
	}


	this->movementVector = this->movementVector * Vector3(0, 1, 0);

}