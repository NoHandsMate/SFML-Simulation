#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Engine {
		
	const int W_WIDTH = 800;
	const int W_HEIGHT = 600;

	public:
		Engine() = default;
		
		void MainLoop();
};


