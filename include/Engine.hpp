#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <type_traits>
#include <concepts>




class Engine {
		
	const int W_WIDTH = 800;
	const int W_HEIGHT = 600;

	public:
		Engine() = default;
		
		void MainLoop();
		
		template<typename T, typename U>
		T genRandomNumber(U min, U max);
};
