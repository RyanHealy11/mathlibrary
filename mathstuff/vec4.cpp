#include "vec4.h"
float vec4::dot(const vec4 & rhs) const
{
	return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w));
}

vec4 vec4::cross(const vec4 & rhs) const
{
	return vec4
	{
		(y * rhs.z) - (z * rhs.y),
		(z * rhs.x) - (x * rhs.z),
		(x * rhs.y) - (y * rhs.x),
		0
	};
}

vec4::vec4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

vec4::vec4(float xx, float yy, float zz, float ww)
{
	x = xx;
	y = yy;
	z = zz;
	w = ww;
}

vec4 vec4::operator+(const vec4 & rhs) const
{
	vec4 add;
	add.x = (x + rhs.x);
	add.y = (y + rhs.y);
	add.z = (z + rhs.z);
	add.w = (w + rhs.z);
	
	return add;
}

vec4 vec4::operator-(const vec4 & rhs) const
{
	vec4 sub;
	sub.x = (x - rhs.x);
	sub.y = (y - rhs.y);
	sub.z = (z - rhs.z);
	sub.w = (w - rhs.w);

	return sub;
}

vec4 & vec4::operator+=(const vec4 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;
	return *this;
}

vec4 & vec4::operator-=(const vec4 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;
	return *this;
}

bool vec4::operator==(const vec4 & rhs) const
{
	if ((x >= (rhs.x - FLT_EPSILON) and x <= (rhs.x + FLT_EPSILON)) and
		(y >= (rhs.y - FLT_EPSILON) and y <= (rhs.y + FLT_EPSILON)) and
		(z >= (rhs.z - FLT_EPSILON) and z <= (rhs.z + FLT_EPSILON)) and
		(w >= (rhs.w - FLT_EPSILON) and w <= (rhs.w + FLT_EPSILON)))
	{
		return true;
	}
	return false;
}

bool vec4::operator!=(const vec4 & rhs) const
{
	if ((x >= (rhs.x - FLT_EPSILON) and x <= (rhs.x + FLT_EPSILON)) and
		(y >= (rhs.y - FLT_EPSILON) and y <= (rhs.y + FLT_EPSILON)) and
		(z >= (rhs.z - FLT_EPSILON) and z <= (rhs.z + FLT_EPSILON)) and
		(w >= (rhs.w - FLT_EPSILON) and w <= (rhs.w + FLT_EPSILON)))
	{
		return false;
	}
	return true;
}

vec4 vec4::operator-() const
{
	vec4 neg;
	neg.x = -x;
	neg.y = -y;
	neg.z = -z;
	neg.w = -w;
	return neg;
}

float vec4::magnitude() const
{
	float mag = sqrt((x * x) + (y * y) + (z * z) + (w + w));
	return mag;
}

vec4 & vec4::normalize()
{
	vec4 norm = getNormalized();

	x = norm.x;
	y = norm.y;
	z = norm.z;
	w = norm.w;
	return *this;
}

vec4 vec4::getNormalized() const
{
	vec4 norm;
	float mag = magnitude();

	norm.x = x / mag;
	norm.y = y / mag;
	norm.z = z / mag;
	norm.w = w / mag;
	return norm;
}

vec4 & vec4::scale(const vec4 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	w *= rhs.w;
	return *this;
}

vec4 vec4::getScaled(const vec4 & rhs) const
{
	vec4 scale;
	scale.x = x * rhs.x;
	scale.y = y * rhs.y;
	scale.z = z * rhs.z;
	scale.w = w * rhs.w;

	return scale;
}

vec4 vec4::operator*(const float rhs) const
{
	vec4 scale;
	scale.x = x * rhs;
	scale.y = y * rhs;
	scale.z = z * rhs;
	scale.w = w * rhs;

	return scale;
}

vec4 & vec4::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	w *= rhs;

	return *this;
}

vec4 & vec4::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	w /= rhs;

	return *this;
}

vec4 operator*(const float lhs, const vec4 & rhs)
{
	vec4 scale;
	scale.x = lhs * rhs.x;
	scale.y = lhs * rhs.y;
	scale.z = lhs * rhs.z;
	scale.w = lhs * rhs.w;

	return scale;
}
