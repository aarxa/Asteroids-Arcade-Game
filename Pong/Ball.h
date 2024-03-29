#pragma once

#include <SFML/Graphics.hpp>



class Ball : public sf::CircleShape
{
public:


	Ball(const sf::Color& ballColor, const float& newRadius, const sf::Vector2f& newPos) :
		sf::CircleShape(newRadius)
	{
		this->setFillColor(ballColor);
		this->setPosition(newPos);
	}




private:

};