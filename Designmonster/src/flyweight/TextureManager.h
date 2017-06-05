#pragma once

#include "ResourceManager.h"

#include <SFML/Graphics.hpp>

class TextureManager : public ResourceManager<TextureManager, sf::Texture> {
	friend class ResourceManager<TextureManager, sf::Texture>;
public:
	TextureManager() {}

private:
	sf::Texture* Load(const std::string& path);
};