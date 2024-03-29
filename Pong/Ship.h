#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

class Ship : public sf::CircleShape
{
public:
	Ship(const float& r, const sf::Color& ShipColor, const sf::Vector2f& newPos, size_t point) : sf::CircleShape(r, point) 
	{
	this->setFillColor(ShipColor);
	this->setPosition(newPos);
	}

private:
	

};