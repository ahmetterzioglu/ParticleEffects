#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "Utils.h"
#include "Particle.h"
using namespace sf;
using namespace std;
	
RenderWindow window;

int main()
{
	srand(static_cast<unsigned int>(std::time(NULL)));
	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Particle Systems");
	Clock clock;
	return 0;
}
