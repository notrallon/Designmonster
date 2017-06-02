#include "Text.h"

Text::Text(const std::string& path, FontManager* fontmanager) : m_FontManager(fontmanager) {
	m_Path = path;
	m_Text.setFont(*m_FontManager->RequireResource(m_Path));
	m_Text.setString("Text");
	m_Text.setPosition(rand() % 1000, rand() % 500);
}

Text::~Text() {
	m_FontManager->ReleaseResource(m_Path);
}

void Text::Draw(sf::RenderWindow& window) {
	window.draw(m_Text);
}
