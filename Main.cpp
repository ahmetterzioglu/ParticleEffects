#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <stdlib.h>
#include <iostream>
#include "Utils.h"
#include "Particle.h"
#include "ParticleSystem.h"
using namespace sf;
using namespace std;
	
RenderWindow window;
Texture texture1;
Texture texture2;
Texture texture3;
Texture texture4;

void getEvents();

int main()
{
	//System
	srand(static_cast<unsigned int>(std::time(NULL)));
	Clock clock;

	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Particle Systems");
	
	//Load Assets
	Font font;
	if (!font.loadFromFile("sansation.ttf"))
	{
		cout << "Font couldn't load!";
	}
	if (!texture1.loadFromFile("flame1.png"))
	{
		cout << "texture1 Image couldn't load!";
	}
	if (!texture2.loadFromFile("flame2.png"))
	{
		cout << "texture2 Image couldn't load!";
	}
	if (!texture3.loadFromFile("proj1.png"))
	{
		cout << "texture3 Image couldn't load!";
	}
	if (!texture4.loadFromFile("star1.png"))
	{
		cout << "texture4 Image couldn't load!";
	}

	//UI
	Text instructionsText;
	instructionsText.setCharacterSize(15);
	instructionsText.setFont(font);
	instructionsText.setPosition(50, 30);
	instructionsText.setFillColor(Color::Red);
	instructionsText.setString("Up Arrow: Increase Emission Rate  /  Down Arrow: Decrease Emission Rate");

	Text pCountText;
	pCountText.setCharacterSize(15);
	pCountText.setFont(font);
	pCountText.setPosition( 50, 50);
	pCountText.setFillColor(Color::Red);
	pCountText.setString("Particle Count");

	Text fpsText;
	fpsText.setCharacterSize(15);
	fpsText.setFont(font);
	fpsText.setPosition(50, 70);
	fpsText.setFillColor(Color::Red);
	fpsText.setString("FPS");

	//setup
	int particleCount = MAX_PARTICLES;
	float emissionRate = 0.01;
	float emissionSpeed = 50;
	float angleRange = 15;

	//Particle Systems
	ParticleSystem* ps = new ParticleSystem(POS1, particleCount, emissionRate, emissionSpeed, angleRange * 2, &texture1);
	ParticleSystem* ps2 = new ParticleSystem(POS2, particleCount, emissionRate / 20, emissionSpeed * 2, angleRange * 3, &texture2);
	ParticleSystem* ps3 = new ParticleSystem(POS3, particleCount, emissionRate / 5, emissionSpeed * 4, angleRange * 4, &texture3);
	ParticleSystem* ps4 = new ParticleSystem(POS4, particleCount, emissionRate/2, emissionSpeed, angleRange * 5, &texture4);


	while (window.isOpen())
	{
		getEvents();
		float dt = clock.restart().asSeconds();
		window.clear();

		ps->update(dt, &window);
		ps2->update(dt, &window);
		ps3->update(dt, &window);
		ps4->update(dt, &window);

		int totalParticles = ps->getParticleCount() + ps2->getParticleCount() + ps3->getParticleCount() + ps4->getParticleCount();
		pCountText.setString("Particle Count: " + to_string(totalParticles));
		fpsText.setString("FPS: "+to_string(1.f / dt).substr(0, 4));
		
		window.draw(pCountText);
		window.draw(fpsText);
		window.draw(instructionsText);
		window.display();
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
