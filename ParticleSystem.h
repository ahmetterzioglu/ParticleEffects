#pragma once
#include "Particle.h"
#include <SFML/Graphics.hpp>
#include "Utils.h"
using namespace sf;
using namespace std;
class ParticleSystem
{
public:
	ParticleSystem(Vector2f emitterPos, int maxParticles, float emissionRate, float emissionSpeed, float angleRange, Texture* texture, Vector3i behavior);
	void update(float dt, RenderWindow* window);
	int getParticleCount();
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
	float angleRange;
	Texture* texture;
	bool upPressed = false;
	bool downPressed = true;
	Vector3i behavior;
};

