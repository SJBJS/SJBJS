#pragma once

#ifndef __MYUTIL_H_
#define __MYUTIL_H_
#include <math.h>
#include <string>
struct Vector2f
{
	float x, y;

	Vector2f(float x =0, float y=0) :x(x), y(y) {}
	Vector2f operator+(const Vector2f &ref) { return  Vector2f(x + ref.x, y + ref.y); }
	Vector2f operator-(const Vector2f &ref) { return Vector2f(x - ref.x, y - ref.y); }
	Vector2f operator*(const float &value) { return Vector2f(x*value, y*value); }
	Vector2f operator/(const float &value) { return Vector2f(x / value, y / value); }
	Vector2f operator=(const Vector2f &value) { 
		x = value.x;
		y = value.y;
		return *this;
	}
	size_t GetLength()const { return sqrt(x*x + y*y); }
};
struct Vector3f {
	float x, y, z;
};
struct ObjectNode
{
	Vector3f position;
	std::string texDir;
};
#endif