#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "Ball.h"
#include "obstacle.h"

using std::cout;
using std::cin;
using std::endl;
using sf::Texture;
using sf::RenderWindow;
using sf::Color;

class Test
{
public: 
	Test() {}
	~Test() {}

	void testImagesLoad();
	void testShipMovement();

private:
	//Ship testship;
	RenderWindow* window;
};
