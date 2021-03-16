#pragma once

#include <SFML/Graphics.hpp>


class Rect : public sf::RectangleShape {
	
	private:
		
		float m_mass  { 0.f };

	public:
	
		using sf::RectangleShape::RectangleShape; // Inherit base constructor

		constexpr void setMass(const float mass) {
			m_mass = mass;
		};


		[[nodiscard]] constexpr float getMass() const {
			return m_mass;
		}
};
