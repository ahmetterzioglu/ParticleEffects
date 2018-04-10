#include "ParticleSystem.h"
#include "Utils.h"


ParticleSystem::ParticleSystem(Vector2f emitterPos, int maxParticles, float emissionRate, float emissionSpeed, float angleRange, Texture* texture)
{
	this->emitterPos = emitterPos;
	this->maxPaticles = maxParticles;
	this->emissionRate = emissionRate;
	this->emissionSpeed = emissionSpeed;
	this->angleRange = angleRange;
	this->texture = texture;
	emitter.setRadius(3);
	emitter.setOrigin(3, 3);
	emitter.setPosition(emitterPos);

	for (int i = 0; i < MAX_PARTICLES; i++) {
		Particle* p = new Particle();
		particles[i] = p;
	}
	
}

void ParticleSystem::update(float dt, RenderWindow* window)
{
	window->draw(emitter);

	if (Keyboard::isKeyPressed(Keyboard::Up) && !upPressed) {
		upPressed = true;
		this->emissionRate /= 2;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && !downPressed) {
		downPressed = true;
		this->emissionRate *= 2;
	}

	if (!Keyboard::isKeyPressed(Keyboard::Up)) {
		upPressed = false;	
	}
	if (!Keyboard::isKeyPressed(Keyboard::Down)) {
		downPressed = false;
	}

	int particlesToCreate = dt / emissionRate;

	
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
		else if(particlesToCreate > 0) {
			p->init(emitterPos, getRandomNumberUpto(emissionSpeed), generateDirection(), DEFAULT_SIZE, getRandomNumberUpto(DEFAULT_LIFETIME), texture);
			particleCount++;
			particlesToCreate--;
		}
	}
}


ParticleSystem::~ParticleSystem()
{
}

int ParticleSystem::getParticleCount()
{
	return particleCount;
}

Vector2f ParticleSystem::generateDirection()
{
	return getDirectionVectorFromDegrees(randomNumberAroundZero(angleRange));
}
