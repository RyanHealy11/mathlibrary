#pragma once


struct vec3
{
	float x, y, z;

	vec3();
	vec3(float xx, float yy, float zz);

	float dot(const vec3 &rhs) const;
	vec3 cross(const vec3 &rhs) const;

	vec3 operator+(const vec3 &rhs) const;
	vec3 operator-(const vec3 &rhs) const;

	vec3 &operator+=(const vec3 &rhs);
	vec3 &operator-=(const vec3 &rhs);

	bool operator==(const vec3 &rhs) const;
	bool operator!=(const vec3 &rhs) const;

	vec3 operator-() const;

	float magnitude() const;

	vec3 &normalize();
	vec3 getNormalized() const;

	vec3 &scale(const vec3 &rhs);
	vec3 getScaled(const vec3 &rhs) const;



	vec3 operator*(const float rhs) const;
	friend vec3 operator*(const float lhs, const vec3 &rhs);

	vec3 &operator*=(const float rhs);
	vec3 &operator/=(const float rhs);

};