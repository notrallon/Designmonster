#include "Resourcefactory.h"

Resourcefactory::Resourcefactory() {
	m_FontManager = new FontManager();
	m_TextureManager = new TextureManager();
}

Resourcefactory::~Resourcefactory() {
	delete m_TextureManager;
	delete m_FontManager;
}

sf::Drawable* Resourcefactory::Load(std::string path)
{
	// Get the line ending
	std::string fileEnding = path.substr(path.find_last_of(".") + 1);

	if (fileEnding == "png") {
		sf::Sprite* sprite = new sf::Sprite();
		sprite->setTexture(*m_TextureManager->RequireResource(path));
		sprite->setPosition(sf::Vector2f(rand() % 1000, rand() % 500));
		return sprite;
	} else if (fileEnding == "ttf") {
		sf::Text* text = new sf::Text();
		text->setFont(*m_FontManager->RequireResource(path));
		return text;
	}
}
