#pragma once

#include <SFML/Graphics.hpp>

class Obstacle : public sf::CircleShape
{
public:
	Obstacle(sf::RenderWindow &window, const sf::Color& ballColor, const float& r, size_t point,const sf::Texture &texture) :
		sf::CircleShape(r, point)
	{
		int randr = 0;
		int randposx = 0, randposy = 0;
		randr = rand() % 6 + 24;
		randposx = window.getSize().x - rand() % (window.getSize().x - 2 * randr) - 2 * randr;
		do {
			randposx = window.getSize().x - rand() % (window.getSize().x - 2 * randr) - 2 * randr;
		} while ((randposx + 2 * r) > ((window.getSize().x / 2) - 20) && (randposx + 2 * r)  < ((window.getSize().x / 2) + 20));
		randposy = window.getSize().y - rand() % (window.getSize().y - 2 * randr) - 2 * randr;
		do {
			randposy = window.getSize().y - rand() % (window.getSize().y - 2 * randr) - 2 * randr;
		} while ((randposy + 2 * r) > ((window.getSize().y / 2) - 20) && (randposy + 2 * r) < ((window.getSize().y / 2) + 20));
		do {
			randposy = window.getSize().y - rand() % (window.getSize().y - 2 * randr) - 2 * randr;
		} while ((randposy + 2 * r) > ((window.getSize().y ) - 40));
		this->setFillColor(ballColor);
		this->setPosition(randposx, randposy);
		this->setTexture(&texture);
	}
	int randposy(sf::RenderWindow& window)
	{
		int randr = rand() % 6 + 24;
		return window.getSize().y - rand() % (window.getSize().y - 2 * randr) - 2 * randr;
	}
private:
};
