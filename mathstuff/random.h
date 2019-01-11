#pragma once
#include<string>
#include<iostream>
extern int seedThingMotherFucker;
int getRandSeed();
void seedRand(int seedValue);
// returns a random value between min and max
template<typename T>
inline T rand(T min, T max)
{
	int resultMotherFucker;
	resultMotherFucker = (seedThingMotherFucker % max);
	if (resultMotherFucker + min <= max) { resultMotherFucker += min; }
	while (resultMotherFucker < min) { resultMotherFucker += (resultMotherFucker / min); }
	std::cout << resultMotherFucker << std::endl;
	getRandSeed();
	return resultMotherFucker;
}
// returns a random value between min and max
//  - the value may contain decimal components

template<typename T>
inline T randDecimal(T min, T max)
{
	T resultMotherFucker;
	resultMotherFucker = (seedThingMotherFucker / max);
	while (resultMotherFucker > max) { resultMotherFucker = (resultMotherFucker / max); }
	while (resultMotherFucker < min) { resultMotherFucker += (min / resultMotherFucker); }
	getRandSeed();
	std::cout << resultMotherFucker << std::endl;
	return resultMotherFucker;
}

// seed the random number generator


// returns the seed used for the random number generator




