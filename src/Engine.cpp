#include "../include/Engine.hpp"



void Engine::MainLoop() {

	sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Simulation");

	while(window.isOpen()) {
		
		sf::Event event;
		while(window.pollEvent(event)) {

			if(event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		// DRAW
		
		window.display();
	}
}
