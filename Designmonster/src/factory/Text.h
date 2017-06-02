#pragma once

#include "Drawable.h"
#include "../flyweight/FontManager.h"

class Text : public Drawable {
public:
					Text(const std::string& path, FontManager* fontmanager);
	virtual			~Text() override;

	virtual void	Draw(sf::RenderWindow& window) override;

private:
	sf::Text		m_Text;
	FontManager*	m_FontManager;
};