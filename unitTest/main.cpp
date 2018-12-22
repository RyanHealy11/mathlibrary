#include <iostream>
#include"utills.h"
#include"unitTest.h"

int main() 
{

	int yay = min(1, 2);


	const double stuff = (60 * DEG_TO_RAD);

	std::cout << pow(2, 10) << std::endl;

	bool two = isPowerOfTwo(8);

	std::cout << nextPowerOfTwo(5) << std::endl;

	assert("all the stuff", 0);

	assert("all the other stuff", 5, sum(2, 3));

	vec3 a = { 2, 2, 2 };
	vec3 b = { 1, 1, 1 };
	vec3 diff = a - b;

	assert("diff x", 1.0f, diff.x, 0.0001f);
	assert("diff y", 1.0f, diff.y, 0.0001f);
	assert("diff z", 1.0f, diff.z, 0.0001f);

	return 0;
}