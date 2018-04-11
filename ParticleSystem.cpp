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

	//Create Particles
	for (int i = 0; i < MAX_PARTICLES; i++) {
		Particle* p = new Particle();
		particles[i] = p;
	}
	
}

void ParticleSystem::update(float dt, RenderWindow* window)
{
	
	//Particle System Rotation with Ease In Out Function
	float multiplier = quadEaseInOut(1-((int)angle % 360)/ 360);
	angle = angle + (dt * 100 * multiplier);
	
	//Handle Keyboard Input
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

	//Calculate how many particles to init per tick
	int particlesToCreate = 0;
	if (emissionRate >= dt) {
		timer += dt;
		if (timer >= emissionRate) {
			particlesToCreate = 1;
			timer = 0;
		}
	}
	else {
		particlesToCreate = dt / emissionRate;
	}

	//Update particles
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
			//Init a particle
			//Behaviors: x->size, y->speed, z->opacity
			Vector3i behavior = Vector3i(BEHAVIOR_QUADEASEINOUT, BEHAVIOR_QUADEASEOUT, BEHAVIOR_QUADEASEIN);
			p->init(emitterPos, getRandomNumberUpto(emissionSpeed), generateDirection(), DEFAULT_SIZE, getRandomNumberUpto(DEFAULT_LIFETIME), texture, behavior);
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

//Get a direction vector for a particle
Vector2f ParticleSystem::generateDirection()
{
	return getDirectionVectorFromDegrees(randomNumberAroundZero(angleRange) + angle);
}
