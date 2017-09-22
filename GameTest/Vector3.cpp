#include "Vector3.h"

Vector3::Vector3(float X, float Y, float Z)
{
	this->x = X;
	this->y = Y;
	this->z = Z;
}


std::ostream& operator<<(std::ostream &os, const Vector3 &vec)
{
	return os<<vec.x<<" "<<vec.y<<" "<<vec.z;
}

//calculate and return the magnitude of this vector
float Vector3::magnitude()
{
	return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}

//multiply this vector by a scalar
Vector3 Vector3::operator*(const float &num)
{
	return Vector3(this->x * num, this->y * num, this->z * num);
}

Vector3 Vector3::operator*(const float &num) const
{
	return Vector3(this->x * num, this->y * num, this->z * num);
}

//multiply this vector by another vector
Vector3 Vector3::operator*(const Vector3 &vec)
{
	return Vector3(this->x * vec.x, this->y * vec.y, this->z * vec.z);
}

Vector3 Vector3::operator*(const Vector3 &vec) const
{
	return Vector3(this->x * vec.x, this->y * vec.y, this->z * vec.z);
}

//add two vectors
Vector3 Vector3::operator+(const Vector3 &vec)
{
	return Vector3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}

Vector3 Vector3::operator+(const Vector3 &vec) const
{
	return Vector3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}


Vector3 Vector3::operator+(const float &val)
{
	return Vector3(this->x + val, this->y + val, this->z + val);
}

Vector3 Vector3::operator+(const float &val) const
{
	return Vector3(this->x + val, this->y + val, this->z + val);
}

Vector3 Vector3::operator-(const float &val)
{
	return Vector3(this->x - val, this->y - val, this->z - val);
}

Vector3 Vector3::operator-(const float &val) const
{
	return Vector3(this->x - val, this->y - val, this->z - val);
}

//subtract two vectors
Vector3 Vector3::operator-(const Vector3 &vec)
{
	return Vector3(this->x - vec.x, this->y - vec.y, this->z - vec.z);
}

Vector3 Vector3::operator-(const Vector3 &vec) const
{
	return Vector3(this->x - vec.x, this->y - vec.y, this->z - vec.z);
}


Vector3& Vector3::operator+=(const Vector3 &vec)
{
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;

	return *this;
}




bool Vector3::operator>(const Vector3 & vec)
{
	if ((this->x > vec.x) &&
		(this->y > vec.y) &&
		(this->z > vec.z))
		return true;

}

bool Vector3::operator<(const Vector3 & vec)
{
	if ((this->x < vec.x) &&
		(this->y < vec.y) &&
		(this->z < vec.z))
		return true;
	else
		return false;
}

bool Vector3::operator>=(const Vector3 & vec)
{
	if ((this->x >= vec.x) &&
		(this->y >= vec.y) &&
		(this->z >= vec.z))
		return true;
	else
		return false;
}

bool Vector3::operator<=(const Vector3 & vec)
{
	if ((this->x <= vec.x) &&
		(this->y <= vec.y) &&
		(this->z <= vec.z))
		return true;
	else
		return false;
}


bool Vector3::operator>(const Vector3 & vec) const
{
	if ((this->x > vec.x) &&
		(this->y > vec.y) &&
		(this->z > vec.z))
		return true;
	else
		return false;
}

bool Vector3::operator<(const Vector3 & vec) const
{
	if ((this->x < vec.x) &&
		(this->y < vec.y) &&
		(this->z < vec.z))
		return true;
	else
		return false;
}

bool Vector3::operator>=(const Vector3 & vec) const
{
	if ((this->x >= vec.x) &&
		(this->y >= vec.y) &&
		(this->z >= vec.z))
		return true;
	else
		return false;
}

bool Vector3::operator<=(const Vector3 & vec) const
{
	if ((this->x <= vec.x) &&
		(this->y <= vec.y) &&
		(this->z <= vec.z))
		return true;
	else
		return false;
}



Vector3 Vector3::lerp(const Vector3 curVec, const Vector3 tarVec, const float speed, const float delta)
{
	return curVec + Vector3(fabsf(tarVec.x - curVec.x)*(speed / 100)*delta, fabsf(tarVec.y - curVec.y)*delta, fabsf(tarVec.z - curVec.z)*(speed / 100)*delta);
}

Vector3 Vector3::absoluteCoordinate()
{

	return Vector3(round(this->x), round(this->y), round(this->z));
}

//normalize this vector
void Vector3::normalize()
{
	float magnitude = sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
	this->x /= magnitude;
	this->y /= magnitude;
	this->z /= magnitude;
}

//calculate and return dot product
float Vector3::dot(const Vector3 &vec)
{
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

//calculate and return cross product
Vector3 Vector3::cross(const Vector3 &vec)
{
	return Vector3(y * vec.z - this->z * vec.y,
		this->z * vec.x - this->x * vec.z,
		this->x * vec.y - this->y * vec.x);
}
