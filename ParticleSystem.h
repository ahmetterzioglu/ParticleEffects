#pragma once
#include "Particle.h"
#include <SFML/Graphics.hpp>
#include "Utils.h"
using namespace sf;
using namespace std;
class ParticleSystem
{
public:
	ParticleSystem(Vector2f emitterPos, int maxParticles, float emissionRate);
	void update(float dt);
	~ParticleSystem();
private:
	int maxPaticles;
	Particle* particles[MAX_PARTICLES];
	Vector2f emitterPos;
	float emissionRate;
	float timer;
};

