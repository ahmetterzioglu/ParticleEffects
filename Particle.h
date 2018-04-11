#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Particle
{
public:
	Particle();
	void init(Vector2f position, float speed, Vector2f direction, Vector2f size, float lifeTime, Texture* texture, Vector3i behavior);
	bool update(float dt);
	void draw(RenderWindow* window);
	bool getAlive();
	~Particle();
private: 
	RectangleShape shape;
	float speed;
	Vector2f direction;
	Vector2f size;
	bool isAlive = false;
	float lifeTime;
	float timer;
	Vector3i behavior;
	Vector2f actualSize;
};

