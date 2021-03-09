#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <type_traits>
#include <concepts>


template<typename U>
	concept Arithmetic = std::is_arithmetic_v<U>;


class Engine {
		
	const int W_WIDTH = 800;
	const int W_HEIGHT = 600;

	public:
		Engine() = default;
		
		void MainLoop();
		
		template<Arithmetic T, Arithmetic U>
		[[nodiscard]] T genRandomNumber(const U min, const U max) const; 
};


