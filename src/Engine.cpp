#include "../include/Engine.hpp"

#include <random>

template<Arithmetic T, Arithmetic U>
[[nodiscard]] T Engine::genRandomNumber(const U min, const U max) const {
	
	std::random_device seed;
	std::mt19937 generator(seed());
	
	if(std::is_integral_v<T>) {

		std::uniform_int_distribution<> distrib(min, max);
		return distrib(generator);
		
	} else {

		std::uniform_int_distribution<> distrib(min, max);

		return static_cast<T>(distrib(generator));
	}
}


void Engine::MainLoop() {

	sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Simulation");
	
	std::vector<sf::RectangleShape> shapes;

	[&]() {

		for(int i = 0; i < 5; i++) {
			
			auto rect_width = genRandomNumber<float>(20, 101);
			auto rect_height = genRandomNumber<float>(20, 101);

			sf::RectangleShape rect(sf::Vector2f(rect_width, rect_height));

			auto red = genRandomNumber<int>(0, 255);
			auto green = genRandomNumber<int>(0, 255);
			auto blue = genRandomNumber<int>(0, 255);

			rect.setFillColor(sf::Color(red, green, blue));

			auto posX = genRandomNumber<float>(W_WIDTH - 100, W_HEIGHT - 100);
			auto posY = genRandomNumber<float>(W_WIDTH - 100, W_HEIGHT - 100);

			rect.setPosition(sf::Vector2f(posX, posY));

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
		
		//for(auto& elem : Shapes)
		//	window.draw(elem);
		
		window.display();
	}
}
