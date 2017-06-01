#include "Sprite.h"

Sprite::Sprite(std::string path) {
	m_Path = path;
}

void Sprite::Draw(sf::RenderWindow & window) {
	window.draw(*m_Sprite);
}
