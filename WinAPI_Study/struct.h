#pragma once
#include <cassert>
#include <math.h>

struct Vector2
{
	float _x;
	float _y;

public:
	Vector2() : _x(0), _y(0)
	{

	}
	Vector2(float x, float y) : _x(x), _y(y)
	{

	}
	Vector2(int x, int y) : _x(x), _y(y)
	{

	}
	Vector2(const POINT& pt) : _x(static_cast<float>(pt.x)), _y(static_cast<float>(pt.y))
	{

	}

public :
	float Length() { return sqrt(_x * _x + _y + _y); }

	Vector2 Normalize()
	{
		float len = Length();

		assert(len != 0.f);

		_x /= len;
		_y /= len;

		return *this;
	}

public :
	Vector2 operator = (POINT& other)
	{
		_x = static_cast<float>(other.x);
		_y = static_cast<float>(other.y);
	}

	Vector2 operator + (const Vector2& other)
	{
		return Vector2(_x + other._x, _y + other._y);
	}

	void operator += (const Vector2 other)
	{
		_x += other._x;
		_y += other._y;
	}

	Vector2 operator - (POINT& other)
	{
		return Vector2(_x - other.x, _y - other.y);
	}

	Vector2 operator * (POINT& other)
	{
		return Vector2(_x * other.x, _y * other.y);
	}
	Vector2 operator * (int value)
	{
		return Vector2(_x * static_cast<float>(value), _y * static_cast<float>(value));
	}

	Vector2 operator / (POINT& other)
	{
		assert(!(0.f == other.x || 0.f == other.y));
		return Vector2(_x / other.x, _y / other.y);
	}
	Vector2 operator / (const float& value)
	{
		assert(!(0.f == value));
		return Vector2(_x / value, _y / value);
	}



};