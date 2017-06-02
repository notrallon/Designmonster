#include "Sprite.h"

Sprite::Sprite(const std::string& path, TextureManager* texturemanager) : m_TextureManager(texturemanager) {
	m_Path = path;

	m_Sprite.setTexture(*m_TextureManager->RequireResource(m_Path));
	m_Sprite.setPosition(rand() % 1000, rand() % 500);
}

Sprite::~Sprite() {
	m_TextureManager->ReleaseResource(m_Path);
}

void Sprite::Draw(sf::RenderWindow& window) {
	window.draw(m_Sprite);
}
