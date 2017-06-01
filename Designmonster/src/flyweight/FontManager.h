#pragma once

#include "ResourceManager.h"

#include <SFML/Graphics.hpp>

class FontManager : public ResourceManager<FontManager, sf::Font> {
public:
	FontManager() {}

	sf::Font* Load(const std::string& path) {
		std::cout << "Fontmanager is trying to load: " << path << "\n";
		sf::Font* font = new sf::Font();
		if (!font->loadFromFile(path)) {
			delete font;
			font = nullptr;
		}
		return font;
	}
};