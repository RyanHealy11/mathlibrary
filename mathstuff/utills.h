#pragma once
#include<iostream>
#include"vec2.h"
#include"vec3.h"
#include"vec4.h"
#include"interpolation.h"
//variables

//PI = 3.141592653589793238;

const double cPI = 3.141592653589793238;

const double DEG_TO_RAD = cPI / 180;

const double RAD_TO_DEG = 180 / cPI;


int sum(int a, int b);

//returns the smaller of two values
int min(int a, int b);

//returns the larger of two values
int max(int a, int b);

//returns a value within the range specified
int clamp(int value, int min, int max);

//returns the absolue value of the input 
int abs(int val);

//returns the value to the power specified
int pow(int base, int power);

//returns true if the value is a power of 2
bool isPowerOfTwo(int val);

//returns the next power of 2 after the indicated value
int nextPowerOfTwo(int val);

//moves entered value to the target but only as much as the max delta will allow
float moveTowards(float current, float target, float maxDelta);

