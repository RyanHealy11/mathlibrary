#include "unitTest.h"
#include <iostream>

bool assert(const char * testName, bool expression)
{
	if (expression) 
	{
		std::cout << "[PASS] " << testName << std::endl;
		return true;
	}
	else 
	{
		std::cout << "[FAIL] " << testName << std::endl;
		return false;
	}	
}

bool assert(const char * testName, int expected, int actual)
{
	if (actual == expected)
	{
		std::cout << "[PASS] " << testName << std::endl;
		return true;
	}
	else
	{
		std::cout << "[FAIL] " << testName << std::endl;
		return false;
	}
}

bool assert(const char * testName, float expected, float actual, float tolerance)
{
	if (expected >= (actual - tolerance) and expected <= (actual + tolerance))
	{
		std::cout << "[PASS] " << testName << std::endl;
		return true;
	}
	else
	{
		std::cout << "[FAIL] " << testName << std::endl;
		return false;
	}
}
