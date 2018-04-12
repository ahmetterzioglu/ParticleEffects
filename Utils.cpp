#include "Utils.h"

Vector2f normalizeVector(Vector2f vector) {
	float x = vector.x;
	float y = vector.y;
	float length = sqrtf(x*x + y*y);
	x = x / length;
	y = y / length;
	return Vector2f(x, y);
}


float degreesToReadians(float degrees) {
	return (degrees - 90) * DEG_TO_RAD;
}

Vector2f getDirectionVectorFromDegrees(float degree) {
	return normalizeVector(Vector2f(cos(degreesToReadians(degree)), sin(degreesToReadians(degree))));
}

float randomNumberAroundZero(float number) {
	return (-number + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (number * 2))));
}

float getRandomNumberUpto(float number) {
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	return r * number;
}

float quadEaseOut(float x) {
	return -(x * (x - 2));
}

float quadEaseIn(float x) {
	return x * x;
}

float quadEaseInOut(float x) {
	if (x < 0.5)
	{
		return 2 * x * x;
	}
	else
	{
		return -1 + (4 - 2 * x)*x;
	}
}

//Depending on the behavior and the lifetime ratio of the particle returns coefficient
float getParticleBehaviorMultiplier(int behavior, float x) {
	switch (behavior) {
	case BEHAVIOR_QUADEASEIN:
		return quadEaseIn(x);
	case BEHAVIOR_QUADEASEOUT:
		return quadEaseOut(x);
	case BEHAVIOR_QUADEASEINOUT:
		return quadEaseInOut(x);
	default:
		return x;
	}
}