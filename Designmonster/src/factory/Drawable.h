#pragma once

#include <SFML/Graphics.hpp>

// Drawable is an abstract class for all types of drawables.
class Drawable {
public:
	Drawable() = default;
	virtual ~Drawable() {}

	virtual void Draw(sf::RenderWindow& window) = 0;

protected:
	std::string m_Path;
};