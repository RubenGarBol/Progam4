#pragma once
#include <SFML\Graphics.hpp>
class Bullet
{
public:
	Bullet(sf::Vector2f size) 
	{
		bullet.setSize(size);
		bullet.setFillColor(sf::Color::Blue);
	}

	void fire(int bspeed) 
	{
		bullet.move(bspeed, 0);
	}
	int getder()
	{
		return bullet.getPosition().x + bullet.getSize().x;
	}
	int getizq()
	{
		return bullet.getPosition().x;
	}
	int getsup()
	{
		return bullet.getPosition().y;
	}
	int getinf()
	{
		return bullet.getPosition().y + bullet.getSize().y;
	}

	void draw(sf::RenderWindow &window) 
	{
		window.draw(bullet);
	}
private:
	sf::RectangleShape bullet;
};

