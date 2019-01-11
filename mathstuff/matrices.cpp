#include "matrices.h"

mat3::mat3()
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 1;
	m[5] = 0;
	m[6] = 0;
	m[7] = 0;
	m[8] = 1;
}

mat3::mat3(float * ptr)
{

}

mat3::mat3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
{
	m[0] = m1;
	m[1] = m2;
	m[2] = m3;
	m[3] = m4;
	m[4] = m5;
	m[5] = m6;
	m[6] = m7;
	m[7] = m8;
	m[8] = m9;
}

mat3::operator float*()
{
	float temp[9];
	temp[0] = m1;
	temp[1] = m2;
	temp[2] = m3;
	temp[3] = m4;
	temp[4] = m5;
	temp[5] = m6;
	temp[6] = m7;
	temp[7] = m8;
	temp[8] = m9;
	return temp;
}

vec3 & mat3::operator[](const int index)
{
	return axis[index];
}

mat3 mat3::operator*(const mat3 & rhs) const
{
	mat3 result;
	
	for (int r = 0; r < 3; ++r) 
	{
		for (int c = 0; c < 3; ++c) 
		{
			result.mm[c][r] = mm[0][r] * rhs.mm[c][0] +
				mm[1][r] * rhs.mm[c][1] +
				mm[2][r] * rhs.mm[c][2];
		}
	}
	return result;
}

mat3 & mat3::operator*=(const mat3 & rhs)
{
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			mm[c][r] = mm[0][r] * rhs.mm[c][0] +
			           mm[1][r] * rhs.mm[c][1] +
			           mm[2][r] * rhs.mm[c][2];
		}
	}
	return *this;
}

bool mat3::operator==(const mat3 & rhs) const
{
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			if (!mm[c][r] == rhs.mm[c][r]) { return false; }
		}
	}
	return true;
}

bool mat3::operator!=(const mat3 & rhs) const
{
	int fuck = 0;
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			if (mm[c][r] == rhs.mm[c][r]) { ++fuck; }
		}
	}
	if (fuck == 9) { return false; }
	return true;
}

mat3 mat3::identity()
{
	return mat3(1,0,0,
		        0,1,0,
		        0,0,1);
}

void mat3::set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
{
	m[0] = m1;
	m[1] = m2;
	m[2] = m3;
	m[3] = m4;
	m[4] = m5;
	m[5] = m6;
	m[6] = m7;
	m[7] = m8;
	m[8] = m9;
}

void mat3::set(float * ptr)
{
}

void mat3::transpose()
{
}

mat3 mat3::getTranspose() const
{
	mat3 result; 
	// flip row and column 
	for	(int r = 0 ; r < 3 ; ++r) 
		for (int c = 0; c < 3; ++c) 
			result.mm[r][c] = mm[c][r]; 
	return result;
}