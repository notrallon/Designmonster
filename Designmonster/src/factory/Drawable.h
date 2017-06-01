#pragma once

#include <SFML/Graphics.hpp>

class Drawable {
public:
	Drawable();
	virtual ~Drawable();

	virtual void Draw(sf::RenderWindow& window) = 0;

protected:
	std::string m_Path;
};