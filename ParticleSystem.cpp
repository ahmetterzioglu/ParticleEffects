#include "ParticleSystem.h"
#include "Utils.h"


ParticleSystem::ParticleSystem(Vector2f emitterPos, int maxParticles, float emissionRate)
{
	this->emitterPos = emitterPos;
	this->maxPaticles = maxParticles;
	this->emissionRate = emissionRate;
	for (int i = 0; i<MAX_PARTICLES; i++) {
		Particle* p = new Particle();
		particles[i] = p;
	}
	
}

void ParticleSystem::update(float dt)
{
	//go thru all the particles and update them
}


ParticleSystem::~ParticleSystem()
{
}
