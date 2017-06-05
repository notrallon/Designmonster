#pragma once

#include "ResourceManager.h"

#include <SFML/Graphics.hpp>

class FontManager : public ResourceManager<FontManager, sf::Font> {
	friend class ResourceManager<FontManager, sf::Font>;
public:
	FontManager() {}

private:
	sf::Font* Load(const std::string& path);
};