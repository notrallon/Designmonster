#pragma once

#include "ResourceManager.h"

#include <SFML/Graphics.hpp>

class TextureManager : public ResourceManager<TextureManager, sf::Texture> {
public:
	TextureManager() {}

	sf::Texture* Load(const std::string& path) {
		sf::Texture* texture = new sf::Texture();
		if (!texture->loadFromFile(path)) {
			delete texture;
			texture = nullptr;
		}
		return texture;
	}
};