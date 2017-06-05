#include "TextureManager.h"

sf::Texture * TextureManager::Load(const std::string & path) {
	std::cout << "Texturemanager is attempting to load: " << path << ".\n";
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile(path)) {
		delete texture;
		texture = nullptr;
	}
	return texture;
}