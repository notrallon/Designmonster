#include "factory/Resourcefactory.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

int main() {
	sf::RenderWindow window;
	window.create({ 1280, 720, 32 }, "Designmonster - Richard Norqvist");

	std::string path1 = "Textures/goku.png";
	std::string path2 = "Textures/arrow.png";
	std::string path3 = "Textures/gravestone.png";
	std::string path4 = "Fonts/Stya.ttf";
	// Made this scope just to show what happens when the resource managers destructor runs.
	{
		Resourcefactory resFactory;

		std::vector<sf::Drawable*> drawables;
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
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
							drawables.push_back(resFactory.Load(path1));
						} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
							drawables.push_back(resFactory.Load(path2));
						} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
							drawables.push_back(resFactory.Load(path3));
						} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
							drawables.push_back(resFactory.Load(path4));
						} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
							if (drawables.size() > 0) {
								delete drawables.back();
								drawables.back() = nullptr;
								drawables.pop_back();
							}
						}
					} break;
					default:
						break;
					}
				}

				window.clear();

				for (auto drawable : drawables) {
					window.draw(*drawable);
				}

				window.display();
			}
			for (auto drawable : drawables) {
				delete drawable;
				drawable = nullptr;
			}
		}
	}

	std::cin.get();

	return 0;
}