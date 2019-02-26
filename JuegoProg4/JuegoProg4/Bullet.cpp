#include "Bullet.h"
#include <SFML/Graphics.hpp>

Bullet::Bullet(Vector2f vector)
{
	speed = 7;
	textura.loadFromFile("./res/Imagenes/Coin.png");
	setTexture(textura);
	setPosition(vector);
}
Bullet::~Bullet()
{
	
}


