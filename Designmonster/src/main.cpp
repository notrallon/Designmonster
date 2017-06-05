#include "factory/Resourcefactory.h"
#include "factory/Sprite.h"
#include "factory/Text.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

int main() {
	sf::RenderWindow window;
	window.create({ 1280, 720, 32 }, "Designmonster - Richard Norqvist");

	std::string path1 = "Textures/Ladder.png";
	std::string path2 = "Fonts/Pokemon_Hollow.ttf";
	std::string path3 = "Fonts/Supersonic_Rocketship.ttf";
	std::string path4 = "Fonts/Stya.ttf";
	std::string path5 = "Textures/arrow.png";
	std::string path6 = "Textures/gravestone.png";
	// Made this scope just to show what happens when the resource managers destructor runs.
	{
		Resourcefactory resources;

		std::vector<Drawable*> drawables;
		{
			while (window.isOpen()) {
				sf::Event evnt;
				while (window.pollEvent(evnt)) {
					switch (evnt.type)
					{
					case sf::Event::Closed: {
						window.close();
					} break;

					case sf::Event::KeyPressed: {
						std::string path;
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
							path = path1;
						} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
							path = path2;
						} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
							path = path3;
						} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
							path = path4;
						} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
							path = path5;
						} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
							path = path6;
						} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
							if (drawables.size() > 0) {
								delete drawables.back();
								drawables.back() = nullptr;
								drawables.pop_back();
							}
						}

						Drawable* drawable = resources.Load(path);
						if (drawable != nullptr) {
							drawables.push_back(drawable);
						}

					} break;
					default:
						break;
					}
				}

				window.clear();

				for (auto drawable : drawables) {
					drawable->Draw(window);
				}

				window.display();
			}
			// Delete all our drawables when we leave scope.
			for (auto drawable : drawables) {
				delete drawable;
				drawable = nullptr;
			}
		}
	}

	std::cin.get();

	return 0;
}