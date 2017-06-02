#pragma once

#include "../flyweight/TextureManager.h"
#include "Drawable.h"

class Sprite : public Drawable {
public:
						Sprite(const std::string& path, TextureManager* texturemanager);
	virtual				~Sprite() override;

	virtual void		Draw(sf::RenderWindow& window) override;
private:
	sf::Sprite			m_Sprite;
	TextureManager*		m_TextureManager;
};