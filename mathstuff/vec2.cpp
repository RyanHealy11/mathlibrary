#include "vec2.h"

vec2::vec2()
{
	x = 0;
	y = 0;
}

vec2::vec2(float xx, float yy)
{
	x = xx;
	y = yy;
}

float vec2::dot(const vec2 & rhs) const
{
	return ((x * rhs.x) + (y * rhs.y));
}

vec2 vec2::operator+(const vec2 & rhs) const
{
	vec2 add; 
	add.x = (x + rhs.x);
	add.y = (y + rhs.y);
	
	return add;
}

vec2 vec2::operator-(const vec2 & rhs) const
{
	vec2 sub;
	sub.x = (x - rhs.x);
	sub.y = (y - rhs.y);
		
	return sub;
}

vec2 & vec2::operator+=(const vec2 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

vec2 & vec2::operator-=(const vec2 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

bool vec2::operator==(const vec2 & rhs) const
{
	if ((x >= (rhs.x - FLT_EPSILON) and x <= (rhs.x + FLT_EPSILON)) and
		(y >= (rhs.y - FLT_EPSILON) and y <= (rhs.y + FLT_EPSILON)))
	{ 
		return true; 
	}
	return false;
}

bool vec2::operator!=(const vec2 & rhs) const
{
	if ((x >= (rhs.x - FLT_EPSILON) and x <= (rhs.x + FLT_EPSILON)) and
		(y >= (rhs.y - FLT_EPSILON) and y <= (rhs.y + FLT_EPSILON)))
	{
		return false;
	}
	return true;
}

vec2 vec2::operator-() const
{
	vec2 neg;
	neg.x = -x;
	neg.y = -y;
	return neg;
}

float vec2::magnitude() const
{
	float mag = sqrt((x * x) + (y * y));
	return mag;
}

vec2 & vec2::normalize()
{
	vec2 norm = getNormalized();

	x = norm.x;
	y = norm.y;
	return *this;
}

vec2 vec2::getNormalized() const
{
	vec2 norm;
	float mag = magnitude();
	
	norm.x = x / mag;
	norm.y = y / mag;
	
	return norm;
}

vec2 & vec2::scale(const vec2 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}

vec2 vec2::getScaled(const vec2 & rhs) const
{
	vec2 scale;
	scale.x = x * rhs.x;
	scale.y = y * rhs.y;
	
	return scale;
}

vec2 vec2::operator*(const float rhs) const
{
	vec2 scale;
	scale.x = x * rhs;
	scale.y = y * rhs;

	return scale; 
}

vec2 & vec2::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}

vec2 & vec2::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	return *this;
}

vec2 operator*(const float lhs, const vec2 & rhs)
{
	vec2 scale;
	scale.x = lhs * rhs.x;
	scale.y = lhs * rhs.y;

	return scale;
}
