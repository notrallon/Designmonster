#include "FontManager.h"

sf::Font* FontManager::Load(const std::string & path) {
	std::cout << "Fontmanager is trying to load: " << path << ".\n";
	sf::Font* font = new sf::Font();
	if (!font->loadFromFile(path)) {
		delete font;
		font = nullptr;
	}
	return font;
}
