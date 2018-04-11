#include "Particle.h"
#include "Utils.h"


void Particle::init(Vector2f position, float speed, Vector2f direction, Vector2f size, float lifeTime, Texture* texture, Vector3i behavior)
{
	this->actualSize = size;
	shape.setSize(size);
	shape.setOrigin(size.x / 2, size.y / 2);
	shape.setPosition(position);
	shape.setTexture(texture);
	shape.setFillColor(Color::Green);
	
	this->speed = speed;
	this->direction = direction;
	this->lifeTime = lifeTime;
	this->behavior = behavior;
	timer = 0;
	this->isAlive = true;
}

Particle::Particle()
{
}

//Behavior xyz -> size speed opacity
bool Particle::update(float dt) {
	timer += dt;
	if (timer >= lifeTime) {
		isAlive = false;
		return false;
	}

	float lifetimeRatio = timer / lifeTime;

	shape.setSize(actualSize * getParticleBehaviorMultiplier(behavior.x, lifetimeRatio));

	//Decided to do speed linear down below
	//float speedMultiplier = speed * getParticleBehaviorMultiplier(behavior.y, lifetimeRatio);

	Color color = shape.getFillColor();
	color.a = getParticleBehaviorMultiplier(behavior.z, 1-lifetimeRatio) * 255;
	shape.setFillColor(color);

	Vector2f newPos = shape.getPosition();
	newPos += speed * (1-lifetimeRatio) * direction * dt;
	shape.setPosition(newPos);
	return true;
}

void Particle::draw(RenderWindow* window) {
	window->draw(shape);
}

bool Particle::getAlive()
{
	return isAlive;
}


Particle::~Particle()
{
}


