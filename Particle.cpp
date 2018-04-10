#include "Particle.h"



void Particle::init(Vector2f position, float speed, Vector2f direction, Vector2f size, float lifeTime)
{
	shape.setSize(size);
	shape.setOrigin(size.x / 2, size.y / 2);
	shape.setPosition(position);
	shape.setFillColor(Color::Red);
	this->speed = speed;
	this->direction = direction;
	this->lifeTime = lifeTime;
	timer = 0;
	this->isAlive = true;
}

Particle::Particle()
{
}

bool Particle::update(float dt) {
	timer += dt;
	if (timer >= lifeTime) {
		isAlive = false;
		return false;
	}
	Vector2f newPos = shape.getPosition();
	newPos += speed * direction * dt;
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
