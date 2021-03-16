#include "../include/Engine.hpp"

#include <random>
#include <iostream>

template<typename T, typename U>
T Engine::genRandomNumber(U min, U max) {

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> distrib(min, max);
	
	if constexpr (std::is_same_v<T,U>) {
		T result = distrib(gen);
		return result;
	} else {

		T result = static_cast<T>(distrib(gen));
		return result;
	}
}

 
void Engine::MainLoop() {
	

	sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Simulation");
	
	std::vector<sf::RectangleShape> shapes;
	
	[&](){
		
		for(int i = 0; i < 10; ++i) {
			
			auto rect_width = genRandomNumber<float>(20, 80);
			auto rect_height = genRandomNumber<float>(20, 80);
			
			sf::RectangleShape rect(sf::Vector2f(rect_width, rect_height));
		
			auto posX = genRandomNumber<float>(20, static_cast<int>(W_WIDTH - rect_width));
			auto posY = genRandomNumber<float>(10, static_cast<int>(W_HEIGHT - rect_height));

			rect.setPosition(sf::Vector2f(posX, posY));

			auto red = genRandomNumber<int>(0, 255);
			auto green = genRandomNumber<int>(0, 255);
			auto blue = genRandomNumber<int>(0, 255);

			rect.setFillColor(sf::Color(red, green, blue));

			shapes.push_back(rect);
		}
	
	}();

	while(window.isOpen()) {
		
		sf::Event event;
		while(window.pollEvent(event)) {

			if(event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		
		for(auto& elem : shapes)
			window.draw(elem);
		
		window.display();
	}
}
