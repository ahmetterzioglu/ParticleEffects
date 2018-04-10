#include "ParticleSystem.h"
#include "Utils.h"


ParticleSystem::ParticleSystem(Vector2f emitterPos, int maxParticles, float emissionRate, float emissionSpeed)
{
	this->emitterPos = emitterPos;
	this->maxPaticles = maxParticles;
	this->emissionRate = emissionRate;
	this->emissionSpeed = emissionSpeed;

	for (int i = 0; i < MAX_PARTICLES; i++) {
		Particle* p = new Particle();
		particles[i] = p;
	}
	
}

void ParticleSystem::update(float dt, RenderWindow* window)
{
	bool addNewParticle = false;
	if (timer >= emissionRate) {
		addNewParticle = true;
		timer = 0;
	}
	timer += dt;
	for (int i = 0; i < MAX_PARTICLES; i++) {
		Particle* p = particles[i];
		if (p->getAlive()) {
			if (p->update(dt)) {
				p->draw(window);
			}
			else {
				particleCount--;
			}
		}
		else if (addNewParticle) {
			p->init(emitterPos, emissionSpeed, generateDirection(), DEFAULT_SIZE, DEFAULT_LIFETIME);
			addNewParticle = false;
			particleCount++;
		}
	}
}


ParticleSystem::~ParticleSystem()
{
}

Vector2f ParticleSystem::generateDirection()
{
	return getDirectionVectorFromDegrees(randomNumberAroundZero(45));
}
