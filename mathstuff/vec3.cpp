#include "vec3.h"
#include<cmath>
#include<cfloat>
vec3::vec3()
{
	x = 0;
	y = 0;
}

vec3::vec3(float xx, float yy, float zz)
{
	x = xx;
	y = yy;
	z = zz;
}

float vec3::dot(const vec3 & rhs) const
{
	return ((x * rhs.x) + (y * rhs.y ) + (z * rhs.z));
}

vec3 vec3::cross(const vec3 & rhs) const
{
	return vec3
	{
	(y * rhs.z) - (z * rhs.y),
	(z * rhs.x) - (x * rhs.z),
	(x * rhs.y) - (y * rhs.x)
	};
}

vec3 vec3::operator+(const vec3 & rhs) const
{
	vec3 add;
	add.x = (x + rhs.x);
	add.y = (y + rhs.y);
	add.z = (z + rhs.z);

	return add;
}

vec3 vec3::operator-(const vec3 & rhs) const
{
	vec3 sub;
	sub.x = (x - rhs.x);
	sub.y = (y - rhs.y);
	sub.z = (z - rhs.z);

	return sub;
}

vec3 & vec3::operator+=(const vec3 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

vec3 & vec3::operator-=(const vec3 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

bool vec3::operator==(const vec3 & rhs) const
{
	if ((x >= (rhs.x - FLT_EPSILON) and x <= (rhs.x + FLT_EPSILON)) and
		(y >= (rhs.y - FLT_EPSILON) and y <= (rhs.y + FLT_EPSILON)) and
		(z >= (rhs.z - FLT_EPSILON) and z <= (rhs.z + FLT_EPSILON)))
	{
		return true;
	}
	return false;
}

bool vec3::operator!=(const vec3 & rhs) const
{
	if ((x >= (rhs.x - FLT_EPSILON) and x <= (rhs.x + FLT_EPSILON)) and
		(y >= (rhs.y - FLT_EPSILON) and y <= (rhs.y + FLT_EPSILON)) and
		(z >= (rhs.z - FLT_EPSILON) and z <= (rhs.z + FLT_EPSILON)))
	{
		return false;
	}
	return true;
}

vec3 vec3::operator-() const
{
	vec3 neg;
	neg.x = -x;
	neg.y = -y;
	neg.z = -z;
	return neg;
}

float vec3::magnitude() const
{
	float mag = sqrt((x * x) + (y * y) + (z * z));
	return mag;
}

vec3 & vec3::normalize()
{
	vec3 norm = getNormalized();

	x = norm.x;
	y = norm.y;
	z = norm.z;
	return *this;
}

vec3 vec3::getNormalized() const
{
	vec3 norm;
	float mag = magnitude();

	norm.x = x / mag;
	norm.y = y / mag;
	norm.z = z / mag;
	return norm;
}

vec3 & vec3::scale(const vec3 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}

vec3 vec3::getScaled(const vec3 & rhs) const
{
	vec3 scale;
	scale.x = x * rhs.x;
	scale.y = y * rhs.y;
	scale.z = z * rhs.z;

	return scale;
}

vec3 vec3::operator*(const float rhs) const
{
	vec3 scale;
	scale.x = x * rhs;
	scale.y = y * rhs;
	scale.z = z * rhs;

	return scale;
}

vec3 & vec3::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;

	return *this;
}

vec3 & vec3::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;

	return *this;
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	vec3 scale;
	scale.x = lhs * rhs.x;
	scale.y = lhs * rhs.y;
	scale.z = lhs * rhs.z;

	return scale;
}
