#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

const float SCREEN_WIDTH = 1024;
const float SCREEN_HEIGHT = 768;
const float DEFAULT_EMISSION_RATE = 100;
const float EMISSION_INCREMENT = 10;
const int MAX_PARTICLES = 25000;
const float DEG_TO_RAD = 0.0174532925;
const Vector2f DEFAULT_SIZE = Vector2f(70, 70);
const float DEFAULT_LIFETIME = 5;
const float ANGLE_RANGE = 45;

const int BEHAVIOR_QUADEASEOUT = 0;
const int BEHAVIOR_QUADEASEIN = 1;
const int BEHAVIOR_QUADEASEINOUT = 2;

const Vector2f POS1 = Vector2f(200, SCREEN_HEIGHT-100);
const Vector2f POS2 = Vector2f(400, SCREEN_HEIGHT-400);
const Vector2f POS3 = Vector2f(600, SCREEN_HEIGHT-100);
const Vector2f POS4 = Vector2f(800, SCREEN_HEIGHT-400);

Vector2f normalizeVector(Vector2f vector);
float randomNumberAroundZero(float number);
float degreesToReadians(float degrees);
Vector2f getDirectionVectorFromDegrees(float degree);
float getRandomNumberUpto(float number);
float quadEaseOut(float x);
float quadEaseIn(float x);
float quadEaseInOut(float x);
float getParticleBehaviorMultiplier(int behavior, float x);
