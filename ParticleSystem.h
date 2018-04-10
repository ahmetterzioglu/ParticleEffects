#pragma once
#include "Particle.h"
#include <SFML/Graphics.hpp>
#include "Utils.h"
using namespace sf;
using namespace std;
class ParticleSystem
{
public:
	ParticleSystem(Vector2f emitterPos, int maxParticles, float emissionRate, float emissionSpeed);
	void update(float dt, RenderWindow* window);
	~ParticleSystem();
private:
	Vector2f generateDirection();
	int maxPaticles;
	int particleCount = 0;
	Particle* particles[MAX_PARTICLES];
	Vector2f emitterPos;
	float emissionRate;
	float timer = 0;
	float emissionSpeed;
};

