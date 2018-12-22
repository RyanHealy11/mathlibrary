#include"utills.h"

int sum(int a, int b)
{
	return (a + b);
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int clamp(int value, int min, int max)
{
	if (value > min and value < max) 
	{
		return value;
	}
	else if(value < min)
	{
		return min;
	}
	else if (value > max) 
	{
		return max;
	}
}

int abs(int val)
{
	if (val >= 0) { return val; }
	else if (val < 0) { return -val; }
	
}

int pow(int base, int power)
{
	int start = base;
	for (int i = 1; i < power; i++)
	{
		base = base * start;
	}
	return base;
}

bool isPowerOfTwo(int val)
{
	int twos = 2;
	do 
	{
		if (twos == val) { return true; }
		twos *= 2;
	
	} while (val >= twos);
	return false;

}

int nextPowerOfTwo(int val)
{
	if (isPowerOfTwo(val)) { return (val * 2); }
	else { std::cout << "the value entered is not a power of 2" << std::endl; return 0; }
	
}

float moveTowards(float current, float target, float maxDelta)
{
	if (current < target) 
	{
		if (current + maxDelta <= target) { return (current + maxDelta); }
		return target;
	}
	else if (current > target) 
	{
		if (current - maxDelta >= target) { return (current + maxDelta); }
		return target;
	}
	return current;
}
