#pragma once
const double PI = 3.141592653589793238;

template <typename T>
T lerp(const T& a, const T& b, float t)
{
	return a + (b - a) * t;
}

namespace Tweening 
{
	template <typename T>
	inline T LinearEase(float t, const T& b, const T& c, float d) 
	{
		return b + c * (t / d);
	}
	template <typename T>
	inline T easeInSine(float t, const T& b, const T& c, float d)
	{
		return b + c - c * cosf(t / d * HALF_PI);
	}
}
template <typename T>
T quadraticBezier(const T& a, const T& b, const T& c, float t)
{
	T x = lerp(a, b, t);
	T y = lerp(b, c, t);
	return lerp(x, y, t);
}
template <typename T>
T cubicBezier(const T& a, const T& b, const T& c, const T& d, float t)
{
	T x = lerp(a, b, t);
	T y = lerp(b, c, t);
	T z = lerp(c, d, t);
	return quadraticBezier(x, y, z, t);
}
