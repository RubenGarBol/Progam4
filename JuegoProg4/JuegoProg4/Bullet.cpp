#include "Bullet.h"
#include <SFML/Graphics.hpp>


Bullet::Bullet(sf::Vector2f vector) {

	textura.loadFromFile("./res/Imagenes/Coin.png");
	setTexture(textura);
	setPosition(vector);
}