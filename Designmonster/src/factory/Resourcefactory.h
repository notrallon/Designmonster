#pragma once

#include "Drawable.h"
#include "../flyweight/TextureManager.h"
#include "../flyweight/FontManager.h"

class Resourcefactory {
public:
					Resourcefactory();
					~Resourcefactory();

	Drawable*		Load(const std::string& path);

private:
	TextureManager	m_TextureManager;
	FontManager		m_FontManager;
};
