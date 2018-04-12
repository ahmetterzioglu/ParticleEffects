#include "Particle.h"
#include "Utils.h"


void Particle::init(Vector2f position, float speed, Vector2f direction, Vector2f size, float lifeTime, Texture* texture, Vector3i behavior)
{
	this->actualSize = size;
	shape.setSize(size);
	shape.setOrigin(size.x / 2, size.y / 2);
	shape.setPosition(position);
	shape.setTexture(texture);
	shape.setOutlineColor(Color::White);
	//shape.setOutlineThickness(1);
	shape.setFillColor(Color::Green);
	
	this->speed = speed;
	this->direction = direction;
	this->lifeTime = lifeTime;
	this->behavior = behavior;
	angle = getRandomNumberUpto(360);
	timer = 0;
	this->isAlive = true;
}

Particle::Particle()
{
}

//Returns false if the particle dies this update
bool Particle::update(float dt) {
	timer += dt;
	if (timer >= lifeTime) {
		isAlive = false;
		return false;
	}

	float lifetimeRatio = timer / lifeTime;

	//Change size according to lifetime and set behavior
	Vector2f newSize = actualSize * getParticleBehaviorMultiplier(behavior.x, lifetimeRatio);
	shape.setSize(newSize);
	shape.setOrigin(newSize.x / 2, newSize.y / 2);

	//Change Rotation according to lifetime and set behavior
	angle = angle + (dt * 50 * getParticleBehaviorMultiplier(behavior.y, lifetimeRatio));
	shape.setRotation(angle);

	//Change color according to lifetime and set behavior
	Color color = shape.getFillColor();
	color.a = getParticleBehaviorMultiplier(behavior.z, 1-lifetimeRatio) * 255;
	color.r = lifetimeRatio * 255;
	color.g = (1 - lifetimeRatio) * 255;
	shape.setFillColor(color);

	//Update position - includes linear speed calculation with relation to lifetime
	Vector2f newPos = shape.getPosition();
	newPos += speed * (lifetimeRatio) * direction * dt;
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


