#pragma once
#include <math.h>
#include <iostream>

class Vector3
{
private:
	float magnitude();
	void normalize();
	float dot(const Vector3 &vec);
	Vector3 cross(const Vector3 &vec);
public:
	Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	float x, y, z;
	Vector3 operator*(const Vector3 &vec);
	Vector3 operator*(const Vector3 &vec) const;
	Vector3 operator*(const float &num);
	Vector3 operator*(const float &num) const;
	Vector3 operator+(const Vector3 &vec);
	Vector3 operator+(const Vector3 &vec) const;
	Vector3 operator-(const Vector3 &vec);
	Vector3 operator-(const Vector3 &vec) const;
	Vector3 operator+(const float &val);
	Vector3 operator+(const float &val) const;
	Vector3 operator-(const float &val);
	Vector3 operator-(const float &val) const;


	Vector3& operator+=(const Vector3 &vec);

	friend std::ostream &operator<<(std::ostream &os, const Vector3 &vec);
	bool operator>(const Vector3 &vec);
	bool operator<(const Vector3 &vec);
	bool operator>=(const Vector3 &vec);
	bool operator<=(const Vector3 &vec);

	bool operator>(const Vector3 &vec) const;
	bool operator<(const Vector3 &vec) const;
	bool operator>=(const Vector3 &vec) const;
	bool operator<=(const Vector3 &vec) const;


	static Vector3 lerp(const Vector3 curVec, const Vector3 tarVec, const float speed, const float delta);

	Vector3 absoluteCoordinate();
};
