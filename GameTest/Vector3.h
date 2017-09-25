#pragma once
#include <math.h>
#include <iostream>

class Vector3
{
private:
	//get the magnitude of the vector
	float magnitude();
	//normalize the vector
	void normalize();
	//get the dot value of a vector
	float dot(const Vector3 &vec);
	//cross two vectors
	Vector3 cross(const Vector3 &vec);
public:
	//vector3 constructor 
	Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	//the coordinates
	float x, y, z;
	// * operator to multiply two vectors
	Vector3 operator*(const Vector3 &vec);
	// * operator to multiply two vectors
	Vector3 operator*(const Vector3 &vec) const;
	// * operator to multiply a vector by a float
	Vector3 operator*(const float &num);
	// * operator to multiply a vector by a float
	Vector3 operator*(const float &num) const;
	// + operator to add two vectors
	Vector3 operator+(const Vector3 &vec);
	// + operator to add two vectors
	Vector3 operator+(const Vector3 &vec) const;
	// - operator to substract two vectors
	Vector3 operator-(const Vector3 &vec);
	// - operator to substract two vectors
	Vector3 operator-(const Vector3 &vec) const;
	// + operator to add a float 
	Vector3 operator+(const float &val);
	// + operator to add a float
	Vector3 operator+(const float &val) const;
	// + operator to subtract a float
	Vector3 operator-(const float &val);
	// + operator to substract a float
	Vector3 operator-(const float &val) const;

	// += operator to set a vector to its value in addition to another vector
	Vector3& operator+=(const Vector3 &vec);

	// << operator to get the bitstream
	friend std::ostream &operator<<(std::ostream &os, const Vector3 &vec);
	//compare two vectors
	bool operator>(const Vector3 &vec);
	//compare two vectors
	bool operator<(const Vector3 &vec);
	//compare two vectors
	bool operator>=(const Vector3 &vec);
	//compare two vectors
	bool operator<=(const Vector3 &vec);

	//compare two vectors
	bool operator>(const Vector3 &vec) const;
	//compare two vectors
	bool operator<(const Vector3 &vec) const;
	//compare two vectors
	bool operator>=(const Vector3 &vec) const;
	//compare two vectors
	bool operator<=(const Vector3 &vec) const;


	//lerp a vector to another given by tansition speed and delta time
	static Vector3 lerp(const Vector3 curVec, const Vector3 tarVec, const float speed, const float delta);

	//get the rounded value 
	Vector3 absoluteCoordinate();
};
