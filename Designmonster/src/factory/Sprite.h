#pragma once

#include "../flyweight/TextureManager.h"
#include "Drawable.h"

class Sprite : public Drawable {
public:
	Sprite(std::string path);

	virtual void Draw(sf::RenderWindow& window) override;
private:
	sf::Sprite* m_Sprite;
};