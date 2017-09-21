#include "Player.h"

const double pi180 = 0.017453292519943295769236907684886;


Player::Player(Vector3 pos, float height)
{
	this->position = pos;
	this->cam = Camera(pos + Vector3(0, height * 0.9f / 2, 0));
	bb = BoundingBox(pos, 0.5f,0.5f, height);
}

void Player::MoveRight(double delta)
{
	Vector3 direction;

	direction.x = delta * -sin((this->yaw - 90)*pi180);
	direction.z = delta * cos((this->yaw - 90)*pi180);

}

void Player::MoveLeft(double delta)
{
	Vector3 direction;

	direction.x = delta * -sin((this->yaw + 90)*pi180);
	direction.z = delta * cos((this->yaw + 90)*pi180);

}

void Player::MoveForward(double delta)
{
	Vector3 direction;

	direction.x = delta * sin((this->yaw)*pi180);
	direction.z = delta * -cos((this->yaw)*pi180);

}

void Player::MoveBackwards(double delta)
{
	Vector3 direction;

	direction.x = delta * -sin((this->yaw)*pi180);
	direction.z = delta * cos((this->yaw)*pi180);

}

void Player::MoveUp(double delta)
{
	this->movementVector += Vector3(0, 1, 0)*delta;

}

void Player::MoveDown(double delta)
{
	Vector3 direction;
	direction = Vector3(0, -1, 0)*delta;

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

void Player::Move()
{
	this->position += this->movementVector*this->movementSpeed;
	this->bb.moveBB(this->movementVector*this->movementSpeed);
	this->cam.move(this->movementVector*this->movementSpeed);
}