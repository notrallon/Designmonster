#include "Resourcefactory.h"
#include "Sprite.h"
#include "Text.h"

Resourcefactory::Resourcefactory() {
}

Resourcefactory::~Resourcefactory() {
}

Drawable* Resourcefactory::Load(std::string path) {
	// Return nullptr if the string is empty
	if (path == "") {
		return nullptr;
	}

	// Get the file extension so that we can determine what type of file it is.
	std::string fileExtension = path.substr(path.find_last_of(".") + 1);

	// Return a new type of drawable depending
	// on the file extension.
	if (fileExtension == "png") {
		return new Sprite(path, &m_TextureManager);
	} else if (fileExtension == "ttf") {
		return new Text(path, &m_FontManager);
	}
}
