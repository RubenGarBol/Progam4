#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite {
public:

	Texture textura;
	Bullet(sf::Vector2f size) 
	{
		bullet.setSize(size);
	}

	void disparo(int speed) 
	{
		bullet.move(speed, 0);
	}

	int getDer() 
	{
		return bullet.getPosition().x + bullet.getSize().x;
	}
	int getIzq() 
	{
		return bullet.getPosition().x;
	}
	int getSup()
	{
		return bullet.getPosition().y;
	}
	int getInf() 
	{
		return bullet.getPosition().y + bullet.getSize().y;
	}

	void draw(sf::RenderWindow &window) 
	{
		window.draw(bullet);
	}
	void setPos(sf::Vector2f newPos) 
	{
		bullet.setPosition(newPos);
	}

private:
	sf::RectangleShape bullet;


};



