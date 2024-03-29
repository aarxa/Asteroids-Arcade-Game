/*
	Name: Aarya, Crystal, Jingjing
	Date: 12/9/2022
	Class: CptS 122
	Programming Assignment: PA 9
	Description: Asteroids arcade game in C++/SFML
*/

#include <SFML/Graphics.hpp>
#include <time.h>
#include "obstacle.h"
#include "Ball.h"
#include "Ship.h"
#include "Test.h"
#include <Windows.h>
#include <vector> 
#include <iostream>

int main()
{
	srand((unsigned int)time(NULL));
	
	//Creation of a window to display game
	sf::RenderWindow window(sf::VideoMode(500, 500), "Asteroids Arcade Game");

	//Creation of ship using circle shape modified to make a triangle
	Ship myShip(20, sf::Color::White, sf::Vector2f((window.getSize().x / 2) - 20, (window.getSize().y / 2) - 20), 3);
	
	//A vector holds the bullets to allow for multiple instances of bullet to be shot
	std::vector <Ball> bulletRespawn;

	//imported graphics
	sf::Texture obstacletexture;
	if (!obstacletexture.loadFromFile("OIP.png"))
	{
		// error
	}
	
	//creation of asteroid objects
	Obstacle asteroid1(window, sf::Color::White, rand() % 6 + 24, 8, obstacletexture);
	Obstacle asteroid2(window, sf::Color::White, rand() % 6 + 24, 8, obstacletexture);
	Obstacle asteroid3(window, sf::Color::Green, rand() % 6 + 24, 8, obstacletexture);
	Obstacle asteroid4(window, sf::Color::Yellow, rand() % 6 + 24, 8, obstacletexture);
	Obstacle asteroid5(window, sf::Color::Yellow, rand() % 6 + 24, 8, obstacletexture);
	
	//Initializing direction
	//Variable declarations 
	int direction1 = 1, direction2 = 1, direction3 = 1, direction4 = 1, direction5 = 1, hitCount = 0,
		index = 0, option = 0, points = 0;
	bool shooting = false;

	//importing text to display current score
	sf::Font arial;
	if (!arial.loadFromFile("arial.ttf"))
	{
		// error
	}

	//setting text to size, position
	sf::Text scoreBoard, pointDisplay;
	scoreBoard.setCharacterSize(20);
	scoreBoard.setPosition(10, 10);
	scoreBoard.setFont(arial);
	scoreBoard.setString("SCOREBOARD: ");
	pointDisplay.setFont(arial);
	pointDisplay.setCharacterSize(20);
	pointDisplay.setPosition(scoreBoard.getPosition().x + 150, scoreBoard.getPosition().y);
	

	//check to see that textures were loaded
	sf::Texture texture;
	if (!texture.loadFromFile("background.png"))
	{
		// error
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sf::Texture starttexture;
	if (!starttexture.loadFromFile("AsteroidsMenu.png"))
	{
		// error
	}
	sf::Sprite startsprite;
	startsprite.setTexture(starttexture);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//menu choice
		if (option == 0)
		{
			hitCount = 0;
			window.clear();
			window.draw(startsprite);
			window.display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				option = 1;
			}
		}
		if (option == 1)
		{//For each of these events (the ship will move in direction of key pressed)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				myShip.move(-0.12, 0);

				if (myShip.getPosition().x < 0.f)
				{
					myShip.setPosition(0.f, myShip.getPosition().y); //does not allow for ship to move outside of window bounds
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				myShip.move(0, -0.12);
				if (myShip.getPosition().y < 0.f)
				{
					myShip.setPosition(myShip.getPosition().x, 0.f); //does not allow for ship to move outside of window bounds
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				myShip.move(0.12, 0);

				if (myShip.getPosition().x + myShip.getGlobalBounds().width > window.getSize().x)
				{
					myShip.setPosition(window.getSize().x - myShip.getGlobalBounds().width, myShip.getPosition().y); //does not allow for ship to move outside of window bounds
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				myShip.move(0, 0.12);

				if (myShip.getPosition().y + myShip.getGlobalBounds().width > window.getSize().y)
				{
					myShip.setPosition(myShip.getPosition().x, window.getSize().y - myShip.getGlobalBounds().width); //does not allow for ship to move outside of window bounds
				}
			}

			//does not allow for ship to move outside of set window bounds creating illusion that new asteroids are coming in
			if (asteroid1.getPosition().x > window.getSize().x - 2 * asteroid1.getRadius())
			{
				direction1 = -1;
			}
			if (asteroid1.getPosition().x < 0.f)
			{
				direction1 = 1;
			}
			asteroid1.move(0.06 * direction1, 0.01 * direction1);
			if (asteroid2.getPosition().x > window.getSize().x - 2 * asteroid2.getRadius())
			{
				direction2 = -1;
			}
			if (asteroid2.getPosition().x < 0.f)
			{
				direction2 = 1;
			}
			asteroid2.move(0.06 * direction2, 0.01 * direction2);
			if (asteroid3.getPosition().x > window.getSize().x - 2 * asteroid3.getRadius())
			{
				direction3 = -1;
			}
			if (asteroid3.getPosition().x < 0.f)
			{
				direction3 = 1;
			}
			asteroid3.move(0.06 * direction3, 0.01 * direction3);
			if (asteroid4.getPosition().x > window.getSize().x - 2 * asteroid4.getRadius())
			{
				direction4 = -1;
			}
			if (asteroid4.getPosition().x < 0.f)
			{
				direction4 = 1;
			}
			asteroid4.move(0.06 * direction4, 0.01 * direction4);
			if (asteroid5.getPosition().x > window.getSize().x - 2 * asteroid5.getRadius())
			{
				direction5 = -1;
			}
			if (asteroid5.getPosition().x < 0.f)
			{
				direction5 = 1;
			}
			asteroid5.move(0.06 * direction5, 0.01 * direction5);

			//creation of a projectile when the space bar is pressed, allow for multiple projectiles to be created
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (index < 4)
				{
					Ball Bullet(sf::Color::Red, 2, sf::Vector2f(myShip.getPosition().x + 16, myShip.getPosition().y + 16));
					bulletRespawn.push_back(Bullet); //placing projectile into vector
					index++;
				}
				shooting = true;
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					index = 0; //reset the index
				}
			}

			//while spacebar is pressed we check to see what the projectile does
		
			//if projectile collides with an asteroid, asteroid will move off screen and float back in
			//instead of creating new asteroids
			if (shooting == true)
			{
				for (size_t i = 0; i < bulletRespawn.size(); i++)
				{
					bulletRespawn[i].move(0, -0.15);
					if (asteroid1.getGlobalBounds().intersects(bulletRespawn[i].getGlobalBounds()))
					{
 						points = points + 10;	//updates score by ten points if an asteroid is hit					
						asteroid1.setPosition(sf::Vector2f(window.getSize().x + 716, asteroid1.randposy(window)));
						//if projectile collides with an asteroid, it will disapear from screen
						bulletRespawn[i].setPosition(sf::Vector2f(window.getSize().x + 716, asteroid1.randposy(window)));

					}

					if (asteroid2.getGlobalBounds().intersects(bulletRespawn[i].getGlobalBounds()))
					{
						points = points + 10;
						asteroid2.setPosition(sf::Vector2f(window.getSize().x + 716, asteroid2.randposy(window)));
						bulletRespawn[i].setPosition(sf::Vector2f(window.getSize().x + 716, asteroid2.randposy(window)));
					}

					if (asteroid3.getGlobalBounds().intersects(bulletRespawn[i].getGlobalBounds()))
					{
						points = points + 10;
						asteroid3.setPosition(sf::Vector2f(window.getSize().x + 716, asteroid3.randposy(window)));
						bulletRespawn[i].setPosition(sf::Vector2f(window.getSize().x + 716, asteroid3.randposy(window)));

					}

					if (asteroid4.getGlobalBounds().intersects(bulletRespawn[i].getGlobalBounds()))
					{
						asteroid4.setPosition(sf::Vector2f(window.getSize().x + 1516, asteroid4.randposy(window)));
						points = points + 10;

						bulletRespawn[i].setPosition(sf::Vector2f(window.getSize().x + 1516 + 716, asteroid4.randposy(window)));
					}
					if (asteroid5.getGlobalBounds().intersects(bulletRespawn[i].getGlobalBounds()))
					{
						asteroid5.setPosition(sf::Vector2f(window.getSize().x + 1516, asteroid5.randposy(window)));
						points = points + 10;
						bulletRespawn[i].setPosition(sf::Vector2f(window.getSize().x + 1516 + 716, asteroid5.randposy(window)));

					}
				}
			}
		

			if (points >= 200)
			{
				option = 0; //game will end if player reaches 200 points, return back to home screen
			}
			window.clear();

			window.draw(sprite);
			window.draw(asteroid1);
			window.draw(asteroid2);
			window.draw(asteroid3);
			window.draw(asteroid4);
			window.draw(asteroid5);
			window.draw(myShip);
			window.draw(scoreBoard);
			
			//iterates through and displays bullets drawn from vector
			for (size_t i = 0; i < bulletRespawn.size(); i++)
			{
				window.draw(bulletRespawn[i]);
			}

			//convert the integer points into a string so that it can be displayed
			std::string point_string = std::to_string(points);

			//display updating score
			pointDisplay.setString(point_string);
			window.draw(pointDisplay);
			
			window.display();
		}

	
			
	}


	return 0;
}
