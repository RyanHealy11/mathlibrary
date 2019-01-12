#pragma once


struct vec4
{
	float x, y, z, w;

	float dot(const vec4 &rhs) const;
	vec4 cross(const vec4 &rhs) const;

	vec4();
	vec4(float xx, float yy, float zz, float ww);

	vec4 operator+(const vec4 &rhs) const;
	vec4 operator-(const vec4 &rhs) const;

	vec4 &operator+=(const vec4 &rhs);
	vec4 &operator-=(const vec4 &rhs);

	bool operator==(const vec4 &rhs) const;
	bool operator!=(const vec4 &rhs) const;

	vec4 operator-() const;

	float magnitude() const;

	vec4 &normalize();
	vec4 getNormalized() const;

	vec4 &scale(const vec4 &rhs);
	vec4 getScaled(const vec4 &rhs) const;
	
	vec4 operator*(const float rhs) const;
	friend vec4 operator*(const float lhs, const vec4 &rhs);

	vec4 &operator*=(const float rhs);
	vec4 &operator/=(const float rhs);

};