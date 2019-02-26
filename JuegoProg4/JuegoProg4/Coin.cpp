#include "Coin.h"
#include "SFML/Graphics.hpp"

Coin::Coin(Vector2f vector) {

	textura.loadFromFile("./res/Imagenes/Coin.png");
	setTexture(textura);
	setPosition(vector);
}