#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
const float SCREEN_WIDTH = 1024;
const float SCREEN_HEIGHT = 768;
const float DEFAULT_EMISSION_RATE = 100;
const float EMISSION_INCREMENT = 10;
const int MAX_PARTICLES = 1000;
const float DEG_TO_RAD = 0.0174532925;
const Vector2f DEFAULT_SIZE = Vector2f(10, 10);
const float DEFAULT_LIFETIME = 3;


Vector2f normalizeVector(Vector2f vector);
float randomNumberAroundZero(float number);
float degreesToReadians(float degrees);
Vector2f getDirectionVectorFromDegrees(float degree);
