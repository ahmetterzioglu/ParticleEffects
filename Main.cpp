#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "Utils.h"
#include "Particle.h"
#include "ParticleSystem.h"
using namespace sf;
using namespace std;
	
RenderWindow window;

void getEvents();

int main()
{
	srand(static_cast<unsigned int>(std::time(NULL)));
	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Particle Systems");
	Clock clock;

	//setup
	Vector2f testPos = Vector2f(100, 100);
	int particleCOunt = 500;
	float etmissionRate = 100;
	float emissionSpeed = 50;

	ParticleSystem* ps = new ParticleSystem(testPos, particleCOunt, etmissionRate, emissionSpeed);


	while (window.isOpen())
	{
		getEvents();
		float dt = clock.restart().asSeconds();
		window.clear();
		ps->update(dt, &window);
	}


	return 0;
}


void getEvents() {
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
