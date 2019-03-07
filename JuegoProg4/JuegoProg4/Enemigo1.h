#pragma once
#include<SFML/Graphics.hpp>
#include "Bullet.h"
class Enemigo1
{
public:
	Enemigo1(sf::Vector2f size) 
	{
		enemy.setSize(size);
		enemy.setFillColor(sf::Color::Red);
	}

	void setPos(sf::Vector2f npos) 
	{
		enemy.setPosition(npos);
	}
	void compbala(Bullet bullet)
	{
	}
private:

	sf::RectangleShape enemy;
	
};

