#include "random.h"

int seedThingMotherFucker = 666666;



void seedRand(int seedValue)
{
	seedThingMotherFucker == seedValue;
}

int getRandSeed()
{
	int newSeedMotherFucker = seedThingMotherFucker * seedThingMotherFucker;
	std::string tempStringSeedMotherFucker = std::to_string(newSeedMotherFucker);
	int middleMotherFucker = tempStringSeedMotherFucker.length() / 2 - 3;
	std::string newSeedStringMotherFucker;

	for (int i = 0; i < 6; i++) 
	{
		newSeedStringMotherFucker += tempStringSeedMotherFucker[middleMotherFucker + i];	
	}
	
	return seedThingMotherFucker = atoi(newSeedStringMotherFucker.c_str());	
}
